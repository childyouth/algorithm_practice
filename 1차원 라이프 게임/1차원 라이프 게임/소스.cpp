#include<iostream>

using namespace std;

void life_game(int*&arr, int m, int t);


int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int m, t;
		cin >> m >> t;
		int *a = new int[m];
		for (int j = 0; j < m; j++) {
			cin >> a[j];
		}
		life_game(a,m, t);
		for (int j = 0; j < m; j++) {
			cout << a[j] << " ";
		}
		cout << endl;
	}

	return 0;
}

void minus_arr(int *a) {
	(*a)--;
	if (*a < 0)
		*a = 0;
}

void plus_arr(int *a) {
	(*a)++;
	if (*a > 9)
		*a = 9;
}

void life_game(int *&arr, int m, int t) {
	int *before = new int[m+2];
	for (int i = 0; i < t; i++) {
		before[0] = 0;
		before[m+1] = 0;
		for (int j = 0; j < m; j++) {
			before[j+1] = arr[j];
		}
		for (int j = 1; j <= m; j++) {
			int sum = before[j - 1] + before[j + 1];
			if (sum < 3 || sum > 7) {
				minus_arr(&arr[j - 1]);
			}
			else if (sum >= 4 && sum <= 7) {
				plus_arr(&arr[j - 1]);
			}
			else {
				continue;
			}
		}
	}
}