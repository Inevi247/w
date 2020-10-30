#include <iostream>
#include <math.h>

using namespace std;
//Дано целое число N (> 1). Вывести наименьшее из целых чисел K, для которых сумма 1 + 2 + … + K будет больше или равна N, и саму эту сумму.
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
