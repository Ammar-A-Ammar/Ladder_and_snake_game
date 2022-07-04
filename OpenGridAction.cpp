#include "OpenGridAction.h"
#include"Grid.h"
#include"Ladder.h"
#include"Card.h"
#include"Snake.h"
#include "DecWalletCard_1.h"
#include "NextCard_2.h"
#include "BackwardCard_3.h"
#include "PreventCard_4.h"
#include "FireCard.h"
#include "FreezeCard_6.h"
#include "MCardCairo_7.h"
#include "MCardAlex_8.h"
#include "MCardAswan_9.h"
#include "MCardLuxor_10.h"
#include "MCardHurghada_11.h"
#include "TakeCityCard_12.h"
#include "LoseCityCard_13.h"
#include "ReturnMortgagedCard_14.h"

 OpenGridAction::OpenGridAction(ApplicationManager *pApp):Action(pApp) 
{
}

void OpenGridAction::ReadActionParameters() 
{
	Grid *pGrid = pManager->GetGrid();
	Output *pOut = pGrid->GetOutput();
	Input *pIn = pGrid->GetInput();
	filename = pIn->GetSrting(pOut);
}

void OpenGridAction::Execute() 
{
	ReadActionParameters();
	file.open(filename);
	
	int input;
	file >> input;
	for (int i = 0; i <input; i++) 
	{
		int start = 0;
		int end = 0;
		file >> start;
		file >> end;
		Ladder* pLad = new Ladder(start, end);
		pGrid->AddObjectToCell(pLad);
	}

	file >> input;

	for (int i = 0; i < input; i++) 
	{
		int start = 0;
		int end = 0;
		file >> start;
		file >> end;
		Snake* pLad = new Snake(start, end);
		pGrid->AddObjectToCell(pLad);
	}
	file >> input;
}