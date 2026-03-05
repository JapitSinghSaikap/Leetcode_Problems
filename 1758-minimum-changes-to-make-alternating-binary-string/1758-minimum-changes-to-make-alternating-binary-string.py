class Solution(object):
    def minOperations(self, s):
        """
        :type s: str
        :rtype: int
        """
        count1 = 0  
        count2 = 0  
        for i in range(len(s)):
            
            expected_char_1 = '0' if i % 2 == 0 else '1'
            expected_char_2 = '1' if i % 2 == 0 else '0'
            
            if s[i] != expected_char_1:
                count1 += 1
            if s[i] != expected_char_2:
                count2 += 1
        
        return min(count1, count2)