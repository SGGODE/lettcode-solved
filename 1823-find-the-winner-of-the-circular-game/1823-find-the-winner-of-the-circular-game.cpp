class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>pq;
        for(int i = 1 ; i <= n ; i++){
            pq.push(i);
        }
        while(pq.size()>1){
            for(int i = 1 ; i < k ; i++){
                int x = pq.front();
                pq.pop();
                pq.push(x);
            }
            pq.pop();
        }
        return pq.front();
    }
};