
#pragma once
#include "Card.h"

class MCardCairo_7 : public Card
{
	int city_price; //price of the city 
	int fees; //fees for passing by
	Player* pcityowner; //to check if player has been to card before
	Player* pcmortgaged;

public:
	MCardCairo_7(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of DecWalletCard_1 which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of DecWalletCard_1 on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member
	Player* Getcityowner();
	Player* Getpcmortgaged();
	void Setpcmortgaged(Player* x);
	int Getfees();
	int Getprice();
	void Setcityowner(Player* owner);
	virtual ~MCardCairo_7(); // A Virtual Destructor
	
};

