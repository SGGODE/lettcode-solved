class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size() , j = 0;
        long long result = 0;
        unordered_map<int,int>mp;
        set<int>st;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
            st.insert(nums[i]);
            long long int d = *(st.rbegin()) - *(st.begin());
            if(d > 2){
                // long long int subSize = (long long)((i - j)*(long long)((i - j) + 1))/2;
                // if(i != n-1)result += (subSize - 1);
                // else result += subSize;
                while(j < i && d > 2){
                    --mp[nums[j]];
                    if(mp[nums[j]] == 0){
                        mp.erase(nums[j]);
                        st.erase(nums[j]);
                    }
                    d = *(st.rbegin()) - *(st.begin());
                    ++j;
                }
            }
            result += (i-j)+1;
            //cout<<i<<" "<<j<<endl;
        }
        //long long int subSize = (long long)((n - j)*(long long)((n - j) + 1))/2;
       // result += subSize;
        return result;
    }
};