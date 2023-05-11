class Solution {
public:
    int numOfSubarrays(vector<int>&arr, int k, int threshold) {
       // map<int,int>mp;
        int sum=0;
        int cnt=0;
        int n=arr.size();
        int i=0;
        for(i=0;i<n;i++){
            sum+=arr[i];
            if(i>=k){
                sum-=arr[i-k];
            }
            if(i>=k-1&&(sum/k)>=threshold)++cnt;
        }
        // if(i>=k&&(sum/k)>=threshold)++cnt;
        return cnt;
    }
};