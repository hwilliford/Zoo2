#pragma

#include "Human.h"
#include "Cow.h"

class Hathor: public Human, public Cow {
    private:
        static constexpr unsigned int HATHOR_LIFE = 500;            // life exp of Hathor
        static int numHathor;				// initialization for static in is done at end of file.
        void SetHathorDefaults() {
            Human::SetLicense(4);
            Cow::SetLicense(Human::GetLicense());

            Human::SetGreeting("Moo and Hello.");
            Cow::SetGreeting(Human::GetGreeting());
        }

    public:
        Hathor(): Human(), Cow() {
            SetHathorDefaults();

            numHathor++;

#ifdef ENABLE_DEBUG
	std::cerr << debugHeader << format("{:40} {:>15p}.\n", "Default hathor created", (void*)this);
    std::cerr << debugHeader << format("{:40} {:>15}.\n", " + GetLicense()", Human::GetLicense());
#endif
        }

        Hathor(const std::string &n) {
            SetHathorDefaults();

            Human::SetName(n);

            numHathor++;
#ifdef ENABLE_DEBUG
	std::cerr << debugHeader << format("{:40} {:>15p}.\n", "Named hathor created", (void*)this);
    std::cerr << debugHeader << format("{:40} {:>15}.\n", " + GetLicense()", Human::GetLicense());
#endif
        }

        Hathor(Hathor&h): Human(), Cow() {
            Human::SetName(h.Human::GetName());
            Human::SetLicense(h.Human::GetLicense());
            Cow::SetLicense(h.Human::GetLicense());

            numHathor++;
#ifdef ENABLE_DEBUG
    std::cerr << debugHeader << format("{:<20}  {:>14p}  <-  {:>14p}.\n", "Copy Human", (void*)this, (void*)&h);
    std::cerr << debugHeader << format("{:40} {:>15}.\n", " + GetLicense()", Human::GetLicense());
#endif
        }

        ~Hathor() {
#ifdef ENABLE_DEBUG
	std::cerr << debugHeader << format("{:40} {:>15p}.\n", "~Hathor() called ", (void*)this);
#endif
            numHathor--;

#ifdef ENABLE_DEBUG
	std::cerr << debugHeader << format("{:40} {:>15p}.\n", "Hathor destructor called for", (void*)this);
#endif
        }

        void Print() const;
        string IsA() const override {return "hathor";}
        string greeting() { return "Moo! and Hello!";}
};

void Hathor::Print() const {

    this->Human::Print();
    this->Cow::Print();

	std::cout << format("\t{:+<72}\n", "Hathor data ");
#ifdef ENABLE_DEBUG
	std::cout << format("\t{:40} {:>15p}.\n", "Object Address  :", (void*)this);
    std::cout << format("\t{:40} {:15}.\n", "numHathor", numHathor);
#endif // ENABLE_DEBUG
}

int hathorTesting() {
    Hathor h0;
    h0.Print();

    Hathor h1 ("Wild Man");
    h1.Print();

    return 0;
}

int Hathor::numHathor = 0;
//inline std::string Hathor::IsA() const { return "hathor"; };	// overloaded.
