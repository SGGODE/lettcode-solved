class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
       // priority_queue<int>pq;
       // int m=INT_MAX;
       // for(int i=0;i<nums.size();i++){
       //     if(nums[i]%2){
       //         nums[i]=2*nums[i];
       //     }
       //     pq.push(nums[i]);
       //     m=min(m,nums[i]);
       // }
       //  int min_diff=INT_MAX;
       //  while(1){
       //      int x=pq.top(); pq.pop();
       //      int mi=x-m;
       //      min_diff=min(min_diff,mi);
       //      if(x%2)break;
       //          pq.push(x/2); 
       //         x=x/2;
       //          min_diff=min(min_diff,x);
       //  }
       //  return min_diff;
          priority_queue<int> pq;
        int minVal = INT_MAX;
        for (int num : nums) {
            if (num % 2 == 1)
                num = num * 2;
            pq.push(num);
            minVal = min(minVal, num);
        }
        int minDeviation = INT_MAX;
        while (true) {
            int maxVal = pq.top();
            pq.pop();
            minDeviation = min(minDeviation, maxVal - minVal);
            if (maxVal % 2 == 1)
                break;
            maxVal = maxVal / 2;
            minVal = min(minVal, maxVal);
            pq.push(maxVal);
        }
        return minDeviation;
    }
};