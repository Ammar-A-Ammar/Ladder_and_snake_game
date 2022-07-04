#include "FireCard.h"
FireCard::FireCard(const CellPosition& pos) : Card(pos) // set the cell position of the card
{

}

FireCard::~FireCard(void)
{
}


void FireCard::Apply(Grid* pGrid, Player* pPlayer)
{
	Card c1(position);
	c1.Apply(pGrid, pPlayer);

	CellPosition zero(8, 0);

	pGrid->SetCurrPlayerNum(pGrid->GetCurrentPlayer()->Getplayernum());

	pGrid->AdvanceCurrentPlayer();

	int H2 = pGrid->GetCurrentPlayer()->GetCell()->GetCellPosition().HCell();
	int V2 = pGrid->GetCurrentPlayer()->GetCell()->GetCellPosition().VCell();
	if (H2 == position.HCell() || V2 == position.VCell())
	{
		int neww=(pGrid->GetCurrentPlayer()->GetWallet())/2;
		pGrid->GetCurrentPlayer()->SetWallet(neww);
		pGrid->UpdatePlayerCell(pGrid->GetCurrentPlayer(), zero);
	}

	pGrid->AdvanceCurrentPlayer();

	int H3 = pGrid->GetCurrentPlayer()->GetCell()->GetCellPosition().HCell();
	int V3 = pGrid->GetCurrentPlayer()->GetCell()->GetCellPosition().VCell();
	if (H2 == position.HCell() || V2 == position.VCell())
	{
		int neww = (pGrid->GetCurrentPlayer()->GetWallet()) / 2;
		pGrid->GetCurrentPlayer()->SetWallet(neww);
		pGrid->UpdatePlayerCell(pGrid->GetCurrentPlayer(), zero);
	}

	pGrid->AdvanceCurrentPlayer();

	int H4 = pGrid->GetCurrentPlayer()->GetCell()->GetCellPosition().HCell();
	int V4 = pGrid->GetCurrentPlayer()->GetCell()->GetCellPosition().VCell();
	if (H2 == position.HCell() || V2 == position.VCell())
	{
		int neww = (pGrid->GetCurrentPlayer()->GetWallet()) / 2;
		pGrid->GetCurrentPlayer()->SetWallet(neww);
		pGrid->UpdatePlayerCell(pGrid->GetCurrentPlayer(), zero);
	}
	pGrid->AdvanceCurrentPlayer();

}
