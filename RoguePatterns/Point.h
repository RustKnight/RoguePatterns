#pragma once


struct Point {

	Point() = default;
	Point (int x, int y) : x {(float)x}, y { (float)y}
	{}
	Point(float x, float y) : x{ x }, y{ y }
	{}

	void operator+=(const Point& b) {
	
		Point result { this->x + b.x, this->y + b.y };
	
		this->x = result.x;
		this->y = result.y;
	}

	void operator-=(const Point& b) {

		Point result{ this->x - b.x, this->y - b.y };

		this->x = result.x;
		this->y = result.y;
	}

	bool operator==(const Point& b) {

		return (int)this->x == (int)b.x && (int)this->y == (int)b.y;
	}

	bool operator!=(const Point& b) {

		return (int)this->x != (int)b.x || (int)this->y != (int)b.y;
	}


	Point& operator*(const int throwTiles) {

		if (this->x == 0)
			this->y = y * throwTiles;

		else if (this->y == 0)
			this->x = x * throwTiles;

		return *this;
	}

	Point& operator+(const Point& b) {

		*this += b;
		return *this;
	}

	Point& operator-(const Point& b) {

		*this -= b;
		return *this;
	}



	float x;
	float y;
};