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
        if ((n + 2) % 2 != 0 && k != 1)
            cout << "NO\n";
        else
        {
            cout << "YES\n";
            int now = 1;
            for (int i = 0; i < n; i++)
            {
                for (int i = 0; i < k; i++)
                    cout << now + i * n << " ";
                cout << "\n";
                now++;
            }
        }
    }
}