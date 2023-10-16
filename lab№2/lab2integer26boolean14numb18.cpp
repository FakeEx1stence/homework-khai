#include <cmath>
#include <iostream>
#include <Windows.h>

using namespace std;

int main() { //Integer26
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int K = 0;
	int week = 0; //Ініціалізація змінних
	cout << "Введіть день(1 січня  - 31 грудня): ";
	cin >> K; //Присвоєння змінній K бажанного числа

	if (1 > K || K > 366) {
		cout << "Немає такого дня у році";
	}
	else{ //Визначення дня тижня умовами та операторами
		int week = (K + 6) % 7;
		
		if (week == 0) {
			cout << "Вівторок";
		}
		else if (week == 1) {
			cout << "Середа";
		}
		else if (week == 2) {
			cout << "Четвер";
		}
		else if (week == 3) {
			cout << "П'ятниця";
		}
		else if (week == 4) {
			cout << "Субота";
		}
		else if (week == 5) {
			cout << "Неділя";
		}
		else if (week == 6) {
			cout << "Понеділок";
		}
    }
	//Boolean14

	int A = 0, B = 0, C, i = 0;
	bool b = false;
	cout << "\nВведіть А : ";
	cin >> A; //Присвоєння змінній А бажанного числа
	cout << "Введіть B : ";
	cin >> B; //Присвоєння змінній В бажанного числа
	cout << "Введіть C : ";
	cin >> C; //Присвоєння змінній С бажанного числа

	b = A > 0 && B < 0 && C < 0 || A < 0 && B > 0 && C < 0 || A < 0 && B < 0 && C > 0;

	if (b == true) {
		cout << "Тут рівно одне число є додатним";
	}
	else {
		cout << "Тут більше або менше за одне число є додатним";
	}

	//Number18

	double x = 0; //Ініціалізація змінної х
	cout << "\nВведіть х : ";
	cin >> x;//Присвоєння значення змінній х

	double y = (exp(x + 1) * sqrt(fabs(2 * x - cos(x + (33*3.14/180)) - 25)) / pow(sin(pow(x, 2)), 1 / 3) * (log(fabs(pow(x, 3))) / log(5))); //Вирішення задачі
	cout << "y дорівнює : " << y;
}


