class Solution {
private:
    void dfs(map<string,vector<pair<string,int>>>&mp,string&src,vector<bool>&vis,vector<string>&res){
        res.push_back(src);
        sort(mp[src].begin(),mp[src].end());
        for(auto&it:mp[src]){
            if(!vis[it.second]){
                vis[it.second]=1;
                dfs(mp,it.first,vis,res);
            }
        }
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
       // // vector<string>adj[];
       //  set<string>s;
       //  for(auto&it:tickets){
       //      s.insert(it[0]);
       //      s.insert(it[1]);
       //  }
       //  map<string,int>mx;
       //  int cnt = 1;
       //  for(auto&it:s){
       //      mx[it]=cnt;
       //      ++cnt;
       //  }
       //  map<string,vector<pair<string,int>>>mp;
       //   cnt = 1;
       //  for(int i=0;i<tickets.size();i++){
       //      mp[tickets[i][0]].push_back({tickets[i][1],cnt});
       //      ++cnt;
       //  }
       //  vector<string>res;
       //  vector<bool>vis(602,0);
       //  string node = "JFK";
       //  dfs(mp,node,vis,res);
      //  return res;
         // Build an adjacency list to represent the flights
        unordered_map<string, multiset<string>> flights;
        for (const auto& ticket : tickets) {
            flights[ticket[0]].insert(ticket[1]);
        }
        
        vector<string> itinerary;
        stack<string> dfsStack;
        dfsStack.push("JFK");

        while (!dfsStack.empty()) {
            string from = dfsStack.top();

            if (flights[from].empty()) {
                // If there are no more outgoing flights, add the airport to the itinerary
                itinerary.push_back(from);
                dfsStack.pop();
            } else {
                // Visit the next airport in lexical order
                auto to = flights[from].begin();
                dfsStack.push(*to);
                flights[from].erase(to);
            }
        }

        // Reverse the itinerary to get the correct order
        reverse(itinerary.begin(), itinerary.end());
        
        return itinerary;
    }
};