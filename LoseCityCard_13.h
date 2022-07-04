#pragma once
#include "Card.h"
#include "MCardCairo_7.h"
#include "MCardAlex_8.h"
#include "MCardAswan_9.h"
#include "MCardLuxor_10.h"
#include "MCardHurghada_11.h"

class 
	LoseCityCard_13: public Card
{

public:
	LoseCityCard_13(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of DecWalletCard_1 which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of DecWalletCard_1 on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member

	virtual ~LoseCityCard_13(); // A Virtual Destructor
};
