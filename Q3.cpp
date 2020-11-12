#include "Stack.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool parcheck(const string & expression);

int main()
{
    string str;
    getline(cin, str);

    if (parcheck(str))
        cout << "Correct Expression" << endl;
    else
    {
        cout << "Incorrect Expression" << endl;
    }
    
    return 0;
}

bool parcheck(const string & expression)
{
    char str[25];
    char pars[25];
    Stack<char> s;
    char x;
    int count1 = 0;
    int count2 = 0;

    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] == ' ')
            continue;
        else if ((expression[i] == '+') || (expression[i]) == '-' || (expression[i] == '/') || (expression[i] == '*') || (expression[i] == '{') || (expression[i] == '}') || (expression[i] == '(') || (expression[i] == ')') || ((expression[i]  >= '0') && (expression[i] <= '9')))
        {
            str[count1] = expression[i];
            count1++;
        }
        else 
            return false;
    }

    for (int i = 0; i < count1; i++)
    {
        if ((str[i] == '(') || (str[i] == ')') ||  (str[i] == '{') || (str[i] == '}'))
        {
            pars[count2] = str[i];
            count2++;
        }
    }
    
    for (int i = 0; i < count2; i++)
    {
        if (pars[i] == '(' || pars[i] == '{')
        {
            s.push(str[i]);
            continue;
        }

        if (s.isEmpty())
            return false;
        
        else if (pars[i] == ')')
        {
            x = s.pop();
            if (x == '{')
                return false;
        }

        else if(pars[i] == '}')
        {
            x = s.pop();
            if (x == '(')
                return false;
        }
    }

    return (s.isEmpty());
    
}
