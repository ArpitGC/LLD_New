// Singleton.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "logger.hpp"
using namespace std;
int Logger::ctr = 0;

Logger* Logger::loggerInstance = nullptr;

mutex Logger::mtx;

Logger::Logger() {
   ctr++;
   cout << "new instance create. No of instances"<<ctr<<endl;
}

void Logger::Log(string msg) {
   cout << msg << endl;
}

Logger* Logger::getLogger() {
   mtx.lock();
   if (loggerInstance == nullptr) {
      loggerInstance = new Logger();
   }

   mtx.unlock();
   return loggerInstance;

}



