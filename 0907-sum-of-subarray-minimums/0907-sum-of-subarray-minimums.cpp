class Solution {
public:
    // jan 27, 2024 // 01:11am
    int sumSubarrayMins(vector<int>& arr) {
        long long mod = 1e9 + 7;
        long long ans = 0;
        int left[arr.size()]; // stores index of 1st smallest elemet towards left
        int right[arr.size()]; // stores index od 1st smallest element towards rights
        stack<int> rst;
        stack<int> lst;

        for(int i=0; i<arr.size(); i++){
            // for next smallest element
            while(!rst.empty() && arr[rst.top()]>=arr[i]){
                // equality to account for repeititioons 
                // only one equality only on right to avoid repeititions of subarrays containing both elements 
                // stack is non empty
                right[rst.top()]=i-1;
                rst.pop();
            }
            rst.push(i);

            // for previous smallest element
            // inverse traversal // arr.size()-i-1
            while(!lst.empty() &&arr[lst.top()]>arr[arr.size()-i-1]){
                // stack is non empty
                left[lst.top()]=arr.size()-i-1+1;
                lst.pop();
            }
            lst.push(arr.size()-i-1);
        }

        // for elements having no smaller value on right
        // their range is upto end
        while(!rst.empty()){
            right[rst.top()]=arr.size()-1;
            rst.pop();
        }

        // for elements having no smaller value on left
        // their range is upto start
        while(!lst.empty()){
            left[lst.top()]=0;
            lst.pop();
        }
        
        // calculating ans
        for(int i=0; i<arr.size();i++ ){
            // number of subsets containing i as minimum -> (i-left+1)*(right-i+1)
            ans += ((((i-left[i]+1)%mod)*((right[i]-i+1)%mod))*arr[i])%mod;
        }
        return ans%mod;
    }
};