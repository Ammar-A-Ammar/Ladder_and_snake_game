#include "BackwardCard_3.h"

BackwardCard_3::BackwardCard_3(const CellPosition& pos) : Card(pos)  // set the cell position of the card
{
	cardNumber = 3; // set the inherited cardNumber data member with the card number (1 here)
}

BackwardCard_3::~BackwardCard_3(void)
{
}

void BackwardCard_3::ReadCardParameters(Grid* pGrid)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Input* ip = pGrid->GetInput();
	Output* op = pGrid->GetOutput();
	int x, y;
	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New DecWalletCard_1: Enter its wallet amount ..."
	op->PrintMessage("New BackwardCard_3: click to continue...");
	ip->GetPointClicked(x, y);
	// [ Note ]:
	// In DecWalletCard_1, the only parameter of DecWalletCard_1 is the "walletAmount" value to decrease from player
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar
	op->ClearStatusBar();

}

void BackwardCard_3::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	Card c1(position);
	c1.Apply(pGrid, pPlayer);
	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	
	int dicenumber = pGrid->GetCurrentPlayer()->GetjustRolledDiceNum();
	pGrid->SetCurrPlayerNum(pGrid->GetCurrentPlayer()->Getplayernum());

	pGrid->AdvanceCurrentPlayer();
	pPlayer =pGrid->GetCurrentPlayer();
	pPlayer->Move(pGrid, -dicenumber);
	pGrid->AdvanceCurrentPlayer();
	pPlayer = pGrid->GetCurrentPlayer();
	pPlayer->Move(pGrid, -dicenumber);	
	pGrid->AdvanceCurrentPlayer();
	pPlayer = pGrid->GetCurrentPlayer();
	pPlayer->Move(pGrid, -dicenumber);
	pGrid->AdvanceCurrentPlayer();

}
