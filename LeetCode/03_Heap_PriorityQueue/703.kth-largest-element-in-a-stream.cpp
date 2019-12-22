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
    deque<int> fNumDeq;
    int fTarget;
public:

    KthLargest(int k, vector<int> &nums):
        fTarget(k)
    {
        if (nums.size() != 0) {
            fNumDeq.resize(nums.size());
            std::copy(nums.begin(), nums.end(), fNumDeq.begin());
            std::sort(fNumDeq.begin(), fNumDeq.end(), std::greater<int>());
        }
    }

    int add(int val) {
        cout << "val=" << val << ", ";
        if (fNumDeq.size() == 0)
        {
            fNumDeq.push_front(val);
            return val;
        }

        if (fNumDeq[fTarget - 1] <= val)
        {
            cout << "push_FRONT, ";
            fNumDeq.push_front(val);
            if (fTarget == 1) {
                return fNumDeq[fTarget - 1];
            }
            std::sort(fNumDeq.begin(), fNumDeq.begin() + fTarget, std::greater<int>());
        }
        else
        {
            cout << "push_BACK, ";
            fNumDeq.push_back(val);
            if (fTarget == 1)
            {
                return fNumDeq[fTarget - 1];
            }
            std::sort(fNumDeq.begin() + fTarget, fNumDeq.end(), std::greater<int>());
        }

        // std::sort(fNumDeq.begin(), fNumDeq.end(), std::greater<int>());
        // print(fNumDeq);
        cout << "fTarget=" << fTarget << ", return " << fNumDeq[fTarget - 1] << endl;
        return fNumDeq[fTarget - 1];
    }

    void print(deque<int> &intDeq) {
        cout << "deque elements: ";
        for (deque<int>::iterator ite = intDeq.begin(); ite != intDeq.end(); ++ite)
        {
            cout << *ite << " ";
        }
        cout << endl;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

