#include <iostream>
using namespace std;
int firstDay(int year);
int isLeaf(int year);
int main(void)
{
	int t;
	int year;
	cin >> t;
	for (int i = 0; i<t; i++)
	{
		cin >> year;
		cout << firstDay(year) << endl;
	}
	return 0;
}
int isLeaf(int year)
{
	return (year % 4 == 0 || year % 400 == 0) ? (year % 100 == 0 && year % 400 != 0) ? 0 : 1 : 0;
}

int firstDay(int year) {
	int cnt = 0;
	for (int i = 1582; i < year; i++) {
		if (isLeaf(i)) {
			cnt += 2;
		}
		else {
			cnt += 1;
		}
	}
	return (cnt+5) % 7;
}