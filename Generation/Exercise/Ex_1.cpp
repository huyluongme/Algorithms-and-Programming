/*
	Đề bài: Nhập vào 2 số n và k, liệu kê các chỉnh hợp lặp chập k của {0,1,2,3,..,n-1}
*/

#include <iostream>

using namespace std;

int main() {
	int n, k, x[30], id;

	cin >> n >> k;

	// Xây dựng cấu hình đầu tiên
	for (int i = 0; i < k; i++) x[i] = 0;

	do {
		// In cấu hình đầu tiên
		cout << "{";
		for (int i = 0; i < k - 1; i++) cout << x[i] << ", ";
		cout << x[k - 1] << "}" << endl;

		// Tìm vị trí phần tử có giá trị nhỏ hơn n - 1 thỏa điều kiện vị trí lớn hơn bằng 0;
		id = k - 1;
		while (id >= 0 && x[id] == n - 1) id--;

		// Tăng giá trị phần tử tại vị trí tìm được và gán dãy phần tử đằng sau vị trí tìm được bằng 0
		if (id >= 0) {
			x[id]++;
			for (int i = id + 1; i < k; i++) x[i] = 0;
		}
	} while (id >= 0);

	return 0;
}