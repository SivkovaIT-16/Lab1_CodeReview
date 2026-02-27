#include "Task2.h"
#include <iostream>

// FIX_ME: добавлены новые функции для работы с файлами 
bool ReadBoardSize(std::ifstream& Stream, int& Size)
{
    Stream >> Size;
    if (Stream.fail())
    {
        std::cerr << "Ошибка: некорректный размер доски в файле" << std::endl;
        return false;
    }

    // FIX_ME: добавлена проверка диапазона (1 < N < 80)
    if (Size <= 1 || Size >= 80)
    {
        std::cerr << "Ошибка: размер доски должен быть в диапазоне 1 < N < 80" << std::endl;
        return false;
    }
    return true;
}

bool ReadBoardData(std::ifstream& Stream, std::vector<std::vector<int>>& Board, int Size)
{
    for (int i = 0; i < Size; ++i)
    {
        for (int j = 0; j < Size; ++j)
        {
            Stream >> Board[i][j];
            if (Stream.fail())
            {
                std::cerr << "Ошибка: некорректные данные в клетке [" << i << "][" << j << "]" << std::endl;
                return false;
            }

            // FIX_ME: добавлена проверка диапазона (0 до 30)
            if (Board[i][j] < 0 || Board[i][j] > 30)
            {
                std::cerr << "Ошибка: значение в клетке должно быть от 0 до 30" << std::endl;
                return false;
            }
        }
    }
    return true;
}