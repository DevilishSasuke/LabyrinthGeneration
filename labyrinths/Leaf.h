#pragma once

constexpr int TILESIZE = 3;

#include <vector>
#include <random>
#include <iostream>
#include "Rectangle.h"


class Leaf {
private:
	const int MIN_LEAF_SIZE = 6;
	std::mt19937 rng;

public:
	int x, y;
	int width, height;
	Leaf* leftChild;
	Leaf* rightChild;
	Rectangle room;
	std::vector<Rectangle*> halls;

	Leaf() : x(0), y(0), width(0), height(0) {};
	Leaf(int x, int y, int width, int height, std::mt19937 generator) : x(x), y(y), width(width), height(height), rng(generator) {};
	~Leaf() {
		delete leftChild;
		delete rightChild;
	}

	bool Split();
	void CreateRooms(int roomSize);
	Rectangle GetRoom();
	void CreateHall(Rectangle& left, Rectangle& right);

private:
	int Randomize(std::mt19937& gen, int min, int max) {
		return min + gen() % (max - min + 1);
	}

};