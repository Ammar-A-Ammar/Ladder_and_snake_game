#include "Snake.h"

Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	if (startCellPos.HCell() == endCellPos.HCell() && endCellPos.VCell() > startCellPos.VCell())
		this->endCellPos = endCellPos;
	else
	{
		return;
	}

	///TODO: Do the needed validation
}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{
	

	int x, y;
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	pGrid->PrintErrorMessage("u have reached a snake,click to continue...");
	// 2- Apply the ladder's effect by moving the player to the endCellPos
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
	//    Review the "pGrid" functions and decide which function can be used for that

}

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

void Snake::Save(ofstream& save, ObjType type, string filename) 
{
	if (type == snake) 
	{
		save.open(filename + ".txt", std::ios_base::app);
		save << position.GetCellNum() << " " << endCellPos.GetCellNum() << endl;
	}
}

Snake::~Snake()
{
}