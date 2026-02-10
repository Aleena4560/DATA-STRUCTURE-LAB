#include <iostream>
using namespace std;

int main()
{
    // Declare an array of 5 integers
    int arr[5] = {15, 54, 38, 40, 19};

    // Declare a pointer and point it to the first element of array
    int* ptr = arr;
    cout << "=======| PRINTING OF ARRAY |=======" << endl;
    cout << endl;
    // Use pointer to print array elements
    cout << "Array elements are:\n";

    for (int i = 0; i < 5; i++)
    {
        cout << *(ptr + i) << " ";
    }

    return 0;
}
