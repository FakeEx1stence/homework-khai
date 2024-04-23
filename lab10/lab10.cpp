#include <iostream>

using namespace std;

struct TTime {
	int hrs, min, sec;
};

struct PPoints {
	int A, B, C;
};

struct NNums {
	int A, B, C;
};

void param78();
void func(TTime& T);
void nextHour(TTime& T);

void begin18();
void transmutation(PPoints& P);
int multiply(int A, int B);

void boolean14();
void is(NNums& n);
bool isPositive(int A, int B, int C);

int main() {
	setlocale(LC_ALL, "Ukrainian");

	int choice = 0;

	while (choice != 4) {

		cout << "Оберiть завдання: "
			"\n1.Param78"
			"\n2.Begin18"
			"\n3.Boolean14"
			"\n4.Exit" << endl;

		cin >> choice;

		switch (choice) {
			case 1: {
				param78();		//Задание param78
				break;
			}
			case 2: {
				begin18();		// Задание begin18
				break;
			}
			case 3: {
				boolean14();		// Задание boolean14
				break;
			}
			case 4: {
				cout << "Програма завершена!";
				break;
			}
			default: {
				cout << "Невiрний варiант, спробуйте ще раз\n";
			}
		}
	}
}

//Начало param78

void param78() {
	TTime t1, t2, t3, t4, t5;
	func(t1);
	func(t2);
	func(t3);
	func(t4);
	func(t5);
	
}

void func(TTime& T) {
	cout << "Уведiть години: ";
	cin >> T.hrs;

	cout << "Уведiть хвилини: ";
	cin >> T.min;

	cout << "Уведiть секунди: ";
	cin >> T.sec;


	if (T.hrs < 24 && T.min < 60 && T.sec < 60) {
		nextHour(T);
		cout << "Змiнений годинник: ";
		cout << T.hrs << ":" << T.min << ":" << T.sec << "\n";
	}
	else if (T.hrs > 23) {
		cout << "\nГодин у добi максимум 24!";
	}
	else if (T.min > 59) {
		cout << "\nХвилин у годинi максимум 59!";
	}
	else if (T.hrs > 59) {
		cout << "\nСекунд у хвилинi максимум 59!";
	}
}

void nextHour(TTime& T) {
	T.hrs++;

	if (T.hrs >= 24) {
		T.hrs = 0;
	}
}

//Конец Param78

//Начало begin18

void begin18() {
	PPoints p;
	transmutation(p);
}

void transmutation(PPoints& P) {
	cout << "Уведiть А: ";
	cin >> P.A;
	cout << "Уведiть B: ";
	cin >> P.B;
	cout << "Уведiть C: ";
	cin >> P.C;

	int AC = 0, BC = 0;

	if (P.C > P.A && P.C < P.B) {
		AC = fabs(P.A - P.C);
		BC = fabs(P.B - P.C);

		int result = multiply(AC, BC);
		cout << "Твiр довжин " << AC << " i " << BC << " дорiвнює " << result << endl;
	}
	else {
		cout << "Точка С повинна бути менше за B та бiльше за А (" << P.A << " < С < " << P.B << ")\n";
	}
}

int multiply(int A, int B) {
	return A * B;
}

//Конец begin18

//Начало boolean14
void boolean14() {
	NNums n;
	is(n);
	
}

void is(NNums& N) {
	cout << "Уведiть А: ";
	cin >> N.A;
	cout << "Уведiть B: ";
	cin >> N.B;
	cout << "Уведiть C: ";
	cin >> N.C;

	cout << "Чи рiвно одне число є позитивним? =  " << boolalpha << isPositive(N.A, N.B, N.C) << endl;
}

bool isPositive(int A, int B, int C) {
	return (A > 0 && B < 0 && C < 0 || A < 0 && B > 0 && C < 0 || A < 0 && B < 0 && C > 0);
}

//Конец boolean14
