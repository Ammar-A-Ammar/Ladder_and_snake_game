#include "LoseCityCard_13.h"
LoseCityCard_13::LoseCityCard_13(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 13; // set the inherited cardNumber data member with the card number (1 here)
}

LoseCityCard_13::~LoseCityCard_13(void)
{
}

void LoseCityCard_13::ReadCardParameters(Grid* pGrid)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	int x, y;

	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Input* pinn = pGrid->GetInput();
	Output* poutt = pGrid->GetOutput();
	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New DecWalletCard_1: Enter its wallet amount ..."
	poutt->PrintMessage("New losecitycard_13: :( click to contine ...");
	pinn->GetPointClicked(x, y);


	// [ Note ]:
	// In DecWalletCard_1, the only parameter of DecWalletCard_1 is the "walletAmount" value to decrease from player
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar
	poutt->ClearStatusBar();


}

void LoseCityCard_13::Apply(Grid* pGrid, Player* pPlayer)
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

	if (city1->Getcityowner() == pGrid->GetCurrentPlayer())
		a = city1->Getprice();
	else
		a = -1;
	
	if (city2->Getcityowner() == pGrid->GetCurrentPlayer())
		b = city2->Getprice();
	else
		b = -1;

	if (city3->Getcityowner() == pGrid->GetCurrentPlayer())
		c = city3->Getprice();
	else
		c = -1;

	if (city4->Getcityowner() == pGrid->GetCurrentPlayer())
		d = city4->Getprice();
	else
		d = -1;

	if (city5->Getcityowner() == pGrid->GetCurrentPlayer())
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
	int maxprice = t[0];

	
	if (maxprice == a) 
	{
		city1->Setcityowner(NULL);
		if (city1->Getpcmortgaged() != NULL)
		{
			pPlayer = city1->Getpcmortgaged();
			city1->Setpcmortgaged(NULL);
			city1->Setcityowner(pPlayer);
		}
	}

	if (maxprice == b)
	{
		city2->Setcityowner(NULL);
		if (city2->Getpcmortgaged() != NULL)
		{
			pPlayer = city2->Getpcmortgaged();
			city2->Setpcmortgaged(NULL);
			city2->Setcityowner(pPlayer);
		}
	}

	if (maxprice == c)
	{
		city3->Setcityowner(NULL);
		if (city3->Getpcmortgaged() != NULL)
		{
			pPlayer = city3->Getpcmortgaged();
			city3->Setpcmortgaged(NULL);
			city3->Setcityowner(pPlayer);
		}
	}
	if (maxprice == d)
	{
		city4->Setcityowner(NULL);
		if (city4->Getpcmortgaged() != NULL)
		{
			pPlayer = city4->Getpcmortgaged();
			city4->Setpcmortgaged(NULL);
			city4->Setcityowner(pPlayer);
		}
	}
	if (maxprice == f)
	{
		city5->Setcityowner(NULL);
		if (city5->Getpcmortgaged() != NULL)
		{
			pPlayer = city5->Getpcmortgaged();
			city5->Setpcmortgaged(NULL);
			city5->Setcityowner(pPlayer);
		}
	}


}
