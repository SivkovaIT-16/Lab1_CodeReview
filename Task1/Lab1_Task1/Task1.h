#include <vector>
#include <string>
#include <fstream>

// FIX_ME: имя функции должно начинаться с заглавной буквы и не должно содержать нижних подчёркиваний
// FIX_ME: параметры должны начинаться с заглавной буквы и быть информативными
// FIX_ME: лишние пробелы в угловых скобках
//void find_numbers(vector <vector <int>> &Mvector, int i, int j, vector <int> &Wvector);
void FindNumbers(std::vector<std::vector<int>>& Matrix, int Row, int Col, std::vector<int>& Weights);

// FIX_ME: добавлены функции для работы с файлами (отсутствовали в исходном коде)
bool OpenFile(std::ifstream& Stream, const std::string& FileName);
bool ReadNumber(std::ifstream& Stream, int& Value);
bool ReadArray(std::ifstream& Stream, std::vector<int>& Array, int Size, const std::string& ArrayName);
