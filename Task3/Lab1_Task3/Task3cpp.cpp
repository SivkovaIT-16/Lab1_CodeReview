#include "Task3.h"
#include <iostream>

// FIX_ME: добавлена функция проверки K (2 ≤ K ≤ 10)
bool ValidateK(int K)
{
    if (K < 2 || K > 10)
    {
        std::cout << "Ошибка: K должно быть в диапазоне 2 ≤ K ≤ 10" << std::endl;
        return false;
    }
    return true;
}

// FIX_ME: добавлена функция проверки N (1 < N < 20, N + K < 26)
bool ValidateN(int N, int K)
{
    if (N <= 1)
    {
        std::cout << "Ошибка: N должно быть > 1" << std::endl;
        return false;
    }
    if (N >= 20)
    {
        std::cout << "Ошибка: N должно быть < 20" << std::endl;
        return false;
    }
    if (N + K >= 26)
    {
        std::cout << "Ошибка: N + K должно быть < 26" << std::endl;
        return false;
    }
    return true;
}