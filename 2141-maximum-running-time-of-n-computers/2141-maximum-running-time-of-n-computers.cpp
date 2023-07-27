class Solution {
public:
    long long maxRunTime(int n, vector<int>&nums) {
        long long int sum=0;
        for(auto&it:nums)sum+=it;
        if(n==1)return sum;
        int m=nums.size();
        long long int s=1;
        long long int e=(sum+10/m);
        long long int res=0;
        sort(nums.begin(),nums.end());
        while(s<e){
            long long int mid = (s+e)/2;
            long long int sum1=0;
            long long int xnt=0;
            int k=m-1;
            while(k>=0&&nums[k]>=mid){
                k--;
                ++xnt;
            }
            int rem=0;
            if(xnt<=n)rem=n-xnt;
           // cout<<k<<endl;
            while(k>=0){
                sum1+=nums[k];
                k--;
            }
            //cout<<rem<<" "<<mid<<" "<<sum1<<endl;
            if((rem*mid)<=sum1){
                res=max(res,mid);
                s = mid+1;
            }else{
                e = mid;
            }
        }
        return res;
    }
};