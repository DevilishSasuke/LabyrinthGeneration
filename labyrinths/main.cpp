#include <iostream>
#include "Prim.h"
#include "BinaryTree.h"
#include "Sidewinder.h"
#include "AldousBroder.h"
#include "BSPTree.h"

int main()
{
	unsigned int roomSize = 11;
	unsigned int seed = 98;
	// bugs: 
	// roomsize = 20; seed = 5;
	// roomsize = 15, seed = 99;
	// roomsize = 12, seed = 99;
	// roomsize = 11, seed = 98;

	auto algo = BSPTree(30, 99);
	std::vector<bool> list = algo.Algorithm();
	std::cout << std::endl;
	
	for (int i = 0; i < 100; i++) {
	}

	/*auto algo = BSPTree(20, 5);
	std::vector<bool> list = algo.Algorithm();
	std::cout << std::endl;

	algo = BSPTree(15, 99);
	list = algo.Algorithm();
	std::cout << std::endl;

	algo = BSPTree(12, 99);
	list = algo.Algorithm();
	std::cout << std::endl;

	algo = BSPTree(11, 98);
	list = algo.Algorithm();
	std::cout << std::endl;*/
} 
