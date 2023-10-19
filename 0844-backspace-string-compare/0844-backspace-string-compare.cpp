class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a;
        for(auto&it:s){
            if(it=='#'&&!a.empty())a.pop_back();
            else if(it!='#')a.push_back(it);
        }
        string b;
        for(auto&it:t){
            if(it=='#'&&!b.empty())b.pop_back();
            else if(it!='#')b.push_back(it);
        }
       // cout<<a<<" "<<b<<endl;
        return a==b;
    }
};