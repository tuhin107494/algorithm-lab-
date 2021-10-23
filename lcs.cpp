#include<bits/stdc++.h>
#define FIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
char in[1000][1000];
int lcs[1000][1000];

void  print(string A,int i,int j)
{

    if(i==0||j==0)
    {
        return ;
    }
    if(in[i][j]=='D')
    {
        print(A,i-1,j-1);
        cout<<A[i-1];
    }
    else if(in[i][j]=='U')
    {
        print(A,i-1,j);
    }
    else print(A,i,j-1);
}

int lcs_length(string A,string B)
{

    int m,n,i,j,k;
    m=A.size();
    n=B.size();


    for(i=0; i<=m; i++)
    {
        for(j=0; j<=n; j++)
        {
            if(i==0||j==0)
            {
                lcs[i][j]=0;
            }
            else  if(A[i-1]==B[j-1])
            {
                lcs[i][j]=1+lcs[i-1][j-1];
                in[i][j]='D';
            }
            else if(lcs[i-1][j]>=lcs[i][j-1])
            {
                lcs[i][j]=lcs[i-1][j];
                in[i][j]='U';
            }
            else
            {
                lcs[i][j]=lcs[i][j-1];
                in[i][j]='L';
            }
        }
    }

    return lcs[m][n];
}
int main()
{
    FIO;
    string  a;
    string  b;

    cin>>a;
    cin>>b;

    cout<<lcs_length(a,b)<<endl;
    print(a,a.size(),b.size());

    return 0;
}

/*
abcd
bcfd
output
3
bcd
*/

