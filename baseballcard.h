#ifndef __BASEBALL_CARD_H
#define __BASEBALL_CARD_H

#include <gradable.h>

class BaseballCard : public Gradable {
public:
	BaseballCard(std::string donor_name, int donor_year, std::string manufacturer, int year, std::string player)
		: Gradable{donor_name, donor_year}, m_manufacturer{ manufacturer }, m_player{ player }, m_year{ year } {
	}
	virtual void Value() override;

private:
	std::string m_manufacturer;
	std::string m_player;
	int m_year;
};

#endif