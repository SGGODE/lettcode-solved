class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>res(n,0);
        stack<pair<int,int>>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&st.top().first<=temperatures[i]){
                st.pop();
            }
            if(st.empty())res[i]=0;
            else res[i]=st.top().second-i;
            st.push({temperatures[i],i});
        }
        return res;
    }
};