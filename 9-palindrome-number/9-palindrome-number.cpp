class Solution {
private:
   bool check(string v,int s,int e){
      if(v[s]!=v[e]&&s<e){
            return 0;
        }
        return check(v,s+1,e-1);
    }
public:
    bool isPalindrome(int x) {
        string s=to_string(x);
        int n=s.length()-1;
        int v=0;
        int e=n;
        while(v<e){
            if(s[v]!=s[e])
                return 0;
            v++;
            e--;
        }
        return 1;
    }
};