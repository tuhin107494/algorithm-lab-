#include<bits/stdc++.h>
using namespace std;
int  merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++){
        L[i] = arr[l+ i];}
    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1+ j];}

    i = 0;
    j = 0;
    k = l;
while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

 int  mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m =(r+l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
int  printArray(int A[], int n)
{
    int i;
    for (i=0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
  int n,i=0,j,k,f,g,h;
cin>>n;
int arr[n];
for(i=0;i<n;i++)
{
    cin>>arr[i];
}
    mergeSort(arr, 0, n- 1);

    printf("\nSorted array is \n");
    printArray(arr,n);
    return 0;
}
/*
5
5 4 6 4 3
output
sorted array is 3 4 4 5 6
*/
