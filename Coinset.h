#pragma once

#include "GameObject.h"

class Coinset : public GameObject // inherited from GameObject
{
	// Note: the "position" data member inherited from the GameObject class is used as the ladder's "Start Cell Position"

	 // here is the ladder's End Cell Position
	int Amount;
public:

	Coinset(const CellPosition& CellPos, int Amount); // A constructor for initialization

	virtual void Draw(Output* pOut) const; // Draws a ladder from its start cell to its end cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the ladder by moving player to ladder's end cell

	CellPosition GetCoinSetPosition() const; // A getter for the endCellPos data member
	
	virtual ~Coinset(); // Virtual destructor
};


