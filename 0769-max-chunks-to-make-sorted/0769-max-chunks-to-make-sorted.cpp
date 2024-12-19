// class Solution {
// private:
//     int sub(vector<int>&arr , int index){
//         if(index == arr.size()){
//            if(is_sorted(arr.begin() , arr.end()))return 0;
//            else return -1e9;
//         }
//         int ans = 0;
//         for(int i = index; i < arr.size(); i++){
//             vector<int>temp(arr);
//             sort(temp.begin() + index , temp.begin() + (i+1));
//            //  for(int j = index; j <= i; j++)cout<<temp[j]<<" ";
//            // cout<<endl;
//             ans = max(ans , 1 + sub(temp , i+1));
//         }
//         return ans;
//     }
// public:
//     int maxChunksToSorted(vector<int>& arr) {
//         return sub(arr , 0);
//     }
// };
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int chunks = 0, prefixSum = 0, sortedPrefixSum = 0;

        // Iterate over the array
        for (int i = 0; i < n; i++) {
            // Update prefix sum of `arr`
            prefixSum += arr[i];
            // Update prefix sum of the sorted array
            sortedPrefixSum += i;

            // If the two sums are equal, the two prefixes contain the same
            // elements; a chunk can be formed
            if (prefixSum == sortedPrefixSum) {
                chunks++;
            }
        }
        return chunks;
    }
};