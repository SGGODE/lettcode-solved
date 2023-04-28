class Solution {
private:
    // void fun(int n,int k,vector<bool>&vis,int index,int mark){
    //     if(mark==n-1)return;
    //     if(vis[index]==0){
    //         vis[index]=1;
    //         if((index+k)>n){
    //             int temp=n-index;
    //             int add=k-temp;
    //             fun(n,k,vis,add,mark+1);
    //         }
    //         else fun(n,k,vis,index+k,mark+1);
    //     }else{
    //         if((index+1)>n)fun(n,k,vis,1,mark);
    //         else fun(n,k,vis,index+1,mark);
    //     } 
    // }
    int next(int index,vector<bool>&vis){
        int n=vis.size();
        for(int i=index+1;i<n;i++){
            if(vis[i]==0)return i;
        }
        for(int i=1;i<n;i++){
            if(vis[i]==0)return i;
        }
        return -1;
    }
public:
    int findTheWinner(int n, int k) {
        if(n==1&&k==1)return 1;
        vector<bool>vis(n+1,0);
        int mark=1;
        vis[k]=1;
        int j=k+1;
        if(k==n)j=1;
        while(mark!=n-1){
            int cnt=0;
            while(cnt!=k){
             bool flag=0;
              for(int p=j;p<=n;p++){
                  if(vis[p]==0){
                      ++cnt;
                  }
                  if(cnt==k){
                      j=p;
                      flag=1;
                      break;
                  }
              }
             if(flag){
                vis[j]=1;
                ++mark;
                j=next(j,vis);
                 break;
             }else{
                 j=1;
             }
            }
        }
        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                return i;
            }
        }
        return 0;
    }
};