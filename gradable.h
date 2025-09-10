#ifndef __GRADABLE_H
#define __GRADABLE_H

#include <string>

class Gradable {
public:
	Gradable(std::string donor_name, int donor_year);

	virtual void Grade();
	virtual void Value();

	double getRating() const {
		return this->Rating;
	}

	double getPrice() const {
		return this->Price;
	}

protected:
	void setPrice(double newPrice) {
		Price = newPrice;
	}
	
	void setRating(double newRating) {
		Rating = newRating;
	}
private:
	double Rating{};
	double Price{};
	int DonorDate{};
	std::string DonorName{};
};

#endif