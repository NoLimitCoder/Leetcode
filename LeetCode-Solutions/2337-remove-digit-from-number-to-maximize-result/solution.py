class Solution:
    def removeDigit(self, number: str, digit: str) -> str:
        ans = ""
        mx = 0
        for i in range(len(number)):
            test = number[::]
            if test[i] == digit:
                test = test[:i] + test[i + 1:]
                #print(test)
                if len(test) == 0:
                    continue
                if int(test) > mx:
                    mx = int(test)
                    ans = test
        return ans
