#include "Board.h"
#include "CharStack.h"
#include <string>
#include <iostream>

using namespace std;


Board::Board(){

	head=nullptr;
	tail=nullptr;
	int xCnt = 0;
	int oCnt = 0;

}

bool Board::noMove(char ch , int die){

	

	bool checker = true;

	slot*visitor = head;
	while(visitor!=nullptr){

	if (!visitor->slotStack.isEmpty()){    // check slot is empty or not

	char whichtype;

	visitor->slotStack.pop(whichtype);    //  learn the type (X or O) in the slot
	visitor->slotStack.push(whichtype);

	if (whichtype == ch) {      // check type is the same with the ch ( X or O )
    
	int distance=die;
	slot* avaliableSlot;
	avaliableSlot=visitor;
	int tm=0;

	while(tm<distance && avaliableSlot!=nullptr){

		avaliableSlot=avaliableSlot->next;
		tm++;

	}

	if(avaliableSlot!=nullptr){
    
	if(avaliableSlot->slotStack.isEmpty()){

		return false;

	} else{

		char slottype;

		avaliableSlot->slotStack.pop(slottype);
		avaliableSlot->slotStack.push(slottype);
		
		if (slottype==ch){
         
			return false;

		}


	}

	}

	avaliableSlot=visitor;
		tm = 0;
		while(tm<distance && avaliableSlot!=nullptr){

		avaliableSlot=avaliableSlot->prev;
		tm++;

	}

		if(avaliableSlot!=nullptr){
    
	if(avaliableSlot->slotStack.isEmpty()){

		return false;


	} else{

		char slottype;

		avaliableSlot->slotStack.pop(slottype);
		avaliableSlot->slotStack.push(slottype);
		
		if (slottype==ch){
         
			return false;

		}

	}

	}


	}
    
	} 

	visitor=visitor->next;

	}
 
   return checker;

   
}




int Board::validMove(char ch, int choice, int die, int right){

	int idx=0;
	slot* tempSlot=head;
	while ( idx < choice &&  tempSlot!=nullptr){

		tempSlot=tempSlot->next;
		idx++;

	} if(tempSlot==nullptr){ return 1; }

	else if(tempSlot->slotStack.isEmpty()){     return 4;}

	else{

		char tempchar;
		tempSlot->slotStack.pop(tempchar);
		tempSlot->slotStack.push(tempchar);
		if (tempchar!=ch){ return 4; }


	}


	idx=0;
	 tempSlot=head;
	int destination;
	   if(right == 1)
						{
						   destination = choice + die;
						}
						else
						{
							destination = choice - die;
						}

	if (destination<0){ return 2;}
	else{
	while ( idx < destination &&  tempSlot!=nullptr){

		tempSlot=tempSlot->next;
		idx++;
	}

	if(tempSlot==nullptr){ return 2; }

	else if(tempSlot->slotStack.isEmpty()){     return 0;}

	else{

		char tempchar;
		tempSlot->slotStack.pop(tempchar);
		tempSlot->slotStack.push(tempchar);
		if (tempchar==ch){ return 0; }
		else{ return 3;}

	}

	}

}


void Board::movePiece(int choice,int targetInd){

	slot* temp_slot=head;
	for (int a=0 ; a < choice ; a++){

		temp_slot=temp_slot->next;

	}
	char temp_char;
	temp_slot->slotStack.pop(temp_char);

	temp_slot=head;

	for (int a=0 ; a < targetInd ; a++){

		temp_slot=temp_slot->next;

	}

	temp_slot->slotStack.push(temp_char);

}



void Board::printBoard(){

	int currentHeight=4;
	int slotnumber=0;
	for (int currentSlot=0 ; currentSlot<4 ; currentSlot++ , currentHeight--){

	slot* printSlot = head;
     slotnumber=0;
	while( printSlot!=nullptr){
	if (printSlot->slotStack.isEmpty())
	{
      cout << " " ;
	}
	
	else{
    char ch;
	printSlot->slotStack.pop(ch);
	printSlot->slotStack.push(ch);
    int count = SlotCount(printSlot->slotStack);
	if (count >= currentHeight){
		cout << ch ;
	}
	else{
      
		cout << " " ;

	}

	}
	printSlot = printSlot->next;
	slotnumber++;

	}
	cout << endl;
	
	}
	int i=0;
	while(i  < slotnumber){

		cout << "^" ;
		i++;

	}
	cout << endl;

}

