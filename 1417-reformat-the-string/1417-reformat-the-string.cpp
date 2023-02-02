class Solution {
public:
    string reformat(string s) {
        int cntchar=0;
        int cntnum=0;
        vector<int>num;
        vector<char>chat;
        for(int i=0;i<s.size();i++){
            if(s[i]>='a'&&s[i]<='z'){
                cntchar++;
                chat.push_back(s[i]);
            }
            else{
                cntnum++;
                num.push_back(s[i]-'0');
            } 
        }
        //cout<<chat[0]<<endl;
        string result="";
        int n=s.size();
        if((cntchar==0||cntnum==0)&&n>1)return "";
        else{
            if((cntchar+1==cntnum)||(cntchar==cntnum)){
                int k=0,m=0;bool flag=1;
            for(int i=0;i<s.size();i++){
                if(flag){
                 result.push_back(num[k++]+'0');
                 flag=0;
                }else{
                    flag=1;
                    result.push_back(chat[m++]);
                }
            }
                return result;
            }
            if(cntnum+1==cntchar){
                  int k=0,m=0;bool flag=1;
             for(int i=0;i<s.size();i++){
                if(flag){
                 result.push_back(chat[k++]);
                 flag=0;
                }else{
                    flag=1;
                    result.push_back(num[m++]+'0');
                }
            }
                return result;
            }else return "";
        }
        return result;
    }
};