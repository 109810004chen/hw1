#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

class Shape {
    protected:
        double width, length;
    public:
        Shape(double w, double l = 0) {
            width = w;
            length = l;
        }

        virtual double get_area() = 0;
};

class Circle : public Shape {
    public:
        Circle(double r) : Shape(r) {}

        double get_area() {
            return M_PI * pow(width, 2);
        }
};

class Triangle : public Shape {
    public:
        Triangle(double w, double l) : Shape(w, l) {}

        double get_area() {
            return 0.5 * width * length;
        }
};

class Rectangle : public Shape {
    public:
        Rectangle(double w, double l) : Shape(w, l) {}

        double get_area() {
            return width * length;
        }
};

int main() {
    double width, length;
    string shape_type;

    cout << "Enter shape type (circle, triangle, or rectangle)and width/radius : ";
    cin >> shape_type>>width;

   
    if (shape_type == "triangle" || shape_type == "rectangle") {
        cout << "Enter length: ";
        cin >> length;
    }

    Shape *shape;
    if (shape_type == "circle") {
        shape = new Circle(width);
    } else if (shape_type == "triangle") {
        shape = new Triangle(width, length);
    } else if (shape_type == "rectangle") {
        shape = new Rectangle(width, length);
    } else {
        throw invalid_argument("Invalid shape type");
    }

    double area = shape->get_area();
    cout << "Area of " << shape_type << " with width " << width << " and length " << length << " is " << area << endl;

    delete shape;

    return 0; 
}


