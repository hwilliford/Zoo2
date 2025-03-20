#pragma once
#include <iostream>
#include <string>
#include <format>
#include <random>


#define ANIMAL_HEADER
#define ENABLE_DEBUG		// comment out to disable debugging

#ifdef ENABLE_DEBUG
const std::string debugHeader = "info : \t";
#endif


using namespace std;

class Animal	// base class
{
private:
	std::string name;
	std::string title;
	std::string greeting;
	std::string animalLicense;
	static int numAnimals;				// initialization for static in is done at end of file.

	enum BodyStructure { undifined_b, verterbrate, inverterbrate };
	enum Habitat { undifined_h, terrestrial, aquatic, aeial };
	enum Diet { undifined_d, herbivore, carnivore, omnivore, detritivore };
	enum Locomotion { undifined_l, walking, flying, swimming, crawling };
	enum Respiration { undifined_r, lungs, gills };

	BodyStructure bodyStructure{ undifined_b };
	Habitat habitat{ undifined_h };
	Diet diet{ undifined_d };
	Locomotion locomotion{ undifined_l };
	Respiration respiration{ undifined_r };

public:
	//	constructors / destructor (virtural)
	//	public access functions, public interface &c.


	Animal();
	Animal(const Animal&);							// copy construtor
	Animal(const std::string&, const std::string&);
	//	Animal(const std::string&, const std::string&, const Animal::BodyStructure);
	~Animal();	// destructor
	void Print() const;

	const std::string GetName() const { return name; }
	const std::string GetTitle() const { return title; }
	const std::string GetGreeting() const { return greeting; }
	const std::string GetLicense() const { return animalLicense; }

	const std::string GetBodyStructure() const {
		switch (bodyStructure) {
		case verterbrate:
			return "verterbrate";
			break;
		case inverterbrate:
			return "inverterbrate";
			break;
		case undifined_b:
			return "undifined_b";
			break;
		default:
			return "should not have got here: GetBodyStructure();";
		}
	}

	const std::string GetHabitat() const {
		switch (habitat) {
		case terrestrial:
			return "terrestrial";
			break;
		case aquatic:
			return "aquatic";
			break;
		case aeial:
			return "aeial";
			break;
		case undifined_h:
			return "undifined_h";
			break;
		default:
			return "should not have got here: Gethabitat();";
		}
	}

	const std::string GetDiet() const {
		switch (diet) {
		case herbivore:
			return "herbivore";
			break;
		case carnivore:
			return "carnivore";
			break;
		case omnivore:
			return "omnivore";
			break;
		case detritivore:
			return "detritivore";
			break;
		case undifined_d:
			return "undifined_d";
			break;
		default:
			return "should not have got here: GetDiet();";

		}
	}

	const std::string GetLocomotion() const {
		switch (locomotion) {
		case walking:
			return "walking";
			break;
		case flying:
			return "flying";
			break;
		case swimming:
			return "swimming";
			break;
		case crawling:
			return "crawling";
			break;
		case undifined_l:
			return "undifined_l";
			break;
		default:
			return "should not have got here: GetLocomotion();";
		}
	}

	const std::string GetRespiration() const {
		switch (respiration) {
		case lungs:
			return "lungs";
			break;
		case gills:
			return "gills";
			break;
		case undifined_r:
			return "undifined_r";
			break;
		default:
			return "should not have got here: GetRespiration()";

		}
	}

	void SetBodyStructureVerterbrate() { bodyStructure = verterbrate; }
	void SetBodyStructureInverterbreate() { bodyStructure = inverterbrate; }
	void SetHabitatTerestrial() { habitat = terrestrial; }
	void SetHabitatAquatic() { habitat = aquatic; }
	void SetHabitatAeial() { habitat = aeial; }
	void SetDietHerbivore() { diet = herbivore; }
	void SetDietCarnivore() { diet = carnivore; }
	void SetDietOmnivore() { diet = omnivore; }
	void SetDietDetritivore() { diet = detritivore; }
	void SetLocomotionWalking() { locomotion = walking; }
	void SetLocomotionFlying() { locomotion = flying; }
	void SetLocomotionSwimming() { locomotion = swimming; }
	void SetLocomotionCrawling() { locomotion = crawling; }
	void SetRespirationLungs() { respiration = lungs; }
	void SetRespirationGills() { respiration = gills; }
	void SetName(const std::string& s) { name = s; }
	void SetTitle(const std::string& t) { title = t; }
	void SetGreeting(const std::string& g) { greeting = g; }

