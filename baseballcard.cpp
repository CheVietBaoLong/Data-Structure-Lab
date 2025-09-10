#include <baseballcard.h>

void BaseballCard::Value() {

	// Handle heritage cards.
	if (m_year < 1910) {
		if (getRating() > 80) {
			setPrice(500);
		}
		else if (getRating() > 50) {
			setPrice(300);
		}
		else {
			setPrice(100);
		};
		return;
	}

	// Handle mid-modern cards.
	if (m_year < 1950) {
		if (getRating() > 80) {
			setPrice(300);
		}
		else if (getRating() > 50) {
			setPrice(100);
		}
		else {
			setPrice(50);
		}
		return;
	}

	// Handle modern cards.
	if (getRating() > 80) {
		setPrice(100);
	} else if (getRating() > 50) {
		setPrice(20);
	}
	else {
		setPrice(5);
	}
}