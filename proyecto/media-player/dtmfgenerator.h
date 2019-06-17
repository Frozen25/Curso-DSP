#ifndef DTMFGENERATOR_H
#define DTMFGENERATOR_H
#include <fstream>
#include <iostream>
using namespace std;

class DtmfGenerator
{

public:
	DtmfGenerator();
    void generateTone(int f1,int f2,string name);
    void generateNumber(char* number);
    int getLowFrequency(char number);
    int getHighFrequency(char number);
    string getname(char number);
    void initTones();
};

#endif // DTMFGENERATOR_H
