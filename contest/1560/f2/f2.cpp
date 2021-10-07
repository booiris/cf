#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
char ini[1005];
int len, k;
int dp[15];
int num[15];
int res;
bool dfs(int depth, int cnt, int now, bool up)
{
    if (depth >= len) {
        res = min(res, now);
        return 1;
    }
    for (int i = 0; i <= 9; i++) {
        if (up) {
            int temp_now = now * 10 + i;
            if (dp[depth] < temp_now)
                continue;
            int temp_cnt = cnt;
            if (num[i] == 0) {
                temp_cnt++;
                if (temp_cnt > k)
                    continue;
            }
            num[i]++;
            bool flag = dfs(depth + 1, temp_cnt, temp_now, 1);
            num[i]--;
            if (flag) {
                dp[depth] = temp_now;
                return 1;
            };
        } else {
            if (i < ini[depth] - '0')
                continue;
            int temp_now = now * 10 + i;
            if (dp[depth] < temp_now)
                continue;
            int temp_cnt = cnt;
            if (num[i] == 0) {
                temp_cnt++;
                if (temp_cnt > k)
                    continue;
            }
            num[i]++;
            bool temp_up = i > ini[depth] - '0' ? 1 : 0;
            bool flag = dfs(depth + 1, temp_cnt, temp_now, temp_up);
            num[i]--;
            if (flag) {
                dp[depth] = temp_now;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> ini >> k;
        for (int i = 0; i <= 10; i++)
            dp[i] = 1111111112, num[i] = 0;
        res = 1111111112;
        len = strlen(ini);
        for (int i = ini[0] - '0'; i <= 9; i++) {
            num[i] = 1;
            dfs(1, 1, i, i == ini[0] - '0' ? 0 : 1);
            num[i] = 0;
        }
        cout << res << "\n";
    }
}