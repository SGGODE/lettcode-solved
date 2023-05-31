class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int cnt=0;
        int n=bank.size();
        int m=bank[0].size();
      //  vector<vector<char>>res(n,vector<char>(m,'.'));
        map<int,int>mp;
        for(int i=0;i<n;i++){
            string s=bank[i];
            for(int j=0;j<m;j++){
                if(s[j]=='1'){
                    //res[i][j]='l';
                    mp[i]++;
                }//else mp[i]=0;
            }
        }
        for(int i=0;i<n;i++){
            if(mp.find(i)==mp.end())mp[i]=0;
        }
        for(int i=0;i<n;i++){
           for(int j=i+1;j<n;j++){
               if(mp[j]!=0){
                   cnt+=(mp[i]*mp[j]);
                 //  cout<<i<<endl;
                   i=j-1;
                  // cout<<i<<" "<<n<<endl;
                   break;
               }
           }
             //cout<<i<<" "<<n<<endl;
        }
      //  cout<<mp[3]<<endl;
        return cnt;
    }
};