	void SetLicense(const std::string& s) {
		animalLicense = s;
	}

	void SetLicense(size_t length) {
		const std::string characters = "abcdefghijklmnopqrstuvwxyz0123456789";
		std::string rs;

		for (size_t i = 0; i < length; ++i) 
			rs += characters[rand() % characters.length()];

		animalLicense = rs + "-" + IsA();		// makes sorting by License more intresting. 
	}


	static int GetNumberAnimals() { return numAnimals; };

	virtual std::string IsA() const;

	const unsigned int RandomNumberAnimal(unsigned int s, unsigned int e) {

		std::random_device rd;  // seed generator
		std::mt19937 gen(rd()); // Mersenne Twister engine
		std::uniform_int_distribution<> dis(s, e);

		return dis(gen);
	}
};

void Animal::Print() const
{
	std::cout << std::format("{:=^80}\n", " Animal Record ");
#ifdef ENABLE_DEBUG
	std::cout << std::format("\t{:40} {:>15p}.\n", "Object Address  :", (void*)this);
#endif ENABLE_DEBUG

	std::cout << std::format("\tCount of animals:{:>20}\n", GetNumberAnimals());
	std::cout << std::format("\tTitle of animal :{:>20}\n", GetTitle());
	std::cout << std::format("\tName of animal  :{:>20}\n", GetName());
	std::cout << std::format("\tAnimal license #:{:>20}\n", GetLicense());
	std::cout << std::format("\tGreeting        :{:>20}\n", GetGreeting());
	std::cout << std::format("\tBody Structure  :{:>20}\n", GetBodyStructure());
	std::cout << std::format("\tHabitat         :{:>20}\n", GetHabitat());
	std::cout << std::format("\tDiet            :{:>20}\n", GetDiet());
	std::cout << std::format("\tLocomotion      :{:>20}\n", GetLocomotion());
	std::cout << std::format("\tRespiration     :{:>20}\n", GetRespiration());
}

Animal::Animal() {
	//	default construtor.
	//	all strings are constructed with an empty value by default.

	SetLicense(5);
//	animalLicense = "TODO: implement";
	name = "john doe";
	title = "mr.";
	greeting = "unknown";

	numAnimals++;
#ifdef ENABLE_DEBUG
	std::cerr << debugHeader << format("{:40} {:>15p}.\n", "Default Animal created", (void*)this);
#endif
}

// inline 
Animal::Animal(const Animal& a)	// copy constructor
{
	bodyStructure = a.bodyStructure;
	habitat = a.habitat;
	diet = a.diet;
	locomotion = a.locomotion;
	respiration = a.respiration;
	animalLicense = a.animalLicense;
	this->name = a.name;
	this->title = a.title;
	this->greeting = a.greeting;

	SetLicense(a.GetLicense());

	numAnimals++;
#ifdef ENABLE_DEBUG
	std::cerr << debugHeader << format( "{:40} {:>15p}.\n", "Animal copied", (void*)this);
#endif
}

Animal::Animal(const std::string& n, const std::string& t) {

	SetLicense(5);
//	animalLicense = "TODO: implement";

	name = n;
	title = t;
	greeting = "unknown";

	numAnimals++;
#ifdef ENABLE_DEBUG
	std::cerr << debugHeader << format("{:30} {:p}.\n", "Animal created by name and title", (void*)this);
#endif
}

Animal::~Animal() {
	numAnimals--;
#ifdef ENABLE_DEBUG
	std::cerr << debugHeader << std::format("{:40} {:>15p}.\n", "Animal destructor called for", (void*)this);
#endif
}

std::string Animal::IsA() const { return "animal"; };

// initialize the number of Animals. 
int Animal::numAnimals = 0;

void testAnimal() {
	Animal* a0 = new Animal();				// make john doe.
	a0->Print();

	Animal* a1 = new Animal("TestAnimal01", "Miss");
	a1->Print();

	Animal* a2 = new Animal("TestAnimal02", "Sir");
	a2->Print();

	Animal* a3 = new Animal(*a0);		// make a copy of a0 into a3.
	a3->Print();

	a3->SetName("TestAnimal02.03");				// modify a3
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
	// delete a0;
}
