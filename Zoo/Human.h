#pragma once
#include <iostream>
#include <string>
#include <format>
#include <random>
#include <queue>
#include <map>

#include "Animal.h"

class Human : public Animal
{
private:
	static unsigned int numHuman;						// initialization for static in is done at end of file
	static map<string, Human> humanMap;					// TODO: keep list of all humans created

	enum EyeColour { undefined_e, amber, blue, brown, gray, green, hazel, red, violet };
	enum HairColour { undefined_h, auburn, black, blonde, chestnut, silver, copper };
	enum SkinColour { undefined_s, dk_brown, m_brown, lt_brown, fair, pk_white, pale};

	const EyeColour GetRandomEyeColor();
	const HairColour GetRandomHairColor();
	const SkinColour GetRandomSkinColor();

	EyeColour eyeColor = { GetRandomEyeColor() };
	HairColour hairColor = { GetRandomHairColor()};
	SkinColour skinColor = { GetRandomSkinColor()};

	unsigned int GetRandomHumanWeight();
	unsigned int GetRandomHumanHeight();
	unsigned int weightKg{ GetRandomHumanWeight() };
	unsigned int heightCm{ GetRandomHumanHeight() };


	bool GetRegistraionCheck() {
#ifdef ENABLE_DEBUG
		std::cerr << debugHeader << format("{:40} {:>15p}.\n", "GetRegistrationCheck()", (void*)this);
#endif

	return !(humanMap.find(GetLicense()) != humanMap.end());
	};

	void registerHuman(Human&);
	void deleteHuman(Human&);

public:
	const std::string GetEyeColor();
	const std::string GetHairColor();
	const std::string GetSkinColor();
	inline const unsigned int GetWeight() const {return weightKg;};
	inline const unsigned int GetHeight() const {return heightCm;};

//	Human() = default;									// default constructor proto type
	Human(const Human&h);								// copy constructor
	virtual ~Human();									// virtural destructor
	void Print() const;
	const bool operator==(const Human&h);				// overloaded is equal operator
	Human& operator=(const Human& h);					// overloaded assignment operator
	const bool operator<(const Human& h0 /*, const Human& h1 */);	// overloaded less than operator.
//	Human& operator=(Human&&);							// move assignment 

	void inline SetEyeColorAmber() { eyeColor = amber; }
	void inline SetEyeColorBlue() { eyeColor = blue; }
	void inline SetEyeColorBrown() { eyeColor = brown; }
	void inline SetEyeColorGray() { eyeColor = gray; }
	void inline SetEyeColorGreen() { eyeColor = green; }
	void inline SetEyeColorHazel() { eyeColor = hazel; }
	void inline SetEyeColorRed() { eyeColor = red; }
	void inline SetEyeColorViolet() { eyeColor = violet; }

	void inline SetHairColorAuburn() { hairColor = auburn; }
	void inline SetHairColorBlack() { hairColor = black; }
	void inline SetHairColorBlond() { hairColor = blonde; }
	void inline SetHairColorChestnut() { hairColor = chestnut; }
	void inline SetHairColorSilver() { hairColor = silver; }
	void inline SetHairColorCopper() { hairColor = copper; }

	void inline SetSkinColorDk_brown() { skinColor = dk_brown; }
	void inline SetSkinColorM_brown() { skinColor = m_brown; }
	void inline SetSkinColorLt_brown() { skinColor = lt_brown; }
	void inline SetSkinColorFair() { skinColor = fair; }
	void inline SetSkinColorPk_white() { skinColor = pk_white; }
	void inline SetSkinColorPale() { skinColor = pale; }

	void inline SetHumanDefaults() { 
#ifdef ENABLE_DEBUG
		std::cerr << debugHeader << format("{:40} {:>15p}.\n", "SetHumanDefaults()", (void*)this);
#endif

		SetGreeting("Hello");
		SetLicense(9);
		SetTitle("");
		SetBodyStructureVerterbrate();
		SetHabitatTerestrial();
		SetDietOmnivore();
		SetLocomotionWalking();
		SetRespirationLungs();

#ifdef ENABLE_DEBUG
		std::cerr << debugHeader << format("{:40} {:>15}.\n", " + GetLicense()", GetLicense());
#endif

	}

	void RecordHuman(const Human&);
	static std::map<string, Human> GetCopyHumanMap();		

	Human() : Animal() {								// default constructor
		SetHumanDefaults();

		numHuman++;
#ifdef ENABLE_DEBUG
		std::cerr << debugHeader << format("{:40} {:>15p}.\n", "Default Human created", (void*)this);
#endif
	}

	Human(const std::string& n) : Animal() {				// create named human
		SetHumanDefaults();

		SetName(n);
		numHuman++;
#ifdef ENABLE_DEBUG
		std::cerr << debugHeader << format("{:26} {:13} {:>15p}.\n", "Created a named human", n, (void*)this);
#endif
	}

