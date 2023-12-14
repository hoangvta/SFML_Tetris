#ifndef H_PIECE
#define H_PIECE

#include "Block.h"

class Piece : public Block
{
public:
	void draw();

	void rotate(bool clockWise);
	void setBlockPosition(bool** pos);
	void setBlockSize(int size);

	bool collise(Block& other, bool down = true);
	void pushBlockToVector(std::vector<Block*>& vec);
private:

	bool blockPos[4][4];
	int blockSize;
};

#endif
