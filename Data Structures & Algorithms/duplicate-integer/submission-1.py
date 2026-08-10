class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        num_new = set(nums)
        if len(nums) != len(num_new):
            return True
        else:
            return False