	const std::string GetEyeColor() const
	{								// undefined_e, amber, blue, brown, gray, green, hazel, red, violet
		switch (eyeColor) {
			case undefined_e: 
				return "undefined"; break;
			case amber: 
				return "amber"; break;
			case blue: 
				return "blue"; break;
			case gray: 
				return "gray"; break;
			case green: 
				return "green"; break;
			case hazel: 
				return "hazel"; break;
			case red: 
				return "red"; break;
			case violet: 
				return "violet"; break;
			default: 
				return "should not get here EyeColor()";
		}
		return "bad value";
	}

	const std::string GetHairColor() const
	{
		//auburn, black, blonde, chestnut, silver, copper
			switch (hairColor) {
			case undefined_h: 
				return "undefined"; 
				break;
			case auburn:
				return "auburn";
				break;
			case black:
				return "black";
				break;
			case blonde:
				return "blond";
				break;
			case chestnut:
				return "chestnut";
				break;
			case silver:
				return "silver";
				break;
			case copper:
				return "copper";

			default: 
				return "should not get here GetHairColor()";
			}
		return "bad value";
	}

	const std::string GetSkinColor() const {
		// dk_brown, m_brown, lt_brown, fair, pk_white, pale}
		switch (hairColor) {
		case undefined_s:
			return "undefined";
			break;
		case dk_brown:
			return "dark brown";
			break;
		case m_brown:
			return "medium brown";
			break;
		case lt_brown:
			return "light brown";
			break;
		case fair:
			return "fair";
			break;
		case pk_white:
			return "pink / white";
			break;
		case pale:
			return "pale";
			break;
		default:
			return "should not get here GetSkinColor()";
		}
		return "bad value";
	}

	std::string IsA() const override;
};

unsigned int Human::numHuman = 0;			// human population count at start
std::string Human::IsA() const { return "human"; };	// overloaded.
map<string, Human> Human::humanMap;			// keep a list of all active humans.

inline Human::~Human()
{
#ifdef ENABLE_DEBUG
	std::cerr << debugHeader << format("{:40} {:>15p}.\n", "Default Human deconstruction", (void*)this);
#endif
	humanMap.erase(GetLicense());
	deleteHuman(*this);
}

void Human::Print() const {
	this->Animal::Print();

	std::cout << std::format("\t{:+<72}\n", "Human data ");
#ifdef ENABLE_DEBUG
	std::cout << std::format("\t{:40} {:>15p}.\n", "Object Address  :", (void*)this);
	std::map<string, Human> hMap{ Human::GetCopyHumanMap() };
	std::map<string, Human>::iterator hMapIter = hMap.begin();
	std::cout << std::format("\t{:40} {:>15}.\n", "humanMap.size   :", hMap.size());
#endif // ENABLE_DEBUG
	
	std::cout << std::format("\tID Number       :{:>20}\n", GetLicense());
	std::cout << std::format("\tName            :{:>20}\n", GetName());
	std::cout << std::format("\tEye color       :{:>20}\n", GetEyeColor());
	std::cout << std::format("\tHair color      :{:>20}\n", GetHairColor());
	std::cout << std::format("\tSkin color      :{:>20}\n", GetSkinColor());
	std::cout << std::format("\theight (cm)     :{:>20}\n", GetHeight());
	std::cout << std::format("\tWeight (kg)     :{:>20}\n", GetWeight());
}

inline const Human::EyeColour Human::GetRandomEyeColor()
{
	switch (RandomNumberAnimal(1, 8)) {
	case 1 :
		return amber;
		break;
	case 2:
		return blue;
		break;
	case 3:
		return gray;
		break;
	case 4:
		return green;
		break;
	case 5:
		return hazel;
		break;
	case 6:
		return red;
		break;
	case 7:
		return violet;
		break;
	default :
		return undefined_e;
	}
}

inline const Human::HairColour Human::GetRandomHairColor() {
	// auburn, black, blonde, chestnut, silver, copper
	switch (RandomNumberAnimal(1, 6)) {
	case 1:
		return auburn;
		break;
	case 2:
		return black;
		break;
	case 3:
		return blonde;
		break;
	case 4:
		return chestnut;
		break;
	case 5:
		return silver;
		break;
	case 6:
		return copper;
		break;
	default:
		return undefined_h;
	}
	return undefined_h;
}

inline const Human::SkinColour Human::GetRandomSkinColor() {
	return undefined_s;
}

inline unsigned int Human::GetRandomHumanWeight() {
	//	weight can range between 45 and 200 kg
	int const MIN = 45;		// record is 2.1 kg - microcephalic, osteodysplastic primordial dwarfism.
	int const MAX = 200;	// record is 635 kg - severe obesity

	return RandomNumberAnimal(MIN, MAX);
};

inline unsigned int Human::GetRandomHumanHeight()
{
	//	height can range between 150 and 180 cm (m: 157 - 180, w: 150 to 170)
	int const MIN = 150;	// record is 54
	int const MAX = 180;	// record is 272

	return RandomNumberAnimal(MIN, MAX);
}

inline void Human::registerHuman(Human &h)
{
#ifdef ENABLE_DEBUG
	std::cerr << debugHeader << std::format("{:26} {:13} {:>15p}.\n", "Human registered", h.GetName(), (void*)this);
#endif
	pair<string, Human> hp(h.GetLicense(), h);
	humanMap.insert(hp);
}

