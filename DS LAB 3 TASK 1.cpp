#include <iostream>
using namespace std;

// Structure 
struct Product
{
    string name;
    int code;
    float price;
};

int main()
{
    int n;
    cout << "***********************************************************" << endl;
    cout << "============| GROCERY STORE MANAGEMENT SYSTEM |============" << endl;
    cout << "***********************************************************" << endl;
    cout << endl;
    cout << "Enter number of products: ";
    cin >> n;

    // Dynamic memory allocation for n products
    Product* products = new Product[n];

    // Input product details
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter the following details of product " << i + 1 << endl;

        cout << "Name: ";
        cin.ignore();
        getline(cin, products[i].name);

        cout << "Code: ";
        cin >> products[i].code;

        cout << "Price: ";
        cin >> products[i].price;
    }

    // Displaying product details
    cout << "\n===== Product List =====\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\nProduct " << i + 1 << endl;
        cout << "Name  : " << products[i].name << endl;
        cout << "Code  : " << products[i].code << endl;
        cout << "Price : " << products[i].price << endl;
    }

    // Free dynamically allocated memory
    delete[] products;

    return 0;
}
