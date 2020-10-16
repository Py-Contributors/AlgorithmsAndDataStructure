class Solution:
    def romanToInt(self, s):
        r = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        v = 0
        for i in range(len(s)):
            if i > 0 and r[s[i]] > r[s[i - 1]]:
                v += r[s[i]] - 2 * r[s[i - 1]]
            else:
                v += r[s[i]]
        return v

val = input("Enter Roman numeral: ")
print("Integer equivalent of", val,"is", Solution().romanToInt(val))


