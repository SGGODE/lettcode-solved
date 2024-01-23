class Solution {
private:
    map<string,int>dp;
    int sub(vector<string>&arr,set<char>&st,string&s,int index){
        if(index==arr.size())return 0;
        string res = s +"_"+ to_string(index);
        if(dp.count(res))return dp[res];
        int ans = 0;
        ans = max(ans,sub(arr,st,s,index+1));
        bool flag = 1;
        set<char>sz;
        for(auto&it:arr[index]){
            if(st.count(it)||sz.count(it)){
                flag=0;
                break;
            }
            sz.insert(it);
        }
        if(flag){
            set<char>sp(st);
            sp.insert(sz.begin(),sz.end());
            string temp(s);
            temp.append(arr[index]);
            int len = arr[index].size();
            ans = max(ans,len+sub(arr,sp,temp,index+1));
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