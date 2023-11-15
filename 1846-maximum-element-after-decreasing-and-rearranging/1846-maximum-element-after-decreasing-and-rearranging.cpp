class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        if(arr.size()==1)return 1;
        int m =*max_element(arr.begin(),arr.end());
        int low = *min_element(arr.begin(),arr.end());
        sort(arr.begin(),arr.end());
        if(low>1)arr[0]=1;
        int result = 0;
        for(int i=1;i<arr.size();i++){
            if(abs(arr[i-1]-arr[i])>1){
                result = max(result,arr[i-1]+1);
                arr[i]=arr[i-1]+1;
            }
        }
        return result==0?m:result;
    }
};