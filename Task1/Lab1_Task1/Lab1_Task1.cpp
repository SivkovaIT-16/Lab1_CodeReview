//Археолог нашел N артефактов.Известны веса(сi) и объемы(di) артефактов.Нужно выбрать такое подмножество
//найденных вещей, чтобы суммарный их вес не превысил B кг, но был наиболее близок к B, а количество 
//взятых артефактов было как можно больше.Известно, что решение единственно.Укажите порядковые номера 
//вещей, которые надо взять.Исходные данные находятся в текстовом файле, в первой строке указаны N и B, 
//а во второй строке значения весов(в кг), в третьей объемы находок(в куб.см).Вывести так же суммарный 
//вес и суммарный объем результата.

// FIX_ME: программа должна быть разделена на модули (заголовочный файл .h и файл реализации .cpp)

#include "Task1.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
// FIX_ME: добавлена библиотека
#include <limits>

// FIX_ME: using namespace std в глобальной области видимости
//using namespace std;

int main()
{
    // FIX_ME: добавлена поддержка русского языка
    setlocale(LC_ALL,"Russian");

    // FIX_ME: переменные должны быть инициализированы при объявлении
    // FIX_ME: имена переменных должны начинаться с большой буквы и не должны содержать нижжних подчёркиваний
    //int n, b, k, weight, volume, ind_i, ind_j;
    int N = 0, B = 0, Weight = 0, Volume = 0, IndexI = 0, IndexJ = 0;

    // FIX_ME: добавить std::
    // FIX_ME: имя переменной должно начинаться с большой буквы
    //ifstream stream;
    std::ifstream Stream;

    // FIX_ME: добавлена проверка открытия файла
    //stream.open("a.txt");
    if (!OpenFile(Stream, "a.txt"))
    {
        return 1;
    }

    // FIX_ME: добавлена проверка корректности N
    //stream >> n;
    if (!ReadNumber(Stream, N) || N <= 0 || N >= 20)
    {
        std::cerr << "Ошибка: N должно быть положительным числом" << std::endl;
        return 1;
    }

    // FIX_ME: добавлена проверка корректности B
    //stream >> b;
    if (!ReadNumber(Stream, B) || B <= 0)
    {
        std::cerr << "Ошибка: B должно быть положительным числом" << std::endl;
        return 1;
    }

    // FIX_ME: добавлена инициализация векторов при объявлении
    // FIX_ME: добавить std::
    // FIX_ME: отсутствуют пробелы вокруг бинарного оператора '+'
    // FIX_ME: имя переменной должно начинаться с заглавной буквы и не должно содержать нижних подчёркиваний
    //vector <int> weight_vector(n+1);
    //vector <int> volume_vector(n + 1);
    std::vector<int> Weights(N + 1, 0);
    if (!ReadArray(Stream, Weights, N, "вес"))
    {
        return 1;
    }
    std::vector<int> Volumes(N + 1, 0);
    if (!ReadArray(Stream, Volumes, N, "объём"))
    {
        return 1;
    }

    // FIX_ME: добавлено закрытие файла
    Stream.close();

    // FIX_ME: добавить std::
    // FIX_ME: имена переменных должны быть информативными, начинаться с заглавной буквы и не должны содержать нижних подчёркиваний
    // FIX_ME: лишние пробелы между угловыми скобками
    // FIX_ME: отсутствуют пробелы вокруг бинарного оператора '+'
    //vector <vector <int>> main_vector(n+1, vector <int>(b+1, 0));
    //vector <vector <int>> sum_volume_vector(n+1, vector <int>(b+1, 0));
    std::vector<std::vector<int>> WeightMatrix(N + 1, std::vector<int>(B + 1, 0));
    std::vector<std::vector<int>> VolumeMatrix(N + 1, std::vector<int>(B + 1, 0));
    // FIX_ME: добавлена матрица для отслеживания количества предметов
    std::vector<std::vector<int>> CountMatrix(N + 1, std::vector<int>(B + 1, 0));

    // FIX_ME: использовать префиксный инкремент
    //for (int i = 1; i <= n; i++)
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= B; ++j)
        {
            // FIX_ME: исправлена логика алгоритма
            WeightMatrix[i][j] = WeightMatrix[i - 1][j];
            VolumeMatrix[i][j] = VolumeMatrix[i - 1][j];
            CountMatrix[i][j] = CountMatrix[i - 1][j];

            if (j >= Weights[i])
            {
                int NewWeight = WeightMatrix[i - 1][j - Weights[i]] + Weights[i];
                int NewVolume = VolumeMatrix[i - 1][j - Weights[i]] + Volumes[i];
                int NewCount = CountMatrix[i - 1][j - Weights[i]] + 1;

                // FIX_ME: добавлено сравнение по приоритетам:
                // 1. Больше количество предметов
                // 2. Вес ближе к B
                if (NewCount > CountMatrix[i][j] ||
                    (NewCount == CountMatrix[i][j] &&
                        abs(B - NewWeight) < abs(B - WeightMatrix[i][j])))
                {
                    WeightMatrix[i][j] = NewWeight;
                    VolumeMatrix[i][j] = NewVolume;
                    CountMatrix[i][j] = NewCount;
                }
            }
        }
    }

    // FIX_ME: улучшен поиск оптимального решения
    int BestWeight = 0;
    int BestVolume = 0;
    int BestCount = 0;

    for (int j = B; j >= 0; --j)
    {
        if (CountMatrix[N][j] > BestCount ||
            (CountMatrix[N][j] == BestCount && WeightMatrix[N][j] > BestWeight))
        {
            BestCount = CountMatrix[N][j];
            BestWeight = WeightMatrix[N][j];
            BestVolume = VolumeMatrix[N][j];
            IndexI = N;
            IndexJ = j;
        }
    }

    // FIX_ME: добавлена проверка, что решение найдено
    if (BestWeight == 0)
    {
        std::cerr << "Ошибка: не удалось найти подходящее подмножество" << std::endl;
        return 1;
    }

    // FIX_ME: добавить std::
    //cout << "weight: " << weight << " volume: " << volume << endl;
    //cout << "artifact numbers: ";
    std::cout << "weight: " << BestWeight << " volume: " << BestVolume << std::endl;
    std::cout << "artifact numbers: ";

    //find_numbers(main_vector, ind_i, ind_j, weight_vector);
    FindNumbers(WeightMatrix, IndexI, IndexJ, Weights);
}
