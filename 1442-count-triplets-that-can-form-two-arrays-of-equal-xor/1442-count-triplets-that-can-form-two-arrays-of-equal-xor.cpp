class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            int axor = 0;
            for(int j=i;j<n;j++){
                axor^=arr[j];
                int bxor=0;
                for(int k=j+1;k<n;k++){
                    bxor^=arr[k];
                    if(bxor==axor)++cnt;
                }
            }
        }
        return cnt;
    }
};