#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "level.h"
#include "block.h"
#include "window.h"

const int boardheight=18;
const int boardwidth=11;

class grid {
	block* currentBlock;
	block* nextBlock;
	Level* level;
	std::string **board;
	std::map<int, int> emptyRows;
	std::vector<history*> GridList;
	int currentScore;
	Xwindow* w;

public:
	void SetBoard(int level_num, std::string scriptfile, bool& gameOver, bool textOnly);
	//this sets up the initial configuration of the board.
	void DrawBoard(int l, int hiScore, bool textOnly);
	void drawNextBlock();
	int &returnCurScore();
	std::vector<history*> &returnGridList();  //returns the private member GridList.
	std::string** returnBoard();  //returns the private member, board.
	std::map<int, int> returnRows();  //returns the private member, emptyRows.
	~grid(); //destructor.
	block* getCurrentBlock();
	block* getNextBlock(bool &gameOver);
	block* returnNextBlock();
	void setNextBlock(block* b);
	void setCurrentBlock(block* b, bool& gameOver);
	void levelUp();
	void levelDown(std::string scriptfile);
};

