#pragma once


struct Point {

	Point() = default;
	Point (int x, int y) : x {x}, y {y}
	{}

	void operator+=(const Point& b) {

		Point result { this->x + b.x, this->y + b.y };

		this->x = result.x;
		this->y = result.y;
	}

	bool operator==(const Point& b) {

		return this->x == b.x && this->y == b.y;
	}

	int x;
	int y;
};