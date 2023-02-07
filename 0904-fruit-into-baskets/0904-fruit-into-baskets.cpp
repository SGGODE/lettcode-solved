class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mp;
        for(auto it:fruits)mp[it]++;
        if(mp.size()<=2)return fruits.size();
        int cnt=INT_MIN;
        // for(int i=0;i<fruits.size();i++){
        //     unordered_map<int,int>cp;
        //     for(int j=i;j<fruits.size();j++){
        //         cp[fruits[j]]++;
        //         if(cp.size()<=2){
        //           cnt=max(cnt,j-i+1);  
        //         }else break;
        //     }
        // }
        unordered_map<int,int>xp;
        int curr_sum=0;
        int j=0;
        for(int i=0;i<fruits.size();i++){
            xp[fruits[i]]++;
            if(xp.size()<=2){
                curr_sum+=1;
            }else{
                cnt=max(curr_sum,cnt);
                while(xp.size()!=2&&j<fruits.size()){
                    --xp[fruits[j]];
                    if(xp[fruits[j]]==0)xp.erase(fruits[j]);
                    curr_sum-=1;
                    ++j;
                }
                curr_sum+=1;
            }
        }
        cnt=max(cnt,curr_sum);
        return cnt;
    }
};