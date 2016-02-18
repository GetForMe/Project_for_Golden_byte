#include "Header.h"
#include "AllegroCore.h"
void main()
{
	try {
		AllegroCore DreamCars;
		DreamCars.Initialize(600, 800);
		DreamCars.StartGame();
		
	}
	catch (char *messenge) {
		cout << messenge << endl;
	}
	
	system("pause");

}