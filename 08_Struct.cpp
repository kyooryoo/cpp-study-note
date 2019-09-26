// pay attention to:
// * structure can hold the same or different types of data
// * struct objs could be created per prop or once in all
// * funcs with the same name but diff args are overloading
// * notice that struct uses props while array uses index

#include <iostream>
using namespace std;

// a structure can hold different types of data
struct Inventory {
	double Money;
	int GrapesCount;
	int BlueberriesCount;
	int StrawberriesCount;
	int RaspberriesCount;
};
	
// a structure can hold data in the same type
struct PriceList {
	double GrapesPrice;
	double BlueberriesPrice;
	double StrawberriesPrice;
	double RaspberriesPrice;
};

// overloading: same function name with diff args
void print(Inventory inv) {
	cout << "Inventory:" << endl;
	cout << "\t$" << inv.Money << endl;
	cout << "\tGrapes:       " << inv.GrapesCount << endl;
	cout << "\tBlueberries:  " << inv.BlueberriesCount << endl;
	cout << "\tStrawberries: " << inv.StrawberriesCount << endl;
	cout << "\tRaspberries:  " << inv.RaspberriesCount << endl;
}

void print(PriceList prices) {
	cout << "Prices:" << endl;
	cout << "\tGrapes:       $" << prices.GrapesPrice << endl;
	cout << "\tBlueberries:  $" << prices.BlueberriesPrice << endl;
	cout << "\tStrawberries: $" << prices.StrawberriesPrice << endl;
	cout << "\tRaspberries:  $" << prices.RaspberriesPrice << endl;
}

int main() {
	// two ways of initializing structure objects
	Inventory MyInventory = {50.00, 20, 5, 0, 0};	
	PriceList MyPriceList;
	MyPriceList.GrapesPrice = 10.00;
	MyPriceList.BlueberriesPrice = 10.50;
	MyPriceList.StrawberriesPrice = 9.50;
	MyPriceList.RaspberriesPrice = 11.00;
	
	print(MyInventory);
	print(MyPriceList);
}
