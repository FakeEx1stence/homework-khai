#include <iostream>

using namespace std;

int main() { // Start of main function
	double X, A, Y, B = 0; // Declaration of variables
	//////////////////////////////////////|
	cout << "Enter a mass of candies : ";
	cin >> X;
	cout << "Enter a price of candies : ";
	cin >> A;
	cout << "Enter a mass of cookies : ";
	cin >> Y;
	cout << "Enter a price of cookies : ";
	cin >> B; 
	//////////////////////////////////////|   Initializating a variables
	double PricePerMass1 = A / X;
	double PricePerMass2 = B / Y;

	cout << "Price per 1 kg of candies is " << PricePerMass1 << endl;
	cout << "Price per 1 kg of cookies is " << PricePerMass2 << endl;

	cout << "The price of candies is " << PricePerMass1 / PricePerMass2 << " more than cookies" << endl;

} // End of this code