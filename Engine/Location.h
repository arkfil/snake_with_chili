#pragma once

struct Location {
	
public:
	int x, y;
	Location operator+(const Location& other) {
		return { other.x + x, other.y + y };
	}
	void operator=(const Location& other) {
		x = other.x;
		y = other.y;
	}
	bool operator==(const Location& other) {
		return x == other.x && y == other.y;
	}
	bool isOvelaping(const Location& other) const {
		return other.x >= x
			&& other.x <= x
			&& other.y <= y
			&& other.y >= y;
	}
};