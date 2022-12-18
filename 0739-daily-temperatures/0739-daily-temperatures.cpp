class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        vector<int>ans(n,0);
        //int m=
        // for(int i=0;i<n;i++){
        //  if(i==n-1){
        //      ans.push_back(0);
        //      continue;
        //  }
        //    int cnt=1;
        //   for(int j=i+1;j<n;j++){
        //       if(j==n-1&&temp[i]>=temp[j]){
        //           cnt=0;
        //           break;
        //       }
        //      // if(temp[j]==temp[i])break;
        //       if(temp[j]<=temp[i])cnt++;
        //       else break;
        //      // if(j==n-1&&temp[i]>temp[j]){
        //      //      cnt=0;
        //      //      break;
        //      //  }
        //   }
        //     ans.push_back(cnt);
        // }
        stack<pair<int,int>>s;
        //for(int i=n-1;i>=0;i--)s.push(temp[i]);
        // for(int i=0;i<n;i++){
        //     bool flag=1;
        //     for(int j=i;j<n;j++){
        //         if(temp[j]>temp[i]){
        //             ans.push_back(j-i);
        //             flag=0;
        //             break;
        //         }
        //     }
        //     if(flag)ans.push_back(0);
        // }
        for(int i=0;i<n;i++){
            if(s.empty()){
                s.push({temp[i],i});
                continue;
            }else{
                while(!s.empty()){
                    if(s.top().first<temp[i]){
                    ans[s.top().second]=i-s.top().second;
                    s.pop();
                    }else break;
                }
                s.push({temp[i],i});
            }   
        }
        
        return ans;
    }
};