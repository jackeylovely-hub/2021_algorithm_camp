class MedianFinder {
public:
    priority_queue<int> down; // �����
    priority_queue<int, vector<int>, greater<int>> up; // С����
    MedianFinder() {

    }

    void addNum(int num) {
        //�����Ϊ�գ�����numС�ڴ���ѵĶѶ�������num
        if (down.empty() || num <= down.top())
            down.push(num);
        else
            up.push(num);
        //��������������С����������2,������ѵĶѶ�����С����
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