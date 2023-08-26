class Solution {
public:
    double trimMean(vector<int>& arr) {
        double n = arr.size();
        double miss =0.05*n;
        double sum=0;
        sort(arr.begin(),arr.end());
        for(int i = miss;i<n-miss;i++){
            sum+=arr[i];
        }
        double div = n-(2*miss);
        return sum/div;
    }
};