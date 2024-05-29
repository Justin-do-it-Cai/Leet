#include<iostream>
using namespace std;
int nums[4] = {1,1,1,2};
int main()
{
    int n = 4;
    vector<bool> f(n+1);
    f[0] = 1;
    f[1] = 0;
    f[2] = nums[0] == nums[1] ? 1 : 0;
    f[3] = (nums[0] + 1 == nums[1] && nums[0] + 2 == nums[2]) || (nums[0] == nums[1] && nums[1] == nums[2]) ? 1 : 0;
    for (int i = 4; i < n +1 ; i++)
    {
        if (nums[i-2] == nums[i-1] && f[i-2])
        {
            f[i] = 1;
        }
        else if ((nums[i-3] + 1 == nums[i-2] && nums[i-3] + 2 == nums[i-1] && f[i-3]) || (nums[i-3] == nums[i-2] && nums[i-2] == nums[i-1] && f[i-3]))
        {
            f[i] = 1;
        }
        else f[i] = 0;
    }
    if (f[n])
        cout<<"true";
    else cout<<"false";
    return 0;
}