#pragma once

#include "Card.h"
#include "MCardCairo_7.h"
#include "MCardAlex_8.h"
#include "MCardAswan_9.h"
#include "MCardLuxor_10.h"
#include "MCardHurghada_11.h"
	// [ DecWalletCard_1 ] Summary:
	// Its Apply() Function: Decrements the value of the passing player’s wallet by a value
	// Its Parameters: The Wallet Value to decrease --> put it as a "data member" and read it in ReadCardParameters()

	class ReturnMortgagedCard_14 : public Card
{
	// DecWalletCard_1 Parameters:
public:
	ReturnMortgagedCard_14(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of DecWalletCard_1 which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of DecWalletCard_1 on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member

	virtual ~ReturnMortgagedCard_14(); // A Virtual Destructor
};



