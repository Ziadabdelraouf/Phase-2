#include "PlayBoth.h"
PlayBoth::PlayBoth(ApplicationManager* pApp) :BothRNG(pApp) {
	score = 0;
}
void PlayBoth::Execute() {
	BothRNG::Execute();
	if (num == 0) {
		return;
	}
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	for (size_t i = 0; i < num; i++)  // hmark should have certain value but logic still has some problems
	{
		do {
			pIn->GetPointClicked(x, y);
		} while (pManager->GetFigure(x, y) == NULL);
		if (rcolor==pManager->GetFigure(x, y)->getFillClr() && pManager->GetFigure(x, y)->getType() == rshape)
		{
			score++;
		}
	}
pOut->ClearStatusBar();
pOut->PrintMessage("you scored " + to_string(score) + " out of " + to_string(num));
}
void PlayBoth::ReadActionParameters() {

}
