#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "RNG.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum{ MaxFigCount = 200 }; //max number of figures
private:
	int FigCount;		//Actual number of figures
	int SelectedFigCount;
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure
	int FigerIndex;      //The index of the figure in the Figure list.
	color Color;

	char* Audio;

        RNG r;          // RNG obj to access the function
        int temp1;
        int temp2;
        int temp3;
        CFigure* R;     // it's only use is for the RNG part to access CFigure function and static members


	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

	CFigure* Clipboard;  //Pointer to copied/cut figure

public:	

	ApplicationManager(); 
	~ApplicationManager();

	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	CFigure *GetFigure(int id) const; //Search for a figure given its ID
	int GetFigureCount() const; //returns the number of figures
	int GetNumSelected();
	void UnselectAll();
	void ClearAll();
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window
	color GetColor();
	CFigure* GetSelectedFig(); // Get current selected figure
	void SetFigCount(int);
	void Swaping(int);
	void SaveAll(ofstream & fout);
	void PlayAudio(char*);
};
#endif
