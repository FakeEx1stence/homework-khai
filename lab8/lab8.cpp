#include <iostream>
#include <ctime>
#include <windows.H>
#include <string>
#include <fstream>
#include <sstream>

const int M = 20, N = 20, F = 100;

void array92();
void get_nums(int size, int array[N]);
bool checkfiles(std::string in, std::string out);
void deleteunpair(int arr[], int n, std::string output);


void matrix39();
bool checkfile(std::string in);
void enter(float arr[M][N], int row, int column, std::string in);
int count(const float a[M][N], const int row, const int column);

void sort20();
void shakersort(float arr[], int n, std::string in);

int main() {
	srand(time(NULL));			//Генератор семя случайности
		setlocale(LC_ALL, "Ukrainian");
	
		int choice = 0; 
	
		while (choice != 4) {
	
			std::cout << "Оберiть завдання: "
				"\n1.Array#92"
				"\n2.Matrix#39"
				"\n3.Sort#20"
				"\n4.Exit" << std::endl;
	
			std::cin >> choice;
	
			switch (choice) {
				case 1: {
					array92();		//Задание array92
					break;
				}
				case 2: {
					matrix39();		// Задание matrix39
					break;
				}
				case 3: {
					sort20();		// Задание sort20
					break;
				}
				case 4: {
					std::cout << "Програма завершена!";
					break;
				}
				default: {
					std::cout << "Невiрний варiант, спробуйте ще раз";
				}
			}
	    }
}

// Задание Array92

void array92() {

	int n = 0, startPos = 0, size = 0;
	int mas[N];

	get_nums(size, mas);
}


void get_nums(int size, int array[N]) {

	std::string filename_in = "D:\\array_in_92.txt";
	std::string filename_out = "C:\\Users\\Vitalya\\Desktop\\array_out_92.txt";

	int startPos = 0;

	std::ifstream f;

	if (checkfiles(filename_in, filename_out)) {

		f.open(filename_in);

		std::string lenght;
		std::getline(f, lenght);
		int size = stoi(lenght);
		/*std::cout << " SIZE = " << size;*/


		std::string arr[N];
		std::getline(f, arr[0]);

		std::cout << "\n";
		for (int i = 0; i < size; i++) {
			int spacePos = arr[0].find(' ', startPos);
			std::string numStr = arr[0].substr(startPos, spacePos - startPos);
			array[i] = stoi(numStr);
			startPos = spacePos + 1;
		}
		f.close();

		deleteunpair(array, size,filename_out);

	}
	else {
		std::cout << "Помилка, файл не знайдено";
	}
}

bool checkfiles(std::string in, std::string out) {

	std::ifstream f_in;
	std::ifstream f_out;

	f_in.open(in);
	f_out.open(out);

	if (!f_in.is_open() || !f_out.is_open()) {
		f_in.close();
		f_out.close();
		return 0;
	}
	else if (f_in.is_open() && f_out.is_open()) {
		return 1;
	}
	else {
		return 0;
	}
}

void deleteunpair(int arr[], int n, std::string filename_out) {
	int newSize = 0, temp = 0;
	std::string arrStr;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			arr[newSize] = arr[i];
			arrStr += std::to_string(arr[newSize]);
			arrStr += " ";
			newSize++;
		}
	}

	std::cout << "\n" << arrStr;

	std::cout << "Розмiр масиву: " << newSize << std::endl;

	std::ofstream outp(filename_out);
	if (!outp)
	{
		std::cerr << "Неможливо вiдкрити файл!" << std::endl;
		exit(1);
	}
	else {
		outp << "Розмір масиву: " << newSize << std::endl;
		outp << "Масив: " << arrStr;
	}
}
// Конец Array92

// Задание Matrix39

