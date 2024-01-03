class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        prev=bank[0].count("1")
        res=0
        for i in range(1,len(bank)):
            current=bank[i].count("1")
            res+=prev*current
            if current:
                prev=current
        return res