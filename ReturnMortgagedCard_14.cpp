#include "ReturnMortgagedCard_14.h"

ReturnMortgagedCard_14::ReturnMortgagedCard_14(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 14; // set the inherited cardNumber data member with the card number (1 here)
}

ReturnMortgagedCard_14::~ReturnMortgagedCard_14(void)
{
}

void ReturnMortgagedCard_14::ReadCardParameters(Grid* pGrid)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==
	int x, y;

	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Input* pinn = pGrid->GetInput();
	Output* poutt = pGrid->GetOutput();
	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New DecWalletCard_1: Enter its wallet amount ..."
	poutt->PrintMessage("New ReturnMortgagedCard_14: clcik to contine ...");
	pinn->GetPointClicked(x, y);

	
	// [ Note ]:
	// In DecWalletCard_1, the only parameter of DecWalletCard_1 is the "walletAmount" value to decrease from player
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar
	poutt->ClearStatusBar();
}

void ReturnMortgagedCard_14::Apply(Grid* pGrid, Player* pPlayer)
{
	MCardCairo_7* city1 = NULL;
	MCardAlex_8* city2 = NULL;
	MCardAswan_9* city3 = NULL;
	MCardLuxor_10* city4 = NULL;
	MCardHurghada_11* city5 = NULL;
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Input* pinn = pGrid->GetInput();
	Output* poutt = pGrid->GetOutput();

	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==
	int x, y;
	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card c1(position);
	c1.Apply(pGrid, pPlayer);
	pinn->GetPointClicked(x, y);

	int a, b, c, d, f;

	if (city1->Getpcmortgaged() == pGrid->GetCurrentPlayer())
		a = city1->Getprice();
	else
		a = -1;

	if (city2->Getpcmortgaged() == pGrid->GetCurrentPlayer())
		b = city2->Getprice();
	else
		b = -1;

	if (city3->Getpcmortgaged() == pGrid->GetCurrentPlayer())
		c = city3->Getprice();
	else
		c = -1;

	if (city4->Getpcmortgaged() == pGrid->GetCurrentPlayer())
		d = city4->Getprice();
	else
		d = -1;

	if (city5->Getpcmortgaged() == pGrid->GetCurrentPlayer())
		f = city5->Getprice();
	else f = -1;

	int t[5] = { a,b,c,d,f };

	for (int i = 0;i < 4;i++)
	{
		if (t[i + 1] > t[i])
		{
			int g = t[i];
			t[i] = t[i + 1];
			t[i + 1] = g;
		}
	}
	int minprice = t[4];


	if (minprice == a)
	{
		city1->Setpcmortgaged(NULL);
		if (city1->Getcityowner() != NULL) // extra i odnt think we need it as the city cant be mortgaged without an owner.
		{
			city1->Setpcmortgaged(NULL);
			city1->Setcityowner(pGrid->GetCurrentPlayer());
		}
	}

	if (minprice == b)
	{
		city2->Setpcmortgaged(NULL);
		if (city2->Getcityowner() != NULL) // extra i odnt think we need it as the city cant be mortgaged without an owner.
		{
			city2->Setpcmortgaged(NULL);
			city2->Setcityowner(pGrid->GetCurrentPlayer());
		}
	}

	if (minprice == c)
	{
		city3->Setpcmortgaged(NULL);
		if (city3->Getcityowner() != NULL) // extra i odnt think we need it as the city cant be mortgaged without an owner.
		{
			city3->Setpcmortgaged(NULL);
			city3->Setcityowner(pGrid->GetCurrentPlayer());
		}
	}
	if (minprice == d)
	{
		city4->Setpcmortgaged(NULL);
		if (city4->Getcityowner() != NULL) // extra i odnt think we need it as the city cant be mortgaged without an owner.
		{
			city4->Setpcmortgaged(NULL);
			city4->Setcityowner(pGrid->GetCurrentPlayer());
		}
	}
	if (minprice == f)
	{
		city5->Setpcmortgaged(NULL);
		if (city5->Getcityowner() != NULL) // extra i odnt think we need it as the city cant be mortgaged without an owner.
		{
			city5->Setpcmortgaged(NULL);
			city5->Setcityowner(pGrid->GetCurrentPlayer());
		}
	}


}