
#include "Canvas.h"
#include <iostream>
#include <Math.h>
using namespace std;

Canvas::Canvas(int width, int height) {
	this->width = width;
	this->height = height;
	//declare number of rows
	canvasMatrix = new char* [height];
	for (int i = 0; i < height; i++) {
		canvasMatrix[i] = new char[width]; //initiate number of columns
	}

	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			canvasMatrix[i][j] = ' ';
		}
	}

}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
		{
			canvasMatrix[i][j] = ' ';
		}
	}

	for (int i = 0; i <= 2 * ray; i++) {
		float dist;
		// for vertical movement 
		for (int j = 0; j <= 2 * ray; j++) {
			dist = sqrt((i - ray) * (i - ray) +
				(j - ray) * (j - ray));

			// dist should be in the range (radius - 0.5) 
			// and (radius + 0.5) to print stars(*) 
			if (dist > ray - 0.5 && dist < ray + 0.5)
				canvasMatrix[i][j] = ch;
			else
				canvasMatrix[i][j] = ' ';
		}

	}


}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
	//x-raza este coordonatul de unde incepe cercul pe x
	//x+raza este coordonatul unde se termina cercul pe x etc
	//in if e o proprietate matematica, ceva ce implica raza la patrat
	for (int i = x - ray; i <= x + ray; i++) {
		for (int j = y - ray; j <= y + ray; j++) {
			if ((i - ray) * (i - ray) + (j - ray) * (j - ray) <= ray * ray) {
				canvasMatrix[i][j] = 'a';
			}
		}
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
	for (int i = top; i < bottom; ++i) {
		for (int j = left; j < right; ++j) {
			if (j == left) {
				canvasMatrix[i][j] = ch;
			}
			if (j == right - 1) {
				canvasMatrix[i][j] = ch;
			}
			if (i == top) {
				canvasMatrix[i][j] = ch;
			}
			if (i == bottom - 1) {
				canvasMatrix[i][j] = ch;
			}
		}
	}

}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
	for (int i = top; i < bottom; ++i) {
		for (int j = left; j < right; ++j) {
			canvasMatrix[i][j] = ch;
		}
	}
}

void Canvas::SetPoint(int x, int y, char ch) {
	canvasMatrix[x][y] = ch;
}

void Canvas::DrawLine(int x0, int y0, int x1, int y1, char ch) {
	int dx, dy, p, x, y;

	dx = x1 - x0;
	dy = y1 - y0;

	x = x0;
	y = y0;

	p = 2 * dy - dx;

	while (x < x1)
	{
		if (p >= 0)
		{
			canvasMatrix[x][y] = ch;
			y = y + 1;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			canvasMatrix[x][y] = ch;
			p = p + 2 * dy;
		}
		x = x + 1;
	}
}

void Canvas::Print() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cout << canvasMatrix[i][j];  /* Printing all elements to verify all elements have been correctly assigned or not */
		}
		cout << "\n";
	}
}

void Canvas::Clear() {
	for (int i = 0; i < height; i++)
		delete[] canvasMatrix[i];

	delete[] canvasMatrix;
}