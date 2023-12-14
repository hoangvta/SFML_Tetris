#include "Piece.h"

void Piece::draw()
{	
	sf::Vector2i originPos = getPos();

	for (int i = 0; i < blockSize; i++) {
		for (int j = 0; j < blockSize; j++) {
			if (!blockPos[i][j]) continue;
			setPos(originPos + sf::Vector2i(i - 1, j - 1) * 24);
			Block::draw();
			setPos(originPos);
		}
	}
}

void Piece::rotate(bool clockWise)
{
	if (!clockWise) {
		for (int i = 0; i < blockSize; i++) {
			for (int j = 0; j < i; j++) {
				std::swap(blockPos[i][j], blockPos[j][i]);
			}
		}
		for (int i = 0; i < blockSize; i++) {
			for (int j = 0; j < blockSize / 2; j++) {
				std::swap(blockPos[i][j], blockPos[i][blockSize - j - 1]);
			}
		}
	}
	else {
		rotate(!clockWise);
		rotate(!clockWise);
		rotate(!clockWise);
	}
}

void Piece::setBlockPosition(bool** pos)
{
	for (int i = 0; i < blockSize; i++) {
		for (int j = 0; j < blockSize; j++) {
			blockPos[i][j] = pos[i][j];
		}
	}
}

void Piece::setBlockSize(int size)
{
	blockSize = size;
}

bool Piece::collise(Block& other, bool down)
{
	sf::Vector2i originPos = getPos();

	for (int i = 0; i < blockSize; i++) {
		for (int j = 0; j < blockSize; j++) {
			if (!blockPos[i][j]) continue;
			setPos(originPos + sf::Vector2i(i - 1, j - 1) * 24);
			if (other.collise(*this, down)) {
				setPos(originPos);
				return true;
			}
			setPos(originPos);
		}
	}
	return false;
}

void Piece::pushBlockToVector(std::vector<Block*>& vec)
{
	sf::Vector2i originPos = getPos();

	for (int i = 0; i < blockSize; i++) {
		for (int j = 0; j < blockSize; j++) {
			if (!blockPos[i][j]) continue;


			setPos(originPos + sf::Vector2i(i - 1, j - 1) * 24);
			Block* bl = new Block();
			bl->setPos(getPos());
			vec.push_back(bl);
			setPos(originPos);
		}
	}
}

