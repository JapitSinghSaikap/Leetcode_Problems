class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        res = 0
        n = start ^ goal
        while n:
            n = (n)&(n-1)
            res+=1
        #     res += n&1
        #     n = n>>1

        # while start or goal:
        #     if (start%2) != (goal%2):
        #         res+=1
        #     start = start//2
        #     goal = goal//2
        return res
