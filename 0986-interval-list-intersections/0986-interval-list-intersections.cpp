class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>>result;
        for(int i=0;i<firstList.size();i++){
            for(int j=0;j<secondList.size();j++){
                if(secondList[j][0]<=firstList[i][1]&&firstList[i][0]<=secondList[j][1]){
                    result.push_back({max(secondList[j][0],firstList[i][0]),min(secondList[j][1],firstList[i][1])});
                }
            }
        }
        //   for(int i=0;i<firstList.size();i++){
        //     for(int j=0;j<secondList.size();j++){
        //         if(secondList[j][0]<=firstList[i][1]&&firstList[i][1]<=secondList[j][0]){
        //             result.push_back({max(secondList[j][0],firstList[i][0]),max(secondList[j][0],firstList[i][0])});
        //         }
        //     }
        // }
        return result;
    }
};