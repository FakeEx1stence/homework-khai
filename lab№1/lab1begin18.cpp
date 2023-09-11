#include <iostream>

using namespace std;

int main() { // Main function(start of program)
    int x = 0;
    cout << "Enter a variable number : ";
    cin >> x;
    cout << "Answer is " << (4 * (pow(x - 3, 6)) - 7 * (pow(x - 3, 3)) + 2);
}
