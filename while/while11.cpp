#include <iostream>
#include <math.h>

using namespace std;
//Дано целое число N (> 1). Вывести наименьшее из целых чисел K, для которых сумма 1 + 2 + … + K будет больше или равна N, и саму эту сумму.
int main()
{
    int summa, n, k;
    cin >> n;
    k = 0;
    summa = 0;
    while (summa < n)
    {
        k = k + 1;
        summa = k + summa;
    }
    cout << k << ' ' << summa;
}
