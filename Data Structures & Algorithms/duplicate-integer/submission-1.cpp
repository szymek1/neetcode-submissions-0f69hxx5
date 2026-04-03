class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        vector<int> sorted_nums = nums;

        if (nums.size() == 0) {
            return false;
        }

        for (int i = 0; i < sorted_nums.size() - 1; ++i) {
            for (int j = 0; j < sorted_nums.size() - 1 - i; ++j) {
                if (sorted_nums[j] > sorted_nums[j+1]) {
                    int temp_num = sorted_nums[j];
                    sorted_nums[j] = sorted_nums[j+1];
                    sorted_nums[j+1] = temp_num;
                }
            }
        }

        for (int i = 0; i < sorted_nums.size() - 1; ++i) {
            if (sorted_nums[i] == sorted_nums[i+1]) {
                return true;
            }
        }
        return false;
    }
};