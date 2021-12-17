/*
	Nhập vào một danh sách n tên người. Liệt kê tất cả cách chọn ra đúng k người trong số n người đó
*/

#include <iostream>

using namespace std;

void Import(char List[30][50], int n) {
	for (int i = 0; i < n; i++)
		cin >> List[i];
}

int main() {
	char List[30][50];
	int n, k, x[30], id;
	cin >> n >> k;
	Import(List, n);
	// Xây dựng cấu hình đầu tiên
	for (int i = 0; i < k; i++) x[i] = i;

	do {
		// In cấu hình hiện tại
		cout << "{";
		for (int i = 0; i < k - 1; i++) cout << List[x[i]] << ", ";
		cout << List[x[k - 1]] << "}" << endl;

		// Gán id bằng phần tử tứ k - 1 và lùi id trong khi id >= 0 và giá trị phần tử tại vị trí id bằng với giới hạn trên
		id = k - 1;
		while (id >= 0 && x[id] == n - k + id) id--;

		// Xây dựng cấu hình kế tiếp
		if (id >= 0) {
			x[id]++;
			for (int i = id + 1; i < k; i++) x[i] = x[i - 1] + 1;
		}
	} while (id >= 0);
	return 0;
}
