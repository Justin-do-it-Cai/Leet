#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> beans = {4,1,6,5};
int main()
{
    sort(beans.begin(),beans.end(),greater<int>());
    int maxsize = beans.size();
    long long total = 0;
    long long ans = 0;
    for (int i = 0; i < maxsize; i++)
    {
        total += beans[i];
        long long tmp = (i+1)*beans[i];
        if (ans < tmp)
        {
            ans = tmp;
        }
    }
    cout<< total - ans ;
    return 0;
}