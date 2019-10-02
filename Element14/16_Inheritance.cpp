#include <iostream>
using namespace std;

typedef struct Point {
	double X;
	double Y;

	Point() {
		X = 0;
		Y = 0;
	}

	Point(double x, double y) {
		X = x;
		Y = y;
	}
} Point;

class SimplePolygon {
	protected:
		int _nsides;
		Point* _vertices;

	public:
		SimplePolygon(int nsides) {
			_nsides = nsides;
			_vertices = new Point[nsides];
		}

		~SimplePolygon() {
			delete[] _vertices;
		}

		Point GetVertex(int idx) {
			return _vertices[idx];
		}

		void SetVertex(int idx, Point point) {
			_vertices[idx] = point;
		}
		
		// the algorithm here used for calculaion area is interesting
		double Area() {
			double A = 0;
			for(int i = 0; i < _nsides; i++) {
				Point curr = _vertices[i];
				Point next = _vertices[(i + 1)%_nsides];
				//cout << i << " " << (i + 1)%_nsides << endl;
				A += curr.X * next.Y - next.X * curr.Y;
			}
			return A / 2;
		}
};

class Triangle : public SimplePolygon {
	public:
		Triangle(Point a, Point b, Point c) : SimplePolygon(3) {
			SetVertex(0, a);
			SetVertex(1, b);
			SetVertex(2, c);
		}
};

class Quadrilateral : public SimplePolygon {
	public:
		Quadrilateral(Point a, Point b, Point c, Point d)
		: SimplePolygon(4)	{
			SetVertex(0, a);
			SetVertex(1, b);
			SetVertex(2, c);
			SetVertex(3, d);
		}
};

class Square : public Quadrilateral {
	public:
		Square(double length, Point center)
		: Quadrilateral(
			Point(center.X - length/2, center.Y - length/2),
			Point(center.X + length/2, center.Y - length/2),
			Point(center.X + length/2, center.Y + length/2),
			Point(center.X - length/2, center.Y + length/2)) {

		}
};

class Rectangle : public Quadrilateral {
	public:
		Rectangle(double width, double height, Point center)
		: Quadrilateral(
			Point(center.X - width/2, center.Y - height/2),
			Point(center.X + width/2, center.Y - height/2),
			Point(center.X + width/2, center.Y + height/2),
			Point(center.X - width/2, center.Y + height/2)) {
		}
};

int main() {
	Triangle triangle(Point(0, 0), Point(5, 0), Point(0, 9));
	Point top = triangle.GetVertex(2);
	cout << top.X << " " << top.Y << endl;
	cout << triangle.Area() << endl;

	Square square(5, Point(1, 2));
	cout << square.Area() << endl;

	Rectangle rectangle(2, 4, Point(3, 4));
	cout << rectangle.Area() << endl;

	return 0;
}
