//Во всех заданиях данной подгруппы предполагается, что исходные строки, определяющие выражения, 
//не содержат пробелов.При выполнении заданий не следует использовать оператор цикла.
//Вывести значение целочисленного выражения, заданного в виде строки S.Выражение
//определяется следующим образом :
//<выражение> :: = <цифра> | (<выражение><знак><выражение>)
//< знак > :: = +| − | *

#include <iostream>
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
int ParseNumber(const std::string& Text)
{
    // FIX_ME: фигурная скобка должна быть на новой строке
    // FIX_ME: имя параметра обновлено
    //if (s[0] == '(' && s[s.length() - 1] == ')') {
    if (Text[0] == '(' && Text[Text.length() - 1] == ')')
    {
        // FIX_ME: имя параметра обновлено
        //return Calc(s.substr(1, s.length() - 2));
        return Calc(Text.substr(1, Text.length() - 2));
    }
    // FIX_ME: фигурная скобка должна быть на новой строке
    //else {
    else
    {
        // FIX_ME: имя параметра обновлено
        // FIX_ME: добавить std::
        //return stoi(s);
        return std::stoi(Text);
    }
}

// FIX_ME: фигурная скобка должна быть на новой строке
// FIX_ME: параметр должен быть константной ссылкой
// FIX_ME: имя функции должно быть информативным 
// FIX_ME: имя параметра должно начинаться с заглавной буквы и быть информативным
// FIX_ME: добавить std::
//int Term(string s) {
int ParseTerm(const std::string& Text)
{
    // FIX_ME: имена переменных должны быть информативными и начинаться с заглавной буквы
    //int i = s.length() - 1;
    //int level = 0;
    //int pos = -1;
    int Index = Text.length() - 1;
    int Level = 0;
    int OperatorPosition = -1;

    // FIX_ME: имя переменной обновлено
    // FIX_ME: фигурная скобка должна быть на новой строке
    //while (i >= 0) {
    while (Index >= 0)
    {
        // FIX_ME: имена переменных и имя параметра обновлены
        // FIX_ME: фигурная скобка должна быть на новой строке
        // FIX_ME: использовать префиксный инкремент
        //if (s[i] == ')') {
        //    level++;
        //}
        if (Text[Index] == ')')
        {
            ++Level;
        }
        // FIX_ME: имена переменных и имя параметра обновлены
        // FIX_ME: фигурная скобка должна быть на новой строке
        // FIX_ME: использовать префиксный декремент
        //else if (s[i] == '(') {
        //    level--;
        //}
        else if (Text[Index] == '(')
        {
            --Level;
        }
        // FIX_ME: имена переменных и имя параметра обновлены
        // FIX_ME: фигурная скобка должна быть на новой строке
        // FIX_ME: использовать префиксный декремент
        //else if (level == 0 && s[i] == '*') {
        //    pos = i;
        //    break;
        //}
        //i--;
        else if (Level == 0 && Text[Index] == '*')
        {
            OperatorPosition = Index;
            break;
        }
        --Index;
    }
    // FIX_ME: имена переменных, имя параметра и имена функций обновлены
    // FIX_ME: фигурная скобка должна быть на новой строке
    //if (pos == -1) {
    //    return Num(s);
    //}
    //return Term(s.substr(0, pos)) * Num(s.substr(pos + 1));
    if (OperatorPosition == -1)
    {
        return ParseNumber(text);
    }
    return ParseTerm(Text.substr(0, OperatorPosition)) *
        ParseNumber(Text.substr(OperatorPosition + 1));
}

