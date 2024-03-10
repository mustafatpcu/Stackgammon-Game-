#include <string>
#include <iostream>
#include "CharStack.h"


using namespace std;

struct slot { 
slot * next; 
slot * prev; 
CharStack slotStack; 
slot () {} };


class Board{


private:
	slot* head;
	slot* tail;
	int xCnt ;
	int oCnt ;

public:

	Board();  
	
	bool noMove(char ch , int die); 

	int validMove(char ch, int choice, int die, int right); 

	void movePiece(int choice,int targetInd); 
	
	void printBoard();  

	bool targetSlotFull(int slot_idx);  

	void destroySlot(int slot_idx); 

	void createSlotBegin(char ch, int num);  
	
	void createSlotEnd(char ch, int num);   

	void createEmptySlotEnd(); 

	void clearBoard(); 

	int evaluateGame(); 

	int SlotCount (CharStack & Stack);


};