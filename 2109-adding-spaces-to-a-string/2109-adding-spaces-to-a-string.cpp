class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.size();
        int j = 0;
        string result;
        for(int i = 0; i <= n; i++){
            if(j < spaces.size() && i == spaces[j]){
                result.push_back(' ');
                //cout<<i<<endl;
                result.push_back(s[i]);
                j++;
            }else{
                if(i!=n)result.push_back(s[i]);
            }
        }
        return result;
    }
};