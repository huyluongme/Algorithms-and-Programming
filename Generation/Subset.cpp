#include <iostream>

using namespace std;

int main() {
	int n, k, x[30], id;
	cin >> n >> k;
	
	// Xây dựng cấu hình đầu tiên
	for (int i = 0; i < k; i++) x[i] = i + 1;

	do {
		// In cấu hình hiện tại
		cout << "{";
		for (int i = 0; i < k - 1; i++) cout << x[i] << ", ";
		cout << x[k - 1] << "}" << endl;

		// Gán id bằng phần tử tứ k - 1 và lùi id trong khi id >= 0 và giá trị phần tử tại vị trí id bằng với giới hạn trên
		id = k - 1;
		while (id >= 0 && x[id] == n - k + id + 1) id--;

		// Xây dựng cấu hình kế tiếp
		if (id >= 0) {
			x[id]++;
			for (int i = id + 1; i < k; i++) x[i] = x[i - 1] + 1;
		}
	} while (id >= 0);

	return 0;
}
