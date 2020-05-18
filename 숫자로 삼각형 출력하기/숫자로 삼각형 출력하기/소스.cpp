#include<iostream>

using namespace std;

void draw_triangle(int m);

int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		draw_triangle(m);
	}


	return 0;
}

void draw_triangle(int m) {
	for (int i = 1; i <= m; i++) {
		int sum = i;
		for (int j = 1; j <= i; j++) {
			cout << sum << " ";
			sum += m - j;
		}
		cout << endl;
	}
}