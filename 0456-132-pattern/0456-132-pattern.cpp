class Solution {
private:
    bool sub(vector<int>&nums,int index,int res,int num){
        if(res==2)return 1;
        if(index==nums.size())return 0;
        bool notpick = sub(nums,index+1,res,num);
        bool pick = 0;
        for(int i=index;i<nums.size();i++){
        if(res==-1){
            pick = max(pick,sub(nums,i+1,0,nums[i]));
        }
        else if(res==0&&num<nums[index]){
             pick = max(pick,sub(nums,i+1,1,nums[i]));
        }
        else if(res==1&&((num>0&&nums[index]>0&&num>nums[index])||(num<0&&nums[index]<0&&num>nums[index]))){
           // cout<<num<<" "<<nums[i]<<endl;
            pick = max(pick,sub(nums,i+1,2,nums[i]));
        }
        }
        return max(pick,notpick);
    }
public:
    bool find132pattern(vector<int>& nums) {
       // return sub(nums,0,-1,1);
        int n = nums.size();
        int mine = nums[0];
        stack<pair<int,int>>s;
        for(int i=0;i<n;i++){
            if(s.empty()||i<=1){
                s.push({nums[i],mine});
            }else{
              while(!s.empty()&&nums[i]>s.top().first){
                 s.pop();
              }
              if(!s.empty()){
                  if(s.top().first>nums[i]&&nums[i]>s.top().second)return 1;
              }
                  
            }
            s.push({nums[i],mine});
             mine=min(nums[i],mine);
        }
        return 0;
    }
};