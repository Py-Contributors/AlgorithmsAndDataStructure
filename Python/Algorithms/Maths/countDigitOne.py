class Solution:
    def countDigitOne(self, n: int) -> int:
        count = 0
        for i in range(1, n + 1):
            num = str(i)
            for j in num:
                if int(j) == 1:
                    count += 1
        return count


val = Solution()
print("Enter the number :")
print("1 occur {} times".format(val.countDigitOne(int(input()))))
