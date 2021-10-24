#include<bits/stdc++.h>
using namespace std;
void rod_cutting(int n,int price[])
{
    int tab[n+1][n+1];
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i==0 or j==0)tab[i][j]=0;
            else if(j<i) tab[i][j] = tab[i-1][j];
            else
            {
                tab[i][j] = max(tab[i-1][j], price[i]+tab[i][j-i]);
            }
        }
    }

    int i = n, j = n;
    vector<int> cut_point;
    while(i> 0 and j>0)
    {
        if(tab[i][j] == tab[i-1][j]) i--;
        else
        {
            cut_point.push_back(i);
            j = j-i;
        }
    }

    cout<< "\nMaximum Profit is: " << tab[n][n] << endl;
    cout << "Cutting point is: ";
    for(int i=0; i<cut_point.size(); i++)
    {
        cout << cut_point[i] << ' ';
    }
    cout << endl;

}
int main()
{
    int n;

    cout << "Enter length of rod: ";
    cin >> n;

    cout << "\nprice of each length: ";
    int price[n+1];

    for(int i=1; i<=n; i++)
    {
        cin >> price[i];
    }
    rod_cutting(n,price);

}
