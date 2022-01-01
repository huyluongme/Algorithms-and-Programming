/*
	Liệt kê tất cả các tập hợp con của tập {1, 2,...,n} bằng 2 phương pháp:
	1. Liệt kê tập con
	2. Liệt kê nhị phân và ánh xạ qua tập {1, 2,...,n}
*/

#include <iostream>

using namespace std;

// Liệt kê tập con (cách 1)
void way1(int n) {
	if (n > 0) {
		cout << "{}" << endl;
		int x[30], k = 1, id;

		while (k <= n) {

			for (int i = 0; i < k; i++) x[i] = i + 1;

			do {
				cout << "{";
				for (int i = 0; i < k - 1; i++) cout << x[i] << ", ";
				cout << x[k - 1] << "}" << endl;

				id = k - 1;
				while (id >= 0 && x[id] == n - k + id + 1) id--;

				if (id >= 0) {
					x[id]++;
					for (int i = id + 1; i < k; i++) x[i] = x[i - 1] + 1;
				}
			} while (id >= 0);
			k++;
		}
	}
}

// Liệt kê nhị phân và ánh xạ....
void way2(int n) {
	if (n > 0) {
		cout << "{}" << endl;
		int x[30], k = 1, id;
		for (int i = 0; i < n; i++) x[i] = 0;
		x[n - 1] = 1;
		do {

			cout << "{";
			for (int i = 0; i < n; i++)
				if (x[i] == 1)	cout << i + 1 << ", ";
			cout << "\b\b}" << endl;

			id = n - 1;
			while (id >= 0 && x[id] == 1) id--;
			if (id >= 0) {
				x[id] = 1;
				for (int i = id + 1; i < n; i++) x[i] = 0;
			}

		} while (id >= 0);
	}
}

int main() {
	int n;
	cin >> n;
	cout << "Cach 1:" << endl;
	way1(n);
	cout << endl << "Cach 2:" << endl;
	way2(n);
	return 0;
}
