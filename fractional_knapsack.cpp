#include<bits/stdc++.h>
using namespace std;
vector<pair<int,float>>solution;
vector<pair< pair<int,int>,float > >v;
int cap;
void fknapsack(vector<pair< pair<int,int>,float > >v, int cap,int n)
{
    int i;
    float sum=0;
    for(i=0; i<n; i++)
    {
        if(v[i].first.first<=cap)
        {
            sum+=v[i].first.first*v[i].second;
            cap-=v[i].first.first;
             solution.push_back({v[i].first.second,v[i].first.first*v[i].second});

        }
        else
        {
            sum+=cap*v[i].second;
            solution.push_back({v[i].first.second,(cap*v[i].second)});
            break;
        }
    }
    cout<<"total profit ="<<sum<<endl;
    cout<<"Solution vector"<<endl;
    for(int i=0;i<solution.size();i++)
    {
        cout<<solution[i].first<<" "<<solution[i].second<<endl;
    }
}
bool sortbysecond_element(const pair< pair<int,int>,float >  &a,
               const pair< pair<int,int>,float >  &b)
{
    return (a.second > b.second);
}

int main()
{
    int n,m,cap,i;


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
        v.push_back({{wt[i],i+1},(p[i]/(wt[i]*1.0))});
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
solution vector
4 50
1 10
2 2.5
*/
