
#pragma once
#include "Card.h"

class MCardAswan_9 : public Card
{
	int city_price; //price of the city 
	int fees; //fees for passing by
	Player* pcityowner; //to check if player has been to card before
	Player* pcmortgaged;


public:
	MCardAswan_9(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of DecWalletCard_1 which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of DecWalletCard_1 on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member
	Player* Getcityowner();
	int Getfees();
	int Getprice();
	Player* Getpcmortgaged();
	void Setpcmortgaged(Player *x);
	void Setcityowner(Player* owner);
	virtual ~MCardAswan_9(); // A Virtual Destructor
};

