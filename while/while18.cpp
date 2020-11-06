#include <iostream>
#include <math.h>

using namespace std;
//Дано целое число N (> 0). Используя операции деления нацело и взятия остатка от деления, найти количество и сумму его цифр.
int main()
{
    int summa, n, kolichestvo;
    cin >> n;
    kolichestvo = 0;
    summa = 0;
    while (n > 0)
    {
        summa = summa + n % 10;
        kolichestvo = kolichestvo + 1;
        n = n / 10;
    }
    cout << summa << ' ' << kolichestvo;
}
