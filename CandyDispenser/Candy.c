#include "Candy.h"
#include "stdlib.h"
#include "stdio.h"
Candy initCandy(char* name, int price) {
	if (price < 0 || price % 100 != 0) {
		printf("Invalid price, the price isnt a factor of 100 or is a negative number");
		return;
	}

	Candy tempCandy;
	tempCandy.name = name;
	tempCandy.price = price;
	return tempCandy;
}