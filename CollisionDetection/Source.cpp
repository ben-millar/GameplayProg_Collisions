#include <iostream>
#include <math.h>
#include <time.h>
#include "BoundingBox.h"

class Point_old {
public:
	int x;
	int y;

	void print() {
		std::cout << "x:" << x << " y:" << y << std::endl;
	}
};

class Circle_old {
public:
	Point_old p;
	int r;

	void print() {
		std::cout << "x:" << p.x << " y:" << p.y << " r:" << r << std::endl;
	}
};

class Box_old { 
public: 
	Point_old p; //top-left
	int w; 
	int h; 
	void print() {
		std::cout << "x:" << p.x << " y: " << p.y << " w: " << w << " h: " << h << std::endl;
	} 
};

int calculate_hypotenuse(Point_old a, Point_old b) {
	int result = 0;

	// Find the distance (Length) of X and Y  

	int x_Distance = b.x - a.x;
	int y_Distance = b.y - a.y;

	// Now that we have the distance (Length)
	// of x and y, use Pythagoras theorem 
	// to get the distance (length of hypotenuse) 
	// between Point a and Point b 
	result = sqrt(pow(x_Distance, 2) + pow(y_Distance, 2));

	return result;
}


int main() {

	srand(time(NULL));

	// Point Collision
	Point_old player_point;
	player_point.x = rand() % 10 + 1;
	player_point.y = rand() % 10 + 1;

	Point_old npc_point;
	npc_point.x = rand() % 10 + 1;
	npc_point.y = rand() % 10 + 1;

	// Circle Collision
	Circle_old player_circle;
	player_circle.p.x = rand() % 10 + 1;
	player_circle.p.y = rand() % 10 + 1;
	player_circle.r = rand() % 2 + 1;
	
	Circle_old npc_circle;
	npc_circle.p.x = rand() % 10 + 1;
	npc_circle.p.y = rand() % 10 + 1;
	npc_circle.r = rand() % 2 + 1;

	// Box collision
	Box_old player_box;
	player_box.p.x = rand() % 10 + 1;
	player_box.p.y = rand() % 10 + 1;
	player_box.w = rand() % 5 + 1;
	player_box.h = rand() % 5 + 1;

	Box_old npc_box;
	npc_box.p.x = rand() % 10 + 1;
	npc_box.p.y = rand() % 10 + 1;
	npc_box.w = rand() % 5 + 1;
	npc_box.h = rand() % 5 + 1;


	while (true) {

		// Point Collision check
		if (calculate_hypotenuse(player_point, npc_point) == 0)
		{
			std::cout << "Point Collision" << std::endl;
			player_point.print();
			npc_point.print();
			std::cin.get();
		}
		else
		{
			std::cout << "No Collision" << std::endl;
			player_point.print();
			npc_point.print();
		}

		player_point.x = rand() % 10 + 1;
		player_point.y = rand() % 10 + 1;

		// Circle Collision check
		if (calculate_hypotenuse(player_circle.p, npc_circle.p) < (player_circle.r + npc_circle.r))
		{
			std::cout << "Circle Collision" << std::endl;
			player_circle.print();
			npc_circle.print();
			std::cin.get();
		}
		else
		{
			std::cout << "No Collision" << std::endl;
			player_circle.print();
			npc_circle.print();
		}

		player_circle.p.x = rand() % 10 + 1;
		player_circle.p.y = rand() % 10 + 1;

		// Circle to Point Collision Check
		if (calculate_hypotenuse(player_circle.p, npc_point) < player_circle.r)
		{
			std::cout << "Circle to Point Collision" << std::endl;
			player_circle.print();
			npc_point.print();
			std::cin.get();
		}
		else
		{
			std::cout << "No Collision" << std::endl;
			player_circle.print();
			npc_point.print();
		}

		// Box to Box Collision Check
		// if there is a line of intersection along the y-plane
		if ((player_box.p.x + player_box.w) > npc_box.p.x && player_box.p.x < (npc_box.p.x + npc_box.w))
		{
			// if there is a line of intersection along the x-plane
			if ((player_box.p.y + player_box.h) > npc_box.p.y && player_box.p.y < (npc_box.p.y + npc_box.h))
			{
				std::cout << "Box to Box Collision" << std::endl;
				player_box.print();
				npc_box.print();
				std::cin.get();
			}
			else
			{
				std::cout << "No Collision" << std::endl;
				player_box.print();
				npc_box.print();
			}
		}
		else
		{
			std::cout << "No Collision" << std::endl;
			player_box.print();
			npc_box.print();
		}

		player_box.p.x = rand() % 10 + 1;
		player_box.p.y = rand() % 10 + 1;
	}

	return 0;
}