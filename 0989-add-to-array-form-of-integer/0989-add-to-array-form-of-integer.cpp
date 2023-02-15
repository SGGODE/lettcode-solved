class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        string s;
        for(int i=0;i<num.size();i++){
            s.push_back((num[i])+'0');
        }
        string s2=to_string(k);
        int n=s.size();string result="";
        int m=s2.size();int carry=0;
        if(n>=m){
           int j=m-1;
           for(int i=n-1;i>=0;i--){
               int x=0,y=0;
               if(j>=0){
                   y=s2[j]-'0';
                   --j;
               }
               x=s[i]-'0';
               if((x+y)>9&&carry==0){
                   int sum=x+y+carry;
                   int x=sum%10;
                   result.push_back(x+'0');
                   carry=1;
                   continue;
               }if((x+y)>9&&carry>=1){
                   int sum=x+y+carry;
                   int x=sum%10;
                   result.push_back(x+'0');
                   continue;
               }if((x==0&&y>=1&&carry>=1)||(x>=1&&y==0&&carry>=1)||(x>=1&&y>=1&&carry==0)){
                 int sum=abs(x+y+carry);
                 if(sum>=10){
                 // int sum=x+y+carry;
                   int x=sum%10;
                   result.push_back(x+'0');
                     carry=1;
                   continue;
                 }else{
                     result.push_back(sum+'0');
                     carry=0;
                     continue;
                 }
               }if((x==0&&y==0&&carry>=1)||(x>=1&&y==0&&carry==0)||(x==0&&y>=1&&carry==0)){
                   int sum=x+y+carry;
                   int x=sum%10;
                   result.push_back(x+'0');
                   carry=0;
                   continue;
               }else{
                   int sum=x+y+carry;
                   if(sum>=10){
                 // int sum=x+y+carry;
                   int x=sum%10;
                   result.push_back(x+'0');
                     carry=1;
                   continue;
                 }else{
                     result.push_back(sum+'0');
                     carry=0;
                     continue;
                 }
               }
           }
          
        }else{
            int j=n-1;
           for(int i=m-1;i>=0;i--){
               int x=0,y=0;
               if(j>=0){
                   y=s[j]-'0';
                   --j;
               }
               x=s2[i]-'0';
               if((x+y)>9&&carry==0){
                   int sum=x+y+carry;
                   int x=sum%10;
                   result.push_back(x+'0');
                   carry=1;
                   continue;
               }if((x+y)>9&&carry>=1){
                   int sum=x+y+carry;
                   int x=sum%10;
                   result.push_back(x+'0');
                   continue;
               }if((x==0&&y>=1&&carry>=1)||(x>=1&&y==0&&carry>=1)||(x>=1&&y>=1&&carry==0)){
                 int sum=abs(x+y+carry);
                 if(sum>=10){
                 // int sum=x+y+carry;
                   int x=sum%10;
                   result.push_back(x+'0');
                     carry=1;
                   continue;
                 }else{
                     result.push_back(sum+'0');
                     carry=0;
                     continue;
                 }
               }if((x==0&&y==0&&carry>=1)||(x>=1&&y==0&&carry==0)||(x==0&&y>=1&&carry==0)){
                   int sum=x+y+carry;
                   int x=sum%10;
                   result.push_back(x+'0');
                   carry=0;
                   continue;
               }else{
                   int sum=x+y+carry;
                   if(sum>=10){
                 // int sum=x+y+carry;
                   int x=sum%10;
                   result.push_back(x+'0');
                     carry=1;
                   continue;
                 }else{
                     result.push_back(sum+'0');
                     carry=0;
                     continue;
                 }
               }
           } 
        }
        if(carry==1)result.push_back(carry+'0');
        reverse(result.begin(),result.end());
        vector<int>v;
        //cout<<result<<endl;
        for(auto it:result)v.push_back(it-'0');
        return v;
    }
};