#pragma once
#include "Card.h"

class PreventCard_4 : public Card
{
	Cell* cblocked;

public:
	PreventCard_4(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of DecWalletCard_1 which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of DecWalletCard_1 on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member

	virtual ~PreventCard_4(); // A Virtual Destructor
};

