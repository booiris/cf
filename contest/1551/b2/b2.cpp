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
struct node
{
    int v, p;
} key[200005];
bool cmp(const node &x, const node &y) { return x.v < y.v; }
int ini[200005];
int ans[200005];
int cnt[200005];
int color[200005];
int n, k;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 0; i <= n; i++)
            cnt[i] = 0, color[i] = 1, ans[i] = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> ini[i];
            cnt[ini[i]]++;
        }
        int index = 0;
        for (int i = 0; i < n; i++)
        {
            if (cnt[ini[i]] >= k)
            {
                if (color[ini[i]] > k)
                    continue;
                ans[i] = color[ini[i]];
                color[ini[i]]++;
            }
            else
            {
                key[index].p = i;
                key[index].v = ini[i];
                index++;
            }
        }
        sort(key, key + index, cmp);
        int now = 1;
        for (int i = 0; i < index; i++)
        {
            ans[key[i].p] = now;
            now++;
            if (now > k)
                now = 1;
        }
        for (int i = 1; i < now; i++)
        {
            ans[key[index - i].p] = 0;
        }
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
}