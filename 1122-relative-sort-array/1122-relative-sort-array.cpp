class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>freq,freq2;
        for(auto&it:arr1)freq[it]++;
        for(auto&it:arr2)freq2[it]++;
        vector<int>result;
        for(int i=0;i<arr2.size();i++){
            for(int j=0;j<freq[arr2[i]];j++){
                result.push_back(arr2[i]);
            }
        }
       // vector<int>remain;
        for(auto&it:freq){
           if(!freq2.count(it.first)){
               for(int i=0;i<it.second;i++){
                   result.push_back(it.first);
               }
           }
        }
    
        return result;
    }
};