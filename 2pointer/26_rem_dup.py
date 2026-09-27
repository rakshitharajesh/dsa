class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        replace = 1
        for i in range(len(nums)):
            if nums[i] == nums[replace - 1]:
                continue
            nums[replace] = nums[i]
            replace += 1
        return replace
        