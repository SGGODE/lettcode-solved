class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>res;
        for(int i=0;i<=n;i++){
            int num=i;
            int cnt=0;
            while(num){
              if(num&1)++cnt;
               num=num>>1;
            }
            res.push_back(cnt);
        }
        return res;
    }
};