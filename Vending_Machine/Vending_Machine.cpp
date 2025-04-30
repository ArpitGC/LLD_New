

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
};



#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}