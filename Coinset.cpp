#include "Coinset.h"

Coinset::Coinset(const CellPosition & CoinSetPos, const int Amount) : GameObject(CoinSetPos)
{
	if (Amount>=0)
	{
		this->Amount = Amount;
	}
	///TODO: Do the needed validation
}

void Coinset::Draw(Output* pOut) const
{
	pOut->DrawCoinSet(position);
}

void Coinset::Apply(Grid* pGrid, Player* pPlayer)
{

	int x, y;
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	pGrid->PrintErrorMessage("u have reached a coinset,click to continue...");
	// 2- Apply the ladder's effect by moving the player to the endCellPos
	
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->GetCurrentPlayer();
}

CellPosition Coinset::GetCoinSetPosition() const
{
	return position ;
}

Coinset::~Coinset()
{
}
