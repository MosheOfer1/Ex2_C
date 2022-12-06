#include <stdio.h>
#include "my_mat.h"

int main() {
	//The main class that reads the user's input
	char choice = 'A';
	while (choice != 'D')
	{
		scanf("%c",&choice);
		if (choice=='A')
		{
			recive_mat();
		}
		else if(choice == 'B')
		{
			int x, y;
			scanf("%d%d", &x, &y);
			hasPath(x,y);
		}
		else if (choice == 'C')
		{
			int x, y;
			scanf("%d%d", &x, &y);
			shortestPath(x, y);
		}
	}
	return 0;
}
