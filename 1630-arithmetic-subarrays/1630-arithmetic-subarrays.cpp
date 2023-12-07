class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = l.size();
        vector<bool>res;
        for(int i=0;i<n;i++){
            vector<int>temp;
            for(int j=l[i];j<=r[i];j++){
                temp.push_back(nums[j]);
            }
            sort(temp.begin(),temp.end());
            int dist = abs(temp[0]-temp[1]);
            bool flag = 0;
            for(int i=1;i<temp.size();i++){
                if(abs(temp[i]-temp[i-1])!=dist){
                    flag=1;break;
                }
            }
            res.push_back(!flag);
        }
        return res;
    }
};