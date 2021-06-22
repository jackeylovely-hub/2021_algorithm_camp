/* ������������ķ��������򻯵ڶ���ѭ����
    ����ȽϷ���һ������������±�����⣬���Բ�����ԭ����֮ǰ����ķ������򻯣�
    nums[0,1,3,2,1,1]
    nums[0,1,1,0,1,1]
    ����[L,R]
    for  R  (1,n)
        for L (1,R)
            if  s[R]-s[L-1] = k;
                    ans += 1;

   �򻯣�   �̶����ѭ���������ڲ�ѭ������ʲô������
                  ����ÿ��R(1,n)�м���L(1,R)ʹ��s[R]-s[L-1] = k��
                  ����ÿ��i(1,n)�м���j(1,i)ʹ��s[i]-s[j-1] = k��
                   ����ÿ��i(1,n)�м���j(0, i-1)ʹ��s[i]-s[j] = k;
                                                                       s[j] = k-s[i];
                   ��һ������s���ҵ�������k-s[i]����������.
*/
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        //���������±��0~n:��0��ʼ������n+1��
        vector<int> sum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + nums[i] % 2;
        }
        //����nums[1,1......1]ȫ��1��sum[1,2,3......n],��countֻ�迪��n��С�͹��ˣ�
        //�������count[sum[n]]=count[n];
        vector<int> count(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            count[sum[i]]++;
        }
        //
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            //sum[i]-sum[j]==k;
            //sum[j] == sum[i] - k;
            //�ڽ��������±�֮ǰ��Ҫȷ�� >= 0,��Ҫ�����ж�;
            if (sum[i] - k >= 0) {
                ans += count[sum[i] - k];
            }
        }
        return ans;
    }
};