#include<iostream>
#include<algorithm>

using namespace std;

void cntLastZero(int a, int* cnt_2, int* cnt_5);


int main() {
	int m;

	cin >> m;
	for (int i = 0; i<m; i++) {
		int n;
		int cnt_2 = 0;
		int cnt_5 = 0;

		cin >> n;

		for (int i = 0; i<n; i++) {
			int a;
			cin >> a;
			cntLastZero(a, &cnt_2, &cnt_5);
		}
		cout << min(cnt_2, cnt_5) << endl;
	}
	return 0;
}



void cntLastZero(int a, int* cnt_2, int* cnt_5) {
	while (1) {
		if (a % 2 == 0) {
			*cnt_2 += 1;
			a /= 2;
		}
		else if (a % 5 == 0) {
			*cnt_5 +=1;
			a /= 5;
		}
		else
			break;
	}
}