#include <iostream>
#include <math.h>

using namespace std;
//Дано целое число N (> 0). Используя операции деления нацело и взятия остатка от деления, вывести все его цифры, начиная с самой правой (разряда единиц).
int main()
{
    int summa, n;
    cin >> n;
    while (n > 0)
    {
        cout << n % 10;
        n = n / 10;
    }
}
