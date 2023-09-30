class Solution {
private:
    bool sub(vector<vector<int>>&nums,vector<int>&target,int index,int a,int b,int c){
        if(a==target[0]&&b==target[1]&&c==target[2])return 1;
        if(index==nums.size())return 0;
        bool notpick = sub(nums,target,index+1,a,b,c);
        bool pick = 0;
        if(a==-1&&nums[index][0]<=target[0]&&nums[index][1]<=target[1]&&nums[index][2]<=target[2]){
            pick = max(pick,sub(nums,target,index+1,nums[index][0],nums[index][1],nums[index][2]));
        }else{
           if(nums[index][0]<=target[0]&&nums[index][1]<=target[1]&&nums[index][2]<=target[2]){
               pick = max(pick,sub(nums,target,index+1,max(nums[index][0],a),max(nums[index][1],b),max(nums[index][2],c)));
           } 
        }
        return max(pick,notpick);
    }
public:
    bool mergeTriplets(vector<vector<int>>&nums, vector<int>& target) {
        //return sub(triplets,target,0,-1,-1,-1);
        int a=-1,b=-1,c=-1;
        for(int i=0;i<nums.size();i++){
            if(a==target[0]&&b==target[1]&&c==target[2])return 1;
            if(nums[i][0]<=target[0]&&nums[i][1]<=target[1]&&nums[i][2]<=target[2]){
                a=max(nums[i][0],a);b=max(nums[i][1],b);c=max(nums[i][2],c);
            }
        }
        if(a==target[0]&&b==target[1]&&c==target[2])return 1;
        return 0;
    }
};