class Solution {
private:
    bool check(string s,string target){
        bool flag=1;
        int n=s.size();int y=target.size();
        for(int i=0;i<=n;i+=y){
            string x=s.substr(i,i+y);
            cout<<x<<" "<<target<<endl;
            if(x==target)continue;
            else return 0;
        }
        cout<<"done for this"<<endl;
        return flag;
    }
public:
    string gcdOfStrings(string s1, string s2) {
    //  map<string,int>mp;
    //  string s;
    //  int n=str2.size();
    //  int mi=str1.size();
    //   for(int i=0;i<n/2;i++){
    //       s.push_back(str2[i]);
    //       mp[s]++;
    //   }
    //     int m=INT_MIN;string result;
    //     for(auto it:mp){
    //         int x=it.first.size();
    //         if(n%x==0&&check(str2,it.first)&&mi%x==0){
    //             result.clear();
    //             result=it.first;
    //             m=max(m,x);
    //         }
    //     }
    //     if(m==INT_MIN&&check(str1,str2)){
    //         return str2;
    //     }
    //     cout<<m<<endl;
    //     // if(m==INT_MIN)cout<<"Fuck"<<endl;
    //     // cout<<m<<endl;
    //     return result;
     return (s1+s2==s2+s1)?s1.substr(0,gcd(s1.size(),s2.size())):"";
    }
};