#include <iostream>

#include <coin.h>

double sell_in_auction(Gradable &for_sale);

const double AUCTION_OVERHEAD_FEE{ 0.89 };

double sell_in_auction(Gradable &for_sale) {
	for_sale.Grade();
	for_sale.Value();
    return for_sale.getPrice() * AUCTION_OVERHEAD_FEE;
}

int main() {
	Coin double_eagle{ "Dee Onalduck", 2023, 1849, "Washington, DC", "gold", true};

	double price_for_coin{ sell_in_auction(double_eagle) };

	std::cout << "The University's endowment now has $" << price_for_coin << " more money.\n";
}
