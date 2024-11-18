#include <iostream>

using namespace std;

class Rectangle
{
    int width, height;

public:
    // constructor
    Rectangle();
    Rectangle(int, int);
    int area(void) { return width * height; }
};

Rectangle::Rectangle()
{
    width = 5;
    height = 5;
}
Rectangle::Rectangle(int x, int y)
{
    width = x;
    height = y;
}

int main()
{
    Rectangle rect1(3, 4);
    Rectangle rect2;

    cout << "area: " << rect1.area() << endl;
    cout << "area: " << rect2.area();
    return 0;
}
