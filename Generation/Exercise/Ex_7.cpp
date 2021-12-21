/*
	Nhập vào danh sách n bạn nam và n bạn nữ, in ra tất cả các cách xếp 2n người đó vào một bàn tròn, mỗi bạn nam tiếp đến là một bạn nữ
*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void Import(string List[], int n) {
	cin.ignore();
	for (int i = 0; i < 2 * n; i += 2)
		getline(cin, List[i]);
	for (int i = 1; i < 2 * n; i += 2)
		getline(cin, List[i]);
}

bool check(int x[], int n) {
	for (int i = 0; i < 2 * n; i++)
		if ((x[i] % 2 == 0 && x[i + 1] % 2 == 0) || (x[i] % 2 != 0 && x[i + 1] % 2 != 0))
			return false;
	return true;
}

int main() {
	string List[30];
	int n, x[30], id_i, id_k;
	cin >> n;
	Import(List, n);

	for (int i = 0; i < 2 * n; i++) x[i] = i;

	do {
		if (check(x, n) == true) {
			for (int i = 0; i < 2 * n - 1; i++) cout << List[x[i]] << ", ";
			cout << List[x[2 * n - 1]] << endl;
		}

		id_i = 2 * n - 2;
		while (id_i > 0 && x[id_i] > x[id_i + 1]) id_i--;

		if (id_i > 0) {
			id_k = 2 * n - 1;
			while (x[id_k] < x[id_i]) id_k--;

			swap(x[id_i], x[id_k]);

			int a = id_i + 1, b = 2 * n - 1;
			while (a < b) {
				swap(x[a], x[b]);
				a++;
				b--;
			}
		}
	} while (id_i > 0);
	return 0;
}
