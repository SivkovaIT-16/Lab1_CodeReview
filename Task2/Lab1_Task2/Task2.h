#include <vector>
#include <string>
#include <fstream>

// FIX_ME: добавлены функции для работы с файлами
bool ReadBoardSize(std::ifstream& Stream, int& Size);
bool ReadBoardData(std::ifstream& Stream, std::vector<std::vector<int>>& Board, int Size);
