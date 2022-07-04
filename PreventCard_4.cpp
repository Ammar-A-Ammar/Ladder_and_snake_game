#include "PreventCard_4.h"
PreventCard_4::PreventCard_4(const CellPosition& pos) : Card(pos), cblocked(NULL) // set the cell position of the card
{
	cardNumber = 4; // set the inherited cardNumber data member with the card number (1 here)
}

PreventCard_4::~PreventCard_4(void)
{
}

void PreventCard_4::ReadCardParameters(Grid* pGrid)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Input* ip = pGrid->GetInput();
	Output* op = pGrid->GetOutput();

	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New DecWalletCard_1: Enter its wallet amount ..."
	op->PrintMessage("New PreventCard_4: click to continue ...");
	int x, y;
	ip->GetPointClicked(x, y);
	// [ Note ]:
	// In DecWalletCard_1, the only parameter of DecWalletCard_1 is the "walletAmount" value to decrease from player
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar
	op->ClearStatusBar();

}

void PreventCard_4::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card c1(position);
	c1.Apply(pGrid, pPlayer);
	pPlayer = pGrid->GetCurrentPlayer();

	pGrid->SetCurrPlayerNum(pPlayer->Getplayernum());

	(pGrid->GetOutput())->PrintMessage("Click on one of the other players you want to prevent...");
	CellPosition positionc = (pGrid->GetInput())->GetCellClicked();
	cblocked->GetCellPosition() = positionc;

	if (pPlayer->Getplayernum() == 3)
	{

		for (int i = 0; i < 3; i++) {
			pGrid->AdvanceCurrentPlayer();
			Cell* cpos = (pGrid->GetCurrentPlayer())->GetCell();
			if (cblocked == cpos)
			{
				(pGrid->GetCurrentPlayer())->Move(pGrid, 0);
			}
			else
			{
				(pGrid->GetCurrentPlayer())->Move(pGrid, (pGrid->GetCurrentPlayer())->GetjustRolledDiceNum());
			}
		}
		pGrid->AdvanceCurrentPlayer();

	}
	else if (pPlayer->Getplayernum() == 2)
	{
		pGrid->AdvanceCurrentPlayer();
		(pGrid->GetCurrentPlayer())->Move(pGrid, (pGrid->GetCurrentPlayer())->GetjustRolledDiceNum());
		for (int i = 0; i < 4; i++) {
			pGrid->AdvanceCurrentPlayer();
			Cell* cpos = (pGrid->GetCurrentPlayer())->GetCell();
			if (cblocked == cpos)
			{
				(pGrid->GetCurrentPlayer())->Move(pGrid, 0);
			}
			else
			{
				(pGrid->GetCurrentPlayer())->Move(pGrid, (pGrid->GetCurrentPlayer())->GetjustRolledDiceNum());
			}
		}
		pGrid->AdvanceCurrentPlayer();

	}
	else if (pPlayer->Getplayernum() == 1)
	{
		pGrid->AdvanceCurrentPlayer();
		(pGrid->GetCurrentPlayer())->Move(pGrid, (pGrid->GetCurrentPlayer())->GetjustRolledDiceNum());
		pGrid->AdvanceCurrentPlayer();
		(pGrid->GetCurrentPlayer())->Move(pGrid, (pGrid->GetCurrentPlayer())->GetjustRolledDiceNum());
		for (int i = 0; i < 4; i++) {
			pGrid->AdvanceCurrentPlayer();
			Cell* cpos = (pGrid->GetCurrentPlayer())->GetCell();
			if (cblocked == cpos)
			{
				(pGrid->GetCurrentPlayer())->Move(pGrid, 0);
			}
			else
			{
				(pGrid->GetCurrentPlayer())->Move(pGrid, (pGrid->GetCurrentPlayer())->GetjustRolledDiceNum());
			}
		}
		pGrid->AdvanceCurrentPlayer();

	}
	else if (pPlayer->Getplayernum() == 0)
	{
		pGrid->AdvanceCurrentPlayer();
		(pGrid->GetCurrentPlayer())->Move(pGrid, (pGrid->GetCurrentPlayer())->GetjustRolledDiceNum());
		pGrid->AdvanceCurrentPlayer();
		(pGrid->GetCurrentPlayer())->Move(pGrid, (pGrid->GetCurrentPlayer())->GetjustRolledDiceNum());
		pGrid->AdvanceCurrentPlayer();
		(pGrid->GetCurrentPlayer())->Move(pGrid, (pGrid->GetCurrentPlayer())->GetjustRolledDiceNum());
		for (int i = 0; i < 4; i++) {
			pGrid->AdvanceCurrentPlayer();
			Cell* cpos = (pGrid->GetCurrentPlayer())->GetCell();
			if (cblocked == cpos)
			{
				(pGrid->GetCurrentPlayer())->Move(pGrid, 0);
			}
			else
			{
				(pGrid->GetCurrentPlayer())->Move(pGrid, (pGrid->GetCurrentPlayer())->GetjustRolledDiceNum());
			}
		}
		pGrid->AdvanceCurrentPlayer();

	}
}


