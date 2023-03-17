class Solution {
public:
    bool checkValidString(string s) {
       int n=s.size();
        int cnt=0;
      //  int ecnt=0;
       //  stack<char>st;
       // for(int i=0;i<n;i++){
       //     if(s[i]=='*')++cnt;
       //     if(s[i]==')'){
       //       //  stack<char>st(s);
       //         while(!st.empty()&&st.top()!='('){
       //             st.pop();
       //         }
       //         if(st.empty()&&cnt==0)return 0;
       //         if(st.empty()&&cnt!=0)cnt-=1;
       //         else st.pop();
       //     }
       //  //   if(s[i]!='(')
       //      st.push(s[i]); 
       // }
       //  return st.empty();
       //  if(n==1){
       //      if(s[0]=='*')return 1;
       //      else return 0;
       //  }
       //  //stack<char>st;
       //  int lcnt=0;
       //  for(int i=0;i<n;i++){
       //    if(s[i]=='('){
       //        cnt++;
       //        lcnt--;
       //    }
       //    if(s[i]==')'){
       //        cnt--;
       //        lcnt--;
       //    }
       //    else{
       //        lcnt--;
       //       cnt++; 
       //    } 
       //    if(cnt<0)return 0;
       //  if(lcnt<0)lcnt=0;
       //  }
       // // while(st)
       // // return st.empty();
       //  return lcnt==0;
       //  
         stack<int> open;
        stack<int> star;

        for(int i = 0; i < s.size(); i++){
            if(s[i]=='('){
                open.push(i);
            }
            else if(s[i]=='*'){
                star.push(i);;
            }
            else {
                if(s[i]==')'){
                    if(!open.empty()){
                        open.pop();
                    }
                    else if(!star.empty()){
                        star.pop();
                    }
                    else return false;
                }
            }

        }
        while(!open.empty() && !star.empty() && open.top() < star.top()){
            open.pop();
            star.pop();
        }

        return open.empty();
    }
};