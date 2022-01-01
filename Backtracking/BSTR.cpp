#include <iostream>

using namespace std;

void PrintResult(int x[], int n) {
	for (int i = 0; i < n; i++) cout << x[i];
	cout << endl;
}

void Try(int i, int x[], int n) {
	for (int j = 0; j <= 1; j++) {
		x[i] = j;
		if (i == n - 1) PrintResult(x, n);
		else
			Try(i + 1, x, n);
	}
}

int main() {
	int x[30], n;
	cin >> n;
	Try(0, x, n);
	return 0;
}
