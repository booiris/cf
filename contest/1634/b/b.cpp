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
int ini[100005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        ll x, y;
        cin >> n >> x >> y;
        for (int i = 0; i < n; i++)
            cin >> ini[i];
        for (int i = 0; i < n; i++)
        {
            x ^= ini[i];
        }
        if (((x & 1) == (y & 1)))
            cout << "Alice\n";
        else
            cout << "Bob\n";
    }
}