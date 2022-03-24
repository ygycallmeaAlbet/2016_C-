#include <iostream>
#include <map>
#include "zblock.h"

using namespace std;

// Constructor that sets type
zblock::zblock() : block{'Z'} {}

void zblock::clockwise(string** board){
	if(state==1){
	Coordinate *c=blockCoord[0];
	int x=c->getX(c);
	int y=c->getY(c);
	for(int i=1;i<4;i++){
	Coordinate *d=blockCoord[i];
	int x1=d->getX(d);
	int y1=d->getY(d);
	if(x1<x && y1<y){
	x=x1;
	y=y1;
	}
	}
	carriedOver->setCoord(x, y);

	if((x+1)>bottomRow || (x-1)<topBorder || (y+1)>(rightBorder-1)){}
		else {
		if((board[x][y]==" " || isPresent(x, y)==true) && 
			(board[x][y+1]==" " || isPresent(x, y+1)==true) && 
			(board[x+1][y]==" " || isPresent(x+1, y)==true) && 
			(board[x-1][y+1]==" " || isPresent(x-1, y+1)==true)){
		for(int j=0;j<4;j++){
		Coordinate *c=blockCoord[j];
		int x=c->getX(c);
		int y=c->getY(c);
		board[x][y]=" ";  //the previous coordinates of the block are set to empty.
		}
		blockCoord[0]->setCoord(x, y);
		blockCoord[1]->setCoord(x, y+1);
		blockCoord[2]->setCoord(x+1, y);
		blockCoord[3]->setCoord(x-1, y+1);
		state=2;
		}
		}
	}

	else if(state==2){
		int x=carriedOver->getX(carriedOver);
		int y=carriedOver->getY(carriedOver);

		if((x+1)>bottomRow || (y+1)>(rightBorder-1) || (y+2)>(rightBorder-1)){}
			else {
		if((board[x][y]==" " || isPresent(x, y)==true) && 
			(board[x][y+1]==" " || isPresent(x, y+1)==true) && 
			(board[x+1][y+1]==" " || isPresent(x+1, y+1)==true) && 
			(board[x+1][y+2]==" " || isPresent(x+1, y+2)==true)){
		for(int j=0;j<4;j++){
		Coordinate *c=blockCoord[j];
		int x=c->getX(c);
		int y=c->getY(c);
		board[x][y]=" ";  //the previous coordinates of the block are set to empty.
		}
		blockCoord[0]->setCoord(x, y);
		blockCoord[1]->setCoord(x, y+1);
		blockCoord[2]->setCoord(x+1, y+1);
		blockCoord[3]->setCoord(x+1, y+2);
		state=1;
		}
		}
	}
}

void zblock::anticlockwise(string** board){
	if(state==1){  
		this->clockwise(board);
	}
	else if(state==2){  
		this->clockwise(board);
	}
}

void zblock::updateBoard(string** board){
	for(int i=0;i<4;i++){
	Coordinate *c=blockCoord[i];
	int x=c->getX(c);
	int y=c->getY(c);
	board[x][y]="Z";
	}
}

void zblock::initialize(string** board, int level_num, bool &gameOver){
	state=1;
	level=level_num;
	//set isHeavy.
	if(level_num<=2){
		isHeavy=false;
	}
	else {
		isHeavy=true;
	}

	carriedOver=new Coordinate;
	carriedOver->setCoord(3, 0);

	if(board[3][0]!=" " || board[3][1]!=" " || board[4][1]!=" " || board[4][2]!=" "){
		gameOver=true;
	}
	else { 
	blockCoord[0]=new Coordinate;
	blockCoord[0]->setCoord(3, 0);

	blockCoord[1]=new Coordinate;
	blockCoord[1]->setCoord(3, 1);

	blockCoord[2]=new Coordinate;
	blockCoord[2]->setCoord(4, 1);

	blockCoord[3]=new Coordinate;
	blockCoord[3]->setCoord(4, 2);

	for(int i=0;i<4;i++){
	Coordinate *c=blockCoord[i];
	int x=c->getX(c);
	int y=c->getY(c);
	board[x][y]="Z";
	}
	}
}


