#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, x[30], id_i, id_k;
	cin >> n;

	// Xây dựng cấu hình đầu tiên
	for (int i = 1; i <= n; i++) x[i - 1] = i;

	do {
		// In ra cấu hình hiện tại
		for (int i = 0; i < n; i++) cout << x[i] << " ";
		cout << endl;

		// Tìm vị trí phần tử không thỏa mãn dãy giảm dần từ cuối lên đầu
		id_i = n - 2;
		while (id_i >= 0 && x[id_i] > x[id_i + 1]) id_i--;

		if (id_i >= 0) {

			// Tìm vị trí phần tử có giá trị nhỏ nhất trong dãy giảm dần thỏa điều kiện lớn hơn giá trị tại id_i
			id_k = n - 1;
			while (x[id_k] < x[id_i]) id_k--;

			swap(x[id_i], x[id_k]);

			// Sắp xếp lại dãy giảm dần thành dãy tăng dần
			int a = id_i + 1, b = n - 1;
			while (a < b) {
				swap(x[a], x[b]);
				a++;
				b--;
			}
		}
	} while (id_i >= 0);

	return 0;
}
