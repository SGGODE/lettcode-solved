class Solution {
private:
    // int sub(vector<double>& nums,int index,double target){
    //     if(index==nums.size())return target==0?0:1e9;
    //     if(target<=0)return 1e9;
    //     int dpick = sub(nums,index+1,target-nums[index]);
    //     int rpick = 0;
    //    // cout<<nums[index]<<endl;
    //     nums[index] = nums[index]/2.0;
    //     //cout<<nums[index]<<endl;
    //     rpick = min(1+sub(nums,index+1,target-nums[index]),1+sub(nums,index,target));
    //     //nums[index]=2*nums[index];
    //     return min(dpick,rpick);
    // }
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double>pq;
        double sum = 0;
        for(auto&it:nums){
            pq.push((double)it);
            sum += (double)it;
        }
        double target = sum/2;
        int cnt = 0;
        while(!pq.empty()&&target>0){
            double node = pq.top();
            target-=(node/2);
            pq.pop();
            pq.push(node/2);
            ++cnt;
        }
        return cnt;
    }
};