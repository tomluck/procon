/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // error handling
        if (head == NULL)
        {
            return false;
        }
        if (head->next == NULL) {
            return false;
        }

        // store already visit node
        vector<ListNode*> nodeVec;
        nodeVec.push_back(head);

        // confirm cycle
        ListNode *nextNode = head->next;
        while (nextNode != NULL)
        {
            if (nextNode->next == NULL)
            {
                return false;
            }

            vector<ListNode*>::iterator ite = find(nodeVec.begin(), nodeVec.end(), nextNode->next);
            size_t index = distance(nodeVec.begin(), ite);
            if (index != nodeVec.size())
            {
                // found already visit node
                return true;
            }

            nodeVec.push_back(nextNode);
            nextNode = nextNode->next;
        }

        return false;
    }
};
// @lc code=end

