class Solution(object):
    def __init__(self):
        __Alphabet = [chr(ord('a')+x) for x in range(0, 26)]
        self.__HashAlpha = list(map(lambda x:hash(x), __Alphabet))

    def __hashFun(self, s):
        hashValue = 0
        for x in s:
            hashValue = hashValue + self.__HashAlpha[ord(x)-ord('a')]
        return hashValue
        
    def isScramble(self, s1, s2):
        if len(s1) <= 1:
            if s1 == s2:
                return True
            else:
                return False
              
        s1_hashvalue = self.__hashFun(s1)
        s2_hashvalue = self.__hashFun(s2)
      
        if s1_hashvalue == s2_hashvalue:
            for i in range(1, len(s1)):
                s1_lhalf = s1[0 : i]
                s1_rhalf = s1[i : len(s1)]
                        
                s2_lhalf = s2[0 : i]
                s2_rhalf = s2[i: len(s1)]   
                s2_lhalf_switch = s2[0 : len(s1) - i]
                s2_rhalf_switch = s2[len(s1) - i : len(s1)]
                    
                ans1 = self.isScramble(s1_lhalf, s2_lhalf)
                ans2 = self.isScramble(s1_rhalf, s2_rhalf)
                if ans1 and ans2:
                    return True    
                
                ans1 = self.isScramble(s1_lhalf, s2_rhalf_switch)
                ans2 = self.isScramble(s1_rhalf, s2_lhalf_switch)
                if ans1 and ans2:
                    return True           

        return False

s = Solution();
#print(s.isScramble('aabb', 'abab'))
#print(s.isScramble('abab', 'aabb'))
print(s.isScramble('great', 'rgtae'))
