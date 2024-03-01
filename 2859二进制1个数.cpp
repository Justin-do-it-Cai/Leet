#include<iostream>
#include<vector>
using namespace std;
vector<int> nums = {5,10,1,5,2};
int k = 1;
int count_1(int it)
{
    int res = 0;
    while(it!=0)
    {
        if ((it&1) == 1)
        {
            res++;
            it >>= 1;
        }
        else it >>= 1;
    }
    return res;
}
int main()
{
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (count_1(i) == k)
        {
            ans += nums[i];
        }
    }
    cout<<ans;
    return 0;
}