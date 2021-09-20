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
int key[300005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i=1;i<300001;i++)
    {
        key[i] = key[i-1]^(i-1);
    }
    while (t--) {
        int a, b;
        cin >> a >> b;
        if(key[a]==b)
            cout<<a<<"\n";
        else if((b^key[a])!=a)
            cout<<a+1<<"\n";
        else
            cout<<a+2<<"\n";
    }
}