int Board::SlotCount(CharStack & mainStack){
	CharStack CopyStack(mainStack);
	int count=0;

	if(CopyStack.isEmpty()){

		return count;
	}

	else{

	while(!CopyStack.isEmpty()){
     char ch;
     CopyStack.pop(ch);
     count= count + 1 ;

	}

	return count;


	}

}


bool Board::targetSlotFull(int slot_idx){
	slot* temp_slot=head;
	for (int i=0 ; i < slot_idx ; i++){

		temp_slot=temp_slot->next;

	}
	if(temp_slot->slotStack.isFull()){

		return true;
	}

	return false;

}


void Board::destroySlot(int slot_idx){

	slot* temp_slot=head;
	char whichone;

	if (slot_idx==0){

		
		temp_slot->slotStack.pop(whichone);
		
        head=head->next;
		head->prev=nullptr;
		delete temp_slot;
		

	}
    
	else{


	for (int a=0 ; a < slot_idx ; a++){

		temp_slot=temp_slot->next;

	}

	if(temp_slot->next==nullptr){

		
		temp_slot->slotStack.pop(whichone);
        
		tail=tail->prev;
		tail->next=nullptr;
		delete temp_slot;


	}
	
	else{

		
		temp_slot->slotStack.pop(whichone);

		slot* deleter=temp_slot;

		temp_slot=temp_slot->prev;
		temp_slot->next=temp_slot->next->next;
		temp_slot=temp_slot->next;
		temp_slot->prev=temp_slot->prev->prev;

		delete deleter;




	}



	}

	if (whichone =='x'){     xCnt = xCnt-4;   }    // update current count of X and O
	else if(whichone=='o') { oCnt = oCnt - 4; }

}


void Board::createSlotBegin(char ch, int num){

	if (ch=='x'){   xCnt=xCnt+num; }
	else if (ch=='o')  {  oCnt=oCnt+num;  }

	slot* temperory = new slot();  // new slot that will be added to the head
    
	for ( int i=0 ; i < num ; i++){

	temperory->slotStack.push(ch);     //filling slot

	}

	if(tail==nullptr && head==nullptr){   
    
	head=temperory;
	tail=temperory;
	head->prev=nullptr;
	

	}
    
	else{

    temperory->prev=nullptr;     
    temperory->next=head;       
	head->prev=temperory;
	head=temperory;

	}


}


void Board::createSlotEnd(char ch, int num){

	if (ch=='x'){   xCnt=xCnt+num; }
	else if (ch=='o') {  oCnt=oCnt+num;  }

	slot* temp = new slot();              // new slot that will be added to the end
    
	for ( int i=0 ; i < num ; i++){
	temp->slotStack.push(ch);             //filling slot

	}

	if(tail==nullptr ){

	tail=temp;
	head=temp;
	head->prev = nullptr;
	head->next = nullptr;

	}
    
	else{
    temp->next=nullptr;
	temp->prev=tail;
    tail->next=temp;
	tail= tail->next;

	}


}

void Board::createEmptySlotEnd(){


	slot* newSlot = new slot();  // new slot that will be added to the end
	
	if(tail==nullptr){

	tail= newSlot;
	head= newSlot;
	head->prev=nullptr;

	}
    
	else{

	newSlot->next=nullptr;
	newSlot->prev=tail;
    tail->next= newSlot;
	tail= tail->next;

	}


}


void Board::clearBoard(){

	slot* current = head;
    slot* temp;
    while (current != nullptr) {    // start deleting from the beginning 
        temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}


int Board::evaluateGame(){
	
	if (xCnt<oCnt){ return 1;}                // X wins
	else if (oCnt<xCnt){ return 2;}           // O wins
	else{ return 3;}

}