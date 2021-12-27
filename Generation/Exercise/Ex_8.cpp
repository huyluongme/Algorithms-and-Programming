#include <iostream>
#include <algorithm>

using namespace std;

void permute(int x[], int k) {
	int x_2[30], id_i, id_k;
	for (int i = 0; i < k; i++) x_2[i] = x[i];
	do {
		id_i = k - 2;
		while (id_i >= 0 && x_2[id_i] > x_2[id_i + 1]) id_i--;

		if (id_i >= 0) {
			id_k = k - 1;
			while (x_2[id_k] < x_2[id_i]) id_k--;
			swap(x_2[id_i], x_2[id_k]);
			int a = id_i + 1, b = k - 1;
			if (a < b) {
				swap(x_2[a], x_2[b]);
				a++;
				b--;
			}
			cout << "{";
			for (int i = 0; i < k - 1; i++) cout << x_2[i] << ", ";
			cout << x_2[k - 1] << "}" << endl;
		}
	} while (id_i >= 0);
}

int main() {

	int x[30], n, k, id;
	cin >> n >> k;
	for (int i = 0; i < k; i++) x[i] = i + 1;

	do {
		cout << "{";
		for (int i = 0; i < k - 1; i++) cout << x[i] << ", ";
		cout << x[k - 1] << "}" << endl;
		permute(x, k);
		id = k - 1;
		while (id >= 0 && x[id] == n - k + id + 1) id--;
		if (id >= 0) {
			x[id]++;
			for (int i = id + 1; i < k; i++) x[i] = x[i - 1] + 1;
		}

	} while (id >= 0);
	return 0;
}
