#include <string>

// FIX_ME: using namespace std в глобальной области видимости
// using namespace std;

// FIX_ME: обновлено имя и параметр прототипа функции
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
// FIX_ME: добавить std::
//int Term(string s) {
int ParseTerm(const std::string& Text);

// FIX_ME: добавить функции проверки ввода
bool IsValidExpression(const std::string& Expression);
bool IsBalancedParentheses(const std::string& Expression);
bool HasValidCharacters(const std::string& Expression);