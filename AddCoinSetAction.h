#pragma once

#include "Action.h"

class AddCoinSetAction : public Action
{
	// [Action Parameters]
	int amount;            // 1- the amount of coin
	CellPosition coinPosition; // 2- cell position of the coin

	// Note: These parameters should be read in ReadActionParameters()
	
public:
	AddCoinSetAction(ApplicationManager *pApp); // A Constructor
		
	virtual void ReadActionParameters(); // Reads AddCardAction action parameters (amount, coinPosition)
	
	virtual void Execute(); // Creates a new coin Object
	                        // and Reads the amount of the coin
	                        // then Sets this coin Object to GameObject Pointer of its Cell
	
	virtual ~AddCoinSetAction(); // A Virtual Destructor
};