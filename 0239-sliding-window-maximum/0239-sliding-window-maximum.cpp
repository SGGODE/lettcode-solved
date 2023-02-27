class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        vector<int>v;
        int n=arr.size();
        int m=0;//map<int,int>mp;
        multiset<int>ms;
        //priority_queue<int>pq;
        for(int i=0;i<k;i++){
            m=max(m,arr[i]);
           // mp[arr[i]]++;
            //pq.push(arr[i]);
            ms.insert(arr[i]);
        }
        v.push_back(m);
        for(int i=k;i<n;i++){
         ms.insert(arr[i]);
         ms.erase(ms.find(arr[i-k]));
         int x=*(ms.rbegin());
          v.push_back(x);
        }
        return v;
    }
};