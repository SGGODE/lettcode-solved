class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
       queue<int>pq;
       for(int i=0;i<deck.size();i++)pq.push(i);
       sort(deck.begin(),deck.end());
       vector<int>ans(deck.size());
       for(int i=0;i<deck.size();i++){
           ans[pq.front()]=deck[i];
           pq.pop();
           if(!pq.empty()){
               pq.push(pq.front());
               pq.pop();
           }
       }
        return ans;
    }
};