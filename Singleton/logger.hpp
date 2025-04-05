#pragma once


#include <string>
#include<mutex>
using namespace std;

class Logger {

   static int ctr;
   static Logger* loggerInstance;
   static mutex mtx;
   Logger();
public:
   static Logger* getLogger();

   void Log(string msg);
};