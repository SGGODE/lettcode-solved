class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        vector<int>time(n,0);
        for(int i=0;i<n;i++){
            int x=1;
            if(dist[i]%speed[i]!=0)x=(dist[i]/speed[i])+1;
            else x=(dist[i]/speed[i]);
            if(x==0)time[i]=1;
            else time[i]=x;
        }
        sort(time.begin(),time.end());
        int dim4=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(dim4<time[i]){
                ++cnt;
                ++dim4;
            }else break;
        }
        return cnt;
    }
};