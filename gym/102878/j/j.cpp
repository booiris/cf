#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int key[6];
int f1,f2,f3,f4,f5;
int a1,a2,a3,a4,a5;
bool ans=0;
void solve()
{
    int temp=key[2]-key[1];
    for(int i=-2;i<=2;i++)
    {
        if(abs(temp+i)>100)
            continue;
        for(int j=-1;j<=1;j++)
        {   
            bool flag=0;
            int temp1=key[1]-(temp+i)+j;
            if(abs(temp1)>100)
                continue;
            for(int k=1;k<=5;k++)
            {
                int t=k*(temp+i)+temp1;
                if(abs(t-key[k])>1)
                {
                    flag=1;
                    break;
                }
            }
            if(!flag)
            {
                a2=temp+i;
                a1=temp1;
                ans=1;
                return;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>f1>>f2>>f3>>f4>>f5;
        for(int i=-100;i<=100&&!ans;i++)
        {
            for(int j=-100;j<=100&&!ans;j++)
            {
                for(int k=-100;k<=100&&!ans;k++)
                {
                    a5=i,a4=j,a3=k;
                    key[1]=f1-(i+j+k);
                    key[2]=f2-(16*i+8*j+4*k);
                    key[3]=f3-(81*i+27*j+9*k);
                    key[4]=f4-(256*i+64*j+16*k);
                    key[5]=f5-(625*i+125*j+25*k);
                    if((key[2]-key[1]<=102)&&(key[2]-key[1])>=-102)
                        solve();
                }
            }
        }
        cout<<a1<<" "<<a2<<" "<<a3<<" "<<a4<<" "<<a5<<endl;
//        for(int i=1;i<=5;i++)
//        {
//            int temp=a1*pow(i,0)+a2*pow(i,1)+a3*pow(i,2)+a4*pow(i,3)+a5*pow(i,4);
//            cout<<temp<<" ";
//        }
//        cout<<endl;
    }
}
