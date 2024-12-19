#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;cin>>n>>m;
    vector dp(m+1,0);
    for(int i=1;i<=n;i++)
    {
        int v,w;cin>>v>>w;
        for(int j=m;j>=v;j--)
            dp[j]=max(dp[j],dp[j-v]+w);
    }
    cout<<dp[m]<<"\n";
    return 0;
}