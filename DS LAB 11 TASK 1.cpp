#include <iostream>
using namespace std;

int main() {
    int tickets[10] = {13579, 26791, 26792, 33445, 55555,
                       62483, 77777, 79422, 85647, 93121};
                       
    cout << "LOTTERY TICKET MATCHING PROGRAM \n";
    
    int number;
    cout << "Enter your 5-digit number: ";
    cin >> number;

    bool found = false;

    // Linear Search
    for (int i = 0; i < 10; i++) {
        if (tickets[i] == number) {
            found = true;
            break;
        }
    }

    // Final Conditions
    if (!found) {
        cout << "Invalid number! Not in ticket list.\n";
    }
    else if (number == 55555) {
        cout << "Congratulations! 55555 is the WINNING ticket!\n";
    }
    else {
        cout << "Better luck next time!\n";
    }

    return 0;
}