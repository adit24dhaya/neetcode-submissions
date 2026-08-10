class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        l = 0
        r = len(nums)-1

        newarr = []

        while l <= r :
            if abs(nums[l]) > abs(nums[r]):
                newarr.append(nums[l]**2)
                l += 1
            else:
                newarr.append(nums[r]**2)
                r -=1
        return newarr[::-1]