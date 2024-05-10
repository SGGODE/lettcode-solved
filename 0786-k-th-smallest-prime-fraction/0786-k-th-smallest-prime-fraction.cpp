class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>,greater<pair<double,pair<int,int>>>>pq;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                pq.push({(double)arr[i]/arr[j],{arr[i],arr[j]}});
                //if(pq.size()>k)pq.pop();
            }
        }
        k--;
        while(k!=0){
           // cout<<pq.top().first<<" "<<pq.top().second.first<<" "<<pq.top().second.second<<endl;
            pq.pop();
            k--;
        }
        return {pq.top().second.first,pq.top().second.second};
    }
};