#include<iostream>

using namespace std;

class Point {
private:
	int x;
	int y;
public:
	Point() {
		x = 0;
		y = 0;
	}
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
};

class Line {
private:
	Point a1;
	Point a2;
public:
	Line() {
		a1 = Point();
		a2 = Point();
	}
	Line(Point a1, Point a2) {
		this->a1 = a1;
		this->a2 = a2;
	}
	Point getA() {
		return a1;
	}
	Point getB() {
		return a2;
	}
	void swap() {
		Point tmp = a1;
		a1 = a2;
		a2 = tmp;
	}
};

int is_cross(int x1, int y1, int x2, int y2, int xx1, int yy1, int xx2, int yy2);

int main() {
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x1, y1, x2, y2, xx1, yy1, xx2, yy2;
		cin >> x1 >> y1 >> x2 >> y2 >> xx1 >> yy1 >> xx2 >> yy2;
		cout << is_cross(x1, y1, x2, y2, xx1, yy1, xx2, yy2) << endl;
	}
	return 0;
}

int is_cross(int x1, int y1, int x2, int y2, int xx1, int yy1, int xx2, int yy2) {
	Line A = Line(Point(x1, y1), Point(x2, y2));
	Line B = Line(Point(xx1, yy1), Point(xx2, yy2));

	if (A.getA().getX() == A.getB().getX()) {
		Line tmp = A;
		A = B;
		B = tmp;
	}
	if (A.getA().getX() > A.getB().getX()) {
		A.swap();
	}
	if (B.getA().getY() > B.getB().getY()) {
		B.swap();
	}
	if (A.getA().getX() < B.getA().getX() && B.getA().getX() < A.getB().getX()) {
		if (B.getA().getY() < A.getA().getY() && A.getA().getY() < B.getB().getY()){
			return 1;
		}
		else if (B.getA().getY() == A.getA().getY() || B.getB().getY() == A.getA().getY()) {
			return 2;
		}
	}
	if (A.getA().getX() == B.getA().getX() || B.getA().getX() == A.getB().getX()) {
		if (B.getA().getY() <= A.getA().getY() && A.getA().getY() <= B.getB().getY()) {
			return 2;
		}
	}

	return 0;
}