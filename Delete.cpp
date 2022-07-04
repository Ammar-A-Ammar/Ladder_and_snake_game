#include "Delete.h"
#include "Input.h"
#include "Output.h"
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

Delete::Delete(ApplicationManager* pApp):Action(pApp)
{
}

void Delete::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	
	pOut->PrintMessage(" cardrposition: click on card cell");
	cellpos = pIn->GetCellClicked();

	if (!cellpos.IsValidCell())

		pGrid->PrintErrorMessage(" cell position is not valid");

	pOut->ClearStatusBar();
}

void Delete::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	
	pGrid->DeleteGameObject(cellpos);                
	
	
}

Delete::~Delete()
{
}
