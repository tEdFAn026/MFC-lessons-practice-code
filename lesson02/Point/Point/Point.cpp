#include <iostream>
using namespace std;

//struct Point
class Point {
public:
	int x;
	int y;

	Point() {
		x = 0; y = 0;
	}

	Point(int x, int y) {
		this->x = x; this->y = y;
	}

	~Point() {

	}

	void output() {
		cout << x << endl << y << endl;
	}
};

void main() {
	Point pt(1, 1);
	pt.output();
}