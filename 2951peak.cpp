//
// Created by Yutong Cai on 2024/5/28.
//

#include <iostream>
#include <vector>
using namespace std;
const int len = 150;
vector<int>  mountain;
int main()
{
    mountain.push_back(1);
    mountain.push_back(4);
    mountain.push_back(3);
    mountain.push_back(8);
    mountain.push_back(5);
    vector<int> ans;
    for (int i=1;i < mountain.size() - 1; i++){
        if(mountain[i] > mountain[i-1] && mountain[i]> mountain[i+1]) {
            ans.push_back(i);
        }
    }
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<endl;
    }
    return 0;
}
