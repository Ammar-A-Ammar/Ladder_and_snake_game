#pragma once

#include <string>
#include <fstream>
#include "Action.h"
using namespace std;

class SaveGridAction : public Action
{
	ofstream save;
	string filename;
	Grid *pGrid;
public:
	SaveGridAction(ApplicationManager *pApp);
	void ReadActionParameters();
	void Execute();
};
