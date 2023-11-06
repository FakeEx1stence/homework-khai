#include <iostream>
#include <locale.h>

using namespace std;

void checkxy(int x,int y); //Декларування функції типу void(перевірка точок на координатах)
void geo17();//Декларування функції типу void(задача geom 17)

int main()
{
		setlocale(LC_ALL,"ukrainian");
		
		int choice = 0; //Декларування змінної задля choice
		again:cout << "Виберiть яку з цих задач будете вирiшувати: "
			"\n1. If 21"
			"\n2. Geom 17" << endl;
		std::cin >> choice;
		
		switch (choice) {
			case 1: {
				// if 21
				int x, y; // Декларування змінних типу int(координати)
				double x1, y1; // Декларування змінних типу double задля перевірки на цілочисельність
				bool equalsbehindzero = 0; // Через те що у int число 0.7 є 0, мені довелося зробити окрему змінну типу bool для таких випадків
				cout << "Уведiть кординату x : ";
				cin >> x1;
				x = x1;
				if (x1 > 0 && x1 < 1 || x1 < 0 > -1) { // Якщо x1 дорівнює 0.5, тоді змінна типу bool набуває значення 1 та виводиться повідомлення, що число x1 не є цілочисельним 
					bool equalsbehindzero = 1;
				}
				if (equalsbehindzero == 1) {
					cout << "Число " << x1 << " не є цiлочисельним";
					break;
				}
				if (x1 == 0) {
					goto y;
				 }
				if (equalsbehindzero == 0 && x1 / x != 1) { //умова перевірки х на цілочисельність
					 cout << "Число " << x1 << " не є цiлочисельним";
					 break;
				 }
				if (equalsbehindzero == 1) { // Обнулення змінної для y1 на випадок якщо на моменті обробки х1 змінній equalsbehindzero надалося значення 1
					equalsbehindzero = 0;
				}
				y:cout << "Уведiть кординату у : ";
				std::cin >> y1;
				y = y1;
				if (y1 > 0 && y1 < 1 || y1 < 0 > -1) { // Якщо y1 дорівнює 0.5, тоді змінна типу bool набуває значення 1 та виводиться повідомлення, що число y1 не є цілочисельним
					bool equalsbehindzero = 1;
				}
				if (equalsbehindzero == 1) {
					cout << "Число " << y1 << " не є цiлочисельним";
					break;
				}
				if (y == 0) { // Якщо y1 == y == 0, що є цілим числом(хоч і не зовсім)
					goto check;
				}
				else if (equalsbehindzero == 0 && y1 / y != 1) { //умова перевірки y на цілочисельність
					cout << "Число " << y1 << " не є цiлочисельним";
					break;
				}
				check:checkxy(x, y); // виклик функції перевірки точки
				break;
			}
			case 2: {
				geo17();
				break;
			}
			default: {
				cout << "Такого варiанту немає";
				goto again;
			}
		}
}

void checkxy(int x, int y) { // функція перевірки точки на координатах
	int i = 0;
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
	bool ar1, ar2; // Декларування змінних типу bool
	const float pi = 3.1415;
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
			cout << "Точка лежить у фiгурi" << endl;
		}
		else {
			cout << "Точка лежить поза фiгурою" << endl;
		}
	}
	float perimeterar1 = ((pi * r * 45) / 180) + r + ((r * sqrt(2)) - r); // Периметр першої фігури
	float perimeterar2 = ((pi * r * 90) / 180) + pow(r, 2); // Периметр другої фігури

	float squarearea2 = r * r - (pi * (r * r) / 4); // Площа першої фігури
	float squarearea1 = (r * r - (pi * (r * r) / 4)) / 2; // Площа другої фігури

	int choice = 0;

	again2:cout << "Оберiть, площу та периметр якої фiгури ви хочете дiзнатися: "
		"\n1. Фiгури у II координатнiй чвертi"
		"\n2. Фiгури у III координатнiй чвертi" << endl;
	cin >> choice;
	switch (choice) {
		case 1: {
			cout << "Периметр фiгури у II координатнiй площинi дорiвнює " << perimeterar1 << endl;
			cout << "Площа фiгури у II координатнiй площинi дорiвнює " << squarearea1 << endl;
			break;
		}
		case 2: {
			cout << "Периметр фiгури у III координатнiй площинi дорiвнює " << perimeterar2 << endl;
			cout << "Площа фiгури у II координатнiй площинi дорiвнює " << squarearea2 << endl;
			break;
		}
		default: {
			cout << "Неправильний варiант";
			goto again2;
		}
	}

}