inline void Human::deleteHuman(Human& h) {
#ifdef ENABLE_DEBUG
	std::cerr << debugHeader << format("{:26} {:13} {:>15p}.\n", "Human deleted", h.GetName(), (void*)this);
#endif
	humanMap.erase(h.GetLicense());
	--numHuman;
}

inline const std::string Human::GetEyeColor()
{
	return "todo";
}

inline const std::string Human::GetHairColor()
{
	return "todo";
}

inline const std::string Human::GetSkinColor()
{
	return "todo";
}

inline Human::Human(const Human&h)								// copy constructor
{
#ifdef ENABLE_DEBUG
	std::cerr << debugHeader << std::format("{:<20}  {:>14p}  <-  {:>14p}.\n", "Copy Human", (void*)this, (void*)&h);
#endif // DEBUG
	eyeColor = h.eyeColor;
	hairColor = h.hairColor;
	skinColor = h.skinColor;
	weightKg = h.weightKg;
	heightCm = h.heightCm;

	SetGreeting("Hello");

	SetBodyStructureVerterbrate();
	SetHabitatTerestrial();
	SetDietOmnivore();
	SetLocomotionWalking();
	SetRespirationLungs();

	SetName(h.GetName());

	SetLicense(h.GetLicense());
}

const bool Human::operator==(const Human&h)					// is equal / comparison operator
{
#ifdef ENABLE_DEBUG
	std::cerr << debugHeader << std::format("{:<20} {:>15p} == {:<15p}.\n", "overloaded ++ for Human", (void*)this, (void*)&h);
#endif // ENABLE_DEBUG
	bool b{ this->GetLicense()==h.GetLicense() };

	if (this == &h)
		return true;
	else
		return b;
}


inline Human& Human::operator=(const Human &h)					// move assignment operator
{
#ifdef ENABLE_DEBUG
	std::cerr << debugHeader << std::format("{:<20}  {:>16p} = {:>14p}.\n", "overloaded= for Human", (void*)this, (void*)&h);
#endif // DEBUG

	if (this != &h) {
		eyeColor = h.eyeColor;
		hairColor = h.hairColor;
		skinColor = h.skinColor;
		weightKg = h.weightKg;
		heightCm = h.heightCm;

		SetName( h.GetName() );
		SetTitle(h.GetTitle());
		SetGreeting(h.GetGreeting());
		SetLicense(h.GetLicense());
	}
	return *this;
}

inline const bool Human::operator<(const Human& h0)
{
#ifdef ENABLE_DEBUG
	std::cerr << debugHeader << std::format("{:20} {:>15p} < {:<15p}.\n", "overloaded< for Human", (void*)this, (void*)&h0);
#endif // DEBUG

	return GetLicense() < h0.GetLicense();
}

/*
inline const bool Human::operator<(const Human& h0, const Human& h1)
{

#ifdef ENABLE_DEBUG
	std::cerr << debugHeader << std::format("{:20} {:>15p} = {:<15p}.\n", "overloaded< for Human", (void*)&h0, (void*)&h1);
#endif // DEBUG
	return h0.GetLicense() < h1.GetLicense();
}
*/

void Human::RecordHuman(const Human& h) {
#ifdef ENABLE_DEBUG
	std::cerr << debugHeader << std::format("{:<20} {:<15p}).\n", "RecordHuman()", (void*)&h);
#endif // DEBUG

	pair<string, Human> hp(h.GetLicense(), h);
	humanMap.insert(hp);
}

inline std::map<string, Human> Human::GetCopyHumanMap() {
	std::map<string, Human> hm;

#ifdef ENABLE_DEBUG
	std::cerr << debugHeader << std::format("{:<20}  {:>14p}  <-  {:<14p}.\n", "GetCopyHumanMap()   ", (void*)&hm, (void*)&humanMap);
#endif // DEBUG

	for (auto& [animalLicense, human] : humanMap)
		hm[human.GetLicense()] = human;

	return hm;
}

void humanTesting() {
	// create test human
	auto hm = std::make_unique<map<string, Human>>;
	std::map<string, Human> hm0;

	Human h0 ("Human Zed");
	hm0[h0.GetLicense()] = h0;
//	Human::RecordHuman(h0);

	Human* h1 = new Human("Human Alpha");
	hm0[h1->GetLicense()] = *h1;
	h1->Human::Print();

	auto h2 = std::make_unique<Human>(Human());						// default constructor using safe pointer, make_unique, weak_ptr, shared_ptr
	hm0[h2->GetLicense()] = *h2;
	h2->Human::Print();

	auto h3 = std::make_unique<Human>(Human("Human Beta"));			// create with name.
	hm0[h3->GetLicense()] = *h3;
	h3->Human::Print();

	auto h4 = std::make_unique<Human>(Human("Human Gama"));			// create with name.
	hm0[h4->GetLicense()] = *h4;

	for (auto& [animalLicense, human] : hm0)
		human.Print();
}