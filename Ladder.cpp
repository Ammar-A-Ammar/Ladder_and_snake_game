#include "Ladder.h"
#include <fstream>

Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	if (startCellPos.HCell()==endCellPos.HCell()&&endCellPos.VCell()<startCellPos.VCell())
	this->endCellPos = endCellPos;
	else
	{
		return;
	}
	///TODO: Do the needed validation
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
	

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	
	
	// == Here are some guideline steps (numbered below) to implement this function ==
	
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	pGrid->PrintErrorMessage("u have reached a ladder,click to continue...");
	
	// 2- Apply the ladder's effect by moving the player to the endCellPos
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
	//    Review the "pGrid" functions and decide which function can be used for that
	
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

Ladder::~Ladder()
{
}

void Ladder::Save(ofstream& save, ObjType type, string filename) 
{
	if (type == ladder) 
	{
		save.open(filename + ".txt", std::ios_base::app);
		save << position.GetCellNum() << " " << endCellPos.GetCellNum() << endl;
	}

}
