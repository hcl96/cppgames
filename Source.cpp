#include <iostream>
#include <Windows.h>
#include <conio.h>


using namespace std;
const int s=20;	//define game screen size
int a1 =s-3, a2= s/2;
int money = 0;

char world_mat[s][s];	//initialize 11x11 world matrix

void world() //populates world matrix with empty cells
{
	for (int n = 0; n < s; n++) {	
		for (int m = 0; m < s; m++)
		{
			world_mat[n][m] = ' ';
		}
	}
	world_mat[a1][a2] = 'A';	//assigns player initial position
}

void drop()	//randomly drops coins or rocks
{
	world_mat[1][rand() % 10 + 1] = '$';
	world_mat[1][rand() % 10 + 1] = 'O';
}

void disp()	//prints out the world matrix as output
{
	for (int n = 0; n < s; n++) {
		for (int m = 0; m < s; m++) {
			cout << world_mat[n][m];
			cout << " ";
		}
		cout << endl;
	}
}


void engine()	//main engine that updates the world matrix
{
	for (int n = s; n > 0; n--) {
		for (int m = 0; m < s; m++) {
			if (world_mat[n][m] != 'A' && world_mat[n - 1][m] != 'A') {	//row update cannot affect player position
				if (world_mat[a1 - 1][a2] == '$') { money++;  }	//money up
				else if (world_mat[a1 - 1][a2] == 'O') { money--; }	//money lose
				world_mat[n][m] = world_mat[n - 1][m];	//new row values takes preivous row values
			}

		}
	}
}

void main() {
	world();
	while (true) {
		system("cls");
		cout << "    Wanderer Beta   " << "Score: " << money << endl;
		disp();
		if (_kbhit()==1) { //checks if keyboard has been pressed
			char user_input = _getch();	//checks value of user input
			if (user_input == '`') {
				break;
			}
			else if (user_input == 'a') {	//checks user input and execute corresponding actions
				if (a2 - 1 != -1) {	//checks player stays within boundary
					world_mat[a1][a2 - 1] = 'A'; world_mat[a1][a2] = ' '; a2--; //moves player to left
				}
			}
			else if (user_input == 'd') {
				if (a2 + 1 != s) {
					world_mat[a1][a2 + 1] = 'A'; world_mat[a1][a2] = ' '; a2++;
				}
			}
			
		}
		drop();
		engine();
		cout << endl; cout << "w:up s:down a:left d:right `:exit" << endl;
		Sleep(300);	//delay

	}
}













//NOTES:


/*
int main()
{
	world();
	//disp();
	while (true) {
		cout << "Wanderer Beta" << endl;
		disp();
		if (_kbhit()) {
			char user_input = _getch();
			system("CLS");
			if (user_input == '`') {
				break;
			}
			else if (user_input == 'a') {	//checks user input and execute corresponding actions
				if (a2 - 1 != -1) {	//checks player stays within boundary
					world_mat[a1][a2 - 1] = world_mat[a1][a2]; world_mat[a1][a2] = ' '; a2--;
				}
			}
			else if (user_input == 'd') {
				if (a2 + 1 != 10) {
					world_mat[a1][a2 + 1] = world_mat[a1][a2]; world_mat[a1][a2] = ' '; a2++;
				}
			}
			else if (user_input == 's') {
				if (a1 + 1 != 10) {
					world_mat[a1 + 1][a2] = world_mat[a1][a2]; world_mat[a1][a2] = ' '; a1++;
				}
			}
			else if (user_input == 'w') {
				if (a1 - 1 != -1) {
					world_mat[a1 - 1][a2] = world_mat[a1][a2]; world_mat[a1][a2] = ' '; a1--;
				}
			}
			engine();
		}
		else {
			engine();
		}
		
		disp();
		Sleep(10);
	
	}
	return 0;
}




int main()
{
	while (1)
	{
		cout << "Enter a key: " << endl;
		char key = _getch();
		cout << key;
		system("Pause");
		if (key == '`') {
			break;
		}
		else {
			switch (key) {
			case 'a': cout << '.';
			case 'w': cout << 'w';
			}
		}
	}
	//system("Pause");
	return 0;

}

*/