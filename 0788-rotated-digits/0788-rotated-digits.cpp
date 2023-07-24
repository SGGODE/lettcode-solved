class Solution {
private:
    bool good(int x){
        string res=to_string(x);
        bool flag=1;
        for(int i=0;i<res.size();i++){
            if(res[i]-'0'==1||res[i]-'0'==0||res[i]-'0'==8){
              //  continue;
               int a = 1;
            }else if(res[i]-'0'==2||res[i]-'0'==5||res[i]-'0'==6||res[i]-'0'==9){
               if(res[i]-'0'==2){
                   res[i]='5';
                   continue;
               } 
                if(res[i]-'0'==5){
                   res[i]='2';
                   continue;
               } if(res[i]-'0'==6){
                   res[i]='9';
                   continue;
               } if(res[i]-'0'==9){
                   res[i]='6';
                   //continue;
               } 
            }else{
                res[i]='-1';
                flag=0;
                break;
            }
        }
        if(!flag)return 0;
        return stoi(res)!=x;
    }
public:
    int rotatedDigits(int n) {
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(good(i)){
                //cout<<i<<endl;
                ++cnt;
            }
        }
        return cnt;
    }
};