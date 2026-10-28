// Лабораторная работа № 1. Вариант 81.
// Простые проценты.
#include <iostream>
#include <iomanip>
#include <limits>
#include <locale>
#include <cstdlib>

using namespace std;

// Доход по простой процентной ставке.
double simpleInterest(double principal, double rate, double years) {
    return principal * rate * years / 100.0;
}


int main() {
    system("chcp 65001 > nul");
	setlocale(LC_ALL, ".UTF-8");
    int choice;
    double entry_summ, rate, years;

    do {
        cout << "\n=== Вариант 81: расчёт простых процентов ===\n";
        cout << "1. Рассчитать сумму процентного дохода\n";
        cout << "0. Выход\n";
        cout << "Выберите пункт меню: ";

        if (!(cin >> choice)) {
            cout << "Ошибка: введите целое число.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 0) {
            cout << "Работа завершена.\n";
            break;
        }

        if (choice != 1) {
            cout << "Ошибка: такого пункта меню нет.\n";
            continue;
        }

        cout << "Введите первоначальную сумму, ставку (% годовых) и срок (лет): ";
        if (!(cin >> entry_summ >> rate >> years)) {
            cout << "Ошибка: введите числовые значения.\n";
            return 1;
        }
        if (entry_summ < 0 || rate < 0 || years < 0) {
            cout << "Ошибка: сумма, ставка и срок не должны быть отрицательными.\n";
            continue;
        }

        cout << fixed << setprecision(2);
        cout << "Процентный доход: " << simpleInterest(entry_summ, rate, years) << "\n";
    } while (true);

    return 0;
}
