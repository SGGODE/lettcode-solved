class Solution {
private:
   
public:
    string addBinary(string a, string b) {
       string result="";
       int n=a.size();
       int m=b.size();int carry=0;
       if(n>=m){
           //int carry=0;
           int j=m-1;
          for(int i=n-1;i>=0;i--){
              int x=0,y=0;
               if(j>=0){
                if(b[j]=='0')x=0;
                 else x=1;
                   --j;
              }
              //y=b[i]-'0';
              if(a[i]=='0')y=0;
              else y=1;
              if(x==1&&y==1&&carry==1){
                  result.push_back('1');
                  carry=1;
                  continue;
              }
              else if((x==1&&y==1&&carry==0)||(x==0&&y==1&&carry==1)||(x==1&&y==0&&carry==1)){
                  result.push_back('0');
                  carry=1;
                  continue;
              }else if((x==0&&y==1&&carry==0)||(x==1&&y==0&&carry==0)||(x==0&&y==0&&carry==1)){
                  result.push_back('1');
                  carry=0;
                  continue;
              }else{
                  result.push_back('0');
                  carry=0;
                  continue;  
              }
          }
       }else{
           int j=n-1;
          for(int i=m-1;i>=0;i--){
              int x=0,y=0;
              if(j>=0){
                if(a[j]=='0')x=0;
                 else x=1;
                  --j;
              }
              //y=b[i]-'0';
              if(b[i]=='0')y=0;
              else y=1;
              if(x==1&&y==1&&carry==1){
                  result.push_back('1');
                  carry=1;
                  continue;
              }
              else if((x==1&&y==1&&carry==0)||(x==0&&y==1&&carry==1)||(x==1&&y==0&&carry==1)){
                  result.push_back('0');
                  carry=1;
                  continue;
              }else if((x==0&&y==1&&carry==0)||(x==1&&y==0&&carry==0)||(x==0&&y==0&&carry==1)){
                  result.push_back('1');
                  carry=0;
                  continue;
              }else{
                  result.push_back('0');
                  carry=0;
                  continue;  
              }
          }
       }
        if(carry==1)result.push_back('1');
        //result.append(to_string(carry));
        reverse(result.begin(),result.end());
        return result;
    }
};