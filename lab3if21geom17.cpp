#include <iostream>
#include <locale.h>

using namespace std;

void checkxy(int x,int y); //������������ ������� ���� void(�������� ����� �� �����������)
void geo17();//������������ ������� ���� void(������ geom 17)

int main()
{
		setlocale(LC_ALL,"ukrainian");
		
		int choice = 0; //������������ ����� ����� choice
		again:cout << "�����i�� ��� � ��� ����� ������ ���i������: "
			"\n1. If 21"
			"\n2. Geom 17" << endl;
		std::cin >> choice;
		
		switch (choice) {
			case 1: {
				// if 21
				int x, y; // ������������ ������ ���� int(����������)
				double x1, y1; // ������������ ������ ���� double ����� �������� �� ��������������
				bool equalsbehindzero = 0; // ����� �� �� � int ����� 0.7 � 0, ��� �������� ������� ������ ����� ���� bool ��� ����� �������
				cout << "����i�� ��������� x : ";
				cin >> x1;
				x = x1;
				if (x1 > 0 && x1 < 1 || x1 < 0 > -1) { // ���� x1 ������� 0.5, ��� ����� ���� bool ������ �������� 1 �� ���������� �����������, �� ����� x1 �� � ������������� 
					bool equalsbehindzero = 1;
				}
				if (equalsbehindzero == 1) {
					cout << "����� " << x1 << " �� � �i�����������";
					break;
				}
				if (x1 == 0) {
					goto y;
				 }
				if (equalsbehindzero == 0 && x1 / x != 1) { //����� �������� � �� ��������������
					 cout << "����� " << x1 << " �� � �i�����������";
					 break;
				 }
				if (equalsbehindzero == 1) { // ��������� ����� ��� y1 �� ������� ���� �� ������ ������� �1 ����� equalsbehindzero �������� �������� 1
					equalsbehindzero = 0;
				}
				y:cout << "����i�� ��������� � : ";
				std::cin >> y1;
				y = y1;
				if (y1 > 0 && y1 < 1 || y1 < 0 > -1) { // ���� y1 ������� 0.5, ��� ����� ���� bool ������ �������� 1 �� ���������� �����������, �� ����� y1 �� � �������������
					bool equalsbehindzero = 1;
				}
				if (equalsbehindzero == 1) {
					cout << "����� " << y1 << " �� � �i�����������";
					break;
				}
				if (y == 0) { // ���� y1 == y == 0, �� � ����� ������(��� � �� �����)
					goto check;
				}
				else if (equalsbehindzero == 0 && y1 / y != 1) { //����� �������� y �� ��������������
					cout << "����� " << y1 << " �� � �i�����������";
					break;
				}
				check:checkxy(x, y); // ������ ������� �������� �����
				break;
			}
			case 2: {
				geo17();
				break;
			}
			default: {
				cout << "������ ���i���� ����";
				goto again;
			}
		}
}

void checkxy(int x, int y) { // ������� �������� ����� �� �����������
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

void geo17() { // ������� ���� void, �� �� ������� �������
	float x, y, r; // ������������ ������ ���� float
	bool ar1, ar2; // ������������ ������ ���� bool
	const float pi = 3.1415;
	cout << "����i�� ���i�� ����: ";
	std::cin >> r;


	if (r > 0)
	{
		cout << "����i�� ����� �� ���������� � : ";
		cin >> x;
		cout << "����i�� ����� �� ���������� y : ";
		cin >> y;
	

		ar1 = pow((x - r), 2) + pow((y - r), 2) > pow(r, 2) && x > 0 && y > r && y < -1 * x + (2 * r); //г������ ����� ������(�������)
		ar2 = pow((x + r), 2) + pow((y + r), 2) > pow(r, 2) && x < 0 && y < 0 && y > -1 * r && x > -1 * r; //г������ ����� ������(������)

		if (ar1 || ar2) {
			cout << "����� ������ � �i���i" << endl;
		}
		else {
			cout << "����� ������ ���� �i�����" << endl;
		}
	}
	float perimeterar1 = ((pi * r * 45) / 180) + r + ((r * sqrt(2)) - r); // �������� ����� ������
	float perimeterar2 = ((pi * r * 90) / 180) + pow(r, 2); // �������� ����� ������

	float squarearea2 = r * r - (pi * (r * r) / 4); // ����� ����� ������
	float squarearea1 = (r * r - (pi * (r * r) / 4)) / 2; // ����� ����� ������

	int choice = 0;

	again2:cout << "����i��, ����� �� �������� ��� �i���� �� ������ �i�������: "
		"\n1. �i���� � II ����������i� �����i"
		"\n2. �i���� � III ����������i� �����i" << endl;
	cin >> choice;
	switch (choice) {
		case 1: {
			cout << "�������� �i���� � II ����������i� ������i ���i���� " << perimeterar1 << endl;
			cout << "����� �i���� � II ����������i� ������i ���i���� " << squarearea1 << endl;
			break;
		}
		case 2: {
			cout << "�������� �i���� � III ����������i� ������i ���i���� " << perimeterar2 << endl;
			cout << "����� �i���� � II ����������i� ������i ���i���� " << squarearea2 << endl;
			break;
		}
		default: {
			cout << "������������ ���i���";
			goto again2;
		}
	}

}
