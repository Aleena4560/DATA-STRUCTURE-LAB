#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int key) {
    if (size == 0)
        return -1;

    if (arr[size - 1] == key)
        return size - 1;

    return linearSearch(arr, size - 1, key);
}

int main() {
    int arr[] = {5, 10, 15, 20, 25};
    int size = 5;
    int key;

    cout << "Enter number to search: ";
    cin >> key;

    int result = linearSearch(arr, size, key);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found\n";

    return 0;
}