// class Solution {
// public:
//     double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
//         vector<pair<double,int>>ratio;
//         int index = 0;
//         for(auto & it : classes){
//             double val = ((double)((double)it[0] / (double)it[1]));
//             ratio.push_back({val , index});
//             cout<<val<<" ";
//            // cout<<it[0]<<" "<<it[1]<<" "<<val<<" "<<((double)(1.00 / 2.00))<<endl;
//             ++index;
//         }
//         cout<<endl;
//         sort(ratio.begin(),ratio.end());
//         double sum = ((double)((double)classes[ratio[0].second][0] + extraStudents)/(double)(classes[ratio[0].second][1] + extraStudents));
//        // cout<<ratio[<<" "<<classes[ratio[0].second][0] + extraStudents<<" "<<classes[ratio[0].second][1] + extraStudents<<endl;
//         cout<<sum<<endl;
//         for(int i = 1; i < ratio.size(); i++){
//             cout<<ratio[i].first<<" ";
//             sum += ratio[i].first;
//         }
//         cout<<sum<<endl;
//         return sum / ratio.size();
//     }
// };

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Lambda to calculate the gain of adding an extra student
        auto calculateGain = [](int passes, int totalStudents) {
            return (double)(passes + 1) / (totalStudents + 1) -
                   (double)passes / totalStudents;
        };

        // Max heap to store (-gain, passes, totalStudents)
        priority_queue<pair<double, pair<int, int>>> maxHeap;
        for (const auto& singleClass : classes) {
            maxHeap.push({calculateGain(singleClass[0], singleClass[1]),
                          {singleClass[0], singleClass[1]}});
        }

        // Distribute extra students
        while (extraStudents--) {
            auto [currentGain, classInfo] = maxHeap.top();
            maxHeap.pop();
            int passes = classInfo.first;
            int totalStudents = classInfo.second;
            maxHeap.push({calculateGain(passes + 1, totalStudents + 1),
                          {passes + 1, totalStudents + 1}});
        }

        // Calculate the final average pass ratio
        double totalPassRatio = 0;
        while (!maxHeap.empty()) {
            auto [_, classInfo] = maxHeap.top();
            maxHeap.pop();
            totalPassRatio += (double)classInfo.first / classInfo.second;
        }

        return totalPassRatio / classes.size();
    }
};