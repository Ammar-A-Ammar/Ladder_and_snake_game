#pragma once

#include "Action.h"
#include "Grid.h"
#include "Input.h"
#include "Output.h"
#include "CopyCardAction.h"

class PasteCardAction :  public Action
{
	int Pastednumber;
	Card *pastedCard;
	CellPosition cardPosition;

public:
	PasteCardAction(ApplicationManager *pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads AddCardAction action parameters (cardNumber, cardPosition)

	virtual void Execute(); // Creates a new Card Object of the specific Card Number
							// and Reads the Parameters of This Card Number (if any)
							// then Sets this Card Object to GameObject Pointer of its Cell

	virtual ~PasteCardAction(); // A Virtual Destructor
};


