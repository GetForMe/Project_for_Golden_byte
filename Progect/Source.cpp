#include "Header.h"
#include "AllegroCore.h"
void main()
{
	try {
		AllegroCore Tennis;
		Tennis.Initialize(800, 400);
		Tennis.StartGame();
		
	}
	catch (char *messenge) {
		cout << messenge << endl;
	}
	


	system("pause");

}