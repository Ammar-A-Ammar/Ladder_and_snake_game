#pragma once
#include "Card.h"

// [ DecWalletCard_1 ] Summary:
// Its Apply() Function: Decrements the value of the passing player’s wallet by a value
// Its Parameters: The Wallet Value to decrease --> put it as a "data member" and read it in ReadCardParameters()

class FireCard : public Card
{
	// DecWalletCard_1 Parameters:
	

public:
	FireCard(const CellPosition& pos); // A Constructor takes card position


	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of DecWalletCard_1 on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member

	virtual ~FireCard(); // A Virtual Destructor
};


