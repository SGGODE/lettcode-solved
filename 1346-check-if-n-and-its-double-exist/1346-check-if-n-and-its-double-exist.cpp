class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
         sort(arr.begin(),arr.end());
         for(int i = 0; i < arr.size(); i++){
             for(int j = 0; j < arr.size(); j++){
                 if((2 * arr[i]) == arr[j] && i != j)return 1;
                 //cout<<(2*arr[i])<<" "<<arr[j]<<endl;
             }
         }
        return 0;
    }
};