class Solution:
    def permuteUnique(self, nums):
        nums.sort()                     # Sort to handle duplicates
        res = []
        used = [False] * len(nums)

        def backtrack(path):
            if len(path) == len(nums):
                res.append(path[:])
                return
            
            for i in range(len(nums)):
                # Skip used numbers
                if used[i]:
                    continue

                # Skip duplicates (only use the *first* unused duplicate)
                if i > 0 and nums[i] == nums[i-1] and not used[i-1]:
                    continue

                used[i] = True
                path.append(nums[i])

                backtrack(path)

                # undo (backtrack)
                path.pop()
                used[i] = False

        backtrack([])
        return res
