#include <iostream>
#include <string>
#include <sstream>

void task1();
std::string Dec_To_S(int n);

void task2();
void Dec_To_Sixt(int n);

void task3();
void static DecTo_N_(int n);

void task4();
std::string AddBinary(std::string binary1, std::string binary2);


int main() {
	setlocale(LC_ALL, "Ukrainian");

	int choice = 0;

	while (choice != 5) {

		std::cout << "Оберiть завдання: "
			"\n1.Task1"
			"\n2.Task2"
			"\n3.Task3"
			"\n4.Task4"
			"\n5.Exit" << std::endl;

		std::cin >> choice;

		switch (choice) {
			case 1: {
				task1();		// Задание превращения числа 143 из десятичной в двоичную СС;
				break;
			}
			case 2: {
				task2();		// Задание превращения числа 2288 из десятичной в шестнадцатиричную СС;
				break;
			}
			case 3: {
				task3();		// Задание превращения из десятичной в двенадцатиричную СС;
				break;
			}
			case 4: {
				task4();		// Задание сложения двух чисел 143 и 2288 в двоичной СС;
				break;
			}
			case 5: {
				std::cout << "Програма завершена!";
				break;
			}
			default: {
				std::cout << "Невiрний варiант, спробуйте ще раз";
			}
		}
	}
}

void task1() {
	int number = 143;
	std::cout << "Число number = " << number << std::endl;

	std::cout << "Перетворене число " << number << " у двоiчну СС = " << Dec_To_S(number) << std::endl;
	std::cout << "Перетворене число " << number << " у шiстнадцятиричну СС = "; Dec_To_Sixt(number);
	
	std::cout << "\n";
}

std::string Dec_To_S(int n) {
	std::string binary;
	int temp = 0;


	while (n > 0) {

		binary.push_back('0' + n % 2);
		n /= 2;
	}

	std::reverse(binary.begin(), binary.end());

	return binary;
}

void task2() {
	int number = 2288;

	std::cout << "Число = " << number << std::endl;

	std::cout << "Перетворене число " << number << " у двоiчну СС = " << Dec_To_S(number) << std::endl;
	std::cout << "Перетворене число " << number << " у шiстнадцятиричну СС = "; Dec_To_Sixt(number);

	std::cout << "\n";
}
void Dec_To_Sixt(int n) {
	std::string binary;
	int temp = 0;


	while (n > 0) {

		if (n % 16 < 10) {
			binary.push_back('0' + n % 16);
			n /= 16;
		}
		else if (n % 16 == 10) {
			binary.push_back('A' + n % 16 - 10);
			n /= 16;

		}
		else if (n % 16 == 11) {
			binary.push_back('B' + n % 16 - 11);
			n /= 16;
		}
		else if (n % 16 == 12) {
			binary.push_back('C' + n % 16 - 12);
			n /= 16;
		}
		else if (n % 16 == 13) {
			binary.push_back('D' + n % 16 - 13);
			n /= 16;
		}
		else if (n % 16 == 14) {
			binary.push_back('E' + n % 16 - 14);
			n /= 16;
		}
		else if (n % 16 == 15) {
			binary.push_back('F' + n % 16 - 15);
			n /= 16;
		}

	}

	std::reverse(binary.begin(), binary.end());

	std::cout << binary;
}

void task3() {
	int in;
	std::cout << "Уведiть число: ";
	std::cin >> in;
	std::cout << "Змiнене число: ";

	DecTo_N_(in);

	std::cout << std::endl;
}

void static DecTo_N_(int n) {
	std::string binary;
	int temp = 0;


while (n > 0) {

	if (n % 12 < 10) {
		binary.push_back('0' + n % 12);
		n /= 12;
	}
	else if (n % 12 == 10) {
		binary.push_back('A' + n % 12 - 10);
		n /= 12;

	}
	else if (n % 12 == 11) {
		binary.push_back('B' + n % 12 - 11);
		n /= 12;
	}

}

	std::reverse(binary.begin(), binary.end());

	std::cout << binary;
}

void task4() {
	int number1 = 143;
	int number2 = 2288;
	std::string sum = AddBinary(Dec_To_S(number1), Dec_To_S(number2));

	std::cout << "Сума чисел " << number1 << " i " << number2 << " у двійковій системі дорівнює " << sum;
	
}

std::string AddBinary(std::string binary1, std::string binary2) {
	std::string result = "";
	int temp = 0;

	int i = binary1.length() - 1;
	int j = binary2.length() - 1;

	while (i >= 0 || j >= 0 || temp == 1) {
		int sum = temp;
		if (i >= 0)
			sum += binary1[i--] - '0';
		if (j >= 0)
			sum += binary2[j--] - '0';

		result = char(sum % 2 + '0') + result;
		temp = sum / 2;
	}

	return result;
}
