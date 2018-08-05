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
  
  for(size_t i = 0; i < vObject.size(); i++)
	  printf_s("%d)  %d", i, vObject[i]);
} 

int main(int argc, char** argv)
{
	SetConsoleTitleA("Console");

	
	CallTest();

	_getch();
	return EXIT_SUCCESS;
}




















