#pragma once

#include "LevelGenerator.h"
#include "Leaf.h"

class BSPTree : public LevelGenerator {
public:
	BSPTree() : LevelGenerator() {};
	BSPTree(unsigned int roomSize, unsigned int seed) : LevelGenerator(roomSize, seed) {};
	virtual std::vector<bool>& Algorithm() override;
	std::vector<Leaf*>& CreateLeafs();

	// Show walls that need to be placed
	void ShowWalls(std::vector<Leaf*>& leafs);

	// Show floors that need to be placed
	void ShowFloor(std::vector<Leaf*>& leafs);
};