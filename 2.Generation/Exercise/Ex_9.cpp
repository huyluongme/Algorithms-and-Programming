/*
	Liệt kê tất cả các hoán vị chữ cái trong từ MISSISSIPPI theo thứ tự từ điển
*/
#include <iostream>
#include <algorithm>
using namespace std;
  
int main() {
	string s;
	cin >> s;
	int n, id_i, id_k;
	sort(s.begin(), s.end());
	n = s.size();
	do {
		cout << s << endl;
		id_i = n - 2;
		while (id_i >= 0 && s[id_i] >= s[id_i + 1]) id_i--;
		if (id_i >= 0) {
			id_k = n - 1;
			while (s[id_i] >= s[id_k]) id_k--;
			swap(s[id_i], s[id_k]);
			int a = id_i + 1, b = n - 1;
			while (a < b) {
				swap(s[a], s[b]);
				a++; b--;
			}
		}
	} while (id_i >= 0);
	return 0;
}
