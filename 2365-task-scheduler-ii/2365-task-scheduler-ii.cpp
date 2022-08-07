class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long c=0;
       unordered_map<int,long long> s;
        for(int i:tasks){
            if(s.count(i)){
                 s[i]=c=max(c,s[i]+space)+1;
            }
            else
             s[i]=++c;
    }
        return c;
    }
};