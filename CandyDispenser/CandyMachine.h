#pragma once
#include "List.h"
#include "Candy.h"
#include "Coin.h"
#ifndef _CANDYMACHINE_H_
#define _CANDYMACHINE_H_

typedef struct {
	List Candies;
	List Coins;
	Queue InsertedCoins; //Buffer monedas ingresadas por el usuario, que aun no son procesadas
}CandyMachine;
void initCandyMachine(CandyMachine* candyMachine);

#endif