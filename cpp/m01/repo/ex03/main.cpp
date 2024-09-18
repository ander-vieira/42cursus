#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	Weapon weaponA = Weapon("sword");
	Weapon weaponB = Weapon("sword");
	HumanA humanA = HumanA("Jose", weaponA);
	HumanB humanB = HumanB("Carlos");

	humanA.attack();
	weaponA.setType("club");
	humanA.attack();

	humanB.attack();
	humanB.setWeapon(&weaponB);
	humanB.attack();
	weaponB.setType("club");
	humanB.attack();
}