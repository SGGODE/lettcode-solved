class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if(hour<(n-1))return -1;
        double cnt=1;
        int s=1;
        int e=1000000000;
        while(s<e){
            double time=0;
            double mid=s+(e-s)/2;
            for(int i=0;i<n;i++){
                double x=dist[i];
                if(i==n-1){
                    time=time+(x/mid);
                }else{
                    time=time+ceil(x/mid);
                }
            }
            if(time<=hour){
                e=mid;
            }else{
                s=mid+1;
            }
            //++cnt;
        }
        return s==1000000000?-1:s;
    }
};