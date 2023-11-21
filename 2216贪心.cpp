/*
美化数组
input：
5
1 1 2 3 5
output：
1
input：
6
1 1 2 2 3 3
output：
2
*/

#include<iostream>
#include<vector>
using namespace std;
const int MAXL = 1e5+5;
int main()
{
    vector<int> nums;
    int n,arg;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>arg;
        nums.push_back(arg);
    }
    int len = nums.size();
    int tag = 0,ans = 0;
    while(tag != len - 1)
    {
        if ((tag+ans) % 2 ==0)
        {
            if (nums[tag] == nums[tag+1])
            {
                ans++;
            }
        }
        tag++;
    }
    if ((len-ans) % 2 == 1)
    {
        ans++;
    }
    cout<<ans;
    return 0;
}