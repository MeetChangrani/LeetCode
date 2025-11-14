class Solution:
    def combine(self, n, k):
        res = []

        def backtrack(start, path):
            # If combination length is k, add it
            if len(path) == k:
                res.append(path[:])
                return

            # Choose next number
            for num in range(start, n + 1):
                path.append(num)
                backtrack(num + 1, path)
                path.pop()   # undo
            
        backtrack(1, [])
        return res
