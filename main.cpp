// Лабораторная работа № 1. Вариант 81.
// Простые проценты.
#include <iostream>
#include <iomanip>
#include <limits>
#include <locale>
#include <cstdlib>

using namespace std;

// Доход по простой процентной ставке.
double simpleInterest(double entry_summ, double rate, double years) {
    return entry_summ * rate * years / 100.0;
}
// Итоговая сумма вместе с начисленным доходом.
double totalSimple(double entry_summ, double rate, double years) {
    return entry_summ + simpleInterest(entry_summ, rate, years);
}


int main() {
    system("chcp 65001 > nul");
	setlocale(LC_ALL, ".UTF-8");
    int choice;
    double entry_summ, rate, years;

    do {
        cout << "\n=== Вариант 81: расчёт простых процентов ===\n";
        cout << "1. Рассчитать сумму процентного дохода\n";
        cout << "2. Рассчитать итоговую сумму\n";
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

        if (choice != 1 && choice != 2) {
            cout << "Ошибка: такого пункта меню нет.\n";
            continue;
        }

        cout << "Введите первоначальную сумму, ставку (% годовых) и срок (лет): ";
        if (!(cin >> entry_summ >> rate >> years)) {
            cout << "Ошибка: введите числовые значения.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
        }
        if (entry_summ < 0 || rate < 0 || years < 0) {
            cout << "Ошибка: сумма, ставка и срок не должны быть отрицательными.\n";
            continue;
        }

        cout << fixed << setprecision(2);
        if (choice == 1) {
            cout << "Процентный доход: " << simpleInterest(entry_summ, rate, years) << "\n";
        }
        else {
            cout << "Итоговая сумма: " << totalSimple(entry_summ, rate, years) << "\n";
        }
    } while (true);

    return 0;
}
