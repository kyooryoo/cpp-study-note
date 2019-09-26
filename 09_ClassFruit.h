// this is the class.h file
// lists out props and funcs of a class

// following ifndef stands for `if not defined`
// it tells compiler to ignore if it is defined
#ifndef FRUIT_H
#define FRUIT_H

class Fruit {

	private:
		int Quantity;

	public:
		Fruit(int initialQuantity);
		int GetQuantity();
		void Buy(int quantity);
		void Sell(int quantity);
};

#endif
