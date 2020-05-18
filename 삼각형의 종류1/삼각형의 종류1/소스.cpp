#include<iostream>
#include<algorithm>

using namespace std;
int main() {
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a >= b + c || c >= a + b || b >= a + c) {
			cout << "0" << endl;
			continue;
		}
		if (a == b && b == c) {
			cout << "1" << endl;
			continue;
		}
		else if (a == b || b == c || a == c) {
			cout << "3" << endl;
		}
		else if (a*a + b*b == c*c || a*a + c*c == b*b || c*c + b*b == a*a) {
			cout << "2" << endl;
		}
		else {
			cout << "4" << endl;
		}
	}

	return 0;
}