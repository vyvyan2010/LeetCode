class Solution(object):
            
    def findLadders(self, beginWord, endWord, wordList):        
        queueFront, queueBack = set([beginWord]), set([endWord])
        retpath, path, next = [], [beginWord], collections.defaultdict(list)
           
        if endWord not in wordList:
            return retpath
           
        while queueFront and queueBack:
            if len(queueFront) <= len(queueBack):
                Find = self.Bfs_extended(queueFront, queueBack, 0, wordList, next)
            else:
                Find = self.Bfs_extended(queueBack, queueFront, 1, wordList, next)      
                
            if Find == True:
                break;
 
        self.FindPath(beginWord, endWord, next, path, retpath)
        return retpath
  
    def FindPath(self, beginWord, endWord, next, path, retpath):
        if beginWord == endWord:
            retpath.append(path[:])
            return 
        
        if beginWord in next:
            for x in next[beginWord]:
                path.append(x)
                self.FindPath(x, endWord, next, path, retpath)
                path.pop(-1)
    
    
    def buildTree(self, Direction, KeyWord, letter, next):
        if not Direction:
            next[KeyWord] += [letter]
        else:
            next[letter] += [KeyWord]
    
    
    def Bfs_extended(self, this_lev, other_lev, Direction, wordList, next):
        Find = False
          
        for x in (this_lev | other_lev):
            if x in wordList:
                wordList.remove(x)
          
        next_lev = set()  
        for KeyWord in this_lev:
            for c in string.ascii_lowercase:
                for length in range(len(KeyWord)):
                    letter = KeyWord[:length] + c + KeyWord[length+1:]
                    if letter in other_lev:
                        Find = True
                        self.buildTree(Direction, KeyWord, letter, next)
                    elif letter in wordList:
                        next_lev.add(letter)
                        self.buildTree(Direction, KeyWord, letter, next)

        while this_lev:
            this_lev.pop()
        for x in next_lev:
            this_lev.add(x)
            
        return Find
