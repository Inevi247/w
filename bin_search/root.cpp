#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <set>
#include <string>
#include <vector>
#include <random>
#include<stack>
#include<queue>
#include<list>
#include<map>
#include<algorithm>

using namespace std;

double f(double x) {
	return 1 / pow(2, x) - 10;
}

int main() {
	double eps = 0.001;
	double l = -1e9, r = 1e9;
	while ((r - l) > eps) {
		double mid = (l + r) / 2;
		if (f(mid) > 0)
			l = mid;
		else
			r = mid;
	}
	cout << (l + r) / 2;
}
