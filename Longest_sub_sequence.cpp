#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void Longest_Sub( int *arr, int n )
{
    int  i, j, max = 0;
    vector<int> v1(n);
    fill(v1.begin(),v1.end(),1);
    for ( i = 1; i < n; i++ )
        for ( j = 0; j < i; j++ )
            if ( arr[i] > arr[j] && v1.at(i) < v1.at(j) + 1)
                v1.at(i) = v1.at(j) + 1;
    max = *max_element(v1.begin(),v1.end());

    int tmp = max;
    vector<int> nos; //stores indexes
    for( i = n - 1; i >= 0; --i )
    if( v1.at(i) == tmp )
    {
        nos.push_back( i );
        --tmp;
    }
    reverse( nos.begin(), nos.end());
    cout<<"\nLength of the Longest Increasing Subsequence is "<<max<<endl;
    cout<<"\nThe values of the longest Increasing Subsequence is: "<<endl;
    for(auto s:nos)
    {
        cout<<arr[s]<<endl;
    }
   /* Free memory to avoid memory leak */
   v1.clear();
   //return max;
}

int main()
{
    int arr[]={7 ,6, 1, 4, 5 ,2 ,3, 2 ,1 ,0 ,1 ,3 ,2 ,10, -2, -4, -6, 1, -5};
    int n = sizeof(arr) / sizeof(arr[0]);

    Longest_Sub(arr,n);

    return 0;
}
