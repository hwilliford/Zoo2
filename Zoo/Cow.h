#pragma once
#ifndef ANIMAL_HEADER
#include "Animal.h"
#endif

#include <iostream>
#include <string>
#include <format>
#include <random>

#define COW_HEADER

class Cow : public Animal
{
private:

	static constexpr int COW_Life = 35;
	static int numCow;				// initialization for static in is done at end of file.
	unsigned int weightLbs{ GetRandomCowWeight() };

public:
	Cow() : Animal() {
		SetGreeting("Moo");
		SetLicense(5);
		SetTitle("");
		SetBodyStructureVerterbrate();
		SetHabitatTerestrial();
		SetDietHerbivore();
		SetLocomotionWalking();
		SetRespirationLungs();

		numCow++;
#ifdef ENABLE_DEBUG
		std::cerr << debugHeader << format("{:40} {:>15p}.\n", "Default cow created", (void*)this);
#endif
	}

	Cow(const Cow& c) : Animal() {						// copy construtor

		this->weightLbs = c.weightLbs;
		SetName( c.GetName() );

		SetTitle("");
		SetGreeting("Moo");
		SetBodyStructureVerterbrate();
		SetHabitatTerestrial();
		SetDietHerbivore();
		SetLocomotionWalking();
		SetRespirationLungs();

		numCow++;
#ifdef ENABLE_DEBUG
		std::cerr << debugHeader << format("{:40} {:>15p}.\n", "Copy of cow created", (void*)this);
#endif
	}
	
	Cow(const std::string& n) : Animal() {				// create named cow
		SetGreeting("Moo");
		SetLicense(5);
		SetTitle("");
		SetBodyStructureVerterbrate();
		SetHabitatTerestrial();
		SetDietHerbivore();
		SetLocomotionWalking();
		SetRespirationLungs();

		SetName( n );

		numCow++;
#ifdef ENABLE_DEBUG
		std::cerr << debugHeader << format("{:26} {:13} {:>15p}.\n", "Created a named cow", n, (void*)this);
#endif

	}

	~Cow() {											// defualt cow destructor
		numCow--;
#ifdef ENABLE_DEBUG
		std::cerr << debugHeader << std::format("{:40} {:>15p}.\n", "Cow Destructor called for", (void*)this);
#endif
	}

	void Print() const;
	std::string IsA() {return "cow"; };
	void SetCowName(const std::string& s);

	unsigned int GetRandomCowWeight();
	Cow& operator=(const Cow& c0);
	unsigned int GetCowWeight() const { return weightLbs; }

	static int GetCowNumber() { return numCow; }
};

void Cow::Print() const {
	std::cout << std::format("this is a cow number {:05}, it says {}, it is {:04} Lbs\n", GetCowNumber(), GetGreeting(), GetCowWeight());

	this->Animal::Print();
};

inline void Cow::SetCowName(const std::string& s)
{
	Animal::SetName(s);
}

inline unsigned int Cow::GetRandomCowWeight()
{
	//	cows weight can range between 800 and 1400 lbs
	int const MIN = 800;
	int const MAX = 1400;

	std::random_device rd;  // seed generator
	std::mt19937 gen(rd()); // Mersenne Twister engine
	std::uniform_int_distribution<> dis(MIN, MAX);

	return dis(gen);
};

// overloaded assignment operator
Cow &Cow::operator=(const Cow &c) {
#ifdef DEBUG
	std::cerr << debugHeader << std::format("{} {:15p} {:15p}.\n", "overloaded= Cow", (void*)c, (void*)this);
#endif // DEBUG

	if (this != &c) {
		//Cow::operator=(c);
		// delete any dynamically allocated data members in destination
		// allocate any memory in destination for copies of source
		// copy data members from source to desination object
		SetCowName(c.GetName());
		weightLbs = c.weightLbs;
	}
	return *this;	// for cascaded assignments, c0 = c1 = c2;
}

bool operator<(const Cow& c0, const Cow& c1) {
	return c0.GetCowWeight() < c1.GetCowWeight();
}

bool operator==(const Cow& c0, const Cow& c1) {
	return (c0.GetCowWeight() == c1.GetCowWeight());
}



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


int AddCowToCowList(Cow* c) {
	return 0;
}