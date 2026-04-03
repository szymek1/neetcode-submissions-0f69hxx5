class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
        // it is good but it breaks the oroginal vector
        // and solution indexes are wrong
        sort(nums.begin(), nums.end());
        int top_id = 0; // smallest element index
        int rear_id = nums.size() - 1; // largest element index

        while (nums[top_id] + nums[rear_id] != target) {
            if (nums[top_id] + nums[rear_id] > target) {
                rear_id -= 1;
            } else if (nums[top_id] + nums[rear_id] < target) {
                top_id += 1;
            }
        }
        vector<int> solution = {top_id, rear_id};
        return solution;
        */
        unordered_map<int, int> seen;
        for (int i  = 0; i < nums.size(); ++i) {
            int target_difference = target - nums[i];
            if (seen.count(target_difference)) {
                return {seen[target_difference], i};
            }
            seen[nums[i]] = i;
        }
        return {};
    }
};
