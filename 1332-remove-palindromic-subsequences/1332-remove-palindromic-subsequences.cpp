class Solution {
public:
    int removePalindromeSub(string s) {
        // string x=s;
        // int cnt=0;
        // while(!x.empty()){
        //     int st=0;
        //     int e=x.size()-1;
        //     int n=x.size();
        //     string temp=x;
        //     unordered_map<int,int>mp;
        //     while(st<=e){
        //        if(x[st]==x[e]){
        //            st++;
        //            e--;
        //            mp[st]++;
        //            mp[e]++;
        //        }else if(x[st]!=x[e]){
        //            e--;
        //        }
        //     }
        //     x.clear();
        //     for(int i=0;i<n;i++){
        //         if(mp.count(i)){
        //            continue;
        //         }else x.push_back(temp[i]);
        //     }
        //     ++cnt;
        // }
        // return cnt;
        int st=0;
        int e=s.size()-1;
        while(st<e){
            if(s[st]!=s[e])return 2;
            st++;
            e--;
        }
        return 1;
    }
};