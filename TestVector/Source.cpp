#include <Windows.h>
#include <conio.h>
#include <iostream>
#include "Vector.h"



void CallTest()
{
// call test
  Vector<int>  vObject;
  vObject.push_back(12);
  vObject.push_back(7);
  vObject.push_back(67);
} 

int main(int argc, char** argv)
{
	SetConsoleTitleA("Console");

	
	CallTest();

	_getch();
	return EXIT_SUCCESS;
}




















