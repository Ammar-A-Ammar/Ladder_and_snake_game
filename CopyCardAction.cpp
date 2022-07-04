#include "CopyCardAction.h"
CopyCardAction::CopyCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

CopyCardAction::~CopyCardAction()
{
}

void CopyCardAction::ReadActionParameters()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces
	Grid *pGrid = pManager->GetGrid();
	Output *pOut = pGrid->GetOutput();
	Input *pIn = pGrid->GetInput();

	pOut->PrintMessage("Click on the source Cell:");
	cardPosition = pIn->GetCellClicked();

	Cell c(cardPosition);
	if (c.HasCard())
	{
		Card x(cardPosition);
		CopiedcardNumber = x.GetCardNumber();
	}
	else
	{
		return;
	}
	pOut->ClearStatusBar();
}
	

	

	void CopyCardAction::Execute() 
	{
		ReadActionParameters();
		Grid *pGrid = pManager->GetGrid();
		Output *pOut = pGrid->GetOutput();
		Input *pIn = pGrid->GetInput();
	    Card pCard(cardPosition);
		pCard.SetCardNumber(CopiedcardNumber);
		pGrid->SetClipboard(&pCard);
		pOut->PrintMessage("Card Copied To Clipboard");
	}


	int CopyCardAction::get_copiedcard() 
	{
		return CopiedcardNumber;
	}