#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

class triangle {
public:
	int x1, x2, x3, y1, y2, y3;
	triangle() {
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	}
	bool is_triangle() {
		if (x1 != x2 && y1 != y2) {
			double m = (y2 - y1) / (x2 - x1);
			if ((y3 - y1) == (m * (x3 - x1))) {
				return false;
			}
			return true;
		}
		return false;
	}
	double getLength1() {
		return sqrt(pow(x2 - x1,2) + pow(y2 - y1,2));
	}
	double getLength2() {
		return sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
	}
	double getLength3() {
		return sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
	}
};

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		triangle t;
		double a = t.getLength1();
		double b = t.getLength2();
		double c = t.getLength3();
		double m = max(max(a, b), c);
		if (m == b) {
			double tmp = a;
			a = m;
			b = tmp;
		}
		else if (m == c) {
			double tmp = a;
			a = m;
			c = tmp;
		}
		if (!t.is_triangle()) {
			cout << "0" << endl;
			continue;
		}
		double a_ = pow(b, 2) + pow(c, 2);
		a = pow(a, 2);
		if (a == a_) {
			cout << "1" << endl;
		}
		else if (a > a_) {
			cout << "2" << endl;
		}
		else {
			cout << "3" << endl;
		}
	}
	return 0;
}