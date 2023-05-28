class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        map<char,int>mp;
        char ch='a';
        for(int i=0;i<26;i++){
            mp[ch+i]=i+1;
        }
        map<char,int>present;
        for(int i=0;i<chars.size();i++){
            char ch=chars[i];
            present[ch]=vals[i];
        }
        // for(auto &it:mp)cout<<it.first<<" "<<it.second<<endl;
        // for(auto &it:present)cout<<it.first<<" "<<it.second<<endl;
        int maxsum=INT_MIN;
        int sum=0;
        for(int i=0;i<s.size();i++){
            if(present.count(s[i])){
                sum+=present[s[i]];
            }else{
                sum+=mp[s[i]];
            }
            if(sum>maxsum){
                maxsum=sum;
            }
            if(sum<0)sum=0;
        }
        maxsum=max(0,maxsum);
        return maxsum;
    }
};