class Solution {
private:
    bool check(string s){
        bool flag=1;
       for(int i=0;i<s.size();i++){
           if(isupper(s[i]))continue;
            else flag=0;
       } 
       if(flag)return 1;
        else{
          //  cout<<1<<s<<endl;
           for(int i=1;i<s.size();i++){
                if(islower(s[i]))continue;
                else{
                    //cout<<s[i];
                    return 0;
                }
            } 
        }
        return 1;
    }
public:
    bool detectCapitalUse(string word) {
        if(isupper(word[0])){
            if(check(word))return 1;
            else return 0;
        }else{
            for(int i=0;i<word.size();i++){
                if(isupper(word[i]))return 0;
            }
            //return 1;
        }
        return 1;
    }
};