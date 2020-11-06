#include <iostream>
#include <math.h>

using namespace std;
//Дано целое число N (> 0). Используя операции деления нацело и взятия остатка от деления, найти число, полученное при прочтении числа N справа налево.
int main()
{
    int n, cifra, chislo;
    cin >> n;
    chislo = 0;
    while (n > 0)
    {
        cifra = n % 10;
        n = n / 10;
        chislo = chislo * 10 + cifra;
    }
    cout << chislo;
}
