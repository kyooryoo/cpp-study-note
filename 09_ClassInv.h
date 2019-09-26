#ifndef INVENTORY_H
#define INVENTORY_H

#include "09_ClassFruit.h"

class Inventory
{
public:
	double Money;
	Fruit Grapes;
	Fruit Blueberries;
	Fruit Strawberries;
	Fruit Raspberries;

	Inventory();

	void Print();

	Fruit Buy(Fruit item, int quantity, double price);
	Fruit Sell(Fruit item, int quantity, double price);
};

#endif
