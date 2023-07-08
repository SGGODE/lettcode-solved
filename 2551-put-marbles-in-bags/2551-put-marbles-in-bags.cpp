class Solution {
private:
    // int maxi=0,mini=INT_MAX;
    // void sub(vector<int>&nums,vector<int>res[],int index){
    //     if(index==nums.size()){
    //         int start=0,end=0;
    //         for(int i=0;i<res.size();i++){
    //             if(res[i].empty())return;
    //             else{
    //                 sort(res[i],begin(),res[i].end());
    //                 start=res[i][0];end=res[i][0];bool flag=1;
    //                 int tempstart=start,tempend=end;
    //                 for(auto&it:res[i]){
    //                     if(flag){
    //                         flag=0;
    //                     }else{
    //                         if()
    //                     }
    //                 }
    //             }
    //         }
    //         return;
    //     }
    //     for(int i=0;i<res.size();i++){
    //         res[i].push_back(index);
    //         sub(nums,res,index+1);
    //         res[i].pop_back();
    //         sub(nums,res,index+1);
    //     }
    // }
public:
    long long putMarbles(vector<int>&nums, int k) {
       vector<long long>res;
        for(int i=0;i<nums.size()-1;i++){
            res.push_back(nums[i]+nums[i+1]);
        }
        sort(res.begin(),res.end());
        long long int minsum=0,maxisum=0;
        long long int n=nums.size();
        for(int i=0;i<k-1;i++){
            minsum+=res[i];
            maxisum+=res[n-2-i];
        }
        return maxisum-minsum;
    }
};