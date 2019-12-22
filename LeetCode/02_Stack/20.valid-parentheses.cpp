/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) {
            return true;
        }

        if ((s.at(0) == ')') ||
            (s.at(0) == '}') ||
            (s.at(0) == ']'))
        {
            return false;
        }

        std::stack<char> charStack;
        for (std::string::iterator ite = s.begin(); ite != s.end(); ++ite)
        {
            // open brackets
            if ((*ite == '(') ||
                (*ite == '{') ||
                (*ite == '[')) {
                charStack.push(*ite);
                continue;
            }

            if (charStack.empty())
            {
                return false;
            }

            // closed brackets check
            char popChar = charStack.top();
            if ((*ite == ')') && (popChar != '('))
            {
                return false;
            }
            if ((*ite == '}') && (popChar != '{'))
            {
                return false;
            }
            if ((*ite == ']') && (popChar != '['))
            {
                return false;
            }
            // closed in the correct order
            charStack.pop();
        }
        if (!charStack.empty())
        {
            return false;
        }
        return true;
    }
};
// @lc code=end

