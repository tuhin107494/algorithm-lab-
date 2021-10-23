#include<bits/stdc++.h>
using namespace std;
vector<pair<int,float>>v;
int cap;
void fknapsack(vector<pair<int,float>>v, int cap,int n)
{
    int i;
    float sum=0;
    for(i=0; i<n; i++)
    {
        if(v[i].first<=cap)
        {
            sum+=v[i].first*v[i].second;
            cap-=v[i].first;
        }
        else
        {
            sum+=cap*v[i].second;
            break;
        }
    }
    cout<<"total profit ="<<sum<<endl;
}
bool sortbysecond_element(const pair<int,int> &a,
               const pair<int,int> &b)
{
    return (a.second > b.second);
}

int main()
{
    int n,m,cap,i;
    vector<pair<int,float>>v;

    cin>>n;
    cin>>cap;
    int p[n+1],wt[n+1];
    for(i=0; i<n; i++)
    {
        cin>>wt[i];
    }
    for(i=0; i<n; i++)
    {
        cin>>p[i];
    }

    for(i=0; i<n; i++)
    {
        v.push_back(make_pair(wt[i],(p[i]/(wt[i]*1.0))));
    }
    sort(v.begin(),v.end(),sortbysecond_element);

    fknapsack(v,cap,n);

    return 0;
}

/*
5 6
1 2 2 4 5
10 5 5 50 5
output:
total profit =62.5
*/
