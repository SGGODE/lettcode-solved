class Solution {
private:
    int cnt=0;
    bool check(string s){
        cnt=0;
        cout<<1<<" "<<s<<endl;
        for(int i=0;i<s.size();i++){
            if((s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')||
              (s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')){
                cnt+=1;
            }
        }
        cout<<cnt<<endl;
        return cnt;
    }
public:
    bool halvesAreAlike(string s) {
        int n=s.size();
        string first="",second="";
        // first.append(s.begin(),s.begin()+n/2);
        // second.append(s.begin()+n/2,s.end());
        for(int i=0;i<n/2;i++)first.push_back(s[i]);
        for(int i=n/2;i<n;i++)second.push_back(s[i]);
       // cout<<first<<" "<<second<<endl;
        int firstvol=0,secondvol=0;
         // firstvol=check(first);
         // secondvol=check(second);
        for(int i=0;i<first.size();i++){
            if((first[i]=='a'||first[i]=='e'||first[i]=='i'||first[i]=='o'||first[i]=='u')||
              (first[i]=='A'||first[i]=='E'||first[i]=='I'||first[i]=='O'||first[i]=='U')){
                firstvol+=1;
            }
        }
        for(int i=0;i<second.size();i++){
            if((second[i]=='a'||second[i]=='e'||second[i]=='i'||second[i]=='o'||second[i]=='u')||
              (second[i]=='A'||second[i]=='E'||second[i]=='I'||second[i]=='O'||second[i]=='U')){
                secondvol+=1;
            }
        }
        //cout<<firstvol<<" "<<secondvol<<endl;
       // if(firstvol!=secondvol)return 0;
        return firstvol==secondvol;
    }
};