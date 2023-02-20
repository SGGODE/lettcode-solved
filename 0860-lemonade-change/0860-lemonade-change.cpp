class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int,int>mp;
        for(auto it:bills){
            if(it==5){
                mp[it]++;
                continue;
            }if(it==10){
                if(mp.find(5)!=mp.end()){
                    --mp[5];
                    if(mp[5]==0)mp.erase(5);
                    ++mp[10];
                    continue;
                }else return 0;
                // ++mp[10];
                continue;
            }if(it==20){
                if((mp.find(5)!=mp.end())&&(mp.find(10)!=mp.end())){
                   --mp[5];
                    --mp[10];
                    if(mp[5]==0)mp.erase(5);
                    if(mp[10]==0)mp.erase(10);
                    continue;
                }else if(mp[5]>=3){
                  mp[5]-=3;
                   if(mp[5]==0)mp.erase(5);
                  continue;
                }else return 0;
            }
        }
        return 1;
    }
};