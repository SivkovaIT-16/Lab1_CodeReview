#include <string>

// FIX_ME: фигурная скобка должна быть на новой строке
// FIX_ME: параметр должен быть константной ссылкой
// FIX_ME: имя функции должно быть информативным
// FIX_ME: имя параметра должно начинаться с заглавной буквы и быть информативным
// FIX_ME: добавить std::
//int Calc(string s);
int CalculateExpression(const std::string& Expression);

// FIX_ME: фигурная скобка должна быть на новой строке
// FIX_ME: параметр должен быть константной ссылкой 
// FIX_ME: имя функции должно быть информативным 
// FIX_ME: имя параметра должно начинаться с заглавной буквы и быть информативным
// FIX_ME: добавить std::
//int Num(string s) {
int ParseNumber(const std::string& Text);

// FIX_ME: фигурная скобка должна быть на новой строке
// FIX_ME: параметр должен быть константной ссылкой
// FIX_ME: имя функции должно быть информативным 
// FIX_ME: имя параметра должно начинаться с заглавной буквы и быть информативным
// FIX_ME: добавлены параметры Index и Level для рекурсивного обхода без циклов
// FIX_ME: добавить std::
//int Term(string s) {
int ParseTerm(const std::string& Text, int Index, int Level);

// FIX_ME: добавить функции проверки ввода
bool IsValidExpression(const std::string& Expression);
bool CheckExpression(const std::string& Expression, int& Index, int& Balance);