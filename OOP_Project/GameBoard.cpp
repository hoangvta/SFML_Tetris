#include "GameBoard.h"

GameBoard::GameBoard()
{
	lineClear = 0;
	updateTime = 0;
	updateInteval = 0.8f;
	gameOver = false;
	boardPos = { 240, 50 };

	setupRandomPieces();

	spawnNewPiece();
	boardSize = { 10, 20 };
	blockSize = 24;
	droped.clear();

	setupEdge();

	text.setText(sf::String("Line cleared: " + std::to_string(lineClear)));
	text.setCharacterSize(12);
	text.setPosition({ 550, 250 });

	droped.clear();
}

GameBoard::~GameBoard()
{	
	for (int i = 0; i < 7; i++) {
		int range = 3;
		if (i == 5) range = 2;
		if (i == 6) range = 4;
		for (int j = 0; j < range; j++) {	
			delete[] randomPiece[i][j];
		}
		delete[] randomPiece[i];
	}

	delete randomPiece;

	while (!droped.empty()) {
		delete droped.back();
		droped.pop_back();
	}
	while (!boardEdge.empty()) {
		delete boardEdge.back();
		boardEdge.pop_back();
	}
}

void GameBoard::spawnNewPiece()
{	
	curPiece = new Piece();

	int randPiece = ApplicationEvent::getEvent().getRandomInt() % 7;
	int pieceSize = 3;
	if (randPiece == 5) pieceSize = 2;
	if (randPiece == 6) pieceSize = 4;

	curPiece->setBlockSize(pieceSize);

	curPiece->setBlockPosition(randomPiece[randPiece]);
	
	curPiece->setPos(sf::Vector2i({ 24 * 6, 0 }) + boardPos);
	if (collisionCheck()) {
		gameOver = true;
		curPiece->pushBlockToVector(droped);
	}
}

bool GameBoard::collisionCheck(bool down)
{
	for (auto block : droped) {
		if (curPiece->collise(*block, down)) {
			return true;
		}
	}

	for (auto block : boardEdge) {
		if (curPiece->collise(*block, down)) {
			return true;
		}
	}
	return false;
}

bool GameBoard::checkClearLine()
{
	std::sort(droped.begin(), droped.end(), [&] (Block* a, Block* b) {
		return a->getPos().y > b->getPos().y;
	});

	std::vector<int> lineToClear;
	lineToClear.clear();

	int cnt = 0;

	for (int i = 0; i < droped.size() - 1; i++) {
		if (droped[i]->getPos().y == droped[i + 1]->getPos().y) {
			cnt++;
		}
		else {
			cnt = 0;
		}
		if (cnt == boardSize.x - 1) {
			lineToClear.push_back(droped[i]->getPos().y);
		}
	}

	while (!lineToClear.empty()) {
		lineClear++;
		droped.erase(std::remove_if(droped.begin(), droped.end(), [&](Block* b) {
			if (b->getPos().y == lineToClear.back()) {
				delete b;
				return true;
			}
			return false;
			}), droped.end());
		for (auto i : droped) {
			if (i->getPos().y <= lineToClear.back()) {
				i->setPos(i->getPos() + sf::Vector2i(0, 24));
			}
			else {
				continue;
			}
		}
		lineToClear.pop_back();
	}
	return false;
}

bool GameBoard::isGameOver()
{
	return gameOver;
}

void GameBoard::updatePiece() {
	
	if (ApplicationEvent::getEvent().isKeyPressed(sf::Keyboard::Up)) {
		curPiece->rotate(true);
		if (collisionCheck())
			curPiece->rotate(false);
	}

	if (ApplicationEvent::getEvent().isKeyPressed(sf::Keyboard::Z)) {
		curPiece->rotate(false);
		if (collisionCheck())
			curPiece->rotate(true);
	}

	if (ApplicationEvent::getEvent().isKeyPressed(sf::Keyboard::Right)) {
		curPiece->setPos(curPiece->getPos() + sf::Vector2i(24, 0));	
		if (collisionCheck())
			curPiece->setPos(curPiece->getPos() - sf::Vector2i(24, 0));
	}

	if (ApplicationEvent::getEvent().isKeyPressed(sf::Keyboard::Left)) {
		curPiece->setPos(curPiece->getPos() - sf::Vector2i(24, 0));
		if (collisionCheck())
			curPiece->setPos(curPiece->getPos() + sf::Vector2i(24, 0));
	}

}

