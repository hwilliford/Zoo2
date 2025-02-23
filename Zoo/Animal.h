#pragma once
#include <iostream>
#include <string>
#include <format>

using namespace std;

class Animal	// base class
{
private:
	std::string name;
	std::string title;
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
	Animal(const Animal &);							// copy construtor
	Animal(const std::string&, const std::string&);
//	Animal(const std::string&, const std::string&, const Animal::BodyStructure);
	~Animal();	// destructor
	void Print() const;

	const std::string GetName() const { return name; }
	const std::string GetTitle() const { return title; }
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
	};

	void SetBodyStructureVerterbrate() { bodyStructure = verterbrate; }
	void SetBodyStructureInverterbreate() {	bodyStructure = inverterbrate; };
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
	void SetName(const std::string& s) { name = s; };
	void SetTitle(const std::string& t) { title = t; };

	static int GetNumberAnimals() { return numAnimals; }

};



void Animal::Print() const
{
	std::cout << std::format("{:05} {:>30} {:<30} {:>15} {:>20p}\n", GetNumberAnimals(), GetTitle(), GetName(), GetLicense(), (void*)this );
	std::cout << std::format("\tBody Structure :{:>15}\n", GetBodyStructure() );
	std::cout << std::format("\tHabitat        :{:>15}\n", GetHabitat() );
	std::cout << std::format("\tDiet           :{:>15}\n", GetDiet() );
	std::cout << std::format("\tLocomotion     :{:>15}\n", GetLocomotion() );
	std::cout << std::format("\tRespiration    :{:>15}\n", GetRespiration() );
}

Animal::Animal() {
	//	default construtor.
	//	all strings are constructed with an empty value by default.

	animalLicense = "TODO: implement";
	name = "john doe";
	title = "mr.";

	numAnimals++;
}

// inline 
Animal::Animal(const Animal &a)	// copy constructor
{
	bodyStructure = a.bodyStructure;
	habitat = a.habitat;
	diet = a.diet;
	locomotion = a.locomotion;
	respiration = a.respiration;
	animalLicense = a.animalLicense;
	this->name = a.name;
	this->title = a.title;

	numAnimals++;
}

Animal::Animal(const std::string &n, const std::string &t) {

	animalLicense = "TODO: implement";

	name = n;
	title = t;

	numAnimals++;
}

Animal::~Animal() {
	std::cout << std::format("Destructor called for {:p}\n", (void*)this);

	numAnimals--;
}

// initialize the number of Animals. 
int Animal::numAnimals = 0;