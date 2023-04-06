#include <iostream>
#include <conio.h>
using namespace std;

int accept(int state)
{
    if (state == 1 || state == 3)
        return 1;
    else
        return 0;
}

int Trans(int state, char ch)
{
    if (state == 1)
    {
        if (ch == 'a')
            return 1;
        if (ch == 'b')
            return 2;
    }
    if (state == 2)
    {
        if (ch == 'a')
            return 3;
        if (ch == 'b')
            return 4;

    }
    if (state == 3)
    {
        if (ch == 'a')
            return 2;
        if (ch == 'b')
            return 1;

    }
    if (state == 4)
    {
        if (ch == 'a')
            return 3;
        if (ch == 'b')
            return 4;

    }
    return 0;
}

void StartQuiz1() {
    int state = 1;
    string str;
    cin >> str;    //getche() is legacy Throws Exception :error C4996: 'getche': The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _getche.
    int len = 0;
    while (len < str.length()) {
        int newState = Trans(state, str[len]);
        state = newState;
        len++;
    }
    if (accept(state))
        cout << "Accept";
    else
        cout << "Reject";
}