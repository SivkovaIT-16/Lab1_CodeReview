#include "Task1.h"
#include <iostream>

// FIX_ME: имя функции должно начинаться с заглавной буквы и не должно содержать нижних подчёркиваний
// FIX_ME: параметры должны начинаться с заглавной буквы и быть информативными
// FIX_ME: лишние пробелы в угловых скобках
//void find_numbers(vector <vector <int>> &Mvector, int i, int j, vector <int> &Wvector)
void FindNumbers(std::vector<std::vector<int>>& Matrix, int Row, int Col, std::vector<int>& Weights)
{
    //FIX_ME: отсутствуют фигурные скобки для if
    //if (Mvector[i][j] == 0)
    //    return;
    if (Matrix[Row][Col] == 0)
    {
        return;
    }

    // FIX_ME: отсутствуют пробелы вокруг бинарного оператора '-'
    // FIX_ME: отсутствуют фигурные скобки для if
    //if (Mvector[i-1][j] == Mvector[i][j])
    //    find_numbers(Mvector, i - 1, j, Wvector);
    if (Matrix[Row - 1][Col] == Matrix[Row][Col])
    {
        //find_numbers(Mvector, i - 1, j, Wvector);
        FindNumbers(Matrix, Row - 1, Col, Weights);
    }
    else
    {
        // FIX_ME: добавлен std::
        //cout << i << " ";
        std::cout << Row << " ";

        // FIX_ME: исправлена логика восстановления пути (должен вычитаться вес текущего предмета)
        //find_numbers(Mvector, i - 1, j, Wvector);
        FindNumbers(Matrix, Row - 1, Col - Weights[Row], Weights);
    }
}

// FIX_ME: добавлены новые функции для работы с файлами (отсутствовали в исходном коде)
bool OpenFile(std::ifstream& Stream, const std::string& FileName)
{
    Stream.open(FileName);
    if (!Stream.is_open())
    {
        std::cerr << "Ошибка: не удалось открыть файл " << FileName << std::endl;
        return false;
    }
    return true;
}

bool ReadNumber(std::ifstream& Stream, int& Value)
{
    Stream >> Value;
    if (Stream.fail())
    {
        std::cerr << "Ошибка: некорректные данные в файле" << std::endl;
        return false;
    }
    return true;
}

bool ReadArray(std::ifstream& Stream, std::vector<int>& Array, int Size, const std::string& ArrayName)
{
    for (int i = 1; i <= Size; ++i)
    {
        if (!ReadNumber(Stream, Array[i]))
        {
            std::cerr << "Ошибка: некорректное значение в " << ArrayName << " для артефакта " << i << std::endl;
            return false;
        }
        if (Array[i] < 0)
        {
            std::cerr << "Ошибка: " << ArrayName << " артефакта " << i << " должен быть положительным" << std::endl;
            return false;
        }
    }
    return true;
}