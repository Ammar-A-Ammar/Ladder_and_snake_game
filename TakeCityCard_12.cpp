#include "TakeCityCard_12.h"

TakeCityCard_12::TakeCityCard_12(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 12; // set the inherited cardNumber data member with the card number (1 here)
}

TakeCityCard_12::~TakeCityCard_12(void)
{
}

void TakeCityCard_12::ReadCardParameters(Grid* pGrid)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


}

void TakeCityCard_12::Apply(Grid* pGrid, Player* pPlayer)
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

	poutt->PrintMessage("Enter the name of the city u wont to take.... Cairo, Alex, Aswan, Luxor or Hurghada");
	string r =pinn->GetSrting(poutt);
	
	if (r == "Cairo")
	{
		city1->Setcityowner(pGrid->GetCurrentPlayer());
	}
	if (r == "Alex")
	{
		city2->Setcityowner(pGrid->GetCurrentPlayer());
	}
	if (r == "Aswan")
	{
		city3->Setcityowner(pGrid->GetCurrentPlayer());
	}
	if (r == "Luxor")
	{
		city4->Setcityowner(pGrid->GetCurrentPlayer());
	}
	if (r == "Hurghada")
	{
		city5->Setcityowner(pGrid->GetCurrentPlayer());
	}
}
