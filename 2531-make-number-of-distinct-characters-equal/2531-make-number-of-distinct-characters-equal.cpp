// class Solution {
// public:
//     bool isItPossible(string word1, string word2) {
//       // map<char,int>mp1,mp2;
//       //   for(auto it:word1)mp1[it]++;
//       //   for(auto it:word2)mp2[it]++;
//       //   int n=mp1.size();
//       //   int m=mp2.size();
//       //   if(n==1&&m==1){
//       //         bool flag=0;
//       //          for(auto it:mp1){
//       //              if(mp2.find(it.first)==mp2.end()){
//       //                  flag=1;
//       //              }
//       //          }
//       //           bool flag1=0;
//       //           for(auto it:mp2){
//       //              if(mp1.find(it.first)==mp1.end()){
//       //                  flag1=1;
//       //              } 
//       //           }
//       //           if(flag&&flag1)return 1;
//       //       else return 0;
//       //   }
//       //   if(abs(n-m)<=1&&n>1&&m>1){
//       //       if(n>m){
//       //           bool flag=0;
//       //          for(auto it:mp1){
//       //              if(mp2.find(it.first)==mp2.end()&&it.second>1){
//       //                  flag=1;
//       //              }
//       //          }
//       //           bool flag1=0;
//       //           for(auto it:mp2){
//       //              if(mp1.find(it.first)!=mp1.end()&&it.second>1){
//       //                  flag1=1;
//       //              } 
//       //           }
//       //           if(flag&&flag1)return 1;
//       //       else return 0;
//       //       }else if(n==m){
//       //            bool flag=0;
//       //          for(auto it:mp1){
//       //              if(mp2.find(it.first)==mp2.end()){
//       //                  flag=1;
//       //              }
//       //          }
//       //           bool flag1=0;
//       //           for(auto it:mp2){
//       //              if(mp1.find(it.first)==mp1.end()){
//       //                  flag1=1;
//       //              } 
//       //           }
//       //           if(flag&&flag1)return 1;
//       //       else return 0;
//       //       }
//       //       else{
//       //           bool flag=0;
//       //          for(auto it:mp2){
//       //              if(mp1.find(it.first)==mp1.end()&&it.second>1){
//       //                  flag=1;
//       //              }
//       //          }
//       //           bool flag1=0;
//       //           for(auto it:mp1){
//       //              if(mp2.find(it.first)!=mp2.end()&&it.second>1){
//       //                  flag1=1;
//       //              } 
//       //           }
//       //           if(flag&&flag1)return 1;
//       //       else return 0; 
//       //       }
//       //   }
//       //   return 0;
//         int arr[26];
//         int vrr[26];
//         for(int i=0;i<word1.size();i++){
//             arr[word1[i]-'a']++;
//         }
//          for(int i=0;i<word2.size();i++){
//             vrr[word2[i]-'a']++;
//         }
//         for(int i=0;i<26;i++){
//             for(int j=0;j<26;j++){
//                 if(arr[i]>0&&vrr[j]>0){
//                     arr[i]--;vrr[i]++;arr[j]++;vrr[j]--;
//                     int cnt1=0,cnt2=0;
//                     for(int k=0;k<26;k++){
//                         if(arr[k]>0)cnt1++;
//                         if(vrr[k]>0)cnt2++;
//                     }
//                     if(cnt1==cnt2)return 1;
//                     else{
//                         arr[i]++;arr[j]--;vrr[i]--;vrr[j]++;
//                     }
//                 }
//             }
//         }
//         return 0;
//     }
// };
class Solution {
public:
    bool isItPossible(string word1, string word2) {
        map<char,int>mp1,mp2;
        for(char it:word1)mp1[it]++;
        for(char it:word2)mp2[it]++;
        for(int i=0;i<26;i++){
          for(int j=0;j<26;j++){
            char ch1=i+'a',ch2=j+'a';
            if(mp1.count(ch1)&&mp2.count(ch2)){
              if(--mp1[ch1]==0)mp1.erase(ch1);
                if(--mp2[ch2]==0)mp2.erase(ch2);
                mp2[ch1]++;
                mp1[ch2]++;
                if(mp1.size()==mp2.size())return 1;
                if(--mp1[ch2]==0)mp1.erase(ch2);
                if(--mp2[ch1]==0)mp2.erase(ch1);
                mp1[ch1]++;
                mp2[ch2]++;
            }
          }
        }
        return 0;
    }
};

