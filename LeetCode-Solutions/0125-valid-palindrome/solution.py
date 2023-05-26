class Solution:
    def isPalindrome(self, s: str) -> bool:
        lower = s.lower()
        s = re.sub(r'[^a-z0-9]', '', s.lower())
        print(s)
        for i in range(len(s)):
            if s[i] != s[len(s)-1-i]:
                return False
        return True
