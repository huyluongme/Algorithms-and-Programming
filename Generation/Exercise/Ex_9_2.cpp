/*
	Liệt kê tất cả các hoán vị chữ cái trong từ MISSISSIPPI theo thứ tự từ điển
*/
// Method 2: use next_permutation() to generate next permute
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
	} while (next_permutation(s.begin(),s.end()));
	return 0;
}
