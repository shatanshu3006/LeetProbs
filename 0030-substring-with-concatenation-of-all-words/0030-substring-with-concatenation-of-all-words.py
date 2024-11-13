class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:

        N = len(words)
        Nsingle = len(words[0])
        cnt = Counter(words)
        
        def isValid(subs):   #function to check if a substring is a combination of the given words
            split = [subs[i:i+Nsingle] for i in range(0, len(subs), Nsingle)]     #alternative for this line: split = wrap(subs,N_single)
            if Counter(split)==cnt:
                return True
            return False
        
        i=0
        j=N*Nsingle
        ans=[]
        
        while j<=len(s):    #sliding window over s, checking all substrings with length N*Nsingle
            if isValid(s[i:j]):
                ans.append(i)
            i+=1
            j+=1
        
        return ans