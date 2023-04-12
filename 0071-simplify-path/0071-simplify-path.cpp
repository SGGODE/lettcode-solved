class Solution {
public:
    string simplifyPath(string path) {
       //  string s;
       //  stack<string>st;
       //  int n=path.size();
       //  for(int i=0;i<n;i++){
       //      string temp;
       //      while(i<n&&path[i]!='/'){
       //          temp.push_back(path[i]);
       //          i++;
       //      }
       //      if(temp==".")continue;
       //      else if(temp==".."){
       //          if(!st.empty())st.pop();
       //      }else{
       //          st.push(temp);
       //      }
       //  }
       //  while(!st.empty()){
       //      s ='/'+st.top()+s;
       //      st.pop();
       //  }
       //  // string x;
       //  // for(int i=0;i<s.size();i++){
       //  //     if(s[i]=='/'&&s[i+1]=='/'){
       //  //         continue;
       //  //     }else x.push_back(s[i]);
       //  // }
       //  // int f=x.size();
       //  // for(int i=f-1;i>=0&&f>1;i--){
       //  //     if(x[i]=='/')x.pop_back();
       //  //     else break;
       //  // }
       // if(s.size()==0)return "/";
       //  return s;
          stack<string> st;   // Stack is going to store folders
        string ans="";  // Answer path
        for(int i=0;i<path.length();i++){  // Traversing through string
            if(path[i] == '/'){  // We always going to ignore '/'
                continue;
            }
            string temp="";  // We are gonna store folder names in temp
            while(i<path.length() && path[i] != '/'){  // To store names we use this while loop
                temp += path[i];
                i++;
            }
            if(temp == ".") continue;  // If we get a single '.' then there is no need of pushing in stamp
            else if(temp == ".."){  // This means that we have to go up in path
                if(!st.empty()) st.pop();  // To go up we have to pop
            }
            else{
                st.push(temp);  // If we get no . or .. that means we got the name of the folder
            }           
        } 
        if(st.empty())  ans = '/';  // If there is nothing in our stack then we just need to return /;
        while(!st.empty()){  // If we have something in stack then we have to give in this order "/home/xyz/abc" etc
            ans = '/' + st.top() + ans;  // For that I am using this 
            st.pop();
        }       
        return ans;  // Returning the resulting string 
    }
};