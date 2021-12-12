#include <iostream>

using namespace std;

int main() {
	int x[30], id, n;
	cin >> n;

	// Xây dựng cấu hình đầu tiên
	for (int i = 0; i < n; i++) x[i] = 0;

	// Xây dựng các cấu hình còn lại
	do {
		// In cấu hình hiện tại 
		for (int i = 0; i < n; i++) cout << x[i];
		cout << endl;

		// Gán id bằng vị trí cuối cùng của dãy
		id = n - 1;
		// Lùi dần i về cho đến khi gặp phần tử thứ id bằng 0 hoặc id nhỏ hơn 0
		while (id >= 0 && x[id] == 1) id--;
		
		//Xây dựng cấu hình kế tiếơ
		if (id >= 0) {
			x[id] = 1;
			for (int i = id + 1; i < n; i++) x[i] = 0;
		}
	} while (id >= 0);

	return 0;
}
