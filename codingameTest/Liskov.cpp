#include <iostream>
#include <vector>

using namespace std;

class Shape {
public:
	virtual int area() = 0;
};

class Rectangle : public Shape {
public:
	Rectangle(int width, int height) : width_(width), height_(height) {}
	int area() { return width_ * height_; }
private:
	int width_;
	int height_;
};

class Square : public Rectangle {
public:
	Square(int side) : Rectangle(side, side) {}
};

void processShapes(vector<Shape*>& shapes) {
	for (Shape* shape : shapes) {
		cout << "Area : " << shape->area() << endl;
	}
}

int main() {
	vector<Shape*> shapes;
	shapes.push_back(new Rectangle(4, 5));
	shapes.push_back(new Square(4));
	processShapes(shapes);
	return 0;
}
