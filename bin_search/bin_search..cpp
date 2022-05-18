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

int left_binary_search(vector<int>& v, int x) {
	int l = -1, r = v.size();
	while (l < r - 1) {
		int mid = (l + r) / 2;
		if (v[mid] < x) // здесь может быть любая функция возвращающая bool,
						//для которой массив делится на две части: первая половина удовлетворяет условию,
						// а вторая нет (тогда мы найдём первый элемент для которого условие нарушается)
			l = mid;
		else
			r = mid;
	}
	return r;
}

int right_binary_search(vector<int>& v, int x) {
	int l = -1, r = v.size();
	while (l < r - 1) {
		int mid = (l + r) / 2;
		if (v[mid] <= x)
			l = mid;
		else
			r = mid;
	}
	return r;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		int left = left_binary_search(v, x);
		int right = right_binary_search(v, x);
		if (left == n)
			cout << 0 << endl;
		else
			cout << left + 1 << " " << right << endl;
	}
}
