#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;

int main() { // Main function(start of program)
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice = 0;
    cout << "Оберіть завдання : ";
    cout << "1. Вирішення lab1begin18";
    cout << "2. Вирішення lab1begin26";
    cin >> choice;
    switch (choice) {
        case 1:
            std::cout << "Ви обрали вирішення lab1begin18\n";
            int y = 0;// Оголошення змінної
            cout << "Введіть невідому : " << endl;
            cin >> y;
            cout << "(4(y-3)^6-7(y-3)^3+2) =  " << (4 * ((y - 3)*(y - 3)*(y - 3)*(y - 3)*(y - 3)*(y - 3)) - 7 * ((y - 3)*(y - 3)*(y - 3)) + 2); //Вирішення завдання
            break;
        case 2:
            std::cout << "Вы обрали вирішення lab1begin26\n";
            double X, A, Y, B = 0; // Оголошення змінних
            //////////////////////////////////////|
            cout << "Введіть масу цукерок(кг) : ";
            cin >> X;
            cout << "Введіть ціну цукерок : ";
            cin >> A;
            cout << "Введіть масу печива(кг) : ";
            cin >> Y;
            cout << "Введіть ціну печива : ";
            cin >> B; 
            //////////////////////////////////////|   Ініціалізація змінних
            double PricePerMass1 = A / X;
            double PricePerMass2 = B / Y;

            cout << "Ціна за 1кг цукерок :  " << PricePerMass1 << endl;
            cout << "Ціна за 1кг печива : " << PricePerMass2 << endl;

            if(PricePerMass1>PricePerMass2){
                cout << "Ціна цукерок більша на " << PricePerMass1 / PricePerMass2 << " аніж печиво" << endl;
            }
            else {
                cout << "Ціна цукерок менша на " << PricePerMass1 / PricePerMass2 << " аніж печиво" << endl;
            }
            break;
        default:
            std::cout << "Такого варіанту немає\n";
    }
}
