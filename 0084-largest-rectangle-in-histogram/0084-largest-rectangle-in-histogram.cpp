class Solution {
public:
    int largestRectangleArea(vector<int>&nums) {
        int sum=0;
        // for(int i=0;i<nums.size();i++){
        //     int m=INT_MAX;
        //     for(int j=i;j<nums.size();j++){
        //         m=min(m,nums[j]);
        //         sum=max(sum,m*((j-i)+1));
        //     }
        // }
        // return sum;
        int n = nums.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        stack<pair<int,int>>s1,s2;
        for(int i=n-1;i>=0;i--){
            if(s1.empty()){
                s1.push({nums[i],i});
                left[i]=i;
            }else{
                //stack<pair<int,int>>s3(s1);
                while(!s1.empty()&&s1.top().first>=nums[i]){
                    s1.pop();
                }
                if(s1.empty()){
                    left[i]=n-1;
                   // s1=s3;
                    s1.push({nums[i],i});
                }else{
                    left[i]=s1.top().second-1;
                    s1.push({nums[i],i});
                }
            }
        }
        for(int i=0;i<n;i++){
            if(s2.empty()){
                s2.push({nums[i],i});
                right[i]=i;
            }else{
                //stack<pair<int,int>>s3(s1);
                while(!s2.empty()&&s2.top().first>=nums[i]){
                    s2.pop();
                }
                if(s2.empty()){
                    right[i]=0;
                   // s1=s3;
                    s2.push({nums[i],i});
                }else{
                    right[i]=s2.top().second+1;
                    s2.push({nums[i],i});
                }
            }
        }
        for(int i=0;i<n;i++){
            int curr = (left[i]-right[i])+1;
            sum=max(sum,curr*nums[i]);
        }
        // for(auto&it:left)cout<<it<<" ";
        // cout<<endl;
        // for(auto&it:right)cout<<it<<" ";
        // cout<<endl;
        return sum;
    }
};