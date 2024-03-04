class Solution {
private:
    int sub(vector<int>& tokens, int power,int src,int index){
        if(index==tokens.size())return 0;
        int ans = sub(tokens,power,src,index+1);
        if(power>=tokens[index]){
            ans = max(ans,1+sub(tokens,power-tokens[index],src+1,index+1));
        }else if(src!=0){
             ans = max(ans,-1+sub(tokens,power+tokens[index],src-1,index+1));
        }
        return ans;
    }
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        //return sub(tokens,power,0,0);
        int n = tokens.size();
        vector<bool>vis(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        priority_queue<pair<int,int>>pqx;
        for(int i=0;i<n;i++){
            pq.push({tokens[i],i});
            pqx.push({tokens[i],i});
        }
        int score = 0;
        int maxscore = 0;
        while(!pq.empty()&&!pqx.empty()){
            int mt = pq.top().first;
            int mi = pq.top().second;
            pq.pop();
            maxscore = max(maxscore,score);
            if(!vis[mi]&&power<mt&&score!=0){
               // cout<<mi<<endl;
                while(vis[pqx.top().second]==1&&!pqx.empty())pqx.pop();
                if(pqx.empty())return maxscore;
                score -= 1;
                power += pqx.top().first;
                vis[pqx.top().second]=1;
                pqx.pop();
                if(power>mt){
                    score += 1;
                    power -= mt;
                    vis[mi]=1;maxscore = max(maxscore,score);
                }else return maxscore;
              //  continue;
            }else if(!vis[mi]&&power>=mt){
                power -= mt;
                vis[mi]=1;
                score+=1;
                maxscore = max(maxscore,score);
            }
            maxscore = max(maxscore,score);
            //cout<<power<<" "<<score<<endl;
        }
        return maxscore;
    }
};