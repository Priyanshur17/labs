#include <bits/stdc++.h>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double initialLength, double initialWidth) : length(initialLength), width(initialWidth) {}

    double calculateArea() {
        return length * width;
    }

    double calculatePerimeter() {
        return 2 * (length + width);
    }

    double getLength() {
        return length;
    }

    double getWidth() {
        return width;
    }
};

int main() {
    Rectangle myRectangle(5.0, 3.0);

    cout << "Initial Dimensions:" <<endl;
    cout << "Length: " << myRectangle.getLength() << endl;
    cout << "Width: " << myRectangle.getWidth() << endl;

    cout << "Area: " << myRectangle.calculateArea() << endl;
    cout << "Perimeter: " << myRectangle.calculatePerimeter() << endl;

    return 0;
}
