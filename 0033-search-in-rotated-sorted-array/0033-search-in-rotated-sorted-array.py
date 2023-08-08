class Solution:
    def search(self, nums: List[int], target: int) -> int:
        s = 0
        e = len(nums) - 1
        while s <= e:
            mid = (s + e) // 2
            if nums[mid] == target:
                return mid
            if nums[mid] >= nums[s]:
                if target >= nums[s] and target < nums[mid]:
                    e = mid - 1
                else:
                    s = mid + 1
            else:
                if target > nums[mid] and target <= nums[e]:
                    s = mid + 1
                else:
                    e = mid - 1
        return -1
