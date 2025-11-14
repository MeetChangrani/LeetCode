class Solution:
    def generateParenthesis(self, n: int):
        result = []

        def backtrack(open_count, close_count, current):
            # If the string is complete
            if len(current) == 2 * n:
                result.append(current)
                return

            # Add "(" if we still have left parentheses available
            if open_count < n:
                backtrack(open_count + 1, close_count, current + "(")

            # Add ")" if it does not exceed number of "("
            if close_count < open_count:
                backtrack(open_count, close_count + 1, current + ")")

        backtrack(0, 0, "")
        return result
