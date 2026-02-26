#include "Task1.h"
#include <iostream>

// FIX_ME: имя функции должно начинаться с заглавной буквы и не должно содержать нижних подчёркиваний
// FIX_ME: параметры должны начинаться с заглавной буквы и быть информативными
// FIX_ME: лишние пробелы в угловых скобках
//void find_numbers(vector <vector <int>> &Mvector, int i, int j, vector <int> &Wvector)
void FindNumbers(std::vector<std::vector<int>>& Matrix, int Row, int Col, std::vector<int>& Weights)
{
    //FIX_ME: отсутствуют фигурные скобки для if
    //FIX_ME: параметры обновлены
    //if (Mvector[i][j] == 0)
    if (Matrix[Row][Col] == 0)
    {
        return;
    }

    // FIX_ME: отсутствуют пробелы вокруг бинарного оператора '-'
    // FIX_ME: отсутствуют фигурные скобки для if
    // FIX_ME: параметры обновлены
    //if (Mvector[i-1][j] == Mvector[i][j])
    if (Matrix[Row - 1][Col] == Matrix[Row][Col])
    {
        // FIX_ME: имя функции изменено, параметры обновлены
        //find_numbers(Mvector, i - 1, j, Wvector);
        FindNumbers(Matrix, Row - 1, Col, Weights);
    }
    else
    {
        // FIX_ME: добавлен std::cout
        // FIX_ME: обновлён параметр
        //cout << i << " ";
        std::cout << Row << " ";
        // FIX_ME: имя функции изменено, параметры обновлены
        //find_numbers(Mvector, i - 1, j, Wvector);
        FindNumbers(Matrix, Row - 1, Col, Weights);
    }
}