class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int m=strs[0].size();
        // for(int i=0;i<n;i++){
        //     for(auto it:strs[i])cout<<it<<" ";
        //     cout<<endl;
        // }
        vector<vector<char>>v(n,vector<char>(m));
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
             for(auto it:strs[i])v[i][j++]=it;
          }
        }
        for(auto it:v){
            for(auto vt:it)cout<<vt<<" ";
            cout<<endl;
        }
//         for(int i=0;i<strs[0].size();i++){
//            // int ch=v[i][]
//             for(int j=0;j<n;j++){
                
//             }
//         }
        int cnt=0;
        for(int i=0;i<m;i++){
            int ch=v[0][i]-0;
            for(int j=1;j<n;j++){
                if((v[j][i]-0)>=ch){
                    ch=(v[j][i]-0);
                }else{
                   // cout<<i<<" "<<j<<" "<<v[i][j]<<endl;
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};