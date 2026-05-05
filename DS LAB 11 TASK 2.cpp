#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int target) {
    if (left > right)
        return -1;

    int mid = (left + right) / 2;

    if (arr[mid] == target)
        return mid;
    else if (target < arr[mid])
        return binarySearch(arr, left, mid - 1, target);
    else
        return binarySearch(arr, mid + 1, right, target);
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;
    int key;

    cout << "Enter number to search: ";
    cin >> key;

    int result = binarySearch(arr, 0, size - 1, key);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found\n";

    return 0;
}