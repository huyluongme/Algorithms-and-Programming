/*
	Hãy liệt kê các dãy nhị phân độ dài n mà trong đó cụm chữ số "01" xuất hiện đúng 2 lần
*/
#include <iostream>

using namespace std;

/*
	Đếm số lượng cụm chữ số "01" trong chuỗi có độ dài n
*/
int count01Bin(int x[30], int n) {
	int cout = 0;
	for (int i = 0; i < n; i++)
		if (x[i] == 0 && x[i + 1] == 1) cout++;
	return cout;
}

int main() {
	int x[30], n, id;

	cin >> n;

	// Xây dựng cấu hình đầu tiên
	for (int i = 0; i < n; i++) x[i] = 0;

	do {
		// Kiểm tra cấu hình hiện tại có thỏa điều kiện đề bài, nếu thoải -> In cấu hình
		if (count01Bin(x, n) == 2) {
			for (int i = 0; i < n; i++) cout << x[i];
			cout << endl;
		}

		// Tìm vị trí cần
		id = n - 1;
		while (id >= 0 && x[id] == 1) id--;

		// Gán giá trị cho phần tử có vị trí vừa tìm = 1 và gán các giá trị sau bị trí sau vị trí cần tìm bằng 0
		if (id >= 0) {
			x[id] = 1;
			for (int i = id + 1; i < n; i++) x[i] = 0;
		}
	} while (id >= 0);
	return 0;
}
