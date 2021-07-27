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
int n, m, k;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        int key = n * m / 2 - k;
        if (n & 1)
        {
            k -= m / 2;
            if (k < 0)
            {
                cout << "NO\n";
                continue;
            }
        }
        else if (m & 1)
        {
            key -= n / 2;
            if (key < 0)
            {
                cout << "NO\n";
                continue;
            }
        }
        if ((k & 1) || (key & 1))
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
}