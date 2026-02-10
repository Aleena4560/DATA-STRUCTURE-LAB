#include <iostream>
using namespace std;

// Function to swap two numbers 
void swap(int* a, int* b)
{
    int temp;

    // Store value of a in temp
    temp = *a;

    // Put value of b in a
    *a = *b;

    // Put value of temp in b
    *b = temp;
}

int main()
{
    int x, y;

    // Input two numbers
    cout << "Enter first number: ";
    cin >> x;

    cout << "Enter second number: ";
    cin >> y;

    // Display before swap
    cout << "\nBefore swapping:\n";
    cout << "x = " << x << ", y = " << y << endl;

    // Call swap function 
    swap(&x, &y);

    // Display after swap
    cout << "\nAfter swapping:\n";
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}
