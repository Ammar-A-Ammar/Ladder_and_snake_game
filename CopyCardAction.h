#pragma once

#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "DecWalletCard_1.h"


class CopyCardAction : public Action
{

	// [Action Parameters]
	int CopiedcardNumber;            // 1- the card number
	CellPosition cardPosition;      //  2- cell position of the card

	// Note: These parameters should be read in ReadActionParameters()

public:
	CopyCardAction(ApplicationManager *pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads AddCardAction action parameters (cardNumber, cardPosition)

	virtual void Execute(); // Creates a new Card Object of the specific Card Number
							// and Reads the Parameters of This Card Number (if any)
							// then Sets this Card Object to GameObject Pointer of its Cell

	virtual ~CopyCardAction(); // A Virtual Destructor
	int get_copiedcard();
};


