// 最大子数组
/*input:
9
-2 1 -3 4 -1 2 1 -5 4
output:
6
*/
#include <iostream>
#include <vector>
const int MAX__ = 1e5;
typedef long long ll;
using namespace std;
int main()
{
    vector<int> nums;
    int n, args;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> args;
        nums.push_back(args);
    }
    ll dp[MAX__] = {0};
    dp[0] = nums[0];
    ll res = dp[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = max((ll)nums[i],dp[i-1]+nums[i]);//dp[i]为以nums[i]为结尾的最大子序列
        res = max(res, dp[i]);
    }
    cout << res;
    return 0;
}


//滚动数组
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//     int dp = nums[0];
//     int res = dp;
//     for (int i = 1; i < nums.size(); i++)
//     {
//         dp = max(nums[i],dp+nums[i]); 
//         res = max(res, dp);
//     }
//     return res;
//     }
// };

//python3:
// class Solution:
//     def maxSubArray(self, nums: List[int]) -> int:
//         dp = nums[0]
//         res = dp
//         for i in range(1, len(nums)):
//             dp = max(nums[i], dp + nums[i])
//             res = max(res, dp)
//         return res