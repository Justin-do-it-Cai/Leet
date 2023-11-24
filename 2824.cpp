#include<iostream>
using namespace std;
const int MAXN = 500;
int nums[MAXN] = {0};
int main()
{
    int n,target;
    cin>>n>>target;
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    int ans = 0;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] < target)
            {
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
/*
5 2
-1 1 2 3 1
output:3

7 -2
-6 2 5 -2 -7 -1 3
output:10
*/