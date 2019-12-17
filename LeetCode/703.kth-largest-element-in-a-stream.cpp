/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */

// @lc code=start
class KthLargest {
    // this implementation 9/10 cases passed.
    // not pass 10/10 cases.
private:
    vector<int> fNumVec;
    int fTarget;
public:

    KthLargest(int k, vector<int> &nums):
        fTarget(k)
    {
        if (nums.size() != 0) {
            fNumVec.resize(nums.size());
            std::copy(nums.begin(), nums.end(), fNumVec.begin());
            cout << "sort start in constructor" << endl;
            std::sort(fNumVec.begin(), fNumVec.end(), std::greater<int>());
            cout << "sort end in constructor" << endl;
        }
    }

    int add(int val) {
        fNumVec.push_back(val);
        if ((fNumVec.size() == 1) && (fTarget == 1)) {
            return fNumVec[0];
        }

        if (fTarget == 1) {
            // return largest element
            std::make_heap(fNumVec.begin(), fNumVec.end());
            return fNumVec[0];
        }
        else {
            cout << "sort start" << endl;
            std::sort(fNumVec.begin(), fNumVec.end(), std::greater<int>());
            cout << "sort end" << endl;
            cout << "return " << fNumVec[fTarget - 1] << endl;
            return fNumVec[fTarget - 1];
        }
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

