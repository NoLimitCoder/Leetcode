class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates = [i for i in candidates if i <= target]
        candidates.sort()
        dp = [set() for _ in range(target+1)]
        dp[0].add(())
        for i, c in enumerate(candidates):
            for j in range(target - c, -1, -1):
                for tup in dp[j]:
                    dp[j+c].add(tuple(list(tup) + [c]))
        return list(dp[target])
