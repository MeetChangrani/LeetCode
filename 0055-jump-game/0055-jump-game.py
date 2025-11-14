class Solution:
    def canJump(self, nums):
        far = 0   # farthest index we can reach
        
        for i in range(len(nums)):
            if i > far:        # if we can't reach this index
                return False
            far = max(far, i + nums[i])   # update farthest reach
        
        return True
