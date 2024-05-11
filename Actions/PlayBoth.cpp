#include "PlayBoth.h"

PlayBoth::PlayBoth(ApplicationManager* pApp) :BothRNG(pApp) {
	score = 0;
}
void PlayBoth::Execute() {
	BothRNG::Execute();
	if (num == 0) {
		return; //incase the number of possible right figures are zero it prevents the program from running unnecessary part and prevent overwriting in the status bar
	}
	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	for (size_t i = 0; i < num; i++)  
	{
		do {
			pIn->GetPointClicked(x, y); //gets where the user clicked
		} while (pManager->GetFigure(x, y) == NULL);
		if (rcolor==pManager->GetFigure(x, y)->getFillClr() && pManager->GetFigure(x, y)->getType() == rshape) //check the neccassary condition for the figure to be right
		{
			score++; //increase the score if clicked right
		}
		//implement delete here
		if (pManager->GetFigure(x, y) != NULL) {
			R = pManager->GetFigure(x, y); 
			pManager->usedBeforeDeleteInPlay(R);   //used to push the figure the last on the list 
			delete R;                              // deletes the obj   
			pManager->GetFigure(x, y) == NULL;
			pManager->UpdateInterface();          //updates the interface to make deleting the figure appear to the user
		}
		//
	}
pOut->ClearStatusBar();
pOut->PrintMessage("you scored " + to_string(score) + " out of " + to_string(num) + " and you made " + to_string(num - score) + " incorrect picks");
}
void PlayBoth::ReadActionParameters() {

}
