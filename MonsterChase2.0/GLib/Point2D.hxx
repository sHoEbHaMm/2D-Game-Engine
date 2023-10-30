//#include <assert.h>
//#include "Point2D.h"


/*Point2D operator+=(Point2D point, Point2D offset_val)
{
    point.x += offset_val.x;
    point.y += offset_val.y;

    return point;
}

Point2D operator-=(Point2D point, Point2D offset_val)
{
    point.x -= offset_val.x;
    point.y -= offset_val.y;

    return point;
}

Point2D operator+(const Point2D& lhs, const Point2D& rhs) //Adding two
{
    return Point2D(lhs.GetX() + rhs.GetX(), lhs.GetY() + rhs.GetY());
}

Point2D operator-(const Point2D& lhs, const Point2D& rhs) //Subtracting two
{
    return Point2D(lhs.GetX() - rhs.GetX(), lhs.GetY() - rhs.GetY());
}

bool operator==(const Point2D lhs, const Point2D rhs)
{
    if ((lhs.GetX() == rhs.GetX()) && (lhs.GetY() == rhs.GetY()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator!=(const Point2D& lhs, const Point2D& rhs)
{
    if ((lhs.GetX() == rhs.GetX()) && (lhs.GetY() == rhs.GetY()))
    {
        return false;
    }
    else
    {
        return true;
    }
}

Point2D operator*(const Point2D& point, int a)
{
    return Point2D(point.GetX() * a, point.GetY() * a);
}

Point2D operator/(const Point2D& point, int a)
{
    return Point2D(point.GetX() / a, point.GetY() / a);
}

Point2D operator-(const Point2D& point) //Negate
{
    return Point2D(point.GetX() * (-1), point.GetY() * (-1));
}

Point2D operator*(int a, Point2D& point)
{
    return Point2D(point.GetX() * a, point.GetY() * a);
}

Point2D operator/(int a, Point2D& point)
{
    return Point2D(point.GetX() / a, point.GetY() / a);
}

void operator *=(Point2D& point, int a)
{
    point.SetX(a * point.GetX());
    point.SetY(a * point.GetY());
}

void operator /=(Point2D& point, int a)
{
    point.SetX(a / point.GetX());
    point.SetY(a / point.GetY());
}*/


/*void Point2DUnitTest()
{
    Point2D A(0, 1);
    Point2D B(2, 3);
    // equality
    bool bEqual = A == B;
    assert(bEqual == false);
    bEqual = B == Point2D(2, 3);
    assert(bEqual == true);
    // Inequality
    bool bNotEqual = A != B;
    assert(bNotEqual == true);
    bNotEqual = B != Point2D(2, 3);
    assert(bNotEqual == false);
    // Point2D + Point2D
    Point2D C = A + B;
    assert(C == Point2D(2, 4));
    // Point2D - Point2D
    C = B - A;
    assert(C == Point2D(2, 2));
    // Point2D * int
    C = A * 2;
    assert(C == Point2D(0, 2));
    // Point2D / int
    C = Point2D(6, 4) / 2;
    assert(C == Point2D(3, 2));
    // int * Point2D
    C = 2 * B;
    assert(C == Point2D(4, 6));
    // negate
    C = -B;
    assert(C == Point2D(-2, -3));
    // Point2D += Point2D
    B += Point2D(2, 1);
    assert(B == Point2D(4, 4));
    // Point2D -= Point2d
    B -= Point2D(2, 1);
    assert(B == Point2D(2, 3));
    // Point2D *= int
    B *= 2;
    assert(B == Point2D(4, 6));
    // Point2D /= int
    B /= 2;
    assert(B == Point2D(2, 3));
}*/

