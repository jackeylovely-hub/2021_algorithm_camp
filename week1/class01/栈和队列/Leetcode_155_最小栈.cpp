//解法一：
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stk, f;
    MinStack() {

    }

    void push(int val) {
        stk.push(val);
        f.push(f.empty() ? val : min(val, f.top()));
    }

    void pop() {
        stk.pop();
        f.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return f.top();
    }
};
//解法二：常数项的优化
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stk, f;
    MinStack() {

    }

    void push(int val) {
        stk.push(val);
        if (f.empty() || f.top() >= val) f.push(val);
    }

    void pop() {
        if (stk.top() <= f.top()) f.pop();
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return f.top();
    }
};