/*
 * @lc app=leetcode.cn id=232 lang=cpp
 * @lcpr version=
 *
 * [232] 用栈实现队列
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class MyQueue
{
public:
    stack<int> stIn;
    stack<int> stOut;
    MyQueue() {}

    void push(int x) { stIn.push(x); }

    int pop()
    {
        if (!stOut.empty())
        {
            int res = stOut.top();
            stOut.pop();
            return res;
        }
        else
        {
            while (!stIn.empty())
            {
                stOut.push(stIn.top());
                stIn.pop();
            }
            int res = stOut.top();
            stOut.pop();
            return res;
        }
    }

    int peek()
    {
        if (!stOut.empty())
        {
            return stOut.top();
        }
        else
        {
            while (!stIn.empty())
            {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        return stOut.top();
    }

    bool empty()
    {
        return (stOut.empty() && stIn.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

/*
// @lcpr case=start
// ["MyQueue", "push", "push", "peek", "pop", "empty"][[], [1], [2], [], [],
[]]\n
// @lcpr case=end

 */
