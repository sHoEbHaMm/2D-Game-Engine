#pragma once

#include<Windows.h>
#include<stdint.h>

class Point2D
{
	public:
		Point2D() {
			x = 0;
			y = 0;
		}

		Point2D(int p_x, int p_y) {
			SetX(p_x);
			SetY(p_y);
		}

		int GetX() const { return x; }
		int GetY() const { return y; }

		void SetX(int value) { x = value; }
		void SetY(int value) { y = value; }

		int x;
		int y;


};
	 inline
	Point2D operator+=(Point2D point, Point2D offset_val)
	{
		point.x += offset_val.x;
		point.y += offset_val.y;

		return point;
	}

	 inline
	Point2D operator-=(Point2D point, Point2D offset_val)
	{
		point.x -= offset_val.x;
		point.y -= offset_val.y;

		return point;
	}

	 inline
	Point2D operator+(const Point2D& lhs, const Point2D& rhs) //Adding two
	{
		return Point2D(lhs.GetX() + rhs.GetX(), lhs.GetY() + rhs.GetY());
	}

	 inline
	Point2D operator-(const Point2D& lhs, const Point2D& rhs) //Subtracting two
	{
		return Point2D(lhs.GetX() - rhs.GetX(), lhs.GetY() - rhs.GetY());
	}

	 inline
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

	 inline
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

	 inline
	Point2D operator*(const Point2D& point, int a)
	{
		return Point2D(point.GetX() * a, point.GetY() * a);
	}

	 inline
	Point2D operator/(const Point2D& point, int a)
	{
		return Point2D(point.GetX() / a, point.GetY() / a);
	}

	 inline
	Point2D operator-(const Point2D& point) //Negate
	{
		return Point2D(point.GetX() * (-1), point.GetY() * (-1));
	}

	 inline
	Point2D operator*(int a, Point2D& point)
	{
		return Point2D(point.GetX() * a, point.GetY() * a);
	}

	 inline
	Point2D operator/(int a, Point2D& point)
	{
		return Point2D(point.GetX() / a, point.GetY() / a);
	}

	 inline
	void operator *=(Point2D& point, int a)
	{
		point.SetX(a * point.GetX());
		point.SetY(a * point.GetY());
	}

	 inline
	void operator /=(Point2D& point, int a)
	{
		point.SetX(a / point.GetX());
		point.SetY(a / point.GetY());
	}
