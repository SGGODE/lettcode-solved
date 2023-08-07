# class Solution(object):
#     def check(x):
#         time=0
#         while time<len(x)/2
#            if x[time]==x[len(x)-time-1]:
#               time+=1
#            else:
#             return 0
          
        
#         return 1
        
#     def isStrictlyPalindromic(self, n):
#         """
#         :type n: int
#         :rtype: bool
#         """
#         for x in (3,n-2):
#             if !check(bin(x)):
#                 return 0
            
#         return 1
class Solution(object):
    def check(self, x):
        time = 0
        while time < len(x) / 2:
            if x[time] == x[len(x) - time - 1]:
                time += 1
            else:
                return 0
        return 1

    def isStrictlyPalindromic(self, n):
        # for x in range(2, n - 1):  
        #     if not self.check(str(bin(x)[2:])): 
        #         print(str(bin(x)[2:]))
        #         return False
        return False  

        