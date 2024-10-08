// class Solution {
// private:
//     int len=INT_MAX;
//     vector<int>res;
//     vector<set<int>>store;
//     void sub(vector<string>&nums,int index,vector<vector<string>>&people,set<int>temp){
//         if(index==nums.size()){
//             if(temp.size()<len){
//                 len=temp.size();
//                store.push_back(temp);
//             }
//             return;
//         }
//         bool flag=0;
//         if(!temp.empty()){
//             for(auto&it:temp){
//                 for(auto&vt:people[it]){
//                     if(vt==nums[index]){
//                         flag=1;
//                         sub(nums,index+1,people,temp);
//                     }
//                 }
//             }
//         }
//        // else{
//         if(!flag){
//         for(int i=0;i<people.size();i++){
//             if(temp.find(i)==temp.end()&&!people[i].empty()){
//             for(auto&it:people[i]){
//                 if(it==nums[index]){
//                     if(temp.find(i)!=temp.end())sub(nums,index+1,people,temp);
//                     else{
//                         temp.insert(i);
//                         sub(nums,index+1,people,temp);
//                         temp.erase(i);
//                     }
//                     //sub(nums,index,people,temp);
//                 }
//             }
//         }}
//         }
//     }
// public:
//     vector<int> smallestSufficientTeam(vector<string>&nums,vector<vector<string>>&people) {
//         set<int>s;
//         sub(nums,0,people,s);
//         for(auto&it:store){
//             vector<int>temp(it.begin(),it.end());
//             if(it.size()==len){
//                 res=temp;
//                 break;
//             }
//         }
//         return res;
//     }
// };
int dp[1 << 16][64];
bool choice[1 << 16][64];

class Solution {
public:
    int req_mask, m;
    
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people_skills) {
        int n = req_skills.size();
        m = people_skills.size();
        
        // map each skill to a unique number
        unordered_map<string, int> skills;
        for (int i = 0; i < n; ++i)
            skills[req_skills[i]] = i;
        
        // represent each person by a single bitmasked number (k'th bit represents if a person has the k'th skill or not)
        vector<int> people;
        for (auto &v: people_skills) {
            int h = 0;
            for (string &skill: v)
                h |= 1 << skills[skill];
            
            people.push_back(h);
        }
        
        // required set of skills mask
        req_mask = (1 << n) - 1;
        
        memset(dp, -1, 1 << n + 8);
        memset(choice, 0, 1 << n + 6);
        
        // modified dp
        solve(people, 0, 0);
        
        // build the answer through the choice matrix (see the solve function first)
        vector<int> ans;
        for (int i = 0, mask = 0; i < m; ++i) {
            // did we include the i'th person?
            if (choice[mask][i]) {
                ans.push_back(i);
                mask |= people[i];
            }
            
            if (mask == req_mask)
                break;
        }
        
        return ans;
    }
    
    // dp with memo
    int solve(vector<int> &people, int i, int mask) {
        if (mask == req_mask)
            return 0;
        if (i == m)
            return 10000;
        
        int &ans = dp[mask][i];
        if (ans != -1)
            return ans;
        
        // include current person in the team
        int ans1 = solve(people, i+1, mask | people[i]) + 1;
        
        // don't include
        int ans2 = solve(people, i+1, mask);
        
        // did we include the current person to get the minimum result?
        if (ans1 < ans2)
            choice[mask][i] = 1;
        
        return ans = min(ans1, ans2);
    }
};