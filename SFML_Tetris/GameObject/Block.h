#ifndef H_BLOCK
#define H_BLOCK

#include "../Application/preloader.h"
#include "InteractableObject.h"

class Block : public InteractableObject
{
public:
	Block();
	~Block();

	void update() override;

	void rotate(bool clockWise);

	bool collise(Block& other, bool down);

private:
};

#endif
