#include "Task4.h"
#include <string>
// FIX_ME: добавлена библиотека
#include <stdexcept>

int ParseNumber(const std::string& Text)
{
    // FIX_ME: добавлена проверка на пустое выражение
    if (Text.empty())
    {
        throw std::runtime_error("Пустое выражение");
    }
    // FIX_ME: фигурная скобка должна быть на новой строке
    //if (s[0] == '(' && s[s.length() - 1] == ')') {
    if (Text[0] == '(' && Text[Text.length() - 1] == ')')
    {
        //return Calc(s.substr(1, s.length() - 2));
        return CalculateExpression(Text.substr(1, Text.length() - 2));
    }
    // FIX_ME: фигурная скобка должна быть на новой строке
    //else {
    else
    {
        // FIX_ME: добавлена проверка
        if (Text.length() == 1)
        {
            if (!std::isdigit(Text[0]))
            {
                throw std::runtime_error("Ожидалась цифра, получено: " + Text);
            }
            return std::stoi(Text);
        }
        else
        {
            if (!std::isdigit(Text[0]))
            {
                throw std::runtime_error("Ожидалась цифра, получено: " + Text);
            }
            // FIX_ME: рекурсивный вызов для проверки остальных символов
            return ParseNumber(Text.substr(1));
        }
    }
}

// FIX_ME: удалены все циклы, используется рекурсия
int ParseTerm(const std::string& Text, int Index, int Level)
{
    // FIX_ME: базовый случай рекурсии
    if (Index < 0)
    {
        return ParseNumber(Text);
    }

    // FIX_ME: рекурсивный обход строки справа налево
    if (Text[Index] == ')')
    {
        return ParseTerm(Text, Index - 1, Level + 1);
    }
    else if (Text[Index] == '(')
    {
        return ParseTerm(Text, Index - 1, Level - 1);
    }
    else if (Level == 0 && Text[Index] == '*')
    {
        // FIX_ME: найден оператор умножения
        return ParseTerm(Text.substr(0, Index), Index - 1, 0) *
            ParseNumber(Text.substr(Index + 1));
    }
    else if (Level == 0 && (Text[Index] == '+' || Text[Index] == '-'))
    {
        // FIX_ME: найден оператор сложения или вычитания
        char Op = Text[Index];
        if (Op == '+')
        {
            return CalculateExpression(Text.substr(0, Index)) +
                ParseTerm(Text.substr(Index + 1), Text.substr(Index + 1).length() - 1, 0);
        }
        else
        {
            return CalculateExpression(Text.substr(0, Index)) -
                ParseTerm(Text.substr(Index + 1), Text.substr(Index + 1).length() - 1, 0);
        }
    }
    else
    {
        // FIX_ME: продолжаем движение влево
        return ParseTerm(Text, Index - 1, Level);
    }
}

// FIX_ME: рекурсивная функция без циклов
int CalculateExpression(const std::string& Expression)
{
    return ParseTerm(Expression, Expression.length() - 1, 0);
}

bool CheckExpression(const std::string& Expression, int& Index, int& Balance)
{
    // FIX_ME: базовый случай - достигнут конец строки
    if (Index >= static_cast<int>(Expression.length()))
    {
        return Balance == 0;
    }

    char Ch = Expression[Index];
    Index++;

    // FIX_ME: проверка допустимых символов
    if (!std::isdigit(Ch) && Ch != '(' && Ch != ')' &&
        Ch != '+' && Ch != '-' && Ch != '*')
    {
        return false;
    }

    // FIX_ME: проверка баланса скобок
    if (Ch == '(') Balance++;
    if (Ch == ')') Balance--;
    if (Balance < 0) return false;

    // FIX_ME: рекурсивный вызов для следующего символа
    return CheckExpression(Expression, Index, Balance);
}

// FIX_ME: добавлена функция проверки валидности выражения
bool IsValidExpression(const std::string& Expression)
{
    if (Expression.empty()) return false;

    int Index = 0;
    int Balance = 0;
    return CheckExpression(Expression, Index, Balance);
}