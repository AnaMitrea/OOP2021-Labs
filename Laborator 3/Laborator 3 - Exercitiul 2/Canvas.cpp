#include "Canvas.h"
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

Canvas::Canvas(int width, int height)
{
	this->width = width;
	this->height = height;
	Clear();
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < this->width; i++) {
		for (int j = 0; j < this->height; j++) {
			if (pow(i - x, 2) + pow(j - y, 2) >= ray * (ray - 1) && pow(i - x, 2) + pow(j - y, 2) <= ray * (ray + 1)) {
				this->mat[i][j] = ch;
			}
		}
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < this->width; i++) {
		for (int j = 0; j < this->height; j++) {
			if (pow(i - x, 2) + pow(j - y, 2) < ray*ray) {
				this->mat[i][j] = ch;
			}
		}
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = left; i <= right; i++) {
		for (int j = top; j <= bottom; j++) {
			if (i == left || i == right || j == top || j == bottom) {
				this->mat[i][j] = ch;
			}
		}
	}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = left; i <= right; i++) {
		for (int j = top; j <= bottom; j++) {
			this->mat[i][j] = ch;
		}
	}
}

void Canvas::SetPoint(int x, int y, char ch)
{
	this->mat[x][y] = ch;
}

int sign(float deltay)
{
	if (deltay < 0)
		return deltay;
	else
		return -deltay;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx, dy, p, x, y;
	dx = x2 - x1;
	dy = y2 - y1;
	x = x1;
	y = y1;
	p = 2 * dy - dx;
	while (x < x2) {
		if (p >= 0) {
			this->mat[x][y] = ch;
			y++;
			p = p + 2 * dy - 2 * dx;
		}
		else {
			this->mat[x][y] = ch;
			p = p + 2 * dy;
		}
		x++;
	}
}

void Canvas::Clear() 
{
	for (int i = 0; i < this->width; i++) {
		for (int j = 0; j < this->height; j++) {
			mat[i][j] = ' ';
		}
	}
}

void Canvas::Print() 
{
	for (int i = 0; i < this->width; i++) {
		for (int j = 0; j < this->height; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	Clear();
}