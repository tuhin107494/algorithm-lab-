
#include<bits/stdc++.h>
using namespace std;
string a, b;
int lcs[1000][1000];
int LCS(int i, int j)
{
    if(a[i]=='\0' or b[j]=='\0') return 0;
    else if(lcs[i][j]!=-1)return lcs[i][j];
    else if(a[i] == b[j])
    {
        return lcs[i][j]=1+LCS(i+1, j+1);
    }
    else
    {
        return lcs[i][j]=max(LCS(i+1, j), LCS(i, j+1));
    }

}
int main()
{
    cout << "Enter the First String: ";
    cin >>a;
    cout << "\nEnter the Second String: ";
    cin >> b;
    memset(lcs,-1,sizeof(lcs));
    int Max = LCS(0, 0);
    cout << "\nLongest Common Subsequence length is: " << Max << endl;
}
