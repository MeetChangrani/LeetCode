class Solution:
    def firstMissingPositive(self, nums):
        n = len(nums)

        # Step 1: Place each number in its correct index position
        # For a number x, correct position is index x-1
        for i in range(n):
            while 1 <= nums[i] <= n and nums[nums[i] - 1] != nums[i]:
                correct_index = nums[i] - 1
                nums[i], nums[correct_index] = nums[correct_index], nums[i]

        # Step 2: Find first index where value != index+1
        for i in range(n):
            if nums[i] != i + 1:
                return i + 1

        # Step 3: If all positions are correct, missing number is n+1
        return n + 1
