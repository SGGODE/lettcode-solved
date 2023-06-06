class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int diff=abs(arr[0]-arr[1]);
        int n=arr.size();
        for(int i=2;i<n;i++){
            if(abs(arr[i]-arr[i-1])==diff)continue;
            else return false;
        }
        return true;
    }
};