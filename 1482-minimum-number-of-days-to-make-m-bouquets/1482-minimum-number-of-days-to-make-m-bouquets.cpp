class Solution {
private:
    int seq(vector<int>&nums,int k,int mid){
        int n = nums.size();
        vector<int>res(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]<=mid){
                res[i]=1;
            }
        }
        //for(auto&it:res)cout<<it<<" ";
       // cout<<endl;
        int cnt = 0;
        int curr=k;
        for(int i=0;i<n;i++){
            if(res[i]==1){
                --curr;
            }else{
                curr=k;
            }
            if(curr==0){
                ++cnt;
                curr=k;
            }
        }
        return cnt;
    }
public:
    int minDays(vector<int>&nums, int m, int k) {
        int s=1;
        int e=*max_element(nums.begin(),nums.end())+10;
        int x = INT_MAX;
        while(s<e){
          //  cout<<s<<" "<<e<<endl;
            int mid = (s+e)/2;
            int cnt = seq(nums,k,mid);
           // cout<<cnt<<endl;
            if(cnt<m){
                s=mid+1;
            }else{
                x=min(x,mid);
                e=mid;
            }
        }
        return x==INT_MAX?-1:x;
    }
};