/*
单调栈模板题：
         （1）思维套路：确定递增或者递减的关系——关键在于前面的不能影响后面决策
                                       在本题中若h[i-1]>h[i],则h[i-1]这个高度就无法影响到后面，需要作为冗余信息出栈。
         （2）代码套路：for(auto h : heights) 循环每个元素
                                        累加宽度变量
                                       while(栈顶与最近元素不满足单调性){
                                                 更新累加宽度；
                                                 弹栈（注意栈是否为空）；
                                                 更新最值；
                                       }
                                       若满足单调性则入栈；
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);//处理单调递增的情况，将栈内元素弹空
        stack<Rec> s;
        int ans = 0;
        for (auto h : heights) {
            int acc_width = 0;
            while (!s.empty() && s.top().height >= h) {
                acc_width += s.top().width;
                ans = max(ans, s.top().height * acc_width);
                s.pop();
            }
            s.push({ h,acc_width + 1 });
        }
        return ans;
    }
private:
    struct Rec {
        int height;
        int width;
    };
};