// FIX_ME: фигурная скобка должна быть на новой строке
// FIX_ME: параметр должен быть константной ссылкой
// FIX_ME: имя функции должно быть информативным
// FIX_ME: имя параметра должно начинаться с заглавной буквы и быть информативным
// FIX_ME: добавить std::
//int Calc(string s) {
int CalculateExpression(const std::string& Expression)
{
    // FIX_ME: имена переменных должны быть информативными и начинаться с заглавной буквы
    // FIX_ME: имя параметра обновлено
    //int i = s.length() - 1;
    //int level = 0;
    //int pos = -1;
    int Index = Expression.length() - 1;
    int Level = 0;
    int OperatorPosition = -1;

    // FIX_ME: имя переменной обновлено
    // FIX_ME: фигурная скобка должна быть на новой строке
    //while (i >= 0) {
    while (Index >= 0)
    {
        // FIX_ME: имена переменных и имя параметра обновлены
        // FIX_ME: фигурная скобка должна быть на новой строке
        // FIX_ME: использовать префиксный инкремент
        //if (s[i] == ')') {
        //    level++;
        //}
        if (Expression[Index] == ')')
        {
            ++Level;
        }
        // FIX_ME: имена переменных и имя параметра обновлены
        // FIX_ME: фигурная скобка должна быть на новой строке
        // FIX_ME: использовать префиксный декремент
        //else if (s[i] == '(') {
        //    level--;
        //}
        else if (Expression[Index] == '(')
        {
            --Level;
        }
        // FIX_ME: имена переменных и имя параметра обновлены
        // FIX_ME: фигурная скобка должна быть на новой строке
        // FIX_ME: использовать префиксный декремент
        //else if (level == 0 && (s[i] == '+' || s[i] == '-')) {
        //    pos = i;
        //    break;
        //}
        //i--;
        else if (Level == 0 && (Expression[Index] == '+' || Expression[Index] == '-'))
        {
            OperatorPosition = Index;
            break;
        }
        --Index;

    }

    // FIX_ME: имя переменной, имя параметра и имя функции обновлены
    // FIX_ME: фигурная скобка должна быть на новой строке
    //if (pos == -1) {
    //    return Term(s);
    //}
    if (OperatorPosition == -1)
    {
        // FIX_ME: имя функции изменено
        return ParseTerm(Expression);
    }

    // FIX_ME: имя переменной должно быть информативным и начинаться с заглавной буквы
    // // FIX_ME: имя переменной и имя параметра обновлены
    //char op = s[pos];
    char Operator = Expression[OperatorPosition];

    // FIX_ME: имя переменной, имя параметра и имена функций обновлены
    // FIX_ME: фигурная скобка должна быть на новой строке
    //if (op == '+') {
    //    return Calc(s.substr(0, pos)) + Term(s.substr(pos + 1));
    //}
    if (Operator == '+')
    {
        return CalculateExpression(Expression.substr(0, OperatorPosition)) +
            ParseTerm(Expression.substr(OperatorPosition + 1));
    }

    // FIX_ME: имя переменной, имя параметра и имена функций обновлены
    // FIX_ME: фигурная скобка должна быть на новой строке
    //if (op == '-') {
    //    return Calc(s.substr(0, pos)) - Term(s.substr(pos + 1));
    //}
    if (Operator == '-')
    {
        return CalculateExpression(Expression.substr(0, OperatorPosition)) -
            ParseTerm(Expression.substr(OperatorPosition + 1));
    }


    return 0;
}

//FIX_ME: фигурная скобка должна быть на новой строке
//int main() {
int main()
{
    setlocale(0, "");
    // FIX_ME: добавить std::
    // FIX_ME: имя переменной должно быть информативным и начинаться с заглавной буквы
    //string s;
    std::string Expression;
    // FIX_ME: добавить std::
    // FIX_ME: имя функции  и имя переменной обновлены
    //cout << "Введите строку вида - <цифра> | (<выражение><знак><выражение>), где знак - (+ | - | *):" << endl;
    //cin >> s;
    //cout << "Результат: " << Calc(s) << endl;
    std::cout << "Введите строку вида - <цифра> | (<выражение><знак><выражение>), где знак - (+ | - | *):" << std::endl;
    std::cin >> Expression;
    std::cout << "Результат: " << CalculateExpression(Expression) << std::endl;
    return 0;
}