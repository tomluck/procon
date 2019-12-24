/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> numMap;
        for (int i = 0; i != nums.size(); ++i)
        {
            numMap.insert(std::make_pair(nums[i], i));
        }

        vector<int> returnValues;
        for (int i = 0; i != nums.size(); ++i)
        {
            std::map<int, int>::iterator ite = numMap.find(target - nums[i]);
            if ((ite != numMap.end()) && (i != ite->second))
            {
                returnValues.push_back(i);
                returnValues.push_back(ite->second);
                return returnValues;
            }
        }
        return returnValues;
    }
};
// @lc code=end

