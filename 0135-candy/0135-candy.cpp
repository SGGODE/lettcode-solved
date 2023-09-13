class Solution {
private:
    int sub(vector<int>&nums,int index,int prev){
        if(index==nums.size())return 0;
        int ans = 1e9;
     //   for(int i=index;i<nums.size();i++){
            if(index>=1&&index<nums.size()){
                if(nums[index-1]<=nums[index])ans = min(ans,(prev+1)+sub(nums,index+1,prev+1));
                else ans = min(ans, 1+sub(nums,index+1,1));
            }else{
                if(index>=1){
                    if(nums[index]>nums[index-1])ans=min(ans,(prev+1)+sub(nums,index+1,prev+1));
                    else ans = min(ans, 1+sub(nums,index+1,1));
                }else{
                    if(nums[index]>nums[index+1])ans=min(ans,(prev+1)+sub(nums,index+1,prev+1));
                    else ans = min(ans, 1+sub(nums,index+1,1));
                }
            }
       // }
        return ans;
    }
public:
    int candy(vector<int>& ratings) {
       // return sub(ratings,0,1);
        int n =ratings.size();
        vector<int>prefix,sufix;
        int cnt=1;
        prefix.push_back(1);
        sufix.push_back(1);
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                prefix.push_back(cnt+1);
                ++cnt;
            }else{
                cnt=1;
                prefix.push_back(cnt);
            }
        }
        cnt=1;
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                sufix.push_back(cnt+1);
                ++cnt;
            }else{
                cnt=1;
                sufix.push_back(cnt);
            }
        }
        reverse(sufix.begin(),sufix.end());
        // for(auto&it:prefix)cout<<it<<" ";
        // cout<<endl;
        // for(auto&it:sufix)cout<<it<<" ";
        // cout<<endl;
        // return 0;
        int sum =0;
        for(int i=0;i<n;i++){
            if(i==0){
                if(i+1<n&&ratings[i+1]<ratings[i])sum+=(sufix[i+1]+1);
                else sum+=1;
            }
            else if(i==n-1){
                if(i-1>=0&&ratings[i-1]<ratings[i])sum+=(prefix[i-1]+1);
                else sum+=1;
            }else{
                if(ratings[i-1]<ratings[i]&&ratings[i+1]<ratings[i]){
                    int ans = max(prefix[i-1],sufix[i+1]);
                    sum+=(ans+1);
                }else if(ratings[i-1]<ratings[i]){
                    sum+=(prefix[i-1]+1);
                }else if(ratings[i+1]<ratings[i]){
                    sum+=(sufix[i+1]+1);
                }else{
                    sum+=1;
                }
            }
        }
        return sum;
    }
};