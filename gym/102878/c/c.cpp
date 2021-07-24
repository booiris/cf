#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int n;
int a[1005];
ll dp[1005][1005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    if(n==1)
    {
        cout<<a[0]<<endl;
        return 0;
    }
    for(int i=n;i<2*n;i++)
        a[i]=a[i-n];
    for(int len=2;len<n;len++)
    {
        for(int i=0;i<2*n;i++)
        {
            int s=i,e=i+len;
            if(e>=2*n)
                break;
            for(int j=s+1;j<=e-1;j++)
            {
                dp[s][e]=max(dp[s][e],dp[s][j]+dp[j][e]+1LL*a[j]*a[s]*a[e]); 
            }
        }
    }
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<i+n;j++)
        {
            ll key= max(1LL*a[i]*a[j]*a[j]+a[j],1LL*a[j]*a[i]*a[i]+a[i]);
            int s=j%n,e=s+n-(j-i);
            ans=max(ans,dp[s][e]+dp[i][j]+key);          
        }
    } 
    cout<<ans<<endl;
}
