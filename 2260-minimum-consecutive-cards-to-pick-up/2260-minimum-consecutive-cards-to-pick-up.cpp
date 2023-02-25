class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
       unordered_map<int,int>mp;
       int min_diff=INT_MAX;
       int n=cards.size();
       for(int i=0;i<n;i++){
           if(mp.find(cards[i])!=mp.end()){
               int x=i-mp[cards[i]];
               min_diff=min(min_diff,x+1);
           }
           mp[cards[i]]=i;
       }
        if(min_diff==INT_MAX)return -1;
        return min_diff;
    }
};