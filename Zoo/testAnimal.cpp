#include "Animal.h"

void testAnimal() {
	Animal* a0 = new Animal();				// make john doe.
	a0->Print();

	Animal* a1 = new Animal("Lily", "Miss");
	a1->Print();

	Animal* a2 = new Animal("Bessie", "Miss");
	a2->Print();

	Animal* a3 = new Animal(*a0);		// make a copy of a0 into a3.
	a3->Print();

	a3->SetName("Brownie");				// modify a3
	a3->SetTitle("Sr.");
	a3->SetBodyStructureVerterbrate();
	a3->SetHabitatTerestrial();
	a3->SetDietHerbivore();
	a3->SetLocomotionWalking();
	a3->SetRespirationLungs();

	a3->Print();						// print modifyed a3

	delete a1;
	delete a2;
	delete a3;

	a0->Print();
}