#include "PasteCardAction.h"

PasteCardAction::PasteCardAction(ApplicationManager *pApp) : Action(pApp)
{
}
PasteCardAction::~PasteCardAction()
{
}

void PasteCardAction::ReadActionParameters()
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pastedCard = pGrid->GetClipboard();

	pOut->PrintMessage("Click on the destination Cell:");
	
	CopyCardAction copiedcard(pManager);
	copiedcard.get_copiedcard();

	Cell c(cardPosition);
	if (c.HasCard() || c.HasLadder() || c.HasSnake())
	{
		pOut->PrintMessage("Invalid Placement:   Click to Continue " );
		return;
	}
	else
		Pastednumber = pGrid->GetClipboard()->GetCardNumber();
	
	pOut->ClearStatusBar();
}

void PasteCardAction::Execute()
{
	Grid *pGrid = pManager->GetGrid();
	Output *pOut = pGrid->GetOutput();
	Input *pIn = pGrid->GetInput();
	Card pCard(cardPosition);


	ReadActionParameters();
	int index;
	pOut->PrintMessage("Enter the number of iterations: ");
	index = pIn->GetInteger(pOut);
	/*for (int i = 0; i < index; i++)
	{*/
		/*pCard.SetCardNumber(Pastednumber);*/

		pGrid->AddObjectToCell(pastedCard);

		//pCard.GetPosition()
	
		Cell pCardCell(pastedCard->GetPosition());
		pCardCell.DrawCellOrCard(pOut);
		
		
	//}
	
	
	 

}