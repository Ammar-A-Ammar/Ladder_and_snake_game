#include "CutCardAction.h"

Grid *gridC; // Grid Pointer

CutCardAction::CutCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

CutCardAction::~CutCardAction()
{
}

void CutCardAction::ReadActionParameters()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces
	Grid *pGrid = pManager->GetGrid();
	Output *pOut = pGrid->GetOutput();
	Input *pIn = pGrid->GetInput();

	pOut->PrintMessage("Click On The Source Cell: ");
	cardposition = pIn->GetCellClicked();


	Cell cut(cardposition);
	if (cut.HasCard())
	{
		gridC->RemoveObjectFromCell(cardposition);
	}

	else
	{
		return;
	}
	pOut->ClearStatusBar();
}

void CutCardAction::Execute() 
{
	ReadActionParameters();
	Card *pCard;
	gridC->SetClipboard(pCard);
}