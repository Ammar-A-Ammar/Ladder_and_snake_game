#include "DecWalletCard_1.h"

DecWalletCard_1::DecWalletCard_1(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 1; // set the inherited cardNumber data member with the card number (1 here)
}

DecWalletCard_1::~DecWalletCard_1(void)
{
}

void DecWalletCard_1::ReadCardParameters(Grid * pGrid)
{
	
	
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==
	int x, y;

	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Input *pinn=pGrid->GetInput();
	Output* poutt = pGrid->GetOutput();
	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New DecWalletCard_1: Enter its wallet amount ..."
	poutt->PrintMessage("New DecWalletCard_1: Enter its wallet amount ...");
	pinn->GetPointClicked(x, y);

	walletAmount = pinn->GetInteger(poutt);
	// [ Note ]:
	// In DecWalletCard_1, the only parameter of DecWalletCard_1 is the "walletAmount" value to decrease from player
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar
	poutt->ClearStatusBar();
}

void DecWalletCard_1::Apply(Grid* pGrid, Player* pPlayer)
{
		
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	

	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card c1(position);
	c1.Apply(pGrid, pPlayer);


	// 2- Decrement the wallet of pPlayer by the walletAmount data member of DecWalletCard_1
	int x=pPlayer->GetWallet();
	x = x - walletAmount;
	pPlayer->SetWallet(x);
}
