class Solution {
private:
    map<string,int>dp;
    int sub(vector<string>&arr,set<char>&st,string&s,int index){
        if(index==arr.size())return 0;
        string res = s +"_"+ to_string(index);
        if(dp.count(res))return dp[res];
        int ans = 0;
        ans = max(ans,sub(arr,st,s,index+1));
        if(!st.empty()){
            bool flag = 1;
            for(auto&it:arr[index]){
                if(st.count(it)){
                    flag=0;
                    break;
                }
            }
            if(flag){
                set<char>sp(st);
                string temp(s);bool f=1;
                for(auto&it:arr[index]){
                    if(sp.count(it)){f=0;break;}
                    sp.insert(it);
                }
               if(f){temp.append(arr[index]);
                int len = arr[index].size();
                ans = max(ans,len+sub(arr,sp,temp,index+1));}
            }
        }else{
             set<char>sp(st);
                string temp(s);bool f=1;
                for(auto&it:arr[index]){
                    if(sp.count(it)){f=0;break;}
                    sp.insert(it);
                }
               if(f){temp.append(arr[index]);
                int len = arr[index].size();
                ans = max(ans,len+sub(arr,sp,temp,index+1));}
        }
        return dp[res]=ans;
    }
public:
    int maxLength(vector<string>& arr) {
       // memset(dp,-1,sizeof(dp));
        set<char> s;
        string temp;
        return sub(arr,s,temp,0);
    }
};