void GameBoard::update()
{
	if (gameOver) {
		text.setText(sf::String("YOU LOSE!\nPoint: " + std::to_string(lineClear) + "\n\nPress Escape\nto return to\nthe main menu"));
		text.setCharacterSize(35);
		text.setPosition({ 120, 150 });
		return;
	}
	text.setText(sf::String("Line cleared: " + std::to_string(lineClear)));

	updatePiece();

	if (collisionCheck(true)) {
		if (updateTime >= updateInteval) {
			curPiece->pushBlockToVector(droped);
			spawnNewPiece();
			checkClearLine();
			updateTime = 0;
		}

		bool doubleTime = ApplicationEvent::getEvent().isKeyHolding(sf::Keyboard::Down);
		updateTime += ApplicationEvent::getEvent().getDeltaTime() * (1 + 5 * doubleTime);
	}
	else {
		if (updateTime >= updateInteval) {
			curPiece->update();
			updateTime = 0;
		}

		bool doubleTime = ApplicationEvent::getEvent().isKeyHolding(sf::Keyboard::Down);
		updateTime += ApplicationEvent::getEvent().getDeltaTime() * (1 + 5 * doubleTime);
	}

}

void GameBoard::draw()
{
	if (!gameOver) {
		for (Block* block : boardEdge) {
			block->draw();
		}

		for (Block* block : droped) {
			block->draw();
		}

		curPiece->draw();
	}
	text.draw();
}

void GameBoard::setupEdge()
{
	
	for (int j = 0; j < boardSize.y + 2; j++) {
		boardEdge.push_back(new Block);
		boardEdge.back()->setPos(sf::Vector2i(0, j) * 24 + boardPos);

		boardEdge.push_back(new Block);
		boardEdge.back()->setPos(sf::Vector2i(boardSize.x + 1, j) * 24 + boardPos);
	}
	
	for (int i = 1; i <= boardSize.x; i++) {
		boardEdge.push_back(new Block);
		boardEdge.back()->setPos(sf::Vector2i(i, boardSize.y + 1) * 24 + boardPos);
	}
}

void GameBoard::setupRandomPieces()
{
	randomPiece = new bool** [7];
	// T
	randomPiece[0] = new bool* [3];
	randomPiece[0][0] = new bool[3] {0, 1, 0};
	randomPiece[0][1] = new bool[3] {1, 1, 1};
	randomPiece[0][2] = new bool[3] {0, 0, 0};
	// J 
	randomPiece[1] = new bool* [3];
	randomPiece[1][0] = new bool[3] {0, 1, 0};
	randomPiece[1][1] = new bool[3] {0, 1, 0};
	randomPiece[1][2] = new bool[3] {1, 1, 0};
	// L
	randomPiece[2] = new bool* [3];
	randomPiece[2][0] = new bool[3] {0, 1, 0};
	randomPiece[2][1] = new bool[3] {0, 1, 0};
	randomPiece[2][2] = new bool[3] {0, 1, 1};
	// Z
	randomPiece[3] = new bool* [3];
	randomPiece[3][0] = new bool[3] {1, 1, 0};
	randomPiece[3][1] = new bool[3] {0, 1, 1};
	randomPiece[3][2] = new bool[3] {0, 0, 0};
	// S
	randomPiece[4] = new bool* [3];
	randomPiece[4][0] = new bool[3] {0, 1, 1};
	randomPiece[4][1] = new bool[3] {1, 1, 0};
	randomPiece[4][2] = new bool[3] {0, 0, 0};
	// O
	randomPiece[5] = new bool* [2];
	randomPiece[5][0] = new bool[2] {1, 1};
	randomPiece[5][1] = new bool[2] {1, 1};
	// I

	randomPiece[6] = new bool* [4];
	randomPiece[6][0] = new bool[4] {0, 0, 0, 0};
	randomPiece[6][1] = new bool[4] {1, 1, 1, 1};
	randomPiece[6][2] = new bool[4] {0, 0, 0, 0};
	randomPiece[6][3] = new bool[4] {0, 0, 0, 0};
}
