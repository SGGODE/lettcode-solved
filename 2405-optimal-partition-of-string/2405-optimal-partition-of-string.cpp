class Solution {
public:
    int partitionString(string s) {
        int cnt = 0;
        set<char>mp;
        for(auto&it:s){
            if(mp.count(it)){
                cnt += 1;
                mp.clear();
                mp.insert(it);
            }else{
                mp.insert(it);
            }
        }
        if(!mp.empty())cnt+=1;
        return cnt;
    }
};