class Solution {
public:
    vector<int> asteroidCollision(vector<int>&nums) {
        stack<int>s;
        for(int i=0;i<nums.size();i++){
            if(s.empty()){
                s.push(nums[i]);
            }else{
                if(s.top()>0&&nums[i]<0&&abs(nums[i])==s.top()){
                    s.pop();
                    continue;
                }
                if((s.top()>0&&nums[i]<0)){
                    bool flag=0;
                    while(!s.empty()&&s.top()<=abs(nums[i])&&s.top()>0&&!flag){
                        if(s.top()>=abs(nums[i]))flag=1;
                        s.pop();
                    }
                    if(!s.empty()&&s.top()>=abs(nums[i]))flag=1;
                    if(!flag)s.push(nums[i]);
                }else{
                    s.push(nums[i]);
                }
            }
        }
        vector<int>res;
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};