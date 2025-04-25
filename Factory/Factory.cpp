/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

class Animal {

public:
   virtual void makeSound() = 0;//pure virtual func
   virtual ~Animal() {}

};

class Dog : public Animal {
public:
   void makeSound() override {
      cout << "Hii I am dog";
   }
};


class Cat : public Animal {
public:
   void makeSound() override {
      cout << "Hii I am cat";
   }
};

class AnimalFactory {
public:
   static Animal* createAnimal(string type) {
      if (type == "dog") return new Dog();
      else if (type == "cat") return new Cat();
      else return nullptr;
   }

};

//just a comment 



int main()
{
   std::cout << "Hello World";

   Animal* a1 = AnimalFactory::createAnimal("dog");
   Animal* a2 = AnimalFactory::createAnimal("cat");


   if (a1) a1->makeSound();
   if (a2) a2->makeSound();


   delete a1;
   delete a2;


   return 0;
}