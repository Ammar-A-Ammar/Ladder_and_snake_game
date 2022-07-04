#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

// This file contains some global constants and definitions to be used in the project.

enum ActionType // The actions supported (add more as needed)
{
	//  [1] Actions of Design Mode

	ADD_LADDER,		// Add Ladder Action
	ADD_SNAKE,		// Add Snake Action	
	ADD_COINSET,    // Adds coinset
	ADD_CARD,		// Add Card Action	
	COPY_CARDCOIN,  // Copies Card or Coin
	CUT_CARDCOIN,   // Cuts card or coin
	PASTE_CARDCOIN,          // paste the card or coin
	DELETE_OBJ,     // deletes object
	SAVE_GRID,      // Saves Grid
	OPEN_GRID,      // Opens Grid
	TO_PLAY_MODE,	// Go to Play Mode
	EXIT,			// Exit Application

	///TODO: Add more action types of Design Mode

	//  [2] Actions of Play Mode

	ROLL_DICE,		    // Roll Dice Action
	TO_DESIGN_MODE,	    // Go to Design Mode
	INPUT_DICEV,       // alternative for roll dice
	OFFER_MORTGAGE,    // Offers mortgage
	ACCEPT_MORTGAGE,   // accepts mortgage
	RETURN_MORTGAGE,   // returns mortgage
	SELL_CITY,         // Sell one or more cities
	NEW_GAME,          // Restart game
	Exit,              // Exit Application
	///TODO: Add more action types of Play Mode

	//  [3] Others

	EMPTY,				// Empty Area in ToolBar (NOT inside any action icon)
	GRID_AREA,			// Inside Grid Area
	STATUS 				// Inside StatusBar Area
};
enum ObjType {
	ladder,
	card,
	snake,
};

#endif