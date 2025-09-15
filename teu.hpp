#ifndef BEADEDBAG_BEADEDBAG_HPP
#define BEADEDBAG_BEADEDBAG_HPP

#include <string>
#include <vector>

/**
 * \class Shippable
 *
 * Anything that is shippable must have a volume and a name. 
 */

class Shippable {

public:

  /**
   * get_volume()
   *
   * Get the volume of the item shipped.
   *
   * \return The volume of the item shipped.
   */
  virtual double get_volume() const = 0;

  /**
   * get_name()
   *
   * Get the name of the item shipped.
   *
   * \return The name of the item shipped.
   */
  virtual std::string get_name() const = 0;
};

/**
 * \class FastFashionPackage
 *
 * A FastFashionPackage is a Shippable item where
 * every item has a name and a volume. 
 *
 */

class FastFashionPackage : public Shippable {
public:
	FastFashionPackage(std::string name, double volume) : package_name(name), package_volume(volume) {};
	
	std::string get_name() const override {
		return package_name;
	}
	double get_volume() const override {
		return package_volume;
	}
private:
	std::string package_name;
	double package_volume;
};

/**
* \class Electronics
* 
* An Electronics item is a Shippable item where
* every item has a name and a volume.
* 
*/

class Electronics : public Shippable {
public:
	Electronics(std::string name) 
		: electronics_name(name), electronics_volume(4.0) {}
	
	std::string get_name() const override {
		return electronics_name;
	}
	double get_volume() const override {
		return electronics_volume;
	}
private:
	std::string electronics_name;
	double electronics_volume;
};


/**
 * \class Teu
 *
 * A Teu is a shipping container that can hold
 * any type of Shippable item.
 *
 * \tparam T The type of item to be shipped.
 */

template <typename T>
class Teu {
public:
	Teu(std::string address, double max_volume)
		: container_address(address), container_max_volume(max_volume) {
	};

	std::string get_manifest() const {
		std::string manifest;
		for (int i = 0; i < manifest_list.size(); ++i) {
			manifest += manifest_list[i].get_name();
			if (i < manifest_list.size() - 1) {
				manifest += ", ";
			}
		}
		return manifest;
	};

	bool add_to_container(const T& to_ship) {
		int count = 0;
		for (int i = 0; i < manifest_list.size(); ++i) {
			if (manifest_list[i].get_name() == to_ship.get_name()) {
				++count;
			}
		}

		if (count >= 1) {
			return false;
		}

		if (used_volume + to_ship.get_volume() <= container_max_volume) {
			manifest_list.push_back(to_ship);
			used_volume += to_ship.get_volume();
			return true;
		}
		return false;
	}

	double get_tonnage() const {
		return used_volume;

	}

private:
	std::string container_address;
	double container_max_volume;
	double used_volume{0.0};
	std::vector<T> manifest_list;
};

#endif
