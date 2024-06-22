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
