// class Solution {
// private:
//     map<pair<pair<int,int>,double>,double>mp;
//     double sub(vector<int>& quality, vector<int>& wage,vector<pair<double,int>>&ratio,int index,double mul,int k){
//         if(k==0)return 0;
//         if(index==wage.size())return 1e9;
//         if(mp.count({{index,k},mul}))return mp[{{index,k},mul}];
//         double ans = 1e9;
//         if(mul==-1){
//             ans = min(ans,min(wage[ratio[index].second]+sub(quality,wage,ratio,index+1,ratio[index].first,k-1),sub(quality,wage,ratio,index+1,mul,k)));
//         }else{
//             if((mul*quality[ratio[index].second])>=wage[ratio[index].second])ans = min(ans,(mul*quality[ratio[index].second])+sub(quality,wage,ratio,index+1,mul,k-1));
//             ans = min(ans,sub(quality,wage,ratio,index+1,mul,k));
//         }
//         return mp[{{index,k},mul}]=ans;
//     }
// public:
//     double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
//         vector<pair<double,int>>res;
//         for(int i=0;i<wage.size();i++){
//             double x = (double)wage[i]/quality[i];
//             res.push_back({x,(double)quality[i]});
//         }
//         sort(res.begin(),res.end());
//         double ans = 1e9;
//         int n = wage.size();
//         int quality_sum = 0;
//         priority_queue<int> pq; 
//         for(int i=0;i<k;i++) {
//             quality_sum += res[i].second;
//             pq.push(res[i].second);
//         }
//         double pay = quality_sum*res[k-1].second;
//         for(int i=k;i<n;i++) {
//             pq.push(res[i].second);
//             quality_sum+=res[i].second-pq.top();
//             pq.pop();
//             pay = min(pay, quality_sum*res[i].first);
//         }
//         return pay;
//         //return ans;
//        // return sub(quality,wage,res,0,-1,k);
//     }
// };
#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        const int n= quality.size();
        vector<array<double, 2>>  worker(n); // (wage/quality, quality)
        for(int i= 0; i < n; i++) {
            worker[i]={(double)wage[i]/quality[i], (double)quality[i]}; 
        }
		// sorting
        sort(worker.begin(), worker.end());

        int quality_sum = 0;

        priority_queue<int> pq; // max heap for quality
        for(int i = 0; i < k; i++) {//Choose the best k workers according to quality/wage
            quality_sum += worker[i][1];
            pq.push(worker[i][1]);
        }
        double pay = quality_sum*worker[k-1][0];
        for(int i = k; i < n; i++) {
            pq.push(worker[i][1]);
            quality_sum+=worker[i][1]-pq.top();// for low cost, higher quality goes away
            pq.pop();

            pay = min(pay, quality_sum*worker[i][0]);
        }
        return pay;
    }
};
