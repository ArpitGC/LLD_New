

class State {
   virtual void InsertCoin() = 0;
   virtual void SelectItem() = 0;
   virtual void Dispense() = 0;

   virtual ~State() = default;
};


//NocointState
//HasCoinState
//ItemDispensState
//SoldOutState


class NoCoinState : public State {
private :
   VendingMachine* machine;
public:
   NoCoinState(VendingMachine* m) : machine(m) {}
   void InsertCoin() override {

   }

   void SelectItem() override {

   }

   void Dispense() override {


   }
};


class HasCoinState : public State {
private:
   vendingMachine* machine;
public :
   HasCoinState(VendingMachine* m) : machine(m) {}
   void InsertCoin() override {

   }

   void SelectItem() override {

   }

   void Dispense() override {


   }
};


class ItemDispenseState : public State {
private:
   VendingMachine* machine;
public:
   ItemDispenseState(VendingMachine* m) : machine(m) {}
   void InsertCoin() override {

   }

   void SelectItem() override {

   }

   void Dispense() override {


   }

};


class SoldOutState :public State {
private: 
   VendingMachine* machine;
public:
   ItemDispenseState(VendingMachine* m) : machine(m) {}
   void InsertCoin() override {

   }

   void SelectItem() override {

   }

   void Dispense() override {


   }
};


class VendingState {






};
#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}