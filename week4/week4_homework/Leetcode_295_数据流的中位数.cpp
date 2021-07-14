class MedianFinder {
public:
    priority_queue<int> down; // 大根堆
    priority_queue<int, vector<int>, greater<int>> up; // 小根堆
    MedianFinder() {

    }

    void addNum(int num) {
        //大根堆为空，或者num小于大根堆的堆顶，加入num
        if (down.empty() || num <= down.top())
            down.push(num);
        else
            up.push(num);
        //如果大根堆数量比小根堆数量多2,将大根堆的堆顶加入小根堆
        if (down.size() == up.size() + 2) {
            int top = down.top();
            down.pop();
            up.push(top);
        }
        else if (up.size() == down.size() + 1) {
            int top = up.top();
            up.pop();
            down.push(top);
        }
    }

    double findMedian() {
        if (up.size() == down.size())
            return (up.top() + down.top()) / 2.0;
        return down.top();
    }
};