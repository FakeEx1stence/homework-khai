#include <iostream>
#include <locale.h>

using namespace std;

void if21(); //Декларування функції типу void(перевірка точок на координатах)
void geo17();//Декларування функції типу void(задача geom 17)
void geo172();//Декларування функції типу void(задача geom 17, розрахування площі та периметру)

int main()
{
	setlocale(LC_ALL, "ukrainian");
	int choice = 0; //Декларування змінної задля choice
		cout << "Виберiть яку з цих задач будете вирiшувати: "
		"\n1. If 21"
		"\n2. Geom 17"
		"\n3. Geom 17.2(Площа та периметр)" << endl;
	
	std::cin >> choice;

	switch (choice) 
	{
			case 1: 
			{
				// if 21
				if21();
				break;
			}
			case 2: 
			{
				// geo17.1(Належність точки до фігури)
				geo17();
				break;
			}
			case 3: 
			{
				//geo17.2(Периметр та площа)
				geo172();
				break;
			}
			default: 
			{
				cout << "Такого варiанту немає\n";
				break;
			}
	}
}

void if21() { // функція перевірки точки на координатах
	// if 21
	int x, y; // Декларування змінних типу int(координати)
	double x1, y1; // Декларування змінних типу double задля перевірки на цілочисельність
	cout << "Уведiть кординату x : ";
	cin >> x;
	cout << "Уведiть кординату у : ";
	std::cin >> y;

	int i = 0;//  вихідна змінна
	if (x == 0 && y == 0) {
	}
	else if (x != 0 && y == 0) {
		i = 1;
	}
	else if (x == 0 && y != 0) {
		i = 2;
	}
	else if (x != 0 && y != 0) {
		i = 3;
	}
	cout << i;
}

//geometry 17

void geo17() { // Функція типу void, що не повертає значень
	float x, y, r; // Декларування змінних типу float
	bool ar1, ar2, isIn; // Декларування змінних типу bool

	cout << "Уведiть радiус кола: ";
	std::cin >> r;


	if (r > 0)
	{
		cout << "Уведiть точку за кординатою х : ";
		cin >> x;
		cout << "Уведiть точку за кординатою y : ";
		cin >> y;


		ar1 = pow((x - r), 2) + pow((y - r), 2) > pow(r, 2) && x > 0 && y > r && y < -1 * x + (2 * r); //Рівняння першої фігури(верхньої)
		ar2 = pow((x + r), 2) + pow((y + r), 2) > pow(r, 2) && x < 0 && y < 0 && y > -1 * r && x > -1 * r; //Рівняння другої фігури(нижньої)

		if (ar1 || ar2) {
			cout << "In";
		}
		else {
			cout << "Out";
		}
		
	}
	else {
		cout << "Радіус не може бути від'ємним";
	}

}

void geo172() {
	const float pi = 3.1415;
	float r;
	cout << "Уведiть радiус: ";
	cin >> r;

	float perimeterar1 = ((pi * r * 45) / 180) + r + ((r * sqrt(2)) - r); // Периметр першої фігури
	float perimeterar2 = ((pi * r * 90) / 180) + pow(r, 2); // Периметр другої фігури

	float squarearea2 = r * r - (pi * (r * r) / 4); // Площа першої фігури
	float squarearea1 = (r * r - (pi * (r * r) / 4)) / 2; // Площа другої фігури

	int choice = 0;

	cout << "Оберiть, площу та периметр якої фiгури ви хочете дiзнатися: "
	"\n1. Фiгури у II координатнiй чвертi"
	"\n2. Фiгури у III координатнiй чвертi" << endl;
	cin >> choice;
	switch (choice)
	{
		case 1: 
		{
			cout << "Периметр фiгури у II координатнiй площинi дорiвнює " << perimeterar1 << endl;
			cout << "Площа фiгури у II координатнiй площинi дорiвнює " << squarearea1 << endl;
			break;
		}
		case 2: 
		{
			cout << "Периметр фiгури у III координатнiй площинi дорiвнює " << perimeterar2 << endl;
			cout << "Площа фiгури у II координатнiй площинi дорiвнює " << squarearea2 << endl;
			break;
		}
		default: 
		{
			cout << "Неправильний варiант";
		}
	}
}
