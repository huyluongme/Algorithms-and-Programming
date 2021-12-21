/*
	Nhập vào danh sách n người, in ra tất cả cách xếp n người đó vào một bàn
*/
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void Import(string List[], int n) {
	cin.ignore();
	for (int i = 0; i < n; i++) {
		getline(cin, List[i]);
	}
}

int main() {
	int n, x[30], id_i, id_k;
	string List[30];
	cin >> n;
	Import(List, n);

	for (int i = 0; i < n; i++) x[i] = i;

	do {
		for (int i = 0; i < n - 1; i++) cout << List[x[i]] << ", ";
		cout << List[x[n - 1]] << endl;

		id_i = n - 2;
		while (id_i >= 0 && x[id_i] > x[id_i + 1]) id_i--;

		if (id_i >= 0) {
			id_k = n - 1;
			while (x[id_k] < x[id_i]) id_k--;
			swap(x[id_i], x[id_k]);

			int a = id_i + 1, b = n - 1;
			while (a < b) {
				swap(x[a], x[b]);
				a++; b--;
			}
		}

	} while (id_i >= 0);
	return 0;
}
