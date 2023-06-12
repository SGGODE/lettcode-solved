class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.empty())return {};
        vector<string>res;
       long long int start=nums[0];
       long long int end=-1;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]-1==nums[i-1]){
                continue;
            }else{
                end=nums[i-1];
                if(start==end){
                    res.push_back(to_string(start));
                }
                else{
                string x=to_string(end);
                string s=to_string(start);
                s.push_back('-');s.push_back('>');
                s.append(x);
                    res.push_back(s);
                }
                start=nums[i];
                end=-1;
            }
        }
        if(start==nums[n-1])res.push_back(to_string(start));
        else{
            string x=to_string(nums[n-1]);
                string s=to_string(start);
                s.push_back('-');s.push_back('>');
                s.append(x);
                    res.push_back(s);
        }
        return res;
    }
};