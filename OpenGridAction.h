#pragma once
#include "Action.h"
#include <fstream>

class OpenGridAction :
	public Action
{
	ifstream file;
	string filename;
	Grid *pGrid;
public:
	OpenGridAction(ApplicationManager *pApp);
	void ReadActionParameters();
	void Execute();
};

