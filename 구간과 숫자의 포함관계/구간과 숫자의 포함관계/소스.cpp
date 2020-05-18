#include <iostream>
#include<algorithm>
using namespace std;
int isNumInRange(int a,int b, int c);
int main(void)
{
	int t;
	int a,b,c;
	cin >> t;
	for (int i = 0; i<t; i++)
	{
		cin >> a >> b >> c;
		cout << isNumInRange(a,b,c) << endl;
	}
	return 0;
}
int isNumInRange(int a,int b, int c) {
	int first = min(a, b);
	int last = max(a, b);
	if (a <= c && c <= b)
		return 1;
	return 0;
}