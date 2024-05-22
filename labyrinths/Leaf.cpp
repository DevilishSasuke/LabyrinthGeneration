#include "Leaf.h"
#include <iostream>

bool Leaf::Split() {
	if (leftChild != NULL && rightChild != NULL) return false;

	bool splitH = static_cast<double>(rng()) / rng.max() > 0.5;
	if (width > height && static_cast<double>(width) / height >= 1.25)
		splitH = false;
	else if (height > width && static_cast<double>(height) / width >= 1.25)
		splitH = true;

	int maxH = splitH ? height : width;

	if (maxH <= MIN_LEAF_SIZE) return false;

	int split = Randomize(rng, MIN_LEAF_SIZE, std::max(MIN_LEAF_SIZE, maxH - MIN_LEAF_SIZE));
	
	if (splitH) {
		if (height - split < MIN_LEAF_SIZE) return false;
		leftChild = new Leaf(x, y, width, split, rng);
		maxH = rng() % 100 + 100;
		for (int i = 0; i < maxH; ++i) rng();
		rightChild = new Leaf(x, y + split, width, height - split, rng);
	}
	else {
		if (width - split < MIN_LEAF_SIZE) return false;
		leftChild = new Leaf(x, y, split, height, rng);
		maxH = rng() % 100 + 100;
		for (int i = 0; i < maxH; ++i) rng();
		rightChild = new Leaf(x + split, y, width - split, height, rng);
	}

	return true;
};

void Leaf::CreateRooms(int roomSize) {
	if (leftChild != NULL || rightChild != NULL) {
		if (leftChild != NULL) leftChild->CreateRooms(roomSize);
		if (rightChild != NULL) rightChild->CreateRooms(roomSize);
	}
	else {
		int roomWidth, roomHeight, roomPosX, roomPosY;

		roomWidth = Randomize(rng, TILESIZE, std::max(TILESIZE, width - 2)) - 1; 
		roomHeight = Randomize(rng, TILESIZE, std::max(TILESIZE, height - 2)) - 1;
		roomPosX = x + Randomize(rng, 1, std::max(1, width - roomWidth - 1));
		roomPosY = y + Randomize(rng, 1, std::max(1, height - roomHeight - 1));

		if ((roomPosX + roomWidth) < roomSize && (roomPosY + roomHeight) < roomSize)
			room = Rectangle(roomPosX, roomPosY, roomPosX + roomWidth, roomPosY + roomHeight);
	}
}

Rectangle Leaf::GetRoom() {
	Rectangle empty;
	if (room.Exists()) return room;
	else {
		Rectangle leftRoom;
		Rectangle rightRoom;

		if (leftChild != NULL)
			leftRoom = leftChild->GetRoom();
		if (rightChild != NULL)
			rightRoom = rightChild->GetRoom();

		if (!leftRoom.Exists() && !rightRoom.Exists()) return empty;

		if (!leftRoom.Exists()) return rightRoom;
		if (!rightRoom.Exists()) return leftRoom;

		if (rng() % 2 == 1)
			return leftRoom;
		else return rightRoom;
	}
}

void Leaf::CreateHall(Rectangle& left, Rectangle& right) {

}