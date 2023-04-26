class Solution {
public:
    int addDigits(int num) {
        string s=to_string(num);
        while(s.size()>1){
            string x(s);
            long long int sum=0;
            for(int i=0;i<x.size();i++){
                sum+=x[i]-'0';
            }
            s.clear();
            s=to_string(sum);
        }
        return stoi(s);
    }
};