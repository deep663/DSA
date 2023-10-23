#include <iostream>
using namespace std;

void traverseArray(int arr[], int n)
{
    for(int i = 0; i<n; i++ )
    {
        cout<<arr[i]<<' ';
    }
}

const int n = 2;
const int m = 2;

void traverse2DArray(int arr[][m], int n)
{
    for(int i = 0; i< n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<arr[i][j]<<' ';
        }
    }
}


int main()
{
    // int arr[] = {1,2,3,4,5 };
    // int n = sizeof(arr)/sizeof(arr[0]);
    // traverseArray(arr, n);

    int arr2D[n][m] = {{1,2},{3,4}};
    traverse2DArray(arr2D,n);

}