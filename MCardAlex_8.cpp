#include "MCardAlex_8.h"



MCardAlex_8::MCardAlex_8(const CellPosition& pos) : Card(pos), city_price(0), fees(0), pcityowner(NULL)
// set the cell position of the card
{
	cardNumber = 8; // set the inherited cardNumber data member with the card number (1 here)
}
int MCardAlex_8::Getprice()
{
	return city_price;
}
int MCardAlex_8::Getfees()
{
	return fees;
}

void MCardAlex_8::Setpcmortgaged(Player* x)
{
	pcmortgaged = x;
}
Player* MCardAlex_8::Getpcmortgaged() 
{
	return  pcmortgaged;
	
}

MCardAlex_8::~MCardAlex_8(void)
{
}
Player* MCardAlex_8::Getcityowner()
{
	return pcityowner;
}
void MCardAlex_8::Setcityowner(Player* owner)
{
	pcityowner = owner;
}
void MCardAlex_8::ReadCardParameters(Grid* pGrid)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	int x, y;

	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Input* ip = pGrid->GetInput();
	Output* op = pGrid->GetOutput();

	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New DecWalletCard_1: Enter its wallet amount ..."
	op->PrintMessage("New MONOPLY Card : Alex.... click to cintinue");
	ip->GetPointClicked(x, y);

	int cp = ip->GetInteger(op);
	city_price = cp;

	int feees = ip->GetInteger(op);
	fees = feees;

	op->ClearStatusBar();

	// [ Note ]:
	// In DecWalletCard_1, the only parameter of DecWalletCard_1 is the "walletAmount" value to decrease from player
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar
}

void MCardAlex_8::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	int x, y;    // for click function

	Card c1(position);         // calling apply to print messege
	c1.Apply(pGrid, pPlayer);

	Input* ip = pGrid->GetInput();     // we will use them below
	Output* op = pGrid->GetOutput();

	ip->GetPointClicked(x, y);


	if (pcityowner == NULL)
	{
		op->PrintMessage("Type 1 to buy city and 2 to discard ...click to continue");
		ip->GetPointClicked(x, y);
		ip->GetInteger(op);
		if ((ip->GetInteger(op)) == 1)
		{
			int z = pGrid->GetCurrentPlayer()->GetWallet() - city_price;
			pGrid->GetCurrentPlayer()->SetWallet(z);

			pcityowner = pGrid->GetCurrentPlayer();
		}
		else
		{
			op->PrintMessage("Discarded...click to continue");
			ip->GetPointClicked(x, y);

		}
	}

	if (pcityowner == pGrid->GetCurrentPlayer())
	{
		op->PrintMessage("you already own Cairo...click to continue");
		ip->GetPointClicked(x, y);
	}

	if (pcityowner != pGrid->GetCurrentPlayer() && pcityowner != NULL)
	{
		int l = pGrid->GetCurrentPlayer()->GetWallet() - fees;
		pGrid->GetCurrentPlayer()->SetWallet(l);
		int w = pcityowner->GetWallet() + fees;
		pcityowner->SetWallet(w);
	}
}