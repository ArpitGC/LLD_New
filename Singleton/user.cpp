
#include <iostream>
#include "logger.hpp"
#include <thread>
using namespace std;

void user1logs() {
   Logger* logger1 = Logger::getLogger();
   logger1->Log("From User 1");

}

void user2logs() {


   Logger* logger2 = Logger::getLogger();
   logger2->Log("From User 2");

}

int main()
{

   thread t1(user1logs);
   thread t2(user2logs);

   t1.join();
   t2.join();
  // std::cout << "Hello World!\n";
   return 0;
} 