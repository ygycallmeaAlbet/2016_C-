#ifndef _TBLOCK_H_
#define _TBLOCK_H_
#include <iostream>
#include "block.h"

class tblock: public block{
public:
	tblock();
	void initialize(std::string** board, int level_num, bool &gameOver) override;
	void clockwise(std::string** board) override;
	void anticlockwise(std::string** board) override;
	void updateBoard(std::string** board) override;
};
#endif
