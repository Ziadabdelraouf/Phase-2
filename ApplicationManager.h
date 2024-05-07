#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum{ MaxFigCount = 200 }; //max number of figures
private:
	int FigCount;		//Actual number of figures
	int SelectedFigCount;  //Get the count of the selected figure.
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure
	int FigerIndex;      //The index of the figure in the Figure list.
	color Color;
	bool IsCut;
	//Pointers to Input and Output classes
	Input* pIn;
	Output* pOut;

	CFigure* Clipboard;  //Pointer to copied/cut figure


public:	

	ApplicationManager();
	~ApplicationManager();

	// -- Action-Related Functions
	ActionType GetUserAction() const; //Reads the input command from the user and returns the corresponding action type
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	

	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure* GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	CFigure* GetFigure(int id) const; //Search for a figure given its ID
	int GetFigureCount() const; //returns the number of figures
	void AddClipBoard(CFigure* pFig);
	CFigure* GetClipboard();
	int GetNumSelected();
	void UnselectAll();
	void ClearAll();
	void UnCut();
	void Delete();
	// -- Interface Management Functions
	Input* GetInput() const; //Return pointer to the input
	Output* GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window
	color GetColor();    
	
	void SetFigCount(int);  //Reset the figure manually if we need.
	
	void SaveAll(ofstream & fout); //Saves all figures
	void PlayAudio(char*);   //Play the filename audio ".wav"
	
	CFigure* GetSelectedFig(); // Get current selected figure
	
	void Swaping(int);  //Swaping between the layers of figures.
	int getColoredTypeNum(int sh, int c);
	bool GetIsCut();
	void SetIsCut(bool);
	CFigure** GetAllSelected();
	void PasteFigure();
	
};
#endif


