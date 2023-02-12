class Solution {
public:
    int maximumSwap(int num) {
       string s=to_string(num);
       long long int m=num;
        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<s.size();j++){
                string x=s;
                swap(x[i],x[j]);
                long long res=stoll(x);
                m=max(m,res);
            }
        }
        return m;
    }
};