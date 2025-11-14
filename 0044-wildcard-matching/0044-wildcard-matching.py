class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        i = j = 0           # i -> s pointer, j -> pattern pointer
        star = -1           # last position of '*' in pattern
        match = 0           # position in s when '*' was used

        while i < len(s):
            # Case 1: characters match or pattern has '?'
            if j < len(p) and (p[j] == s[i] or p[j] == '?'):
                i += 1
                j += 1

            # Case 2: '*' found in pattern — record its position
            elif j < len(p) and p[j] == '*':
                star = j
                match = i
                j += 1

            # Case 3: previous '*' can match this character
            elif star != -1:
                j = star + 1      # restart in pattern after '*'
                match += 1
                i = match         # let '*' match one more char

            # No match
            else:
                return False

        # Consume remaining '*' in pattern
        while j < len(p) and p[j] == '*':
            j += 1

        return j == len(p)
