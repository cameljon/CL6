#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(time(NULL));
	string rooms[4][3];
	int mapWidth = 4;
	int mapHeight = 3;

	rooms[0][0] = "Sea Shore \n You are standing on the beach.";
	rooms[0][1] = "Village Entrance \n A sleepy village sits, barely anybody wandering around.";
	rooms[0][2] = "Village Inn \n You could order some tasty pancakes here.";
	rooms[1][0] = "Cliffside \n A tall cliff to the north blocks you way further";
	rooms[1][1] = "Grassy Field \n You are standing in a grassy field.";
	rooms[1][2] = "Forest Entrance \n You can't see through the trees.";
	rooms[2][0] = "Cave Entrance \n A gaping hole in the cliff wall leads inwards to a dark cavern.";
	rooms[2][1] = "Hermit's House \n Small house built into the side of the cliff.";
	rooms[2][2] = "Ominous Fissure \n It's really just a giant crack in the ground.";
	rooms[3][0] = "Inside Cave \n The spooky cave is dark and damp.";
	rooms[3][1] = "Deep Cave \n There is a man in here, much to your surprise.";
	rooms[3][2] = "Much Deeper Cave \n The man disappeared. Maybe we shouldn't be here.";
	
	int x = 1;
	int y = 1;
	int keyX, keyY, doorX, doorY;
	keyX = rand() % (mapWidth - 1);
	keyY = rand() % (mapHeight - 1);
	doorX = rand() % (mapWidth - 1);
	doorY = rand() % (mapHeight - 1);

	bool isDone = false;
	bool hasKey = false;

	while (!isDone)
	{
		//Map with position.
		for (int i = 0; i < mapHeight; i++)
		{
			for (int h = 0; h < mapWidth; h++)
			{
				if (i == y && h == x)
				{
					cout << "[X]";

				}
				else
				{
					cout << "[ ]";
				}
			}
			cout << endl;
		}

		cout << rooms[x][y] << endl;
		if (hasKey)
		{
			cout << "You are carrying the key." << endl;
		}
		cout << endl << "[N]orth, [S]outh, [E]ast, or [W]est \n>>";
		char choice1;
		cin >> choice1;
		choice1 = tolower(choice1);

		switch (choice1)
		{
		case 'n':
			if (y > 0)
			{
				y -= 1;
			}
			else 
			{ 
				cout << "You can't go that way!" << endl;  
			}
			break;
		case 'e':
			if (x < mapWidth - 1)
			{
				x += 1;
			}
			else
			{
				cout << "You can't go that way!" << endl;
			}
			break;
		case 's':
			if (y < mapHeight - 1)
			{
				y += 1;
			}
			else
			{
				cout << "You can't go that way!" << endl;
			}
			break;
		case 'w':
			if (x > 0)
			{
				x -= 1;
			}
			else
			{
				cout << "You can't go that way!" << endl;
			}
			break;
		default:
			cout << "Invalid choice!" << endl;


		}

		if (x == keyX && y == keyY && !hasKey) {
			cout << "There is a key here!" << endl;
			cout << "You picked up the key!" << endl;
			hasKey = true;
		}
		if (x == doorX && y == doorY) {
			if (!hasKey)
			{
				cout << "There is a door here, but it's locked!" << endl;
			}
			else
			{
				cout << "You unlocked the door!" << endl;
				isDone = true;
			}
		}
		system("cls");

	}

	cout << "You win!" << endl;

	return 0;
}