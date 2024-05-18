#include <iostream>
#include "Prim.h"
#include "BinaryTree.h"
#include "Sidewinder.h"
#include "AldousBroder.h"
#include "BSPTree.h"

int main()
{
	unsigned int roomSize = 20;
	unsigned int seed = 5;

	auto algo = BSPTree(roomSize, seed);
	std::vector<bool> list = algo.Algorithm();


} 
