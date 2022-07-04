#pragma once
#include "Card.h"


class NextCard_2 : public Card
{
	int choice;

public:
	NextCard_2(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of DecWalletCard_1 which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of DecWalletCard_1 on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member

	virtual ~NextCard_2(); // A Virtual Destructor
};

