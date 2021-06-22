/* 采用数组计数的方法，来简化第二重循环。
    这里比较烦的一个点就是数组下标的问题，可以采用在原数组之前补零的方法来简化；
    nums[0,1,3,2,1,1]
    nums[0,1,1,0,1,1]
    区间[L,R]
    for  R  (1,n)
        for L (1,R)
            if  s[R]-s[L-1] = k;
                    ans += 1;

   简化：   固定外层循环，考虑内层循环满足什么条件。
                  对于每个R(1,n)有几个L(1,R)使得s[R]-s[L-1] = k；
                  对于每个i(1,n)有几个j(1,i)使得s[i]-s[j-1] = k；
                   对于每个i(1,n)有几个j(0, i-1)使得s[i]-s[j] = k;
                                                                       s[j] = k-s[i];
                   在一个数组s中找到，等于k-s[i]的数的数量.
*/
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        //代表数组下标从0~n:从0开始长度是n+1；
        vector<int> sum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + nums[i] % 2;
        }
        //即便nums[1,1......1]全是1，sum[1,2,3......n],故count只需开到n大小就够了；
        //极端最大：count[sum[n]]=count[n];
        vector<int> count(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            count[sum[i]]++;
        }
        //
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            //sum[i]-sum[j]==k;
            //sum[j] == sum[i] - k;
            //在进入数组下标之前，要确保 >= 0,故要进行判断;
            if (sum[i] - k >= 0) {
                ans += count[sum[i] - k];
            }
        }
        return ans;
    }
};