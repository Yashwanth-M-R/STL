#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// creating a Values class to be used as a generic datatype to store values and use get_median method
class Values
{
public:
    int x;
    int size;
    // creating a vector
    vector<int> a;

    // method to take input from user
    void input()
    {
        cout << "Enter the size: ";
        cin >> size;
        cout << "Enter the values: ";
        for (int i = 0; i < size; i++)
        {
            cin >> x;
            // storing the values in the vector
            a.push_back(x);
        }
        // sorting
        sort(a.begin(), a.end());
    }

    // method to get median
    int get_median()
    {   
        if (size % 2 == 0) //incase even number of values in the container
        {
            return (a[(size / 2) - 1] + a[(size / 2)]) / 2;
        }
        else //odd number of values in container
        {
            return a[size / 2];
        }
    }
};

int main()
{
    Values v1;//creating an object v1 to store and retrieve median
    v1.input();
    int median = v1.get_median();
    cout << "The median is: " <<median << endl;
}
