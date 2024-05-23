#include "BSPTree.h"

std::vector<bool>& BSPTree::Algorithm() {
	CreateLeafs();

	return resultGraph;
}

std::vector<Leaf*>& BSPTree::CreateLeafs() {
	int vectorSize = 0, vectorCapacity = 150;
	const int MAX_LEAF_SIZE = 5;

	std::vector<Leaf*> leafs;
	Leaf root = Leaf(0, 0, roomSize, roomSize, rng);

	bool splited = true;
	leafs.reserve(vectorCapacity);
	leafs.push_back(&root);
	vectorSize++;

	while (splited && vectorSize + 2 < vectorCapacity) {
		splited = false;
		for (Leaf* leaf : leafs) {
			if (leaf->leftChild == NULL && leaf->rightChild== NULL)
				if (leaf->width> MAX_LEAF_SIZE || leaf->height > MAX_LEAF_SIZE ||
					(static_cast<double>(rng()) / rng.max() > 0.25))
					if (leaf->Split()) {
						leafs.push_back(leaf->leftChild);
						leafs.push_back(leaf->rightChild);
						vectorSize += 2;
						splited = true;
					}
		}
	}

	root.CreateRooms(roomSize);
	ShowRooms(leafs);
//	ShowWalls(leafs);
//	ShowFloor(leafs);
	return leafs;
}

