#pragma once

#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "Cell.h"
#include "Grid.h"
#include "ApplicationManager.h"

class CutCardAction : public Action
{
private:
	int CuttedCardNumber;
		CellPosition cardposition;
public:
	CutCardAction(ApplicationManager *pApp);  // Constructor

	// ============ Virtual Functions ============

	virtual void ReadActionParameters();
	virtual void Execute();
	virtual ~CutCardAction(); 
};
