// class Solution {
// public:
//     string repeatLimitedString(string s, int repeatLimit) {
//         int arr[26] = {0};
//         for(auto & it : s){
//             arr[it - 'a']++;
//         }
//         priority_queue<char>pq;
//         for(int i = 0; i < 26; i++){
//             if(arr[i] != 0)pq.push('a' + i);
//         }
// //         for(int i = 25; i >= 0; i--){
            
// //         }
//         // sort(s.begin() , s.end());
//         // reverse(s.begin() , s.end());
//         // int currChar = 1;
//         // for(int i = 1; i < s.size(); i++){
//         //     if(s[i] == s[i-1])++currChar;
//         //     else{
//         //         currChar = 1;
//         //     }
//         //     if(currChar > repeatLimit){
//         //         int j = i
//         //     }
//         // }
//         string result;
//         while(!pq.empty()){
//             char ch = pq.top();
//             pq.pop();
//             int len = arr[ch - 'a'];
//             int applyLen = min(len , repeatLimit);
//             arr[ch - 'a'] -= applyLen;
            
//             for(int i = 0; i < applyLen; i++)result.push_back(ch);
            
//             if(arr[ch - 'a'] > 0 && !pq.empty()){
//                 char second = pq.top();
//                 pq.pop();
//                 arr[second - 'a'] -= 1;
//                 result.push_back(second);
//                 if(arr[ch - 'a'] > 0)pq.push(second);
//                 pq.push(ch);
//             }
//         }
//         return result;
//     }
// };
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }

        priority_queue<char> maxHeap;
        for (auto& [ch, count] : freq) {
            maxHeap.push(ch);
        }

        string result;

        while (!maxHeap.empty()) {
            char ch = maxHeap.top();
            maxHeap.pop();
            int count = freq[ch];

            int use = min(count, repeatLimit);
            result.append(use, ch);

            freq[ch] -= use;

            if (freq[ch] > 0 && !maxHeap.empty()) {
                char nextCh = maxHeap.top();
                maxHeap.pop();

                result.push_back(nextCh);
                freq[nextCh]--;

                if (freq[nextCh] > 0) {
                    maxHeap.push(nextCh);
                }

                maxHeap.push(ch);
            }
        }

        return result;
    }
};