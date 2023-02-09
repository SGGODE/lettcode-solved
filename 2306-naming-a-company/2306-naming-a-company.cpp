class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
  //       int n=v.size();
  // long long int cnt=0;
  //  unordered_map<string,int>mp;
  //  for(auto it:v)mp[it]++;
  //  for(int i=0;i<n;i++){
  //    for(int j=i+1;j<n;j++){
  //      string x=v[i],y=v[j];
  //      // char ch=y[0],tr=x[0];
  //      // x[0]=ch;
  //      // y[0]=tr;
  //      swap(x[0],y[0]);
  //      if(mp.find(x)==mp.end()&&mp.find(y)==mp.end())cnt+=2;
  //      // else{
  //      //  // cnt+=2;
  //      //   cout<<x<<" "<<y<<endl;
  //      // }
  //    }
  //  }
  //  // cout<<cnt<<endl;
  //       return cnt;
         long long disName = 0;
        vector<unordered_set<string>> arr(26);
        for (string s : ideas) 
            arr[s[0] - 'a'].insert(s.substr(1));
        
        for (int i = 0; i < 25; i++) {
            for (int j = i + 1; j < 26; j++) {
                unordered_set<string> set;
                set.insert(arr[i].begin(), arr[i].end());
                set.insert(arr[j].begin(), arr[j].end());
                disName += (arr[i].size() - set.size()) * (arr[j].size() - set.size());
            }
        }
        return disName * 2;
    }
};