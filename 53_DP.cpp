//最大子数组
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
    int n,args;
    cin>>n;
    while (n--)
    {
        cin>>args;
        nums.push_back(args);
    }
    ll dp[MAX__] = {0};
    
    return 0;
}