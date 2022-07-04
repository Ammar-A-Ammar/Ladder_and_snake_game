#include "Card.h"
#include <fstream>

Card::Card(const CellPosition & pos) : GameObject(pos) // sets the cell position of the GameObject
{
}

void Card::SetCardNumber(int cnum)
{
	cardNumber = cnum; // needs validation
}

int Card::GetCardNumber()
{
	return cardNumber;
}

void Card::Draw(Output* pOut) const
{

	///TODO: call the appropriate Ouput function that draws a cell containing the "cardNumber" in "position"
	pOut->DrawCell(position, cardNumber);

}

void Card::ReadCardParameters(Grid * pGrid)
{
	// we should not make it pure virtual because some Cards doesn't have parameters
	// and if we make it pure virtual, that will make those Cards abstract classes
}

void Card::Apply(Grid* pGrid, Player* pPlayer) 
{
	
	// The following line is to print the following message if a player reaches a card of any type

	pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + ". Click to continue ...");
	Input* pinn = pGrid->GetInput();
	int x, y;
	pinn->GetPointClicked(x, y);
}

void Card::Save(ofstream& save, ObjType type, string filename) 
{
	if (type == card) 
	{
		save.open(filename, std::ios_base::app);
		switch (cardNumber) 
		{
			/*===CARDS WITH NO INPUTS===*/
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
			save << cardNumber << " " << position.GetCellNum();
			break;
			default:
			break;
		}
	}
}

Card::~Card()
{
}
