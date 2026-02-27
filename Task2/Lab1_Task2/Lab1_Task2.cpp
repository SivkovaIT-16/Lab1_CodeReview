//Хромой король.На квадратной доске в каждой клетке короля ожидают неприятности в количестве 
//от 0 до 30. Хромой король, находящийся в правом верхнем углу, мечтает попасть в левый нижний 
//угол.При этом он может передвигаться только в клетку слева или снизу и хочет, чтобы сумма 
//всех неприятностей, оказавшихся у него на пути, была бы минимальной.
//Определить эту сумму и путь, каким образом должен двигаться король.Ввод и вывод организовать 
//при помощи текстовых файлов.Формат входных данных : в первой строке входного файла
//записано число N - размер доски(1 < N < 80).Далее следует N строк, каждая из которых содержит
//N чисел - количество неприятностей в клетках доски.В первую строку выходного файл нужно
//вывести единственное число : минимальную сумму, а во второй строке вывести путь в виде
//строки символов, обозначив символом L движение влево, а символом D - движение вниз.

// FIX_ME: программа должна быть разделена на модули (заголовочный файл .h и файл реализации .cpp)

#include "Task2.h"
#include <iostream> 
#include <fstream>  
#include <vector>    
#include <algorithm> 

// FIX_ME: using namespace std в глобальной области видимости
//using namespace std;

