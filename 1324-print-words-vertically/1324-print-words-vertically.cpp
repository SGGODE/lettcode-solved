class Solution {
public:
    vector<string> printVertically(string s) {
        int t=0;
        stringstream ss(s);
        string word;
        vector<string>words;
        map<int,int>mp;
        int i=0;
        while(ss>>word){
           int x=word.size();
           words.push_back(word);
           mp[i]=x; 
           t=max(t,x);
            ++i;
        }
        // for(int j=0;j<i;j++){
        //     for(int k=0;k<j;k++){
        //         mp[k]=max(mp[k],mp[j]);
        //     }
        // }
        int index=0;
        vector<string>res;
        while(t--){
            string x;
           // mp[index]=i-1;
            for(int i=0;i<words.size();i++){
                if(words[i].size()>index){
                    x.push_back(words[i][index]);
                }else{
                   for(int j=i+1;j<words.size();j++){
                       if(words[j].size()>index){
                           x.push_back(' ');
                           break;
                       }
                   }
                } 
            }
           // cout<<mp[index]<<endl;
            ++index;
            res.push_back(x);
        }
        return res;
    }
};