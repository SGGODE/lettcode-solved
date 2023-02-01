class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<pair<int,int>>v; vector<string>result;
        if(nums.size()==0)return result;
        int prev=nums[0];
        int curr=nums[0];
        if(nums.size()==1){
            result.push_back(to_string(nums[0]));
            return result;
        }
         if(nums.size()==2){
            if(nums[0]+1!=nums[1]){
                result.push_back(to_string(nums[0]));
                result.push_back(to_string(nums[1]));
            }else{
             string s=to_string(nums[0]);
                s.append("->");
                s.append(to_string(nums[1]));
                result.push_back(s);
            }
            return result;
        }
        int n=nums.size();
        for(int i=1;i<n;i++){
           if(nums[i-1]+1!=nums[i]){
               v.push_back({prev,nums[i-1]});
               prev=nums[i];
           }
        }
        v.push_back({prev,nums.back()});
        for(auto it:v){
          //  cout<<it.first<<""<<it.second<<" ";
            if(it.first==it.second){
                result.push_back(to_string(it.first));
            }else{
                string s=to_string(it.first);
                s.append("->");
                s.append(to_string(it.second));
                result.push_back(s);
            }
        }//cout<<endl;
        return result;;
    }
};