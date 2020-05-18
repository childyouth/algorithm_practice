#include <iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int closestNumber(int n, int m);
int main(void)
{
	int t;
	int n, m;
	cin >> t;
	for (int i = 0; i<t; i++)
	{
		cin >> n >> m;
		cout << closestNumber(n, m) << endl;
	}
	return 0;
}
int closestNumber(int n, int m)
{
	int ans1, ans2;
	double a = abs(n) / abs(m);
	int remain = abs(n) % abs(m);
	/*if (a == 0) {
		return 0;
	}
	else {*/
		a = (int)a;
		/*if (a == 0) {
			if (n < 0)
				return -m;
			else if(n > 0)
				return m;
			return 0;
		}*/
		ans1 = m * a;
		ans2 = m * (a + 1);
		int vec = abs(n) / n;
		if (remain >= abs(m) / 2)
			return vec * abs(ans2);
		else {
			return vec * abs(ans1);
		}
		
//	}

}