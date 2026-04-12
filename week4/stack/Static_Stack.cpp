#include <iostream>
using namespace std;

// Static Stack ( fixed size of Array )
int stack[10];
int top = 0;

// enter value in stack
void push(int value)
{
    if (top == 9) // top == size of arr -1 ;
    {
        cout << "Stack overflow";
        return;
    }
    stack[top] = value;
    top++;
}

// pop means delete ;
int pop()
{
    if (top <= 0)
    {
        cout << "Stack Underflow, Push values then pop";
        return -1;
    }
    top--;
    return stack[top];
}

int main()
{
    bool flag = true;
    int input;

    while (flag)
    {
        cout << "Enter: 1 : To Push , 2 : To Pop , 3 : To Exit => ";
        cin >> input;

        if (input == 1)
        {
            int value;
            cout << "Enter Value " << endl;
            cin >> value;
            push(value);
        }
        else if (input == 2)
        {
            int value;
            value = pop();
            cout << value << "\n";
        }
        else if (input == 3)
        {
            flag = false;
            cout << "Program Exits ";
        }
        else
        {
            cout << "Invalid Input ";
        }
    }
}