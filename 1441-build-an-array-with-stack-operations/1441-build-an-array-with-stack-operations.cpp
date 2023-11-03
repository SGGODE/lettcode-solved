class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>res;
        set<int>s(target.begin(),target.end());
        for(int i=1;i<=n;i++){
            if(s.count(i)){
                res.push_back("Push");
                s.erase(i);
                if(s.empty())break;
            }else{
                res.push_back("Push");
                res.push_back("Pop");
            }
        }
        return res;
    }
};