void matrix39() {
	int n = 0, startPos = 0, rows = 0, columns = 0, skip = 0;
	float arr[M][N];
	std::string filename;

	std::string filename_in = "D:\\matrix_in_39.txt";
	

	std::ifstream f;

	if (checkfile(filename_in)) {
		f.open(filename_in);

		std::string size;

		std::getline(f, size);
		
		for (int i = 0; i < size.size(); i++) {
			if (size[i] == ' ') {
				skip = i;
			}		
		}

		/*std::cout << "SKIP = " << skip << std::endl;

		std::cout << "SIZE: " << size[0] << std::endl;*/

			rows = stoi(size);
			if (rows > 20) {
				std::cout << "Рядків не може бути більше за 20" << std::endl;
				exit(0);
			}
			else {
				for (int i = 0; i < size.size() - skip; i++) {
					size[i] = size[skip + i];
					size[skip + i] = 0;
				}

				columns = stoi(size);
				if (columns > 20) {
					std::cout << "Колон не може бути більше за 20" << std::endl;
					exit(0);
				}
				else {
					enter(arr, rows, columns, filename_in);
				}
			}
	}
	else {
		std::cout << "Помилка, файл не знайдено";
	}
}

bool checkfile(std::string in) {

	std::ifstream f_in;

	f_in.open(in);

	if (f_in.is_open()) {
		return 1;
	}
	else {
		return 0;
	}
}


void enter(float arr[M][N], int row, int column, std::string in) {
	std::string out;
	float num = 0;
	int numRows = 0, numCols = 0;

	std::ifstream f; 

	std::istringstream iss(out);
	
	f.open(in);

	std::getline(f, out);

	while (std::getline(f, out) && numRows < row) { 
		std::istringstream iss(out); 
		numCols = 0; 

		while (iss >> num && numCols < column) { 
			arr[numRows][numCols] = num; 
			numCols++;
		}

		numRows++;
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			std::cout << arr[i][j] << " ";
		}
		std::cout << "\n";
	}

	std::ofstream outp;

	outp.open(in, std::ios::app);

	if (!outp)
	{
		std::cerr << "Неможливо вiдкрити файл!" << std::endl;
		exit(1);
	}
	else {
		outp << "\nНеунiкальних стовпців : " << count(arr, row, column) << std::endl;
	}

}

int count(const float a[M][N], const int row, const int column) {
	bool foundZero = false;
	int nonunique = 0;

	std::cout << "\n";

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

// Задание Sort20

void sort20() {
	float arr[M];
	std::string filename;

	std::string filename_in = "D:\\sort_in_20.txt";

	std::ifstream f;
	std::istringstream iss(filename_in);

	int count = 0;

	if (checkfile(filename_in)) {
		f.open(filename_in);

		while (count < M && f >> arr[count]) {
			count++;
		}

		for (int i = 0; i < count; i++) {
			std::cout << arr[i] << " ";
		}

		shakersort(arr, count, filename_in);
	}
	else {
		std::cout << "Помилка, файл не знайдено";
	}
}


void shakersort(float arr[], int n, std::string in) {
	int temp = 0;

	std::cout << n;

	while (temp != n) {
		for (int i = 0; i < n; i++) {
			if (arr[i] < arr[i + 1]) {
				std::swap(arr[i], arr[i + 1]);
			}
			for (int j = 0; j < n; j++) {
				std::cout << "|" << arr[j];
			}
			std::cout << "\n";
		}
		for (int i = n; i > 0; --i) {
			if (arr[i] > arr[i - 1]) {
				std::swap(arr[i], arr[i - 1]);
			}
		}
		
		temp = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] > arr[i + 1]) {
				temp++;
				/*std::cout <<  "TEMP = " << temp;*/
			}
			else {
				break;
			}
		}
	}

	/*for (int i = 0; i < n; i++) {
		std::cout << "|" << arr[i];
	}*/
	std::cout << "\n";

	std::ofstream outp;

	outp.open(in, std::ios::app);

	outp << "\nОтсортований масив: ";

	for (int i = 0; i < n; i++) {
		outp << arr[i] << " ";
	}

}

// Конец Sort20

// Конец
