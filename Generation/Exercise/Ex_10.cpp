/*
	Liệt kê tất cả các cách phân tích số nguyên dương n thành tổng các số nguyên dương, hai cách phân
	tích là hoán vị của nhau chỉ tính là một cách
*/

#include <iostream>

using namespace std;

bool check(int x_n[], int x[], int n) {
	int temp = 0;
	for (int i = 0; i < n - 1; i++)
		if (x[i] == 1) temp += x_n[i];
	return temp == n;
}

int main() {
	int x[30], x_n[30], n, id;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		x[i] = 0;
		x_n[i] = i + 1;
	}
	do {
		if (check(x_n, x, n)) {
			for (int i = 0; i < n - 1; i++)
				if (x[i] == 1)
					cout << x_n[i] << "+";
			cout << "\b \n";

		}

		id = n - 2;
		while (id >= 0 && x[id] == 1) id--;
		if (id >= 0) {
			x[id] = 1;
			for (int i = id + 1; i < n - 1; i++) x[i] = 0;
		}
	} while (id >= 0);
	return 0;
}
