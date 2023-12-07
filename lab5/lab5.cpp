#include <iostream>
#include <locale.h>
#include <cmath>

using namespace std;

void geo17(); //Декларування функції типу void(задача geo17)

void solve24();//Декларування функції типу void(задача Solve24)
double factorial(int temp);

void solve32();//Декларування функції типу void(задача Solve32)

int main()
{
	setlocale(LC_ALL, "ukrainian");

		int choice = 0; //Декларування змінної задля choice

		while (true && choice !=4){
			setlocale(LC_ALL, "ukrainian");
			cout.clear();
			cout << "Виберiть яку з цих задач будете вирiшувати: "
				"\n1. Geometry#17"
				"\n2. Solve24.1"
				"\n3. Solve32.2"
				"\n4. Вийти з програми" << endl;


			std::cin >> choice;

			switch (choice)
			{
				case 1:
				{
					// Geo17
					geo17();
					break;
				}
				case 2:
				{
					// Solve24
					solve24();
					break;
				}
				case 3:
				{
					// Solve32
					solve32();
					break;
				}
				case 4:
				{
					cout << "Програма завершена";
					break;
				}
				default:
				{
					cout << "Такого варiанту немає\n";
					break;
				}
			}
		}
}

void geo17() { // Функція типу void, що не повертає значень
	float x, y, r; // Декларування змінних типу float
	bool ar1, ar2; // Декларування змінних типу bool
	int n, count = 0;

	cout << "Кількість разів: ";
	cin >> n;

		cout << "Уведiть радiус кола: ";
		std::cin >> r;

		for (int i = 1; i <= n; i++)
		{

			if (r > 0)
			{
				cout << "Уведiть точку за кординатою х : ";
				cin >> x;
				cout << "Уведiть точку за кординатою y : ";
				cin >> y;


				ar1 = pow((x - r), 2) + pow((y - r), 2) > pow(r, 2) && x > 0 && y > r && y < -1 * x + (2 * r); //Рівняння першої фігури(верхньої)
				ar2 = pow((x + r), 2) + pow((y + r), 2) > pow(r, 2) && x < 0 && y < 0 && y > -1 * r && x > -1 * r; //Рівняння другої фігури(нижньої)

				if (ar1 || ar2) {
					count++;
				}
				else {
					
				}

			}
			else {
				cout << "Радіус не може бути від'ємним" << endl;
			}
		}
	cout << "Кількість вдалих спроб: " << count << " з " << n;
}

void solve24()
{
	int k = 0,n; 
	const double pi = 3.14;
	double x;

	cout << "Введіть х: ";
	cin >> x;

	cout << "Обмеження n: ";
	cin >> n; 

	
	long double sum = 0;	
	
	cout.precision(15);
	if (!cin || n < 0)
	{
		cout << "Неправильне введення даних" << endl;
	}
	else 
	{
		for (k; k <= n; k++)
		{
			int temp = 1 + (2 * k);
			int count = 0;

			long double part1 = pow(-1,k)*pow((-1*pi/2.0+sqrt(x)),temp);
			long double part2 = factorial(temp);

			long double solving = pow((-1.0 * (part1 / part2)), x);

			sum += solving;
			solving = 0;

			count = k % 3;

			if (count == 2) {
				cout << "Сума ряду: " << sum << endl;
			}
		}
	}
	
}

double factorial(int temp)
{
	int equals = 1;
	for (int i = 1; i <= temp; i++)
	{
		equals *= i;
	}
	return equals;
}

void solve32()
{
	int k = 0, n;
	const double pi = 3.14, e = 1;
	double x, g = 1E+5;


	cout << "Введіть х: ";
	cin >> x;

	cout << "Діапазон суми ряду: ";
	cin >> g;

	long double sum = 0;

	do
	{
		k++;
			int temp = 1 + (2 * k);
			int count = 0;

			long double part1 = pow(5, k);
			long double part2 = sqrt(k) * pow(2, k - 1);

			long double solving = part1 / part2;

			cout << "Solve equals: " << solving << endl;

			sum += solving;
			solving = 0;

			count = k % 3;

			if (count == 2) {
				cout << "Сума ряду: " << sum << endl;
			}
	} while (sum < g);
}
