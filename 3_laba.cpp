#include <iostream>

class Point {
public:
    virtual void draw() const = 0;
    virtual void remove() const = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void rotate() const = 0;
    virtual ~Point() { std::cout << "Point destructor called." << std::endl; }
};

class Shape : public Point {
protected:
    double x, y;

public:
    Shape(double x, double y) : x(x), y(y) {}

    void move(double dx, double dy) override {
        x += dx;
        y += dy;
        std::cout << "Shape moved to (" << x << ", " << y << ")" << std::endl;
    }

    virtual ~Shape() { std::cout << "Shape destructor called." << std::endl; }
};

class Line : public Shape {
protected:
    double length;

public:
    Line(double x, double y, double length) : Shape(x, y), length(length) {}

    void draw() const override {
        std::cout << "Line from (" << x << ", " << y << ") with length " << length << std::endl;
    }

    void remove() const override { std::cout << "Line removed." << std::endl; }

    void rotate() const override { std::cout << "Line rotated." << std::endl; }

    ~Line() { std::cout << "Line destructor called." << std::endl; }
};

class Parallelogram : public Shape {
protected:
    double sideA, sideB;
    double angle;

public:
    Parallelogram(double x, double y, double a, double b, double angle)
        : Shape(x, y), sideA(a), sideB(b), angle(angle) {}

    void draw() const override {
        std::cout << "Parallelogram with side A: " << sideA << ", side B: " << sideB
                  << " and angle: " << angle << " degrees at (" << x << ", " << y << ")" << std::endl;
    }

    void remove() const override { std::cout << "Parallelogram removed." << std::endl; }

    void rotate() const override { std::cout << "Parallelogram rotated." << std::endl; }

    ~Parallelogram() { std::cout << "Parallelogram destructor called." << std::endl; }
};

class Rectangle : public Parallelogram {
public:
    Rectangle(double x, double y, double width, double height)
        : Parallelogram(x, y, width, height, 90.0) {}

    void draw() const override {
        std::cout << "Rectangle with width: " << sideA << ", height: " << sideB
                  << " at (" << x << ", " << y << ")" << std::endl;
    }

    void remove() const override { std::cout << "Rectangle removed." << std::endl; }

    void rotate() const override { std::cout << "Rectangle rotated." << std::endl; }

    ~Rectangle() { std::cout << "Rectangle destructor called." << std::endl; }
};

class Rhombus : public Parallelogram {
public:
    Rhombus(double x, double y, double side, double angle)
        : Parallelogram(x, y, side, side, angle) {}

    void draw() const override {
        std::cout << "Rhombus with sides: " << sideA << " at (" << x << ", " << y << ")"
                  << " and angle: " << angle << " degrees" << std::endl;
    }

    void remove() const override { std::cout << "Rhombus removed." << std::endl; }

    void rotate() const override { std::cout << "Rhombus rotated." << std::endl; }

    ~Rhombus() { std::cout << "Rhombus destructor called." << std::endl; }
};

class Square : public Rectangle {
public:
    Square(double x, double y, double side) : Rectangle(x, y, side, side) {}

    void draw() const override {
        std::cout << "Square with side: " << sideA << " at (" << x << ", " << y << ")"
                  << std::endl;
    }

    void remove() const override { std::cout << "Square removed." << std::endl; }

    void rotate() const override { std::cout << "Square rotated." << std::endl; }

    ~Square() { std::cout << "Square destructor called." << std::endl; }
};

int main() {
    Line line(0, 0, 10);
    line.draw();
    line.move(5, 5);
    line.rotate();
    line.remove();

    Rectangle rect(0, 0, 10, 5);
    rect.draw();
    rect.move(5, 5);
    rect.rotate();
    rect.remove();

    Rhombus rhombus(0, 0, 10, 60);
    rhombus.draw();
    rhombus.move(5, 5);
    rhombus.rotate();

    Square square(0, 0, 10);
    square.draw();
    square.move(5, 5);
    square.rotate();
    square.remove();

    // Создаем массив указателей на Point и инициализируем их адресами объектов
    Point *points[4];
    points[0] = &line;
    points[1] = &rect;
    points[2] = &rhombus;
    points[3] = &square;

    // Демонстрируем позднее связывание, вызывая методы через указатели на базовый класс
    for (int i = 0; i < 4; i++) {
        points[i]->draw();
        points[i]->move(1, 1);
        points[i]->rotate();
        points[i]->remove();
        std::cout << std::endl;
    }

    return 0;
}
