#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Using priority queue to sort the array elems in ascending order to find Kth smallest element
int Find_Kth_Smallest(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, less<int>> pq;

    for (int num : arr)
    {
        pq.push(num);
        if (pq.size() > k)
        {
            pq.pop(); //(k-1)th elem
        }
    }

    return pq.top(); // kth elem is returned
}

int main()
{
    int n, k;

    // Taking input from user
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the value of K: ";
    cin >> k;

    // checking if the input is valid
    if (n <= 0 || k <= 0 || k > n)
    {
        cout << "Invalid input.\n";
        return 1;
    }

    vector<int> arr(n);
    // storing the elements inside a vector
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    int kth = Find_Kth_Smallest(arr, k);
    cout << "The " << k << "th smallest element is: " << kth << "\n";

    return 0;
}
