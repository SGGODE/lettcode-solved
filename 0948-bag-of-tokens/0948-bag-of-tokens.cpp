class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
       int n = tokens.size();
       vector<bool>vis(n, false);
       priority_queue<pair<int,int>,vector<pair<int, int>>,greater<pair<int,int>>>pq;
       priority_queue<pair<int,int>>pqx;

        for (int i = 0; i < n; i++) {
            pq.push({tokens[i], i});
            pqx.push({tokens[i], i});
        }

        int score = 0;
        int maxscore = 0;

        while (!pq.empty() && !pqx.empty()) {
            int mt = pq.top().first;
            int mi = pq.top().second;
            pq.pop();

            if (!vis[mi] && power < mt && score != 0) {
                while(!pqx.empty() && vis[pqx.top().second])pqx.pop();

                if (pqx.empty()) return maxscore;

                score -= 1;
                power += pqx.top().first;
                vis[pqx.top().second] = true;
                pqx.pop();

                if (power > mt) {
                    score += 1;
                    power -= mt;
                    vis[mi] = true;
                } else {
                    return maxscore;
                }
            } else if (!vis[mi] && power >= mt) {
                power -= mt;
                vis[mi] = true;
                score += 1;
            }

            maxscore = max(maxscore, score);
        }

        return maxscore;
    }
};