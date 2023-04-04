class Solution {
public:
    int partitionString(string s) {
        int cnt=0;
        string x;
        for(int i=0;i<s.size();i++){
              size_t found = x.find(s[i]);
            if(found != string::npos){
                ++cnt;
                x.clear();
                x.push_back(s[i]);
            }else{
                x.push_back(s[i]);
            }
        }
        if(!x.empty())++cnt;
        return cnt;
    }
};