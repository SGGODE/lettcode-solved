#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> largestDivisibleSubset(std::vector<int>& nums) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        std::vector<int> count(n, 1);
        std::vector<int> pre(n, -1);
        int max = 0, index = -1;
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] % nums[j] == 0) {
                    if (1 + count[j] > count[i]) {
                        count[i] = count[j] + 1;
                        pre[i] = j;
                    }
                }
            }
            if (count[i] > max) {
                max = count[i];
                index = i;
            }
        }
        std::vector<int> res;
        while (index != -1) {
            res.push_back(nums[index]);
            index = pre[index];
        }
        return res;
    }
};
