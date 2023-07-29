class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long int s = 0;
        long long int e = 1e14;
        long long time = INT_MAX;
       // sort(ranks.begin(),ranks.end());
        while(s<e){
            long long int mid = (s+e)/2;
            long long int cnt=0;
            for(int i=0;i<ranks.size();i++){
               cnt+=sqrt(mid/ranks[i]);
            }
            if(cnt>=cars){
                time=min(time,mid);
                e=mid;
            }else{
                s=mid+1;
            }
        }
        return s;
    }
};