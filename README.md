# Animal Class Project in C++

## Overview
Welcome to the Animal Class Project! This project defines a basic `Animal` class in C++, allowing users or students to create new animals using inheritance and IS-A relationships. The primary goal of this project is to demonstrate the concept of object-oriented programming (OOP) in C++, focusing on inheritance and polymorphism.

## Project Structure
- `Animal.h`: Header file containing the definition of the `Animal` class and a testing function to use the class functions.
- `Cow.h` : Example files demonstrating the creation of a `Cow` class that inherits from the `Animal` class. A Cow IS-A Animal.
- `main.cpp`: A sample main program that showcases how to use the `testAnimal` and `testCow` functions.
- `README.md`: This file provides an overview of the project and instructions for use.

## Getting Started
To get started with the Animal Class Project, follow these steps:

1. Move to the directory you want the working copy of the files. In my case I will have them off my ${HOME} directory in a sub directory "Code", then a layer deeper into "repo".
   ```bash
   cd ~/Code/repo
   
2. Clone the repository to your local machine by moving to the directory you want the files.:
   ```bash
   git clone https://github.com/hwilliford/Zoo2.git

3. Change to the directory where the source files are stored:
   ```bash
   cd Zoo2/Zoo
   
4. Compile using C++20 features
   ```bash
   g++ -std=c++20 -o zoo main.cpp
   g++ -I fmt/include -std=c++20 -o zoo main.cpp -lfmt

5. excute and enjoy the running code.
   ```bash
   ./zoo
