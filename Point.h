#pragma once

class Point
{
public:
	int x, y;
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	Point()
	{
		this->x = 0;
		this->y = 0;
	}
	//Point(const Point& other);
	// If need be, we can have operator overload
	// and other functions here

	bool operator==(Point &point)
	{
	    if ((this->x == point.x && this->y == point.y))
        {
            return true;
        }
        return false;
	}
	Point operator=(Point &point)
	{

	    this->x = point.x, this->y = point.y ;
	    return *this ;
	}

};
