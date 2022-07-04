#pragma once
#include "Card.h"

class FreezeCard_6:public Card


{
	bool oddoreven; //true for even false for odd
	int numberofturns;
public:
	FreezeCard_6(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of DecWalletCard_1 which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of DecWalletCard_1 on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member

	virtual ~FreezeCard_6(); // A Virtual Destructor
};

