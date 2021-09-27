#include <iostream>
using namespace std;

int main()
{
	int n, k, x[30], id;
	cin >> n >> k;
	if (k == 0)
		cout << "Empty set";
	else if (k > 0) {
		for (int i = 0; i < k; i++) x[i] = i + 1;

		do {
			cout << "{";
			for (int i = 0; i < k - 1; i++) cout << x[i] << ", ";
			cout << x[k - 1] << "}\n";

			id = k - 1;
			while (id >= 0 && x[id] == n - k + id + 1) id--;

			if (id >= 0) {
				x[id]++;
				for (int i = id + 1; i < k; i++) x[i] = x[i - 1] + 1;
			}

		} while (id >= 0);
	}
	return 0;
}