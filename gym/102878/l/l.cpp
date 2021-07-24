#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int n, m;
int s[1005][1005], p[1005][1005];
int dp[1005][1005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d%d", &s[i][j], &p[i][j]);
        }
    }
    memset(dp, INF, sizeof dp);
    for (int i = 0; i < m; i++)
    {
        dp[0][s[0][i]] = p[0][i];
    }
    for (int i = 1; i < n; i++)
    {
        int key = INF, now = 1000;
        int key1 = INF;
        for (int j = m - 1; j >= 0; j--)
        {
            while (now >= s[i][j])
            {
                dp[i][now] = min(dp[i][now], dp[i - 1][now] + key1);
                key = min(key, dp[i - 1][now]);
                now--;
            }
            key1 = min(key1, p[i][j]);
            dp[i][s[i][j]] = min(dp[i][s[i][j]], key + p[i][j]);
        }
        while (now--)
            dp[i][now] = min(dp[i][now], dp[i - 1][now] + key1);
        //        for (int j = 1; j <= 10; j++)
        //            printf("%d ", dp[i][j] == INF ? -1 : dp[i][j]);
        //        printf("\n");
    }
    int maxp = 1;
    ll ans = INF;
    for (int i = 1; i <= 1000; i++)
    {
        if (ans * i > 1LL * dp[n - 1][i] * maxp)
        {
            ans = dp[n - 1][i], maxp = i;
        }
    }
    printf("%lld\n", ans);
}
