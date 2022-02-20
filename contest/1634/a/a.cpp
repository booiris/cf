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
char ini[105];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        cin >> ini;
        if (k == 0)
        {
            cout << 1 << "\n";
            continue;
        }
        bool flag = 0;
        for (int i = 0; i < n / 2; i++)
        {
            if (ini[i] != ini[n - i - 1])
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            cout << 2 << "\n";
        else
            cout << 1 << "\n";
    }
}