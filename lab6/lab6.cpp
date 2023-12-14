#include <iostream>
#include <locale.h>
#include <cmath>

using namespace std;

void array26(); //Декларування функції типу void(задача Array26)
void input_arr(int arr[], int& n);
void checkpair(int arr[], int n);

/*Дан цілочисельний масив розміру N. Перевірити, чергуються в ньому парні і
непарні числа. Якщо чергуються, то вивести 0, якщо немає, то вивести
порядковий номер першого елемента, що порушує закономірність.*/

void array92();//Декларування функції типу void(задача Array92)
void deleteunpair(int arr[],int n);


int main()
{
	setlocale(LC_ALL, "ukrainian");

	int choice = 0; //Декларування змінної задля choice

	while (choice != 3) {
		setlocale(LC_ALL, "ukrainian");
		cout.clear();
		cout << "Виберiть яку з цих задач будете вирiшувати: "
			"\n1. Array#26"
			"\n2. Array#92"
			"\n3. Вийти з програми" << endl;


		cin >> choice;

		switch (choice)
		{
			case 1:
			{
				// array26
				array26();
				break;
			}
			case 2:
			{
				// array92
				array92();
				break;
			}
			case 3:
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

void array26() {
	const int N = 50;
	int n = 0;
	int arr[N];
	input_arr(arr, n);
	checkpair(arr, n);
}

void input_arr(int arr[], int& n)
{
	cout << "Кількість елементів масиву: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

void checkpair(int arr[], int n) {
	int count = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i - 1] % 2 == 0 && arr[i] % 2 == 1 || arr[i - 1] % 2 == 1 && arr[i] % 2 == 0)
		{
			if (i + 2 == n) {
				count++;
				continue;
			}
			if (count == 1) {
				cout << "0" << endl;
				break;
			}
			continue;
		}
		else if (arr[i - 1] % 2 == 0 && arr[i] % 2 != 1 || arr[i - 1] % 2 == 1 && arr[i] % 2 != 0){
			cout << arr[i] << endl;
			break;
		}
	}
}

void array92() {
	const int N = 50;
	int n = 0;
	int arr[N];
	input_arr(arr, n);
	deleteunpair(arr, n);
}

void deleteunpair(int arr[], int n) {
	int newSize = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 != 0) {
			 arr[i] = 0; 
			 arr[newSize] = arr[i];
			 newSize++;
			 continue;
		}
		cout << arr[i] << " ";
	}
	cout << "Розмір масиву: " << newSize-1 << endl;
}
