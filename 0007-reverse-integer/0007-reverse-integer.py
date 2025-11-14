class Solution:
    def reverse(self, x: int) -> int:
        rev = 0
        sign = 1 if x > 0 else -1
        x = abs(x)

        while x != 0:
            digit = x % 10
            x //= 10

            # Check overflow for 32-bit signed integer
            if rev > (2**31 - 1) // 10:
                return 0

            rev = rev * 10 + digit

        return sign * rev
