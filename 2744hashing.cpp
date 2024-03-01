#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> words = {"cd", "ac", "dc", "ca", "zz"};
// string reverseString(string str) {
//     string reversed_str = "";
//     for (int i = str.length() - 1; i >= 0; i--) {
//         reversed_str += str[i];
//     }
//     return reversed_str;
// }
// int main()
// {
//     cout<<"asd";
//     int maxn = words.size();
//     int map[500] = {0};
//     int ans = 0;
//     for (int i = 0; i < maxn; i++)
//     {
//         if (map[i] == 0)
//         {
//             for (int j = i+1; j < maxn; j++)
//             {
//                 if (words[i] == reverseString(words[j]))
//                 {
//                     map[i] = 1;
//                     map[j] = 1;
//                     ans++;
//                 }
//             }
//         }
//     }
//     cout<<ans;
//     return 0;
// }

int main()
{
    int ans = 0;
    bool seen[26][26]{};
    for (auto &s : words)
    {
        int x = s[0] - 'a';
        int y = s[1] - 'a';
        if (seen[y][x])
        {
            ans++; // s 和 seen 中的 y+x 匹配
        }
        else
        {
            seen[x][y] = true;
        }
    }
    cout<<ans<<endl;
    return 0;
}
