#pragma once
#include "Card.h"
#include "Player.h"

class BackwardCard_3 : public Card
{ // just rolled dicenumber of the current player

public:
	BackwardCard_3(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of DecWalletCard_1 which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of DecWalletCard_1 on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member

	virtual ~BackwardCard_3(); // A Virtual Destructor
};

