class Solution:
    def __init__(self):
        self.mod = int(1e9 + 7)
        self.dp = [[[-1 for _ in range(3)] for _ in range(2)] for _ in range(100001)]
    
    def sub(self, n, absences, lates):
        if n == 0:
            return 1
        if self.dp[n][absences][lates] != -1:
            return self.dp[n][absences][lates] % self.mod
        
        ans = 0
        
        # Case 1: Adding 'P' (Present)
        ans = (ans + self.sub(n - 1, absences, 0)) % self.mod
        
        # Case 2: Adding 'A' (Absent)
        if absences > 0:
            ans = (ans + self.sub(n - 1, absences - 1, 0)) % self.mod
        
        # Case 3: Adding 'L' (Late)
        if lates < 2:
            ans = (ans + self.sub(n - 1, absences, lates + 1)) % self.mod
        
        self.dp[n][absences][lates] = ans % self.mod
        return ans
    
    def checkRecord(self, n: int) -> int:
        return self.sub(n, 1, 0)