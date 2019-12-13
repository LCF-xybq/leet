/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
class MyQueue {
    stack<int> s;
    stack<int> t;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res;
        if (!t.empty()) {
            res = t.top();
            t.pop();
        } else {
            while (!s.empty()) {
                t.push(s.top());
                s.pop();
            }
            res = t.top();
            t.pop();
        }
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        int res;
        if (!t.empty()) {
            res = t.top();
        } else {
            while (!s.empty()) {
                t.push(s.top());
                s.pop();
            }
            res = t.top();
        }
        return res;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty() && t.empty();
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

