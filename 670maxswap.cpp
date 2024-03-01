#include <iostream>
#include <stdio.h>
using namespace std;
int num = 2736;
int main()
{
    string s = to_string(num);
    int n = s.length();
    int max_idx = n - 1;
    int p = -1, q;
    for (int i = n - 2; i >= 0; i--)
    {
        if (s[i] > s[max_idx])
        { // s[i] 是目前最大数字
            max_idx = i;
        }
        else if (s[i] < s[max_idx])
        { // s[i] 右边有比它大的
            p = i;
            q = max_idx; // 更新 p 和 q
        }
    }
    if (p == -1)
    { // 这意味着 s 是降序的
        return num;
    }
    swap(s[p], s[q]); // 交换 s[p] 和 s[q]
    cout<<stoi(s);
// 设 num的十进制字符串为 s。算法如下：
// 倒序遍历 sss，同时维护最大数的下标 maxIdx。它只在遇到更大的数字才更新，遇到相同数字不会更新，从而满足上面讨论的「最后一个」。
// 如果发现 s[i]<s[maxIdx]，满足交换要求，我们先把这两个下标保存在变量 p 和q 中。注：p 在遍历前的初始值为−1。
// 继续向左遍历，如果又遇到 s[i]<s[maxIdx，就更新 p=i, q=maxIdx,因为 s[i] 越靠左越好，我们要交换的是从左到右第一个右边有比它大的数字。
// 遍历结束，如果无需交换，即 p=−1，那么直接返回 num。否则交换 s[p] 和 s[q]，然后把 s 转换成数字返回。
    return 0;
}
