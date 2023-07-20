#include <iostream>
#include <set>
using namespace std;

int main()
{
    int myElems[] = {90, 25, 28, 33, 31, 23, 32, 32, 28, 36, 90, 42, 36, 10, 8, 58, 20, 36, 30, 41, 56, 68, 34, 26, 16, 13, 20, 1, 9};
    cout << "Array elements" << endl;
    for (int i : myElems)
        cout << i << " ";
    cout << "\n";
    int size = sizeof(myElems) / sizeof(myElems[0]);
    cout << "The number of elements in the array " << size << endl;
    set<int> n;
    for (int i = 0; i < size; i++)
        n.insert(myElems[i]);
    cout << "The number of uniquue elemnts in the array is " << n.size() << endl;
    return 0;
}
