#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int n,m;
int s[1005][1005],p[1005][1005];
ll dp[1005][1005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>s[i][j]>>p[i][j];
    }
    for(int i=0;i<n;i++)
    {
        for(int k=1;k<=1000;k++)
            dp[i][k]=1e13;
    }
    for(int i=0;i<n;i++)
    {
        dp[0][s[0][i]]=p[0][i];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=1;k<=1000;k++)
            {
                if(k<s[i][j])
                    dp[i][k]=min(dp[i][k],dp[i-1][k]+p[i][j]);
                else
                    dp[i][s[i][j]]=min(dp[i][s[i][j]],dp[i-1][s[i][j]]+p[i][j]);
            }
        }
    }
    ll ans=1e13;
    int maxp=1;
    for(int i=1;i<=1000;i++)
    {
        if(dp[n-1][i]==1e13)
            continue;
        if(ans*i>dp[n-1][i]*maxp)
        {
            ans=dp[n-1][i];
            maxp=i;
        }
    }
    cout<<ans<<endl;
}
