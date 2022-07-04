#include "SaveGridAction.h"
#include"Grid.h"
#include<fstream>

SaveGridAction::SaveGridAction(ApplicationManager *pApp) :Action(pApp) 
{
}
void SaveGridAction::ReadActionParameters() 
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	filename = pIn->GetSrting(pOut);
}
void SaveGridAction::Execute() {
	ReadActionParameters();
	save.open(filename, std::ios_base::app);
	pGrid->Saving(save, ladder, filename);
	pGrid->Saving(save, snake , filename);
	pGrid->Saving(save, card  , filename);
}