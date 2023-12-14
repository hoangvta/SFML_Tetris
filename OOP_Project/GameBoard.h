#ifndef H_GAMEBOARD
#define H_GAMEBOARD

#include "preloader.h"
#include "ApplicationEvent.h"

#include "InteractableObject.h"
#include "Piece.h"
#include "Text.h"

#include <vector>
#include <algorithm>

class GameBoard
{
public:
	GameBoard();
	~GameBoard();

	void spawnNewPiece();
	bool collisionCheck(bool down = false);
	bool checkClearLine();
	bool isGameOver();

	void updatePiece();
	void update();
	
	void draw();
private:
	bool gameOver;
	int lineClear;

	void setupEdge();
	void setupRandomPieces();

	Piece* curPiece;
	sf::Vector2u boardSize;
	sf::Int8 blockSize;

	float updateTime;
	float updateInteval;
	
	std::vector<Block*> droped;
	std::vector<Block*> boardEdge;
	sf::Vector2i boardPos;

	bool*** randomPiece;

	Text text;
};

#endif