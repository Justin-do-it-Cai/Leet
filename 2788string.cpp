#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
vector<string> words = {"one.two.three", "four.five", "six"};
char separator = '.';
int main()
{
    vector<string> res;
    for (string &word : words)
    {
        stringstream ss(word);
        string sub;
        while (getline(ss, sub, separator))
        {
            if (!sub.empty())
            {
                res.push_back(sub);
            }
        }
    }
    for (string &word : res)
    {
        cout << word << endl;
    }
    return 0;
}

// class Solution:
//     def splitWordsBySeparator(self, words: List[str], separator: str) -> List[str]:
//         res = []
//         for word in words:
//             res += [sub for sub in word.split(separator) if len(sub)]
//         return res
