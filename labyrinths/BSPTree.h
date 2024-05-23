#pragma once

#include "LevelGenerator.h"
#include "Leaf.h"

class BSPTree : public LevelGenerator {
public:
	BSPTree() : LevelGenerator() {};
	BSPTree(unsigned int roomSize, unsigned int seed) : LevelGenerator(roomSize, seed) {};
	virtual std::vector<bool>& Algorithm() override;
	std::vector<Leaf*>& CreateLeafs();

	void ShowRooms(std::vector<Leaf*>& leafs) {
		std::vector<std::vector<bool>> vec(roomSize, std::vector<bool>(roomSize));

		Rectangle room;
		for (Leaf* leaf : leafs) {
			if (leaf->room.Exists()) {
				room = leaf->room;
				for (int i = room.x1; i <= room.x2; i++) {
					vec[room.y1][i] = true;
					vec[room.y2][i] = true;
				}
				for (int i = room.y1; i <= room.y2; i++) {
					vec[i][room.x1] = true;
					vec[i][room.x2] = true;
				}
			}
			if (leaf->halls.size() > 0) {
				for (Rectangle* hall : leaf->halls) {
					for (int i = hall->x1; i <= hall->x2; ++i) {
						for (int j = hall->y1; j <= hall->y2; ++j) {
							vec[j][i] = true;
						}
					}
				}
			}
		}

		for (std::vector<bool> part : vec) {
			for (bool flag : part) std::cout << (flag ? "=" : "0") << " ";
			std::cout << std::endl;
		}
	}
};