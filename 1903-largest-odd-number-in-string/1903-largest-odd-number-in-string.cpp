class Solution {
public:
    string largestOddNumber(string num) {
       /* int last=0;
        int large=-1;
        for(int i=0;i<num.size();i++){
            last=last*10+num[i]-'0';
            if((num[i]-'0')%2!=0){
                large=max(large,num[i]-'0');
            }
        }
        if(large==-1){
            return "";
        }
        if(last%2!=0){
            return to_string(last);
        }
        return to_string(large)
        string s;
       long long int large=-1;
        for(int i=0;i<num.size();i++){
            s.push_back(num[i]);
            if(stoll(s)%2!=0){
                long long int m=stoll(s);
                large=max(large,m);
            }
        }
        if(large==-1){
            return "";
        }
        return to_string(large);;*/
        for(int i=num.size()-1;i>=0;i--){
            if((num[i]-'0')%2!=0){
                return num.substr(0,i+1);
            }
        }
        return "";
    }
};