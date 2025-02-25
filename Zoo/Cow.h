#pragma once
#include <iostream>
#include <string>
#include <format>

#ifndef ANIMAL_HEADER
#include "Animal.h"
#endif

#define COW_HEADER

class Cow : public Animal
{
private:

	static constexpr int COW_Life = 35;
	static int numCow;				// initialization for static in is done at end of file.

public:
	Cow() : Animal() {
		SetGreeting("Moo");
		SetBodyStructureVerterbrate();
		SetHabitatTerestrial();
		SetDietHerbivore();
		SetLocomotionWalking();
		SetRespirationLungs();

		numCow++;
		std::cout << format("Default Cow created.\n");
	}

	void Print() const;
	void SetCowName(const std::string& s);

	static int GetCowNumber() { return numCow; }

	//	void TestCow();
};

void Cow::Print() const {
	std::cout << std::format("this is a cow number {:05}, it says {}\n", GetCowNumber(), GetGreeting());

	this->Animal::Print();
};

inline void Cow::SetCowName(const std::string& s)
{
	Animal::SetName(s);
};

// initialize the number of Cows. 
int Cow::numCow = 0;

inline void testCow() {

	Cow* c0 = new Cow();				// make john doe.
	c0->Cow::Print();

	Cow* c1 = new Cow();
	c1->Print();
	c1->SetName("Mr. Moo");
	c1->Print();

	delete c1;

	c0->Print();
};
