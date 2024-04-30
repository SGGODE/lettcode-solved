class Solution {
public:
     typedef long long ll;
    long long wonderfulSubstrings(string word) {
         unordered_map<ll,ll> mp; // Using unordered_map to store cumulative XOR frequencies

        mp[0] = 1; // Initialize XOR frequency of 0 to 1 (empty substring)
        int cum_xor = 0; // Initialize cumulative XOR value
        ll result = 0; // Initialize result to store count of wonderful substrings

        // Loop through each character in the string
        for(char &ch : word){
            int shift = ch - 'a'; // Calculate the shift value for the current character
            cum_xor ^= (1 << shift); // Update cumulative XOR value

            result += mp[cum_xor]; // Increment result by frequency of current cumulative XOR value

            // Loop through each character from 'a' to 'j'
            for(char ch1 = 'a'; ch1 <= 'j'; ch1++){
                shift = ch1 - 'a'; // Calculate the shift value for the current character
                ll check_xor = (cum_xor ^ (1 << shift)); // Calculate XOR value after flipping the bit for the current character
                result += mp[check_xor]; // Increment result by frequency of the calculated XOR value
            }
            mp[cum_xor]++; // Increment the frequency of the current cumulative XOR value
        }
        return result; // Return the total count of wonderful substrings
    }
};