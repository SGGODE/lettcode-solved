from typing import List
from collections import defaultdict
from bisect import bisect_left

class Solution:
    def __init__(self):
        self.dp = []

    def sub(self, power: List[int], count: dict, s: List[int], index: int, start: bool) -> int:
        if index == len(power):
            return 0
        if self.dp[index] != -1:
            return self.dp[index]
        
        ans = power[index] * count[power[index]]
        
        if not start:
            ans = max(ans, self.sub(power, count, s, index + 1, False))
            pos = bisect_left(s, (power[index] + 3, float('-inf')))
            if pos < len(s):
                ans = max(ans, power[index] * count[power[index]] + self.sub(power, count, s, s[pos][1], True))
        else:
            pos = bisect_left(s, (power[index] + 3, float('-inf')))
            if pos < len(s):
                ans = max(ans, power[index] * count[power[index]] + self.sub(power, count, s, s[pos][1], True))
        
        self.dp[index] = ans
        return ans

    def maximumTotalDamage(self, power: List[int]) -> int:
        n = len(power)
        self.dp = [-1] * n
        power.sort()
        
        count = defaultdict(int)
        s = []
        index = 0
        
        for it in power:
            count[it] += 1
            if count[it] == 1:
                s.append((it, index))
            index += 1
        
        answer = self.sub(power, count, s, 0, False)
        return answer
# class Solution {
# private:
#     vector<long long>dp;
#     long long sub(vector<int>&power,unordered_map<int,int>&count,set<pair<int,int>>&s,int index,int start){
#         if(index==power.size())return 0;
#         if(dp[index]!=-1)return dp[index];
#         long long ans = power[index]*count[power[index]];
#         if(!start){
#             ans = max(ans,sub(power,count,s,index+1,0));
#             auto it = s.lower_bound({power[index]+3,numeric_limits<int>::min()});
#             if(it!=s.end())ans = max(ans,power[index]*count[power[index]]+sub(power,count,s,it->second,1));
#         }else{
#             auto it = s.lower_bound({power[index]+3,numeric_limits<int>::min()});
#             if(it!=s.end())ans = max(ans,power[index]*count[power[index]]+sub(power,count,s,it->second,1));
#         }
#         return dp[index]=ans;
#     }
# public:
#     long long maximumTotalDamage(vector<int>& power) {
#         int n = power.size();
#         dp.resize(n,-1);
#         sort(power.begin(),power.end());
#         unordered_map<int,int>count;
#         set<pair<int,int>>s;
#         int index = 0;
#         for(auto&it:power){
#           count[it]++;
#           if(count[it]==1)s.insert({it,index});
#           ++index;
#         }
#         long long answer = 0;
#         return sub(power,count,s,0,0);
#     }
# };