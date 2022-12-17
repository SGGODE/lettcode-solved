class Solution {
#define ll long long 
private:
    bool check(string ch){
        if(ch=="+"||ch=="-"||ch=="/"||ch=="*")return 1;
        return 0;
    }
public:
    int evalRPN(vector<string>& tok) {
        stack<string>s;
        for(int i=0;i<tok.size();i++){
            if(check(tok[i])){
                ll x=0;
                x=stoll(s.top());
                s.pop();
                ll y=0;y=stoll(s.top());
                s.pop();
                if(tok[i]=="+"){
                 ll z=x+y;
                  s.push(to_string(z));
                }
                if(tok[i]=="-"){
                 ll z=y-x;
                  s.push(to_string(z));
                }
                if(tok[i]=="/"){
                 ll z=y/x;
                  s.push(to_string(z));
                }
                if(tok[i]=="*"){
                 ll z=x*y;
                  s.push(to_string(z));
                }
            }else s.push(tok[i]);
        }
        return stoll(s.top());
    }
};