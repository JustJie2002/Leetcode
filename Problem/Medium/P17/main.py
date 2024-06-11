

KEY_PAD = [
    "",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
]

class Solution:
    def letterCombinations(self, digs):
        n = len(digs)

        ans = []
        def recurse(i, s):
            if i == n:
                if s:
                    ans.append(s)
                return
            for c in KEY_PAD[int(digs[i])]:
                recurse(i + 1, s + c)

        recurse(0, "")
        return ans