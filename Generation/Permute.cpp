#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, x[12], id_i, id_k;
	cin >> n;
	if (n == 0)
		cout << 0;
	else if (n > 0) {
		for (int i = 0; i < n; i++) x[i] = i + 1;

		do {
			for (int i = 0; i < n; i++) cout << x[i] << " ";
			cout << "\n";

			id_i = n - 2; id_k = n - 1;
			while (id_i >= 0 && x[id_i] > x[id_i + 1]) id_i--;

			if (id_i >= 0) {
				while (x[id_k] < x[id_i]) id_k--;

				swap(x[id_i], x[id_k]);

				int a = id_i + 1, b = n - 1;

				while (a < b)
				{
					swap(x[a], x[b]);
					a++;
					b--;
				}
			}
		} while (id_i >= 0);
	}
	return 0;
}