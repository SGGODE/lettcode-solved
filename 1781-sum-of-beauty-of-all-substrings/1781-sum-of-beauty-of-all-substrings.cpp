class Solution {
private:
    int beauty(vector<int>&v){
    int mf=-1;
    int lf=1e9;
    for(int i=0;i<v.size();i++){
        mf=max(mf,v[i]);
        if(v[i]>=1){
            lf=min(lf,v[i]);
        }
    }
    return mf-lf;
}

public:
    int beautySum(string s) {
         int sum=0;
       int n= s.length();
        for(int i=0;i<n;i++){
            vector<int>v(26,0);
            for(int j=i;j<n;j++){
               v[s[j]-'a']++;
               sum=sum+beauty(v);
            }
        }
     /* map<string,int>mp;
        int sum=0;
       int n= s.length();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                string sub;
                sub=s.substr(i,j);
                mp[sub]++;
            }
        }
       // int sum=0;
       
       for(auto it:mp){
           string v=it.first;
           //cout<<v<<endl;
           map<char,int>let;
           for(int i=0;i<v.size();i++) let[v[i]]++;
           int m=INT_MIN;
           int mi=INT_MAX;
           if(let.size()==1){
               continue;
           }
           for(auto cu:let){
               m=max(m,cu.second);
               mi=min(mi,cu.second);
           }
          sum+=m-mi; 
          //cout<<sum<<endl;
       }
       map<char,int>lt;
       for(int i=0;i<s.size();i++) lt[s[i]]++;
       int m=INT_MIN;
       int mi=INT_MAX;
       for(auto cu:lt){
            m=max(m,cu.second);
            mi=min(mi,cu.second);
        }
        sum+=m-mi; */
        return sum;
    }
};