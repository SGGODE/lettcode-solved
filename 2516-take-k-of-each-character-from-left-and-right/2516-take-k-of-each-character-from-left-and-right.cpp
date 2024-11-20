class Solution {
public:
    int takeCharacters(string s, int k) {
        // //size.
        // int n = s.size();
        // //bae case 1.
        // if(k == 0)return 0;
        // //base case 2.
        // if((3 * k) > n)return -1;
        // //base case 3.
        // unordered_map<char,int>freq , freqB , freqC , freqA;
        // for(auto&it : s)freq[it]++;
        // if(freq['a'] < k || freq['b'] < k || freq['c'] < k)return -1;
        // int mlen = 1e9 , i = 0 , j = 0;
        // //find minimum required from mix left and right.
        // while(i < n){
        //     freqA[s[i]]++;
        //     bool flag = 0;
        //     while(j <= i && freqA['a'] >= k && 
        //        freqA['b'] >= k && 
        //        freqA['c'] >= k){
        //         --freqA[s[j]];
        //         flag = 1;
        //         if(freqA[s[j]] == 0){freqA.erase(s[j]);break;}
        //         j++;
        //  }
        //   if(flag)mlen = min(mlen , (i-j)+1);
        //     //else mlen = min(mlen , (i + (n - j - 1)));
        //     cout<<mlen<<" "<<i<<" "<<j<<endl;
        //     i++;
        //     //j = n - 1;
        // }
        // return mlen;
        if(k == 0) return 0;
        int n = s.size();
        vector<int> v(3, 0);
        for(int i = 0; i < n; i++) v[s[i]-'a'] += 1;

        if(v[0] < k || v[1] < k || v[2] < k) return -1;

        int reg = 0, j = 0;
        vector<int> count(3, 0);

        for (int i = 0; i < n; i++) {
            count[s[i] - 'a']++;
            
            while(count[0] > v[0] - k || count[1] > v[1] - k || count[2] > v[2] - k) {
                count[s[j] - 'a']--;
                j++;
            }

            reg = max(reg, i - j + 1);
        }

        return n - reg;
    }
};