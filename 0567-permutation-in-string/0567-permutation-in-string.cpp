// class Solution {
// public:
//     bool checkInclusion(string s1, string s2) {
//         if(s1==s2)return 1;
//         reverse(s1.begin(),s1.end());
//         if(s2.size()<s1.size())return 0;
//         if(s1==s2)return 1;
//         int k=0;
//         //cout<<s1<<endl;
//         for(int i=0;i<s2.size();i++){
//             if(s2[i]==s1[k]){
//                 for(int j=i;j<s2.size()&&k<s1.size();j++){
//                     if(s2[j]==s1[k]){
//                        // cout<<k<<endl;
//                        // cout<<s2[j]<<endl;
//                         k+=1;
//                         continue;
//                     }else{
//                         break;
//                     }
//                 }
//                 if(k==s1.size()){
//                     //cout<<"me"<<endl;
//                    // cout<<k<<endl;
//                     return 1;
//                 }else{
//                     k=0;
//                 }
//             }
//         }
//         return 0;
//     }
// };
class Solution {
    bool areVectorsEqual(vector<int> a, vector<int> b){
        for(int i=0; i<26; i++){
            if(a[i]!=b[i]) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size()) return false;
        vector<int> freqS1(26, 0);
        for(char c: s1) freqS1[c-'a']++;
        
        vector<int> freqS2(26, 0);
        int i=0, j=0;
        
        while(j<s2.size()){
            freqS2[s2[j]-'a']++;
            
            if(j-i+1==s1.size()){
                if(areVectorsEqual(freqS1, freqS2)) return true;
            }
            
            if(j-i+1<s1.size()) j++;
            else{
                freqS2[s2[i]-'a']--;
                i++;
                j++;
            }
        }
        return false;
    }
};