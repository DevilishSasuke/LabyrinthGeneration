#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <random>

class Leaf;
class Utilities {
public:
	virtual int Randomize(std::mt19937& gen, int min, int max) = 0;
	virtual void ShowWalls(std::vector<Leaf*>& leafs) = 0;
	virtual void ShowFloor(std::vector<Leaf*>& leafs) = 0;
	virtual std::vector<std::vector<int>> GetRandomGraph() = 0;
		/*std::vector<std::vector<int>> graph(roomSizeSqr, std::vector<int>(roomSizeSqr));
		int dif = 0;

		for (int i = 0; i < roomSizeSqr; ++i) {
			for (int j = 0; j < roomSizeSqr; ++j) {
				if (j > i) break;
				dif = abs(i - j);
				if (dif != 1 &&
					dif != roomSize ||
					(dif == 1 && (i % roomSize == 0)))
					continue;

				if (graph[j][i] != 0)
					graph[i][j] = graph[j][i];
				else {
					graph[i][j] = rng() % 100 + 1;
					graph[j][i] = graph[i][j];
				}
			}
		}

		return graph;*/
};
// void ShowRooms(std::vector<Leaf*>& leafs)