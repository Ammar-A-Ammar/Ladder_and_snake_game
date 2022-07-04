#include "NextCard_2.h"
#include "Player.h"
#include "Coinset.h"
#include "Ladder.h"
#include "Snake.h"


NextCard_2::NextCard_2(const CellPosition& pos) : Card(pos)// set the cell position of the card
{
	 // set the inherited cardNumber data member with the card number (1 here)
	cardNumber = 2;
}

NextCard_2::~NextCard_2(void)
{
}

void NextCard_2::ReadCardParameters(Grid* pGrid)
{
	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Input* pinn = pGrid->GetInput();
	Output* poutt = pGrid->GetOutput();
	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New DecWalletCard_1: Enter its wallet amount ..."
	poutt->PrintMessage("New NextCard_2: Enter a number:(1 means ladders, 2 snakes, 3 coin sets, 4 cards)");
	int x, y;
	pinn->GetPointClicked(x, y);
	choice = pinn->GetInteger(poutt);
	// [ Note ]:
	// In DecWalletCard_1, the only parameter of DecWalletCard_1 is the "walletAmount" value to decrease from player
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar
	poutt->ClearStatusBar();
}

void NextCard_2::Apply(Grid* pGrid, Player* pPlayer)
{
	Card c1(position);
	c1.Apply(pGrid, pPlayer);
	if (choice == 1)
	{
		if (pGrid->GetNextLadder(position) != NULL)
		{
			Ladder* l = pGrid->GetNextLadder(position);
			CellPosition p4=l->GetEndPosition();
			pGrid->UpdatePlayerCell(pPlayer, p4);
		}
	}
	else if (choice == 2)
	{
		if (pGrid->GetNextSnake(position) != NULL)
		{
			Snake* l = pGrid->GetNextSnake(position);
			CellPosition p4 = l->GetEndPosition();
			pGrid->UpdatePlayerCell(pPlayer, p4);
		}
	}
	else if (choice == 3)
	{
		if (pGrid->GetNextCoinSet(position) != NULL)
		{
			Coinset* l = pGrid->GetNextCoinSet(position);
			CellPosition p4 = l->GetCoinSetPosition();
			pGrid->UpdatePlayerCell(pPlayer, p4);
		}
	}
	if (choice == 4)
	{
		if (pGrid->GetNextCard(position) != NULL)
		{
			Card* l = pGrid->GetNextCard(position);
			CellPosition p4 = l->GetPosition();
			pGrid->UpdatePlayerCell(pPlayer, p4);
		}
	}
}
