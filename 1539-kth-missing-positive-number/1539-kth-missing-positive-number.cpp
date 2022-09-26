class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int m=*max_element(arr.begin(),arr.end());
        int n=*min_element(arr.begin(),arr.end());
        int x=m+k;
        vector<int>v(x,0);
        for(int i=0;i<arr.size();i++){
            v[arr[i]]++;
        }
        int c=k;
        for(int i=1;i<m+k;i++){
            if(v[i]==0){
                  --c;
                if(c==0){
                    return i;
                }
            }
        }
        return arr.size()+k; 
    }
};