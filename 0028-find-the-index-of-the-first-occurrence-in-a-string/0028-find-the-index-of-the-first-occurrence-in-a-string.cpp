class Solution {
private:
    bool check(int index,string x,string s){
        int m=x.size();
        string p;
        for(int i=index;i<index+m;i++){
            p.push_back(s[i]);
        }
      //  cout<<p<<endl;
        return p==x;
    }
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        if(haystack==needle)return 0;
        for(int i=0;i<n;i++){
            if(m==1&&(haystack[i]==needle[0]))return i;
            if((haystack[i]==needle[0])&&((i+m-1)<n)&&check(i,needle,haystack)){
                return i;
            }
        }
        return -1;
    }
};