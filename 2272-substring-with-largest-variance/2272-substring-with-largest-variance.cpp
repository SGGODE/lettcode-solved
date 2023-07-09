class Solution {
public:
    int largestVariance(string s) {
        vector<int> arr(26); // Array to store the frequency of each letter (a-z)
        for(auto x : s) {
            arr[x - 'a']++; // Increment the count for the corresponding letter
        }
        int ans = 0; // Variable to store the maximum variance found
        for(char i = 'a'; i <= 'z'; i++) { // Iterate through each letter i
            for(char j = 'a'; j <= 'z'; j++) { // Iterate through each letter j
                // Skip if j is the same as i or either i or j has a frequency of 0
                if(j == i || arr[i - 'a'] == 0 || arr[j - 'a'] == 0)
                    continue;
                for(int k = 1; k <= 2; k++) { // Perform the calculation twice (forward and backward)
                    int A1 = 0; // Counter for letter i
                    int A2 = 0; // Counter for letter j
                    for(auto x : s) {
                        if(x == i)
                            A1++; // Increment A1 if the current letter is i
                        if(x == j)
                            A2++; // Increment A2 if the current letter is j
                        if(A2 > A1) {
                            A1 = 0;
                            A2 = 0; // Reset A1 and A2 if A2 becomes greater than A1
                        }
                        if(A1 > 0 && A2 > 0)
                            ans = max(ans, A1 - A2); // Update the maximum variance if A1 - A2 is greater
                    }
                    reverse(s.begin(), s.end()); // Reverse the string for the next iteration
                }
            }
        }
        return ans; // Return the maximum variance found
    }
    // int largestVariance(string s) {
    //     int n=s.size();
    //     int len=0;
    //     // for(int i=0;i<n;i++){
    //     //     if(len>=(n-i))break;
    //     //     map<char,int>mp;
    //     //     for(int j=i;j<n;j++){
    //     //        mp[s[j]]++;
    //     //        if(mp.size()>=2){
    //     //            priority_queue<int>pq; priority_queue<int,vector<int>,greater<int>>px;
    //     //            for(auto&it:mp){
    //     //                pq.push(it.second);px.push(it.second);
    //     //            }
    //     //            int x=pq.top()-px.top();
    //     //            len=max(len,x);
    //     //        }
    //     //     }
    //     // }
    //     map<char,int>mp;
    //     for(auto&it:s)mp[it]++;
    //     for(int i=0;i<26;i++){
    //         for(int j=0;j<26;j++){
    //             char ch1='a',ch2='a';
    //             ch1=ch1+i;
    //             ch2=ch2+j;
    //             if(mp[ch1]>0&&mp[ch2]>0){
    //                for(int h=0;h<=1;h++){
    //                 int cnt1=0;int cnt2=0;
    //                 for(int k=0;k<n;k++){
    //                     if(ch1==s[k]){
    //                         ++cnt1;
    //                     }
    //                     if(ch2==s[k]){
    //                         ++cnt2;
    //                     }
    //                     if(cnt1<cnt2)cnt1=cnt2=0;
    //                     if(cnt1>0&&cnt2>0){
    //                         len=max(len,cnt1-cnt2);
    //                     }
    //                 }
    //             }
    //                  reverse(s.begin(), s.end());
    //             }
    //         }
    //     }
    //     return len;
    // }
};