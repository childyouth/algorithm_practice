#include <iostream>
using namespace std;
int lengthOfIntervalIntersection(int a, int b, int c, int d);
int main(void)
{
	int t;
	cin >> t;
	for (int i = 0; i<t; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << lengthOfIntervalIntersection(a, b, c, d) << endl;
	}
	return 0;
}

int lengthOfIntervalIntersection(int a, int b, int c, int d)
{
	if (a > c) {
		swap(a, c);
		swap(b, d);
	}
	if (a <= c && c <= b) {
		if (b > d) {
			return d - c;
		}
		return b - c;
	}

	return -1;
}