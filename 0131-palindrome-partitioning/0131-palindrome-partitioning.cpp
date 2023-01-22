class Solution {
private:
    bool check_palindrome(string s,int index,int i){
        int st=index;int e=i;
        while(st<=e){
            if(s[st++]!=s[e--])return 0;
        }
        return 1;
    }
    void the_helper(vector<vector<string>>&result,vector<string>&dump,string s,int n,int index){
        if(index==n){
            result.push_back(dump);
            return;
        }
        for(int i=index;i<n;i++){
            if(check_palindrome(s,index,i)){
                dump.push_back(s.substr(index,i-index+1));
                the_helper(result,dump,s,n,i+1);
                dump.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
      vector<vector<string>>result;
      vector<string>dump;
      int n=s.size();
      the_helper(result,dump,s,n,0);
      return result;
    }
};