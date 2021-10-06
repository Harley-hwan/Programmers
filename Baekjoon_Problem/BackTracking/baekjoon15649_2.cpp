#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n, m; cin >> n >> m;


	for (int i = 1; i <= n; i++) {
		vector<bool> v(len - i, false);
		v.insert(v.end(), i, true);
		cout << "=============== " << i << "개 ===============\n";
		do {
			string temp = "";
			for (int k = 0; k < len; k++) {
				if (v[k]) temp += s[k];
			}
			cout << temp << "\n";
		} while (next_permutation(v.begin(), v.end()));
		cout << "===================================\n";
	}

	return 0;
}