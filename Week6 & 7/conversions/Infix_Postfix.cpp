#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

// int precedence(String opr)
// {
//     if (opr == "*" || opr == "/" || opr == "%")
//     {
//         return 6;
//     }
//     if (opr == "+" || opr == "-")
//     {
//         return 5;
//     }
//     if (opr == "<" || opr == ">")
//     {
//         return 4;
//     }
//     if (opr == "!")
//     {
//         return 3;
//     }
//     if (opr == "&")
//     {
//         return 2;
//     }
//     if (opr == "|")
//     {
//         return 1;
//     }
//     cout << "Invalid Operator or undefined ";
//     return 0;
// }
const int stack[50];
int Top = 0;

void push(string value)
{
    if (Top == 50)
    {
        cout << "Stack Overflow ";
        return;
    }
    stack[Top] = value;
    Top++;
}
string pop()
{
    if (Top == 0)
    {
        cout << "Stack Underflow";
        return NULL;
    }
    Top--;
    return stack[Top]
}
int main()
{

    string infix, postfix = "";
    cout << "Enter Infix expression : ";
    cin >> infix;

    string opr[] = {"+", "-", "/", "*", "%", "<", ">", "!=", "&", "|"};

    for (int i = 0; i < infix.length(); i++)
    {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
        {
            postfix += infix[i];
            cout << postfix;
        }
        else
        {
            if (Top == 0)
            {
                push(infix[i])
            }
            else
            {
            }
        }
        if (infix[i] == "(" || infix[i] == ")")
        {
        }
    }
}