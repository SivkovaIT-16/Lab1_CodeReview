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

// FIX_ME: using namespace std в глобальной области видимости
//using namespace std;

int main()
{
    // FIX_ME: переменные должны быть инициализированы при объявлении
    // FIX_ME: имена переменных должны начинаться с большой буквы и не должны содержать нижжних подчёркиваний
    //int n, b, k, weight, volume, ind_i, ind_j;
    int N = 0, B = 0, K = 0, Weight = 0, Volume = 0, IndexI = 0, IndexJ = 0;

    // FIX_ME: добавить std::
    // FIX_ME: имя переменной должно начинаться с большой буквы
    //ifstream stream;
    std::ifstream Stream;

    // FIX_ME: обновлены имена переменных
    //stream.open("a.txt");
    //stream >> n;
    //stream >> b;
    Stream.open("a.txt");
    Stream >> N;
    Stream >> B;

    // FIX_ME: добавить std::
    //FIX_ME: обновлено имя переменной
    // FIX_ME: отсутствуют пробелы вокруг бинарного оператора '+'
    // FIX_ME: имя переменной должно начинаться с заглавной буквы и не должно содержать нижних подчёркиваний
    //vector <int> weight_vector(n+1);
    std::vector<int> Weights(N + 1);

    // FIX_ME: отсутствуют фигурные скобки для for
    // FIX_ME: использовать префиксный инкремент
    // FIX_ME: обновлены имена переменных
    //for (int i = 1; i <= n; i++)
    //    stream >> weight_vector[i];
    for (int i = 1; i <= N; ++i)
    {
        Stream >> Weights[i];
    }

    // FIX_ME: добавить std::
    //FIX_ME: обновлено имя переменной
    // FIX_ME: отсутствуют пробелы вокруг бинарного оператора '+'
    // FIX_ME: имя переменной должно начинаться с заглавной буквы и не должно содержать нижних подчёркиваний
    //vector <int> volume_vector(n+1);
    std::vector<int> Volumes(N + 1);

    // FIX_ME: отсутствуют фигурные скобки для for
    // FIX_ME: использовать префиксный инкремент
    // FIX_ME: обновлены имена переменных
    //for (int i = 1; i <= n; i++)
    //    stream >> volume_vector[i];
    for (int i = 1; i <= N; ++i)
    {
        Stream >> Volumes[i];
    }

    // FIX_ME: добавить std::
    // FIX_ME: имена переменных должны быть информативными, начинаться с заглавной буквы и не должны содержать нижних подчёркиваний
    // FIX_ME: лишние пробелы между угловыми скобками
    // FIX_ME: отсутствуют пробелы вокруг бинарного оператора '+'
    //vector <vector <int>> main_vector(n+1, vector <int>(b+1, 0));
    //vector <vector <int>> sum_volume_vector(n+1, vector <int>(b+1, 0));
    std::vector<std::vector<int>> WeightMatrix(N + 1, std::vector<int>(B + 1, 0));
    std::vector<std::vector<int>> VolumeMatrix(N + 1, std::vector<int>(B + 1, 0));

    // FIX_ME: использовать префиксный инкремент
    //FIX_ME: обновлено имя переменной
    //for (int i = 1; i <= n; i++)
    for (int i = 1; i <= N; ++i)
    {
        // FIX_ME: использовать префиксный инкремент
        //FIX_ME: обновлено имя переменной
        //for (int j = 1; j <= b; j++)
        for (int j = 1; j <= B; ++j)
        {
            //FIX_ME: обновлено имя переменной
            //if (j >= weight_vector[i])
            if (j >= Weights[i])
            {
                // FIX_ME: отсутствуют пробелы вокруг бинарного оператора '-'
                // FIX_ME: обновлены имена переменных
                //main_vector[i][j] = main_vector[i-1][j] + weight_vector[i];
                //sum_volume_vector[i][j] = sum_volume_vector[i-1][j] + volume_vector[i];
                WeightMatrix[i][j] = WeightMatrix[i - 1][j] + Weights[i];
                VolumeMatrix[i][j] = VolumeMatrix[i - 1][j] + Volumes[i];
            }
            else
            {
                // FIX_ME: отсутствуют пробелы вокруг бинарного оператора '-'
                // FIX_ME: обновлены имена переменных
                //main_vector[i][j] = main_vector[i-1][j];
                //sum_volume_vector[i][j] = sum_volume_vector[i-1][j];
                WeightMatrix[i][j] = WeightMatrix[i - 1][j];
                VolumeMatrix[i][j] = VolumeMatrix[i - 1][j];
            }
        }
    }
    // FIX_ME: обновлены имена переменных
    //k = b;
    K = B;

    //FIX_ME: булевы переменные должны начинаться с префикса 'b'
    //bool flag = true;
    bool bFlag = true;

    // FIX_ME: избыточное сравнение с true
    // FIX_ME: использовать префиксный инкремент
    // FIX_ME: обновлены имена переменных
    //while (flag == true && k >= 1)
    //{
    //    for (int i = n; i >= 1; i--)
    //    {
    //        for (int j = b; j >= 1; j--)
    //        {
    //            if (main_vector[i][j] == k)
    //            {
    //                ind_i = i; ind_j = j;
    //                weight = main_vector[i][j];
    //                volume = sum_volume_vector[i][j];
    //                flag = false;
    //            }
    while (bFlag && K >= 1)
    {
        for (int i = N; i >= 1; --i)
        {
            for (int j = B; j >= 1; --j)
            {
                if (WeightMatrix[i][j] == K)
                {

                    IndexI = i;
                    IndexJ = j;
                    Weight = WeightMatrix[i][j];
                    Volume = VolumeMatrix[i][j];
                    bFlag = false;
                }
                // FIX_ME: избыточное сравнение с false
                //FIX_ME: обновлено имя переменной
                // FIX_ME: отсутствуют фигурные скобки для if
                //if (flag == false)
                if (!bFlag)
                {
                    break;
                }
            }
            // FIX_ME: избыточное сравнение с false
            //FIX_ME: обновлено имя переменной
            // FIX_ME: отсутствуют фигурные скобки для if
            //if (flag == false)
            if (!bFlag)
            {
                break;
            }
        }
        // FIX_ME: использовать префиксный декремент
        //FIX_ME: обновлено имя переменной
        //k--;
        --K;
    }
    // FIX_ME: обновлены имена переменных
    // FIX_ME: добавить std::cout
    //cout << "weight: " << weight << " volume: " << volume << endl;
    //cout << "artifact numbers: ";
    std::cout << "weight: " << Weight << " volume: " << Volume << std::endl;
    std::cout << "artifact numbers: ";
    // FIX_ME: имя функции изменено, параметры обновлены
    //find_numbers(main_vector, ind_i, ind_j, weight_vector);
    FindNumbers(WeightMatrix, IndexI, IndexJ, Weights);
}
