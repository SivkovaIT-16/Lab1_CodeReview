//К - ичные числа.Среди чисел в системе счисления с основанием K(2≤K≤10) определить 
//сколько имеется чисел из N(1 < N < 20, N + K < 26) разрядов таких, что в их записи 
//содержится два и более подряд идущих нулей.Для того, чтобы избежать переполнения, ответ 
//представьте в виде вещественного числа.

#include "Task3.h"
#include <iostream>
#include <cmath>
// FIX_ME: добавлена библиотека
#include <windows.h>

// FIX_ME: using namespace std в глобальной области видимости
//using namespace std;

// FIX_ME: фигурная скобка должна быть на новой строке
//int main() {
int main()
{
    // FIX_ME: добавлена поддержка русского языка
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    // FIX_ME: имена переменных должны быть информативными и начинаться с заглавной буквы
    // FIX_ME: переменные должны быть инициализированы при объявлении
    //int k, n;
    int K = 0, N = 0;

    // FIX_ME: добавить std::
    // FIX_ME: отсутствуют пробелы вокруг операторов сравнения
    // FIX_ME: добавлены проверки ввода
    //cout << "Введите K (2<=K<=10) : ";
    //cin >> k;
    //cout << "Введите N (1<N<20, N+K<26) : ";
    //cin >> n;
    std::cout << "Введите K (2 <= K <= 10) : ";
    std::cin >> K;

    if (!ValidateK(K))
    {
        return 1;
    }

    std::cout << "Введите N (1 < N < 20, N + K < 26) : ";
    std::cin >> N;

    if (!ValidateN(N, K))
    {
        return 1;
    }


    // FIX_ME: имена переменных должны быть информативными и начинаться с заглавной буквы
    // FIX_ME: переменные должны быть инициализированы при объявлении
    // FIX ME: комментарии должны заканчиваться точкой
    //double nz, oz, tz;
    //nz = k - 1; // Числа без ведущих нулей
    //oz = 1;     // Числа, заканчивающиеся на 0 (без подряд идущих нулей)
    //tz = 0;     // Числа, содержащие подряд идущие нули
    double NumbersWithoutZero = K - 1; // Числа без ведущих нулей.
    double NumbersEndingWithZero = 1; // Числа, заканчивающиеся на 0 (без подряд идущих нулей).
    double NumbersWithTwoZeros = 0; // Числа, содержащие подряд идущие нули.

    // FIX_ME: фигурная скобка должна быть на новой строке
    // FIX_ME: имена переменных должны быть информативными
    // FIX_ME: использовать префиксный инкремент
    //for (int i = 2; i <= n; i++) {
    //    double _nz = nz;
    //    double _oz = oz;
    //    double _tz = tz;

    //    nz = (_nz + _oz) * (k - 1);
    //    oz = _nz;
    //    tz = _tz * k + _oz;
    //}
    for (int i = 2; i <= N; ++i)
    {
        double PrevNumbersWithoutZero = NumbersWithoutZero;
        double PrevNumbersEndingWithZero = NumbersEndingWithZero;
        double PrevNumbersWithTwoZeros = NumbersWithTwoZeros;

        NumbersWithoutZero = (PrevNumbersWithoutZero + PrevNumbersEndingWithZero) * (K - 1);
        NumbersEndingWithZero = PrevNumbersWithoutZero;
        NumbersWithTwoZeros = PrevNumbersWithTwoZeros * K + PrevNumbersEndingWithZero;
    }

    // FIX_ME: добавить std::
    //cout << "Числа без двух подряд идущих нулей: " << fixed << nz + oz << "\n";
    //cout << "Числа с двумя и более подряд идущими нулями: " << fixed << tz << "\n";
    std::cout << "Числа без двух подряд идущих нулей: " << std::fixed << NumbersWithoutZero + NumbersEndingWithZero << "\n";
    std::cout << "Числа с двумя и более подряд идущими нулями: " << std::fixed << NumbersWithTwoZeros << "\n";

    return 0;
}