// FIX_ME: фигурная скобка должна быть на новой строке
//int main() {
int main()
{
    // FIX_ME: добавлена поддержка русского языка
    setlocale(LC_ALL, "Russian");

    // FIX_ME: добавлена проверка открытия файлов с использованием функций
    // FIX_ME: имена переменных должны начинаться с заглавной буквы
    // FIX_ME: добавить std::
    //ifstream inputFile("input1.txt");
    //ofstream outputFile("output1.txt");
    std::ifstream InputFile("input1.txt");
    std::ofstream OutputFile("output1.txt");

    // FIX_ME: фигурная скобка должна быть на новой строке
    // FIX_ME: добавить std:: 
    //if (!inputFile.is_open()) {
    //    cerr << "Не удалось открыть входной файл!" << endl;
    //    return 1;
    //}
    if (!InputFile.is_open())
    {
        std::cerr << "Не удалось открыть входной файл!" << std::endl;
        return 1;
    }


    // FIX_ME: фигурная скобка должна быть на новой строке
    // FIX_ME: добавить std:: 
    //if (!outputFile.is_open()) {
    //    cerr << "Не удалось открыть выходной файл!" << endl;
    //    inputFile.close();
    //    return 1;
    //}
    if (!OutputFile.is_open())
    {
        std::cerr << "Не удалось открыть выходной файл!" << std::endl;
        InputFile.close();
        return 1;
    }

    // FIX_ME: имя переменной должно начинаться с заглавной буквы
    // FIX_ME: переменная должна быть инициализирована
    //int n;
    int N = 0;

    // FIX_ME: добавлена проверка чтения размера доски 
    //inputFile >> n;
    if (!ReadBoardSize(InputFile, N))
    {
        InputFile.close();
        OutputFile.close();
        return 1;
    }

    // FIX_ME: имена переменных должны начинаться с заглавной буквы
    // FIX_ME: убрать лишние пробелы в угловых скобках
    // FIX_ME: добавить std::
    //vector<vector<int>> board(n, vector<int>(n));
    std::vector<std::vector<int>> Board(N, std::vector<int>(N)); // Создает двумерный вектор (матрицу) board размера n x n для хранения значений доски.

    // FIX_ME: добавлена проверка чтения данных доски через функцию
    //for (int i = 0; i < n; ++i) { 
    //    for (int j = 0; j < n; ++j) { 
    //        inputFile >> board[i][j];
    //    }
    //}
    if (!ReadBoardData(InputFile, Board, N))
    {
        InputFile.close();
        OutputFile.close();
        return 1;
    }

    //inputFile.close();
    InputFile.close();

    // FIX_ME: имена переменных должны начинаться с заглавной буквы
    // FIX_ME: убрать лишние пробелы в угловых скобках
    // FIX_ME: комментарии должны начинаться с заглавной буквы, добавить пробел после '//'
    //vector<vector<int>> dp(n, vector<int>(n, 0)); // хранит минимальную сумму неприятностей для достижения клетки (i, j).
    //vector<vector<char>> path(n, vector<char>(n, ' '));//path[i][j] хранит символ 'L' (влево) или 'D' (вниз), указывающий, откуда мы пришли в клетку (i, j).
    std::vector<std::vector<int>> DP(N, std::vector<int>(N, 0)); // Xранит минимальную сумму неприятностей для достижения клетки (i, j).
    std::vector<std::vector<char>> Path(N, std::vector<char>(N, ' ')); // Path[i][j] хранит символ 'L' (влево) или 'D' (вниз), указывающий, откуда мы пришли в клетку (i, j).

    //dp[0][n - 1] = board[0][n - 1];
    DP[0][N - 1] = Board[0][N - 1];

    // Заполняем первый столбец (движение только вниз):
    // FIX_ME: фигурная скобка должна быть на новой строке
    //for (int = 1; i < n; ++i) {
    for (int i = 1; i < N; ++i)
    {
        //dp[i][n - 1] = dp[i - 1][n - 1] + board[i][n - 1];
        //path[i][n - 1] = 'D';
        DP[i][N - 1] = DP[i - 1][N - 1] + Board[i][N - 1];
        Path[i][N - 1] = 'D';
    }

    // Заполняем первую строку (движение только влево):
    // FIX_ME: фигурная скобка должна быть на новой строке
    //for (int j = n - 2; j >= 0; --j) {
    for (int j = N - 2; j >= 0; --j)
    {
        //dp[0][j] = dp[0][j + 1] + board[0][j]; 
        //path[0][j] = 'L';
        DP[0][j] = DP[0][j + 1] + Board[0][j];
        Path[0][j] = 'L'; // Записывает 'L' в path, указывая, что мы пришли в эту клетку справа.
    }

    // Заполняем оставшуюся часть
    // FIX_ME: фигурная скобка должна быть на новой строке
    //for (int i = 1; i < n; ++i) {
    //    for (int j = n - 2; j >= 0; --j) {
    //        if (dp[i - 1][j] < dp[i][j + 1]) {
    //            dp[i][j] = dp[i - 1][j] + board[i][j];
    //            path[i][j] = 'D';
    //        }
    //        else {
    //            dp[i][j] = dp[i][j + 1] + board[i][j];
    //            path[i][j] = 'L';
    //        }
    //    }
    //}
    for (int i = 1; i < N; ++i)
    {
        for (int j = N - 2; j >= 0; --j)
        {

            if (DP[i - 1][j] < DP[i][j + 1]) // Проверяет, какой путь лучше: сверху или справа.
            { 
                DP[i][j] = DP[i - 1][j] + Board[i][j];
                Path[i][j] = 'D';
            }
            else
            {
                DP[i][j] = DP[i][j + 1] + Board[i][j];
                Path[i][j] = 'L';
            }
        }
    }

    // Восстановление пути:
    // FIX_ME: имя переменной должно начинаться с заглавной буквы
    // FIX_ME: добавить std::
    //string route = "";
    std::string Route = "";

    // FIX_ME: имена переменных должны начинаться с заглавной буквы
    //int row = n - 1;
    //int col = 0;
    int Row = N - 1;
    int Col = 0;

    // FIX_ME: фигурная скобка должна быть на новой строке
    // // FIX_ME: использовать префиксный инкремент и декремент 
    //while (row != 0 || col != n - 1) {
    //    route += path[row][col];
    //    if (path[row][col] == 'D') {
    //        row--;
    //    }
    //    else {
    //        col++;
    //    }
    //}
    while (Row != 0 || Col != N - 1)
    {
        Route += Path[Row][Col];
        if (Path[Row][Col] == 'D')
        {
            --Row;
        }
        else {
            ++Col;
        }
    }

    // FIX_ME: добавить std::
    //reverse(route.begin(), route.end());
    std::reverse(Route.begin(), Route.end()); // Переворачивает строку route, чтобы получить путь от правой верхней клетки к левой нижней.

    // FIX_ME: добавить std::
    //outputFile << dp[n - 1][0] << endl;
    //outputFile << route << endl;
    //outputFile.close();
    OutputFile << DP[N - 1][0] << std::endl; // Записывает минимальную сумму (dp[n - 1][0]) в файл "output1.txt".
    OutputFile << Route << std::endl; // Записывает маршрут (route) в файл "output1.txt".
    OutputFile.close();

    return 0;
}