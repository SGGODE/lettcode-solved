class Solution {
public:
    int minDeletions(string s) {
        map<char,int>mp;
        for(auto&it:s)mp[it]++;
        map<int,int>mx;
        vector<int>freq;
        for(auto&it:mp){
            mx[it.second]++;
           // st.insert(it.second);
        }
        int cnt = 0;
        for(auto&it:mx){
            for(int i=0;i<it.second;i++){
                freq.push_back(it.first);
            }
        }
        sort(freq.begin(),freq.end());
          set<int>st;
        for(int i = freq.size()-1;i>=0;i--){
            if(st.count(freq[i])){
                bool flag=0;
                for(int j=freq[i]-1;j>=1;j--){
                    if(!st.count(j)){
                        flag=1;
                        st.insert(j);
                        cnt+=(freq[i]-j);
                        break;
                    }
                }
                if(!flag)cnt+=freq[i];
            }
            else st.insert(freq[i]);
        }
        return cnt;
    }
};