/*
����ջģ���⣺
         ��1��˼ά��·��ȷ���������ߵݼ��Ĺ�ϵ�����ؼ�����ǰ��Ĳ���Ӱ��������
                                       �ڱ�������h[i-1]>h[i],��h[i-1]����߶Ⱦ��޷�Ӱ�쵽���棬��Ҫ��Ϊ������Ϣ��ջ��
         ��2��������·��for(auto h : heights) ѭ��ÿ��Ԫ��
                                        �ۼӿ�ȱ���
                                       while(ջ�������Ԫ�ز����㵥����){
                                                 �����ۼӿ�ȣ�
                                                 ��ջ��ע��ջ�Ƿ�Ϊ�գ���
                                                 ������ֵ��
                                       }
                                       �����㵥��������ջ��
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);//�������������������ջ��Ԫ�ص���
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