class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == "0" or num2 == "0":
            return "0"

        n1, n2 = len(num1), len(num2)
        result = [0] * (n1 + n2)

        # Reverse both strings to multiply from least significant digit
        num1 = num1[::-1]
        num2 = num2[::-1]

        for i in range(n1):
            for j in range(n2):
                digit = int(num1[i]) * int(num2[j])
                result[i + j] += digit

                # Handle carry
                result[i + j + 1] += result[i + j] // 10
                result[i + j] %= 10

        # Remove leading zeros
        while len(result) > 1 and result[-1] == 0:
            result.pop()

        # Convert digits back to string
        return ''.join(str(d) for d in result[::-1])
