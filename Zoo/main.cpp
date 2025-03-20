#include <list>
using std::list;

#include <vector>
using std::vector;

#include <deque>
using std::deque;

#include <stack>
using std::stack;

#include <queue>
using std::queue;
#include <iomanip>
#include <map>
using std::map;
using std::pair;

#include <iostream>
#include <string>
#include <format>
using std::format;

#include "Animal.h"
#include "Cow.h"
#include "Human.h"

void testLinkedList() {
	std::cout << format ("{:*^80}\n", " Test for LinkedList() ");

	list<Cow>	cowList;	// create a list of cows.

	// Get some cows, name them and put them into a list.
	Cow* c0 = new Cow();	// make a new cow in dynamic memory
	c0->SetName("Mr. Moo");	// use member function to SetName of cow c0.
	cowList.push_back(*c0);	// add the cow to the heardList.

	auto c0a = std::make_unique<Cow>(Cow("Jr. Moo"));		// example of safe pointer useage.
	cowList.push_back(*c0a);

	// The next 4 instances are anonymous objects in main()
	// There is no way to access them outside of the heardList.
	cowList.push_back(Cow("Bessie"));
	cowList.push_back(Cow("Daisy"));
	cowList.push_back(Cow("Buttercup"));
	cowList.push_back(Cow("Mooana"));

	// now lets walk the list 
	while (!cowList.empty()) {
		cowList.front().Print();
		cowList.pop_front();
	}
	delete c0;	// was allocated on the heap clean up the heap
}

void testIterator() {
	std::cout << format("{:*^80}\n", " Test for Iterator() ");

	list<Cow> cowList;

	Cow* c0 = new Cow();	// make a new cow in dynamic memory
	c0->SetName("Clover");	// use member function to SetName of cow c0

	cowList.push_back(*c0);	// add cow to cowList.

	// next Cow instances are anonymous objects
	cowList.push_back(Cow("Mabel"));
	cowList.push_back(Cow("Rosie"));
	cowList.push_back(Cow("Sir Loin"));

	// now sort the cows by weight in Lbs.
	cowList.sort();		//  sort() relys on the operator<

	// now walk the list using simplify iterator notiation 'auto'
	auto autoIter = cowList.begin();
	while (autoIter != cowList.end()) {
		(*autoIter).Print();
		++autoIter;
	}
}

void testVector() {
	std::cout << format("{:*^80}\n", " Test for Vector() ");

	vector<Cow> cowVector1, cowVector2;

	// add 3 cows as anonymous objects 
	cowVector1.push_back(Cow("Bella"));
	cowVector1.push_back(Cow("Penelope"));
	cowVector1.push_back(Cow("Tulip"));
	cowVector1.push_back(Cow("Ferdinand"));

	// walk vector and print out what it has.
	for (auto iter = cowVector1.begin(); iter != cowVector1.end(); iter++)
		(iter)->Print();
	
	// walk vector in old school for loop
	for (int i = 0; i < cowVector1.size(); i++)
		cowVector1[i].Print();	// print first vector

	cowVector2 = cowVector1;	// assign cowVectro2 to cowVector1.

	// verify cowVector2 after overide=.
	for (int i = 0; i < cowVector2.size(); i++)
		cowVector2[i].Print();

	// preferred range 'for loop' with auto, simplifying things
	for (const auto& cow : cowVector2)
		cow.Print();
}

void testDeque() {
	std::cout << format("{:*^80}\n", " Test for Deque() ");

	deque<Cow> cowDeque;		// pronounced deck
	Cow *c0 = new Cow("Butterbean");

	// create some anonymous cow objects.
	cowDeque.push_back(Cow("Magnolia"));
	cowDeque.push_back(Cow("Cheddar"));
	cowDeque.push_back(Cow("Blossom"));

	// insert one past the beginning
	cowDeque.insert(std::next(cowDeque.begin()), Cow("Marigold"));
	cowDeque.insert(cowDeque.begin(), Cow("Marigold II"));

	cowDeque[0] = Cow("Cocoa");	// replace the 0th element (no bounds checking)
	cowDeque[3] = *c0;

	while (!cowDeque.empty()) {
		cowDeque.front().Print();
		cowDeque.pop_front();
	}
}

void testStack() {
	std::cout << format("{:*^80}\n", " Test for Stack() ");

	stack<Cow> cowStack;	// create a stack

	// add Cows to the stack (anonymous objects)
	cowStack.push(Cow("Ginger"));
	cowStack.push(Cow("Maple"));
	cowStack.push(Cow("Milky Way"));
	cowStack.push(Cow("Bo Vine"));

	while (!cowStack.empty()) {
		cowStack.top().Print();
		cowStack.pop();
	}
}

void testQueue() {
	queue<Cow> cowQueue;	// create a queue of cows

	// add cows as anonymous objects
	cowQueue.push(Cow("Hazel"));
	cowQueue.push(Cow("Moochelle"));
	cowQueue.push(Cow("Dandelion"));
	cowQueue.push(Cow("Oreo"));

	while (!cowQueue.empty()) {
		cowQueue.front().Print();
		cowQueue.pop();
	}
}

void testMap() {
	std::cout << format("{:*^80}\n", " Test for Map() ");

	Cow c0 ("Tilly");
	Cow c1 ("Juniper");
	Cow c2 ("MooMoo");
	Cow c3 ("Sundae");

	// create pairings of licence to Cows
	pair<string, Cow> cowPair0(c0.GetLicense(), c0);
	pair<string, Cow> cowPair1(c1.GetLicense(), c1);
	pair<string, Cow> cowPair2(c2.GetLicense(), c2);

	// Create map of cows w/ string keys
	map<string, Cow> cowMap;
	cowMap.insert(cowPair0);
	cowMap.insert(cowPair1);
	cowMap.insert(cowPair2);

	// insert using virtual indices per map
	cowMap[c3.GetLicense()] = c3;

	// lets iterate using a range-for loop with 'auto'
	// Output should be by order of animalLicense
	for (auto& [animalLicense, cow] : cowMap)
		cow.Print();

	// iterate through set with map iterator
	map<string, Cow>::iterator mapIter = cowMap.begin();
	while (mapIter != cowMap.end()) {
		pair<string, Cow> temp = *mapIter;
		Cow& tempC = temp.second;			// get the 2nd element.
		tempC.Print();						// print it

		++mapIter;
	}

	// lets iterate using a range-for loop with 'auto'
	// Output should be by order of animalLicense
	for (auto& [animalLicense, cow] : cowMap)
		cow.Print();
}

int main() {

	std::cout << format("{:*^80}\n", " Start of animal testing ");
	testAnimal();

	std::cout << format("{:*^80}\n", " Start of cow testing ");
	testCow();

	std::cout << format("{:*^80}\n", " Start of testing STL containters ");

	testLinkedList();
	testIterator();
	testVector();
	testDeque();
	testStack();
	testQueue();
	testMap();

	std::cout << format("{:*^80}\n", " End of testing STL containters ");
	std::cout << format("{:*^80}\n", " End of cow testing ");

	std::cout << format("{:*^80}\n", " Start of testing Human ");
	humanTesting();

	std::cout << format("{:*^80}\n", " End of testing Human ");

	std::cout << format("{:*^80}\n", " End of code ");
	return 0;
}
