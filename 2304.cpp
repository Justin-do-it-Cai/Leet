#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 55;
int grid[MAXN][MAXN];
int moveCost[MAXN * MAXN][MAXN];
int dp[MAXN][MAXN]={0};
int main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < m * n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> moveCost[i][j];
        }
    }
    // int dp[m][n];
    int ans = INT_MAX;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0)
            {
                dp[i][j] = grid[i][j];
            }
            else
            {
                int mincost = INT_MAX;
                for (int k = 0; k < n; k++)
                {
                    mincost = min(dp[i - 1][k] + moveCost[grid[i - 1][k]][j] + grid[i][j], mincost);
                }
                dp[i][j] = mincost;
                if (i == m - 1)
                {
                    ans = min(mincost, ans);
                }
            }
        }
    }
    cout << ans;
    return 0;
}

/*
input:
3 2

5 3
4 0
2 1

9 8
1 5
10 12
18 6
2 4
14 3

output:
17

py:
rows = len(grid)
        cols = len(grid[0])
        dp = [[float("inf")] * cols for _ in range(rows)]

        for col in range(cols):
            dp[0][col] = grid[0][col]

        for row in range(1, rows):
            for col in range(cols):
                minCost = float("inf")
                for prevCol in range(cols):
                    newCost = dp[row - 1][prevCol] + moveCost[grid[row - 1][prevCol]][col] + grid[row][col]
                    minCost = min(minCost, newCost)

                dp[row][col] = minCost

            if row == rows - 1:
                minCost = float("inf")
                for col in range(cols):
                    minCost = min(minCost, dp[row][col])

                return minCost
*/