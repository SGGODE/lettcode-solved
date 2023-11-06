class Solution {
public:
    int kthGrammar(int n, int k) {
        // string s;s.push_back('0');
        // for(int i=2;i<=n;i++){
        //     string temp;
        //     for(auto&it:s){
        //         if(it=='0')temp.append("01");
        //         else temp.append("10");
        //     }
        //     s=temp;
        // }
        // //cout<<s<<endl;
        // return s[k-1]-'0';
        if (n == 1) return 0;
        int length = 1 << (n - 2);
        if (k <= length) return kthGrammar(n - 1, k);
        else return 1 - kthGrammar(n - 1, k - length);
    }
};