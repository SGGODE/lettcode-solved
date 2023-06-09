class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int maxlen=INT_MIN;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int k,j;
            for(j=i-1;j>=0;j--){
                if(arr[j]<arr[j+1])continue;
                else break;
            }
            for(k=i+1;k<n;k++){
                if(arr[k]<arr[k-1])continue;
                else break;
            }
           if(j!=i-1&&k!=i+1)maxlen=max(maxlen,(k-j-1));
        }
        return maxlen>=3?maxlen:0;
    }
};