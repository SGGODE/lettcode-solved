class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int cnt=0;
        string x=to_string(num);
        for(int i=0;i<x.size()-k+1;i++){
            string s;
            for(int j=i;j<i+k;j++){
                s.push_back(x[j]);
            }
            int v=stoi(s);
            if(v==0)continue;
            if(num%v==0)cnt++;
        }
        return cnt;
    }
};