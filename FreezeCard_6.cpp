#include "FreezeCard_6.h"

FreezeCard_6::FreezeCard_6(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 1; // set the inherited cardNumber data member with the card number (1 here)
}

FreezeCard_6::~FreezeCard_6(void)
{
}

void FreezeCard_6::ReadCardParameters(Grid* pGrid)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==
	int o, i;

	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Input* pinn = pGrid->GetInput();
	Output* poutt = pGrid->GetOutput();
	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New DecWalletCard_1: Enter its wallet amount ..."
	poutt->PrintMessage("New Freeze Card_1: Enter type of cells to freeze odd or even ...click to continue");
	pinn->GetPointClicked(o, i);
	string x=pinn->GetSrting(poutt);

	poutt->PrintMessage("now choose number of turns 1 or 2 ...");
	pinn->GetPointClicked(o, i);
	numberofturns = pinn->GetInteger(poutt);
	if (x=="true")
	{
		oddoreven = true;
	}
	if (x=="false")
	{
		oddoreven = false;
	}
	// 3- Clear the status bar
	poutt->ClearStatusBar();
}

void FreezeCard_6::Apply(Grid* pGrid, Player* pPlayer)
{
	Card c1(position);
	c1.Apply(pGrid, pPlayer);
// current player will move
	int d = pGrid->GetCurrentPlayer()->GetjustRolledDiceNum();
	for (int i = 0;i < numberofturns;i++)
	{
		pGrid->GetCurrentPlayer()->Move(pGrid, d);
	}
	if (oddoreven == true)
	{
		pGrid->AdvanceCurrentPlayer(); // next player
		CellPosition p22 = (pGrid->GetCurrentPlayer()->GetCell()->GetCellPosition());
		int num = p22.GetCellNumFromPosition(p22);
		if (num % 2 != 0)    //odd cell num so the current player+ will move
		{
			for (int i = 0;i < numberofturns;i++)                     // fix for all ..........
			{
			int d = pGrid->GetCurrentPlayer()->GetjustRolledDiceNum();
			
				pGrid->GetCurrentPlayer()->Move(pGrid, d);
			}
		}
	}
	if (oddoreven == true)
	{
		pGrid->AdvanceCurrentPlayer(); // next player
		CellPosition p22 = (pGrid->GetCurrentPlayer()->GetCell()->GetCellPosition());
		int num = p22.GetCellNumFromPosition(p22);
		if (num % 2 != 0)    //odd cell num so the current player+ will move
		{
			int d = pGrid->GetCurrentPlayer()->GetjustRolledDiceNum();
			for (int i = 0;i < numberofturns;i++)
			{
				pGrid->GetCurrentPlayer()->Move(pGrid, d);
			}
		}
	}
	if (oddoreven == true)
	{
		pGrid->AdvanceCurrentPlayer(); // next player
		CellPosition p22 = (pGrid->GetCurrentPlayer()->GetCell()->GetCellPosition());
		int num = p22.GetCellNumFromPosition(p22);
		if (num % 2 != 0)    //odd cell num so the current player+ will move
		{
			int d = pGrid->GetCurrentPlayer()->GetjustRolledDiceNum();
			for (int i = 0;i < numberofturns;i++)
			{
				pGrid->GetCurrentPlayer()->Move(pGrid, d);
			}
		}
	}
	if (oddoreven == false)
	{
		pGrid->AdvanceCurrentPlayer(); // next player
		CellPosition p22 = (pGrid->GetCurrentPlayer()->GetCell()->GetCellPosition());
		int num = p22.GetCellNumFromPosition(p22);
		if (num % 2 == 0)    //odd cell num so the current player+ will move
		{
			int d = pGrid->GetCurrentPlayer()->GetjustRolledDiceNum();
			for (int i = 0;i < numberofturns;i++)
			{
				pGrid->GetCurrentPlayer()->Move(pGrid, d);
			}
		}
	}
	if (oddoreven == false)
	{
		pGrid->AdvanceCurrentPlayer(); // next player
		CellPosition p22 = (pGrid->GetCurrentPlayer()->GetCell()->GetCellPosition());
		int num = p22.GetCellNumFromPosition(p22);
		if (num % 2 == 0)    //odd cell num so the current player+ will move
		{
			int d = pGrid->GetCurrentPlayer()->GetjustRolledDiceNum();
			for (int i = 0;i < numberofturns;i++)
			{
				pGrid->GetCurrentPlayer()->Move(pGrid, d);
			}
		}
	}
	if (oddoreven == false)
	{
		pGrid->AdvanceCurrentPlayer(); // next player
		CellPosition p22 = (pGrid->GetCurrentPlayer()->GetCell()->GetCellPosition());
		int num = p22.GetCellNumFromPosition(p22);
		if (num % 2 == 0)    //odd cell num so the current player+ will move
		{
			int d = pGrid->GetCurrentPlayer()->GetjustRolledDiceNum();
			for (int i = 0;i < numberofturns;i++)
			{
				pGrid->GetCurrentPlayer()->Move(pGrid, d);
			}
		}
	}
	pGrid->AdvanceCurrentPlayer();
}