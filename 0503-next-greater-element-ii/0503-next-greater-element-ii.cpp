class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n,-1);
        // for(int i=0;i<n;i++){
        //     bool flag=0;
        //     for(int j=i+1;j<n;j++){
        //         if(nums[j]>nums[i]){
        //             res[i]=nums[j];
        //             flag=1;break;
        //         }
        //     }
        //     if(!flag){
        //         for(int j=0;j<i;j++){
        //         if(nums[j]>nums[i]){
        //             res[i]=nums[j];
        //             flag=1;break;
        //         }             
        //         }
        //     }
        // }
        stack<int>s;
        vector<int>next(n,-1);
        for(int i=(2*n)-1;i>=0;i--){
            if(s.empty()){
                s.push({nums[i%n]});
            }else{
                while(!s.empty()&&s.top()<=nums[i%n])s.pop();
                if(!s.empty())next[i%n]=s.top();
                s.push(nums[i%n]);
            }
        }
        for(int i=0;i<n;i++)res[i]=next[i];
        return res;
    }
};