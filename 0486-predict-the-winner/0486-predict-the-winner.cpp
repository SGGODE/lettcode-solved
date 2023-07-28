class Solution {
private:
    bool win(vector<int>&nums,int start,int end,int sanket,int abhas,bool turn){
        if(start>end){
            //if(turn)sanket+=nums[start];
            //else abhas+=nums[end];
             cout<<sanket<<" "<<abhas<<endl;
            if(sanket>=abhas)return 1;
            return 0;
        }
        bool ans=0;
        if(turn){
            if(win(nums,start+1,end,sanket+nums[start],abhas,0)||win(nums,start,end-1,sanket+nums[end],abhas,0)){
                ans=1;
            }
        }else{
            if(win(nums,start+1,end,sanket,abhas+nums[start],1)&&win(nums,start,end-1,sanket,abhas+nums[end],1)){
                ans=1;
            }
        }
        return ans;
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        return win(nums,0,n-1,0,0,1);
    }
};