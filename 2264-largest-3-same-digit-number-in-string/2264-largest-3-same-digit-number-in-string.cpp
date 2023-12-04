class Solution {
public:
    string largestGoodInteger(string num) {
         int res = -1;
         for(int i=0;i<num.size()-2;i++){
             string temp;map<int,int>mp;
             for(int j=i;j<i+3;j++){
                 temp.push_back(num[j]);
                 mp[num[j]+'0']++;
             }
            if(mp.size()==1)res = max(res,stoi(temp));
         }
        if(res==0)return "000";
        return res!=-1?to_string(res):"";
    }
};