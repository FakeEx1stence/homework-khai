#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;

void array39(); // Завдання #39
void answer(int nonunique);

void array51(); // Завдання #51

const int M = 50, N = 50;


int main() {
	srand(time(NULL));			//Генератор семя случайности
	setlocale(LC_ALL, "Ukrainian");

	int choice = 0; 

	while (choice != 3) {

		cout << "Оберiть завдання: "
			"\n1.Array#39"
			"\n2.Array#51"
			"\n3.Exit" << endl;

		cin >> choice;

		switch (choice) {
			case 1: {
				array39();
				break;
			}
			case 2: {
				array51();
				break;
			}
			case 3: {
				cout << "Програма завершена!";
				break;
			}
			default: {
				cout << "Невiрний варiант, спробуйте ще раз";
			}
		}
    }
}

void array39() {					//Завдання 39

	int a[M][N];						// Массив(не забыть переименовать в matr1)
	int row = 0, column = 0, nonunique = 0;
	bool foundZero = false;				//Переменная-проверка на ноль

	do
	{
		cout << "Число рядків (2-20): ";
		cin >> row;
		cout << "Число стовпців (2-20): ";					
		cin >> column;
	}
	// доки некоректні вхід.дані
	while (column < 2 || column>N || row <2 || row>M);

	int size = 0;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {							//Случайные значение всем элементам массива
			a[i][j] = (rand() % 15) + 1;
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {							//Отладка
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {							//Отметка неуникальных столбцов придавая повторным значениям 0
			for (int g = i + 1; g < row; g++) {
				if (a[i][j] == a[g][j]) {
					a[g][j] = 0;
				}
			}
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {						//Проверка на нахождение неуникального столбца
			if (a[i][j] == 0) {
				foundZero = true;
				break;
			}
		}
		if (foundZero) {
			nonunique++;
		}
	} 


	cout << "\n\nTemp Array\n\n";

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cout << "| " << a[i][j] << " | ";								//Отладка
		}
		cout << "\n";
	}
	answer(nonunique);											//Вызов функции ответа
}

void answer(int nonunique) {
	cout << "\n Тут " << nonunique << " стовпцi з повторюючими елементами" << endl;
}
	
void array51() {					//Завдання 51
	cout << "hello";
}
