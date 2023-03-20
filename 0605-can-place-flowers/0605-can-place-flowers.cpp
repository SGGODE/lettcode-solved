class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) {
        int x=nums.size();
        if(x==1&&n==1){
            if(nums[0]==0)return 1;
            return 0;
        }
        vector<bool>vis(x,0);int cnt=0;
        for(int i=0;i<x;i++){
            if(nums[i]==1)vis[i]=1;
        }
      //  int cnt=0;
        if(vis[0]==0&&vis[1]==0){
            ++cnt;
            vis[0]=1;
        }
        if(vis[x-1]==0&&vis[x-2]==0){
            ++cnt;
            vis[x-1]=1;
        }
        for(int i=1;i<x-1;i++){
            if(vis[i]==0&&vis[i+1]==0&&vis[i-1]==0){
                ++cnt;
                vis[i]=1;
            }
        }
        if(x>=3){
        if(vis[0]==0&&vis[1]==0&&vis[2]==1)++cnt;
        if(vis[x-1]==0&&vis[x-2]==0&&vis[x-3]==1)++cnt;
        }
        cout<<cnt<<endl;
        return cnt>=n;
    }
};