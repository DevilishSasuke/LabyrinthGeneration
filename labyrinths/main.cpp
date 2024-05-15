#include <iostream>
#include "Prim.h"
#include "BinaryTree.h"
#include "Sidewinder.h"

int main()
{
	unsigned int roomSize = 3;
	unsigned int seed = 5;

	auto algo = Sidewinder(roomSize, seed);
	std::vector<bool> list = algo.Algorithm();

}
