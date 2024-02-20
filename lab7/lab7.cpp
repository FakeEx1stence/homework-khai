#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;

const int M = 50, N = 50;

void array39(); // Завдання #39
int count(const int a[M][N], const int row, const int column);
void enter(int a[M][N], int& column, int& row);

void array51(); // Завдання #51 Дана матриця розміру M × N. Поміняти місцями рядки, що містять
void swap(int a[M][N], const int row, const int column); // мінімальний і максимальний елементи матриці.

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
	int matr1[M][N];						// Массив
	int row, column;

	enter(matr1, row, column);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cout << " | " << matr1[i][j] << "\t | ";
		}
		cout << "\n";
	}

	cout << "Тут " << count(matr1, row, column) << " неунiкальних стовпцiв" << endl;
}

int count(const int a[M][N], const int row, const int column) {
	bool foundZero = false;
	int nonunique = 0;

	for (int j = 0; j < column; j++) {
		foundZero = 0;
		for (int i = 0; i < row; i++) {
			for (int g = i + 1; g < row; g++) {
				if (a[i][j] == a[g][j]) {
					foundZero = true;
					break;
				}
			}
			if (foundZero) {
				break;
			}
		}
		if (foundZero) {
			nonunique++;
		}
	}
	return nonunique;
}


void enter(int a[M][N], int& column, int& row) {
	do
	{
		cout << "Число стовпцiв (2-20): ";
		cin >> column;
		cout << "Число рядкiв (2-20): ";
		cin >> row;
	}
	// доки некоректні вхід.дані
	while (column < 2 || column>N || row <2 || row>M);

	for (int i = 0; i < column; i++) {
		for (int j = 0; j < row; j++) {							//Случайные значение всем элементам массива
			a[i][j] = (rand() % 100) + 1;
		}
	}
}


void array51() {					//Завдання 51
	int matr1[M][N];						// Массив
	int row = 0, column = 0;

	enter(matr1, row, column);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cout << " | " << matr1[i][j] <<  "\t | ";
		}
		cout << "\n";
	}

	swap(matr1, row, column);
}

void swap(int a[M][N], const int row, const int column) {
	int min = 100, max = 0; 
	int temp[M];
	int minIx = 0,maxIx = 0; 

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (a[i][j] < min) {
				min = a[i][j];
				minIx = i;
			}
			else if (a[i][j] > max) {
				max = a[i][j];
				maxIx = i;
			}	
		}
	}

	cout << "Min number is " << min << " and it is located in this index: " << minIx << endl;
	cout << "Max number is " << max << " and it is located in this index: " << maxIx << endl;

	for (int i = 0; i < column; i++) {
		temp[i] = a[minIx][i];
		a[minIx][i] = a[maxIx][i];
		a[maxIx][i] = temp[i];
	}
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cout << " | " << a[i][j] << "\t | ";
		}
		cout << "\n";
	}

}
