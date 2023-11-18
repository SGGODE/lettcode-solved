class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // sort(nums.begin(),nums.end());
        // int len = 0;
        // for(int i=0;i<nums.size();i++){
        //     int fcnt = 0, fk = k;
        //     int j = i;
        //     for(;j>=0&&fk>=0;j--){
        //         if(abs(nums[i]-nums[j])<=fk)fk-=abs(nums[i]-nums[j]);
        //         else{++j;break;}
        //     }
        //     if(j==-1)len = max(len,i+1);
        //     else len=max(len,(i-j));
        // }
        // return len;
        sort(nums.begin(), nums.end());
        long int i = 0, j = 0, sum = 0, l = 0, tsum = 0;
        for (i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while ((i - j + 1) * nums[i] - sum > k) {
                sum -= nums[j];
                j++;
            }
            l = max(l, i - j + 1);
        }
        return l;
    }
};