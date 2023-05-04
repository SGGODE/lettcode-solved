class Solution {
public:
    string predictPartyVictory(string senate) {
        // priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>>pq;
        // priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>>px;
        // for(int i=0;i<senate.size();i++){
        //     if(senate[i]=='R'){
        //         pq.push({i,'R'});
        //     }else{
        //         px.push({i,'D'});
        //     }
        // }
        // int n=senate.size();
        // vector<bool>vis(n,0);
        // for(int i=0;i<n;i++){
        //     if(vis[i])continue;
        //     if(senate[i]=='R'){
        //         if(px.empty())return "Radiant";
        //         else{
        //           vis[px.top().first]=1;
        //           px.pop();
        //           if(px.empty())return "Radiant";  
        //         }
        //     }else{
        //          if(pq.empty())return "Dire";
        //         else{
        //              vis[pq.top().first]=1;
        //              pq.pop();
        //             if(pq.empty())return "Dire";
        //         }
        //     }
        // }
        // return " ";
         int score = 0; // +ve for R and -ve for D
        for (int i = 0; i < senate.size(); ++i) {
            const char ch = senate[i];
            if (ch == 'R') {
                if (score < 0) 
                    senate.push_back('D');
                
                ++score;
            } else {
                if (score > 0) 
                    senate.push_back('R');
                
                --score;
            }
        }
        return score > 0 ? "Radiant" : "Dire";
    }
};