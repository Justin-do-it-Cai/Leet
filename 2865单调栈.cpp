// 因此对于每个索引 i，可以将数组分为两部分处理，即保证数组的左侧构成非递减，右侧构成非递增。为了使得数组元素尽可能大，此时 heights[i]应取值为 maxHeights[i]
// 设区间 [0,i]构成的非递减数组元素和最大值为 prefix[i]，区间 [i,n−1]构成的非递增数组元素和最大值为 suffix[i]，此时构成的山状数组的元素之和即为prefix[i]+suffix[i]−maxHeights[i]。
//单调栈+动态规划
// prefix[i] =  prefix[i−1]+heights[i],       if heights[i]≥heights[i−1]
//              heights[i]×(i−j)+prefix[j],   if heights[i]<heights[i−1]
// 其中 j 是最后一座塔左边第一个高度小于等于 heights[i] 的塔的下标。我们可以使用单调栈来维护这个下标。

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        stack<int> stk;
        vector<int> left(n, -1);
        vector<int> right(n, n);
        for (int i = 0; i < n; ++i) {
            int x = maxHeights[i];
            while (!stk.empty() && maxHeights[stk.top()] > x) {
                stk.pop();
            }
            if (!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; ~i; --i) {
            int x = maxHeights[i];
            while (!stk.empty() && maxHeights[stk.top()] >= x) {
                stk.pop();
            }
            if (!stk.empty()) {
                right[i] = stk.top();
            }
            stk.push(i);
        }
        long long f[n], g[n];
        for (int i = 0; i < n; ++i) {
            int x = maxHeights[i];
            if (i && x >= maxHeights[i - 1]) {
                f[i] = f[i - 1] + x;
            } else {
                int j = left[i];
                f[i] = 1LL * x * (i - j) + (j != -1 ? f[j] : 0);
            }
        }
        for (int i = n - 1; ~i; --i) {
            int x = maxHeights[i];
            if (i < n - 1 && x >= maxHeights[i + 1]) {
                g[i] = g[i + 1] + x;
            } else {
                int j = right[i];
                g[i] = 1LL * x * (j - i) + (j != n ? g[j] : 0);
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, f[i] + g[i] - maxHeights[i]);
        }
        return ans;
    }
};

