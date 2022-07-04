#include "AddCoinSetAction.h"

#include "Input.h"
#include "Output.h"
#include "Coinset.h"


AddCoinSetAction::AddCoinSetAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddCoinSetAction::~AddCoinSetAction()
{
}

void AddCoinSetAction::ReadActionParameters() 
{	
	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();


	// 2- Read the "coinNumber" parameter and set its data member

	pOut->PrintMessage("type card number");
	amount =pIn->GetInteger(pOut);
	

	// 3- Read the "coinPosition" parameter (its cell position) and set its data member
	
	pOut->PrintMessage(" cardrposition: click on card cell");
	coinPosition = pIn->GetCellClicked();

	// 4- Make the needed validations on the read parameters 

	if (!coinPosition.IsValidCell())                             
	{
		pGrid->PrintErrorMessage(" cell position is not valid");
	}

	// 5- Clear status bar

	pOut->ClearStatusBar();
}

void AddCoinSetAction::Execute() 
{
	ReadActionParameters();

	Coinset * pCoinset = NULL; // will point to the card object type
	switch (amount)
	{
	
	if (!pCoinset)
	{
		Grid* pGrid = pManager->GetGrid();
		pGrid->PrintErrorMessage("this coin is not valid");
	}

	if (pCoinset)
		{
		// A- We get a pointer to the Grid from the ApplicationManager
		Grid* pGrid = pManager->GetGrid();
		Player* pPlayer=pGrid->GetCurrentPlayer();
		Output* pOut = pGrid->GetOutput();
		// B- Make the "pcoin" return the amount to wallaet xxxxxxxxxxxxxxxxxxxxxx here is the problem
		pCoinset->Apply(pGrid,pPlayer);

		// C- Add the card object to the GameObject of its Cell:
		
		bool added = pGrid->AddObjectToCell(pCoinset);
		
		if (!added && coinPosition.IsValidCell())
			{
			pGrid->PrintErrorMessage(" Error: Cell already has an object !Click to continue ...");
			}
		
		}
	
	}
}


