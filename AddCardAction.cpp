#include "AddCardAction.h"

#include "Input.h"
#include "Output.h"
#include "DecWalletCard_1.h"
#include "NextCard_2.h"
#include "BackwardCard_3.h"
#include "PreventCard_4.h"
#include "FireCard.h"
#include "FreezeCard_6.h"
#include "MCardCairo_7.h"
#include "MCardAlex_8.h"
#include "MCardAswan_9.h"
#include "MCardLuxor_10.h"
#include "MCardHurghada_11.h"
#include "TakeCityCard_12.h"
#include "LoseCityCard_13.h"
#include "ReturnMortgagedCard_14.h"




AddCardAction::AddCardAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddCardAction::~AddCardAction()
{
}

void AddCardAction::ReadActionParameters() 
{	

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces

	Grid *pGrid  = pManager->GetGrid();
	Output *pOut = pGrid->GetOutput();
	
	
	// 2- Read the "cardNumber" parameter and set its data member

	Input *pIn   = pGrid->GetInput();
	pOut->PrintMessage("type card number");

	// 3- Read the "cardPosition" parameter (its cell position) and set its data member

	cardNumber =pIn->GetInteger(pOut);

	// 4- Make the needed validations on the read parameters

	if (!cardPosition.IsValidCell())                             
	{
		pGrid->PrintErrorMessage(" cell position is not valid");
	}

	// 5- Clear status bar

	pOut->ClearStatusBar();
}

void AddCardAction::Execute() 
{

	
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- The first line of any Action Execution is to read its parameter first
	
	ReadActionParameters();

	// 2- Switch case on cardNumber data member and create the appropriate card object type
	Card * pCard = NULL; // will point to the card object type
	switch (cardNumber)
	{
	case 1:
		pCard = new DecWalletCard_1(cardPosition);
		break;

		// A- Add the remaining cases

		case 2:
		pCard = new NextCard_2(cardPosition);
		break;
	case 3:
		pCard = new BackwardCard_3(cardPosition);
		break;
	case 4:
		pCard = new PreventCard_4(cardPosition);
		break;
	case 5:
		pCard = new FireCard(cardPosition);
		break;
	case 6:
		pCard = new FreezeCard_6(cardPosition);
		break;
	case 7:
		pCard = new MCardCairo_7(cardPosition);
		break;
	case 8:
		pCard = new MCardAlex_8(cardPosition);
		break;
	case 9:
		pCard = new MCardAswan_9(cardPosition);
		break;
	case 10:
		pCard = new MCardLuxor_10(cardPosition);
		break;
	case 11:
		pCard = new MCardHurghada_11(cardPosition);
		break;
	case 12:
		pCard = new TakeCityCard_12(cardPosition);
		break;
	case 13:
		pCard = new LoseCityCard_13(cardPosition);
		break;
	case 14:
		pCard = new ReturnMortgagedCard_14(cardPosition);
		break;
	}
	if (!pCard)
	{
		Grid* pGrid = pManager->GetGrid();
		pGrid->PrintErrorMessage("this card is not valid");

	}

	// 3- if pCard is correctly set in the switch case (i.e. if pCard is pointing to an object -- NOT NULL)
	if (pCard)
	{
		// A- We get a pointer to the Grid from the ApplicationManager

		Grid* pGrid = pManager->GetGrid();
		Output* pOut = pGrid->GetOutput();

		// B- Make the "pCard" reads its card parameters: ReadCardParameters(), It is virtual and depends on the card type

		pCard->ReadCardParameters(pGrid);

		// C- Add the card object to the GameObject of its Cell:

		bool added = pGrid->AddObjectToCell(pCard);
		
		if (!(added) && cardPosition.IsValidCell())
		{
			pGrid->PrintErrorMessage(" Error: Cell already has an object !Click to continue ...");
		}

		// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar
		
	}

	// Here, the card is created and added to the GameObject of its Cell, so we finished executing the AddCardAction

}
