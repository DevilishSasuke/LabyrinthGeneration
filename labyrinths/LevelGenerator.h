#pragma once

#include "Utilities.h"

class LevelGenerator {
protected:
	unsigned int seed;
	unsigned int roomSize;
	unsigned int roomSizeSqr;
	std::vector<std::vector<int>> graph;
	std::vector<bool> resultGraph;
	std::mt19937 rng;

public:
	LevelGenerator() : seed(0), roomSize(0), roomSizeSqr(0), rng(seed) {}
	LevelGenerator(unsigned int roomSize, unsigned int seed) : LevelGenerator(roomSize, seed, true) {};
	LevelGenerator(unsigned int roomSize, unsigned int seed, bool initValue) : 
		seed(seed), rng(seed),
		roomSize(roomSize), roomSizeSqr(roomSize* roomSize) {
		resultGraph.resize(roomSizeSqr * roomSizeSqr, initValue);
	}
	virtual ~LevelGenerator() {};

	virtual std::vector<bool>& Algorithm() = 0;
	virtual void GetRandomGraph() {
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
	}

	inline void SetWall(int x, int y) {
		resultGraph[x * roomSizeSqr + y] = true;
		resultGraph[y * roomSizeSqr + x] = true;
	}

	inline void DeleteWall(int x, int y) {
		resultGraph[x * roomSizeSqr + y] = false;
		resultGraph[y * roomSizeSqr + x] = false;
	}
};