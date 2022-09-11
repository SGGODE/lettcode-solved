/*class Solution {
private:
    bool isValid(char ch){
        if((ch>='a'&&ch<='z')&&(ch>='A'&&ch<='Z')&&(ch>='0'&&ch<='9'))
             return 1;
       return 0;
    }
    char tolower(char ch){
        if((ch>='a'&&ch<='z')&&(ch>='0'&&ch<='9'))
            return ch;
        else{
            char temp=ch-'A'+'a';
            return temp;
        }
    }
    bool get(string v,int s,int e){
       while(s<=e){
        if(v[s]!=v[e]){
            return 0;
        }
        else{
            ++s;
            --e;
         }
       }
        return 1;
    }
       
public:
    bool isPalindrome(string s) {
        string temp="";
        for(int i=0;i<s.length();i++){
            if(isValid(s[i])){
                temp.push_back(s[i]);
            }
        }
        for(int i=0;i<temp.length();i++){
            temp[i]=tolower(temp[i]);
        }
        int n=temp.length()-1;
        return get(temp,0,n);
    }
};*/
class Solution {
private:
    bool valid(char ch) {
        if( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            return 1;
        }
        
        return 0;
    }
    
    char toLowerCase(char ch) {
    if( (ch >='a' && ch <='z') || (ch >='0' && ch <='9') )
        return ch;
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}
    bool checkPalindrome(string a) {
    int s = 0;
    int e = a.length()-1;

    while(s<=e) {
        if(a[s] != a[e])
        {
            return 0;       
        }
        else{
            s++;
            e--;
        }
    }
    return 1;
}
public:
    bool isPalindrome(string s) {
        
        //faltu character hatado
        string temp = "";
        
        for(int j=0; j<s.length(); j++) {   
            if(valid(s[j])) {
                temp.push_back(s[j]);
            }
        }
        
        //lowercase me kardo
        for(int j=0; j<temp.length(); j++) { 
            temp[j] = toLowerCase(temp[j]);
        }
        
        //check palindrome
        return checkPalindrome(temp);
        
    }
};