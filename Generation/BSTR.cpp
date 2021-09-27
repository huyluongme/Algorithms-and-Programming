#include <iostream>

using namespace std;

int main()
{
	int n, x[30], id;
	cin >> n;

	if (n > 0) {
		for (int i = 0; i < n; i++) x[i] = 0;

		do {
			for (int i = 0; i < n; i++) cout << x[i];
			cout << "\n";

			id = n - 1;

			while (id >= 0 && x[id] == 1) id--;

			if (id >= 0) {
				x[id] = 1;
				for (int i = id + 1; i < n; i++) x[i] = 0;
			}
		} while (id >= 0);
	}
	else
	{
		cout << "Binary strings of 0 bits or less do not exist";
	}
	return 0;
}