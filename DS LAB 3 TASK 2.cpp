#include <iostream>
using namespace std;

int main()
{
    // Create a pointer for a character
    char* ch;

    // Allocate memory for one character
    ch = new char;

    // Ask user to enter a character
    cout << "Enter a character: ";
    cin >> *ch;

    // Display the stored character
    cout << "Stored character is: " << *ch << endl;

    // Free the allocated memory
    delete ch;

    // Make pointer safe by setting it to nullptr
    ch = nullptr;

    return 0;
}
