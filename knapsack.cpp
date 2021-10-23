#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll knapSack( ll W, ll wt[], ll p[], ll n)
{

    ll i, w;
    ll k[n+1][W+1];
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i==0 || w==0)
            {
                k[i][w] = 0;

            }
            else if (wt[i-1] <= w)
            {

                k[i][w] = max((p[i-1] + k[i-1][w-wt[i-1]]),  k[i-1][w]);

            }
            else
            {
                k[i][w] = k[i-1][w];

            }
        }

    }
    return k[n][W];
}

int main()
{
    ll n,cap,i;
    cin>>n;
    cin>>cap;
    ll p[n+1],wt[n+1];

    for(i=0; i<n; i++)
    {
        cin>>wt[i]>>p[i];
    }

    cout<<knapSack(cap, wt, p, n)<<endl;

    return 0;
}
/*
input
5 6

1 10
2 5
2 6
4 50
5 5
output=60
*/
