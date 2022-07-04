#pragma once
#include "Action.h"

class Delete :public Action
{
private:

	CellPosition cellpos;

public:

	Delete(ApplicationManager* pApp); // A Constructor
	virtual void ReadActionParameters(); 
	virtual void Execute(); // Creates a new Card Object of the specific Card Number
							// and Reads the Parameters of This Card Number (if any)
							// then Sets this Card Object to GameObject Pointer of its Cell

	virtual ~Delete(); // A Virtual Destructor
};

