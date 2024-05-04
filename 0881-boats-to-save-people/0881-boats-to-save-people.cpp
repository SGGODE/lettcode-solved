class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int cnt = 0;
        int n = people.size();
        sort(people.begin(),people.end());
        int s = 0,e=n-1;
        while(s<=e){
            if(people[s]+people[e]<=limit){++s;--e;}
            else --e;
            ++cnt;
        }
        return cnt;
    }
};