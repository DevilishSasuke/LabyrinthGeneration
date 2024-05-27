#include <iostream>
#include "Prim.h"
#include "BinaryTree.h"
#include "Sidewinder.h"
#include "AldousBroder.h"
#include "BSPTree.h"

int main()
{
	unsigned int roomSize = 5;
	unsigned int seed = 1;
	int roomSizeSqr = roomSize * roomSize;


	auto algo = Prim(5, 1);
	std::vector<bool> list = algo.Algorithm();

	for (int i = 0; i < list.size(); ++i) {
		if (list[i]) {
			std::cout << i / roomSizeSqr << " " << i % roomSizeSqr << std::endl;
		}
	}
} 
