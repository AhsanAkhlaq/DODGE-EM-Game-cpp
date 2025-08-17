#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#define WIDTH 21
#define HEIGHT 19

using namespace std;

string screen[HEIGHT][WIDTH];		//main screen made of string array
bool f_place[HEIGHT][WIDTH] = { 0 };//food place in array/screen
int speed;							//speed of game
int level;							//initial level
int lives;							// Total Lives 
int score;							//total score
char di;							//background
char col;							//columns of board
char row;							//rows of board
int i, j, road;						//location of player's car
int ei, ej, eroad;					//location of enemy's car 1
int si, sj, sroad;					//location of enemy's car 2
char mv = 'l', emv = 'r', smv = 'r';//direction of motion of all cars
int trash;							//for storing trash values like getch



/*------------------------------All functions prototype used in game------------------------------------------------------*/

void display();		    //for displaying array on screen
void board();		    //for making background display( board, road track) 
void food();			//place food on specific position ( stored in f_place ) in main array
void set_f_place();		//set the place of food
void f_eaten();			//check if food is eaten or not and increase score
void car();				//make player car for specific positions on screen in main array
void move();			//It moves the the player car anti-clockwise and also controls the input form user to chage the road 
void enemy(int& ei, int& ej, char& emv);						//make enemy car for specific positions on screen in main array
void enemy_move(int& ei, int& ej, int& eroad, char& emv);		//it moves the enemy car according to the game level
int random(int r1, int r2);										//A random function to make easy to use rand in this we have to pass only first and last number it will automatically generate random number 
void starting_place(int& ei, int& ej, int& eroad);				//it selects the starting place for enemy car 
void road_change(int& ei, int& ej, int& eroad, int pos);		//it selects the change of road of enemy car and also makes a coreect coordination and road line for enemy
bool collided();				//checks if car is collided and decrease the lives 
bool levelIncreaser();			//Increase the level, add bonus score, change the speed
void set_car();					//set the position of players car 
void second_car();				//to move second car
void input();					//to get input from user during game execution
void menu();					//for displaying menu
void startGame();				//start playing Game
void hackmenu();				//hack manu made by ahsan 
void rules();					//for displaying rules of game
void clearRoad();				//for clearing roads of game
void printHScore();				//for printing Hscore from file
void menuB();					//for diplaying menuB
void saveScore();				//for saving score to file
void menuWin();					//for displaying winning menu
void menuHScore();				//for displaying high score menu
void menuScore();				//for displaying score menu

/*-------------------------------------------Main function------------------------------------*/
int main()
{
	level = 1;
	lives = 3;
	speed = 300;
	score = 0;
	di = -50;
	col = -37;
	row = -37;
	srand(time(0));

	menu();

	exit(0);
}

/*------------------------------------ALL functions body used in game--------------------------------------*/

/// <summary>
/// this function 
/// first display background stored in char ch
/// then set cursor to top position of screen
/// then print menu of score 
/// when user hit any key this program ends
/// </summary>
void menuScore()
{

	system("color fc");
	system("cls");
	char ch = 2;
	char ch2 = 3;
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 120; j++)
		{
			cout << ch;
		}
		cout << endl;
	}

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
	cout << "\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t" << ch2 << setfill(ch2) << fixed << setw(50) << "" << ch2 << endl;
	cout << "\t\t\t\t\t" << ch2 << setfill(' ') << setw(50) << ' ' << ch2 << endl;
	cout << "\t\t\t\t\t" << ch2 << setw(50) << ' ' << ch2 << endl;
	cout << "\t\t\t\t\t" << ch2 << setw(50) << ' ' << ch2 << endl;
	cout << "\t\t\t\t\t" << ch2 << "                Score = " << setw(26) << score << ch2 << endl;
	cout << "\t\t\t\t\t" << ch2 << setw(50) << ' ' << ch2 << endl;
	cout << "\t\t\t\t\t" << ch2 << setw(50) << ' ' << ch2 << endl;
	cout << "\t\t\t\t\t" << ch2 << setfill(ch2) << setw(50) << "" << ch2 << endl;

	trash = _getch();

}
/// <summary>
/// this function 
/// first display background stored in char ch
/// then set cursor to top position of screen
/// then print menu of high score 
/// then change background color infinitely 
/// when user hit any key this program ends
/// </summary>
void menuHScore()
{

	system("color fc");
	system("cls");
	char ch = 2;
	char ch2 = 3;
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 150; j++)
		{
			cout << ch;
		}
		cout << endl;
	}

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
	cout << "\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t" << ch2 << setfill(ch2) << fixed << setw(50) << left << "" << ch2 << endl;
	cout << "\t\t\t\t\t" << ch2 << setfill(' ') << setw(50) << ' ' << ch2 << endl;
	cout << "\t\t\t\t\t" << ch2 << setw(50) << ' ' << ch2 << endl;
	cout << "\t\t\t\t\t" << ch2 << setw(50) << "                   HIGH SCORE !" << ch2 << endl;
	cout << "\t\t\t\t\t" << ch2 << setw(50) << ' ' << ch2 << endl;
	cout << "\t\t\t\t\t" << ch2 << "                Score = " << setw(26) << score << ch2 << endl;
	cout << "\t\t\t\t\t" << ch2 << setw(50) << ' ' << ch2 << endl;
	cout << "\t\t\t\t\t" << ch2 << setw(50) << ' ' << ch2 << endl;
	cout << "\t\t\t\t\t" << ch2 << setfill(ch2) << setw(50) << "" << ch2 << endl;

	while (true)
	{
		system("color ac");
		Sleep(500);
		system("color bc");
		Sleep(500);
		system("color 9c");
		Sleep(500);
		if (_kbhit())
		{
			trash = _getch();
			break;
		}
		system("color dc");
		Sleep(500);
		system("color ec");
		Sleep(500);
		system("color fc");
		Sleep(500);
		system("color bc");
		if (_kbhit())
		{
			trash = _getch();
			break;
		}

	}
}
/// <summary>
/// this function 
/// first display background stored in char ch
/// then set cursor to top position of screen
/// then print menu of winning
/// then change background color infinitely 
/// when user hit any key this program ends
/// </summary>
void menuWin()
{
	system("color cf");
	system("cls");
	char ch = 3;
	char ch2 = 2;
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 150; j++)
		{
			cout << ch;
		}
		cout << endl;
	}

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
	cout << "\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t" << ch2 << setfill(ch2) << fixed << setw(50) << left << "" << ch2 << endl;
	cout << "\t\t\t\t\t" << ch2 << setfill(' ') << setw(50) << ' ' << ch2 << endl;
	cout << "\t\t\t\t\t" << ch2 << setw(50) << ' ' << ch2 << endl;
	cout << "\t\t\t\t\t" << ch2 << setw(50) << "     You Won the game !" << ch2 << endl;
	cout << "\t\t\t\t\t" << ch2 << setw(50) << ' ' << ch2 << endl;
	cout << "\t\t\t\t\t" << ch2 << setw(50) << ' ' << ch2 << endl;
	cout << "\t\t\t\t\t" << ch2 << setw(50) << ' ' << ch2 << endl;
	cout << "\t\t\t\t\t" << ch2 << setfill(ch2) << setw(50) << ' ' << ch2 << endl;


	while (true)
	{
		system("color ac");
		Sleep(500);
		system("color bc");
		Sleep(500);
		system("color 9c");
		Sleep(500);
		if (_kbhit())
		{
			trash = _getch();
			break;
		}
		system("color dc");
		Sleep(500);
		system("color ec");
		Sleep(500);
		system("color fc");
		Sleep(500);
		system("color bc");
		if (_kbhit())
		{
			trash = _getch();
			break;
		}

	}


}
/// <summary>
/// this menu is displayed while game running 
/// it contain
///  continue
/// start new game
/// exit
/// check score
///  help
///  in continue game starts from where left
/// in new game variables are reset and again start game
/// in exit control returns to main menu
/// in check score check score function is called 
/// in help rules function called
/// </summary>
void menuB()
{
	bool run;
	char ch = 4;
	do {
		run = true;
		system("cls");
		system("color fc");
		cout << "\n\n\n\n\t\t\t" << string(48, 31) << endl;
		cout << "\t\t\t" << ch << fixed << setw(40) << setfill(' ') << left << "\t1) Start a new game" << ch << endl;
		cout << "\t\t\t" << ch << setw(40) << "\t2) See high-scores" << ch << endl;
		cout << "\t\t\t" << ch << setw(40) << "\t3) Help" << ch << endl;
		cout << "\t\t\t" << ch << setw(40) << "\t4) Exit" << ch << endl;
		cout << "\t\t\t" << ch << setw(40) << "\t5) Continue" << ch << endl;
		cout << "\t\t\t" << string(48, 30) << endl;

		switch (_getch())
		{
		case '1':
		{
			level = 1;
			lives = 3;
			speed = 300;
			score = 0;
			system("cls");
			startGame();
			break;
		}
		case '2':
		{
			printHScore();
			break;
		}
		case '3':
		{
			rules();
			break;
		}
		case '4':
		{
			saveScore();
			main();
			break;
		}
		case '5':
		{
			system("cls");
			for (int j = 0; j < 6000; j++)
			{

				cout << di;
			}
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
			cout << "\n\n\n\t\tSCORE = " << score << "\t\t\tLEVEL " << level << "\t\t\tLIVES = " << lives << endl;
			run = false;
			break;
		}
		case 'a':
		{
			if (_getch() == 'h')
			{
				if (_getch() == 's')
				{
					if (_getch() == 'a')
					{
						if (_getch() == 'n')
						{
							hackmenu();
						}

					}

				}

			}
			break;
		}
		default:
		{
			cout << "\n\n\n\t\t\tWrong Input";
		}

		}
		if (!run)
		{
			return;
		}
	} while (run);

}
/// <summary>
/// menu to hack game only develper can acess
/// </summary>
void hackmenu()
{
	system("cls");
	char ch = 4;
	cout << "\t\t\t" << ch << fixed << setw(40) << left << "\tHack menu" << ch << endl;
	cout << "\n\n\n\n\t\t\t" << string(48, 31) << endl;
	cout << "\t\t\t" << ch << fixed << setw(40) << left << "\t1) Change level" << ch << endl;
	cout << "\t\t\t" << ch << setw(40) << "\t2)  Change live" << ch << endl;
	cout << "\t\t\t" << ch << setw(40) << "\t3)  Change speed" << ch << endl;
	cout << "\t\t\t" << ch << setw(40) << "\t4)  Change score" << ch << endl;
	cout << "\t\t\t" << string(48, 30) << endl;

	switch (_getch())
	{
	case '1':
	{
		cout << "\n\n\n\t\t\tEnter level between 1-4 :";
		cin >> level;
		break;
	}
	case '2':
	{
		cout << "\n\n\n\t\t\tEnter lives of car :";
		cin >> lives;
		break;
	}
	case '3':
	{
		cout << "\n\n\n\t\tEnter speed how much you want to slow in milli seconds :";
		cin >> speed;
		break;
	}
	case '4':
	{
		cout << "\n\n\n\t\t\tEnter score of car :";
		cin >> score;
		break;
	}
	}
}
/// <summary>
/// this is main code that controls execution of game 
/// it runs the whole game
/// </summary>
void startGame()
{
	set_car();
	bool gameOver = false;


	for (int j = 0; j < 6000; j++)
	{

		cout << di;
	}
	set_f_place();
	starting_place(ei, ej, eroad);
	starting_place(si, sj, sroad);
	board();
	while (!gameOver)
	{

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
		cout << "\n\n\n\t\tSCORE = " << score << "\t\t\tLEVEL " << level << "\t\t\tLIVES = " << lives << endl;
		clearRoad();
		for (int s = 0; s < 100; s++)
		{
			input();
		}
		move();
		gameOver = collided();
		enemy_move(ei, ej, eroad, emv);
		if (level == 4)
		{
			second_car();
		}

		f_eaten();
		food();
		car();
		enemy(ei, ej, emv);
		if (level == 4)
		{
			enemy(si, sj, smv);
		}
		display();
		if (levelIncreaser())
		{
			set_f_place();
			set_car();
			starting_place(ei, ej, eroad);
		}

		Sleep(speed);

	}
	saveScore();


}
/// <summary>
/// this main meneu
/// it contain
/// start new game
/// exit
/// check score
///  help
/// in new game variables are reset and again start game
/// in exit control returns to main funtion and exit from program
/// in check score check score function is called 
/// in help rules function called
/// </summary>
void menu()
{
	bool run;
	char ch = 4;
	do {
		run = true;
		system("cls");
		system("color fc");
		cout << "\n\n\n\n\t\t\t" << setfill(' ') << string(48, 31) << endl;
		cout << "\t\t\t" << ch << fixed << setw(40) << left << "\t1) Start a new game" << ch << endl;
		cout << "\t\t\t" << ch << setw(40) << "\t2) See high-scores" << ch << endl;
		cout << "\t\t\t" << ch << setw(40) << "\t3) Help" << ch << endl;
		cout << "\t\t\t" << ch << setw(40) << "\t4) Exit" << ch << endl;
		cout << "\t\t\t" << string(48, 30) << endl;

		switch (_getch())
		{
		case '1':
		{

			level = 1;
			lives = 3;
			speed = 300;
			score = 0;
			system("cls");
			startGame();
			break;
		}
		case '2':
		{
			printHScore();
			break;
		}
		case '3':
		{
			rules();
			break;
		}
		case '4':
		{
			run = false;
			break;
		}
		case 'a':
		{
			if (_getch() == 'h')
			{
				if (_getch() == 's')
				{
					if (_getch() == 'a')
					{
						if (_getch() == 'n')
						{
							hackmenu();
						}

					}

				}

			}
			break;
		}
		default:
		{
			cout << "\n\n\n\t\t\tWrong Input";
		}

		}
		if (!run)
		{
			return;
		}
	} while (run);
}
/// <summary>
/// it prints high score from file in order
/// </summary>
void printHScore()
{
	ifstream fin("HighScore.txt");
	if (fin.is_open())
	{
		system("cls");
		string text = " HIGH SCORES ";
		for (int j = 0; j < 1000; j++)
		{
			cout << text;
		}
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
		cout << "\n\n\n\n";
		char ch = 4;
		int num;
		cout << "\t\t\t\t\t" << setfill(ch) << fixed << setw(17) << left << "" << endl;
		cout << setfill(' ');
		cout << "\t\t\t\t\t" << ch << setw(15) << "" << ch << endl;
		for (int i = 1; i <= 10; i++)
		{
			fin >> num;
			cout << "\t\t\t\t\t" << ch << setw(3) << right << i << ")  " << left << setw(9) << num << ch << endl;
			cout << "\t\t\t\t\t" << ch << setw(15) << "" << ch << endl;
		}
		cout << "\t\t\t\t\t" << setfill(ch) << setw(17) << "" << endl;

		fin.close();
		trash = _getch();
	}


}
/// <summary>
/// it saves score to file in order
/// </summary>
void saveScore()
{

	int index = 11;
	int Hscore[10] = { 0 };
	ifstream fin("HighScore.txt");
	if (fin.is_open())
	{
		for (int i = 0; i < 10; i++)
		{
			fin >> Hscore[i];
		}
		fin.close();
		for (int i = 0; i < 10; i++)
		{
			if (Hscore[i] < score)
			{
				index = i;
				for (int i = 9; i > index; i--)
				{
					Hscore[i] = Hscore[i - 1];
				}
				Hscore[index] = score;
				break;
			}
		}
		ofstream fout("HighScore.txt");
		for (int i = 0; i < 10; i++)
		{
			fout << Hscore[i] << endl;
		}
		fout.close();

	}
	if (index == 0)
	{
		menuHScore();
	}
	else
	{
		menuScore();
	}

}
/// <summary>
/// it display rules with transition 
/// </summary>
void rules()
{
	char ch = -81;
	char ch2 = -82;

	system("cls");
	string text = " RULE 1 ";
	for (int j = 0; j < 2000; j++)
	{
		cout << text;
	}
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
	cout << "\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t" << ch << setfill(' ') << fixed << setw(50) << left << ' ' << ch2 << endl;
	cout << "\t\t\t" << ch << setw(50) << "     The car with two ## is your car it." << ch2 << endl;
	cout << "\t\t\t" << ch << setw(50) << "     You can only change its road at road end." << ch2 << endl;
	cout << "\t\t\t" << ch << setw(50) << ' ' << ch2 << endl;


	trash = _getch();
	system("cls");
	text = " RULE 2 ";
	for (int j = 0; j < 2000; j++)
	{
		cout << text;
	}
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
	cout << "\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t" << ch << setw(70) << ' ' << ch2 << endl;
	cout << "\t\t" << ch << setw(70) << "     You can control the car by arrow keys or W,A,S,D keys" << ch2 << endl;
	cout << "\t\t" << ch << setw(70) << "     You can increase the speed of car by pressing spacebar or z" << ch2 << endl;
	cout << "\t\t" << ch << setw(70) << "     You can also decrease the speed of car by pressing x" << ch2 << endl;
	cout << "\t\t" << ch << setw(70) << "     And can pause the game by pressing P button." << ch2 << endl;
	cout << "\t\t" << ch << setw(70) << ' ' << ch2 << endl;

	trash = _getch();
	system("cls");
	text = " RULE 3 ";
	for (int j = 0; j < 2000; j++)
	{
		cout << text;
	}
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
	cout << "\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t" << ch << setw(60) << ' ' << ch2 << endl;
	cout << "\t\t\t" << ch << setw(60) << "     Try to avoid collision with oponent car." << ch2 << endl;
	cout << "\t\t\t" << ch << setw(60) << "     In case you colide with enemy !" << ch2 << endl;
	cout << "\t\t\t" << ch << setw(60) << "     Your live will  decerese and you have only 3 lives" << ch2 << endl;
	cout << "\t\t\t" << ch << setw(60) << ' ' << ch2 << endl;


	trash = _getch();
	system("cls");
	text = " RULE 4 ";
	for (int j = 0; j < 2000; j++)
	{
		cout << text;
	}
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
	cout << "\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t" << ch << setw(80) << ' ' << ch2 << endl;
	cout << "\t\t" << ch << setw(80) << "     When you get all the gifts on screen the you will move to next level." << ch2 << endl;
	cout << "\t\t" << ch << setw(80) << "     When you collide all the screen will be refill with gifts." << ch2 << endl;
	cout << "\t\t" << ch << setw(80) << "     When you pass the level 4 you will become a winner." << ch2 << endl;
	cout << "\t\t" << ch << setw(80) << ' ' << ch2 << endl;

	trash = _getch();
	system("cls");
	text = " RULE 5 ";
	for (int j = 0; j < 2000; j++)
	{
		cout << text;
	}
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
	cout << "\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t" << ch << setw(60) << ' ' << ch2 << endl;
	cout << "\t\t\t" << ch << setw(60) << "     Stop reading rules and move toward game." << ch2 << endl;
	cout << "\t\t\t" << ch << setw(60) << ' ' << ch2 << endl;
	cout << "\t\t\t" << ch << setw(60) << "          Press any key  to get back to menu" << ch2 << endl;
	cout << "\t\t\t" << ch << setw(60) << ' ' << ch2 << endl;

	trash = _getch();
}
/// <summary>
/// it takes all inputs from user during game play
/// </summary>
void input()
{
	if (_kbhit())
	{
		char ch = _getch();
		if ((i >= (HEIGHT / 2) - 1 && i <= (HEIGHT / 2) + 1) && j < (WIDTH / 2) - 2)
		{

			switch (ch)
			{
			case 'a':
			case 75:
			{
				if (j != 1)
				{
					j -= 2;
					road--;
				}
				break;
			}

			case 'd':
			case 77:
			{
				if (j != (WIDTH / 2) - 3)
				{
					j += 2;
					road++;
				}
				break;
			}

			}

		}
		else if (i > (HEIGHT - 9) && i < (HEIGHT - 1) && j>8 && j < WIDTH - 9)
		{
			switch (ch)
			{
			case'w':
			case 72:
				if (i != (HEIGHT - 8))
				{
					road++;
					i -= 2;

				}
				break;
			case 's':
			case 80:
			{
				if (i != (HEIGHT - 2))
				{
					road--;
					i += 2;
				}
				break;
			}


			}

		}
		else if ((i >= (HEIGHT / 2) - 1 && i <= (HEIGHT / 2) + 1) && j > WIDTH - 9 && j < WIDTH - 1)
		{

			switch (ch)
			{
			case 'a':
			case 75:
			{
				if (j != WIDTH - 8)
				{
					j -= 2;
					road++;
				}
				break;
			}

			case 'd':
			case 77:
			{
				if (j != WIDTH - 2)
				{
					j += 2;
					road--;
				}
				break;
			}

			}

		}
		else if (i > 0 && i < 8 && j > 8 && j < WIDTH - 9)
		{
			switch (ch)
			{
			case'w':
			case 72:
				if (i != 1)
				{
					road--;
					i -= 2;

				}
				break;
			case 's':
			case 80:
			{
				if (i != 7)
				{
					road++;
					i += 2;
				}
				break;
			}


			}
		}

		if (ch == ' ' || ch == 'z')
		{
			if (speed != 0)
			{
				speed -= 50;
			}
		}
		else if (ch == 'x')
		{
			speed += 50;
		}
		else if (ch == 'p')
		{
			menuB();
		}



	}

}
/// <summary>
/// it display opponents second car during game level 4
/// </summary>
void second_car()
{
	enemy_move(si, sj, sroad, smv);

}
/// <summary>
/// it checks that if he has to increase the user level or not 
/// if yes it will increase the level and add 100 to score
/// </summary>
/// <returns>true is level increased false if not increased</returns>
bool levelIncreaser()
{
	bool food_E = false;
	for (int i = 0; i < HEIGHT && !food_E; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (f_place[i][j] == 1)
			{
				food_E = true;
				break;
			}

		}
	}
	if (!food_E)
	{

		score += 100;
		if (level < 4)
		{
			level++;
			return true;

		}
		else if (level == 4)
		{
			menuWin();
			return false;
		}
		else
		{
			return false;
		}

	}
	else
	{
		return false;
	}
}
/// <summary>
/// it set starting index of players car
/// </summary>
void set_car()
{
	i = 1, j = (WIDTH / 2) - 1, road = 1;
}
/// <summary>
/// it checks if car is collided or not 
/// it checks that if car index is same as his 
/// or car is in front of it means collided 
/// it will decerese one live on collision
/// </summary>
/// <returns>true if all lives ended otherwise false</returns>
bool collided()
{
	if (mv == 'l')
	{
		if (i == ei && (j == ej || (j - 1) == ej))
		{
			if (lives != 1)
			{
				cout << '\a';
				lives--;
				set_f_place();
				return false;
			}
			else
			{
				return true;
			}
		}
		else if ((level == 4))
		{
			if (i == si && (j == sj || (j - 1) == sj))
			{
				if (lives != 1)
				{
					cout << '\a';
					lives--;
					set_f_place();
					return false;
				}
				else
				{
					return true;
				}
			}
		}
	}
	else if (mv == 'r')
	{
		if (i == ei && (j == ej || (j + 1) == ej))
		{
			if (lives != 1)
			{
				cout << '\a';
				lives--;
				set_f_place();
				return false;
			}
			else
			{
				return true;
			}
		}
		else if ((level == 4))
		{
			if (i == si && (j == sj || (j + 1) == sj))
			{
				if (lives != 1)
				{
					cout << '\a';
					lives--;
					set_f_place();
					return false;
				}
				else
				{
					return true;
				}
			}
		}

	}
	else if (mv == 'u')
	{
		if ((i == ei || (i - 1) == ei) && j == ej)
		{
			if (lives != 1)
			{
				cout << '\a';
				lives--;
				set_f_place();
				return false;
			}
			else
			{
				return true;
			}
		}
		else if ((level == 4))
		{
			if ((i == si || (i - 1) == si) && j == sj)
			{
				if (lives != 1)
				{
					cout << '\a';
					lives--;
					set_f_place();
					return false;
				}
				else
				{
					return true;
				}
			}
		}

	}
	else if (mv == 'd')
	{
		if ((i == ei || (i + 1) == ei) && j == ej)
		{
			if (lives != 1)
			{
				cout << '\a';
				lives--;
				set_f_place();
				return false;
			}
			else
			{
				return true;
			}
		}
		else if ((level == 4))
		{
			if ((i == si || (i + 1) == si) && j == sj)
			{
				if (lives != 1)
				{
					cout << '\a';
					lives--;
					set_f_place();
					return false;
				}
				else
				{
					return true;
				}
			}
		}

	}

	return false;

}
/// <summary>
/// if checks if food is eaten 
/// if eaten the it will remove its place from f_place 
/// </summary>
void f_eaten()
{
	if (f_place[i][j])
	{
		score++;
		f_place[i][j] = 0;
	}
}
/// <summary>
/// it moves the player car anticlockwise in any road
/// </summary>
void move()
{
	int line = (road * 2) - 1;

	if (i == line && j > line)
	{
		j--;
		mv = 'l';
	}
	else if (j == line && i < (HEIGHT - line - 1))
	{
		i++;
		mv = 'd';
	}
	else if (i == (HEIGHT - 1 - line) && j < (WIDTH - 1 - line))
	{
		j++;
		mv = 'r';
	}
	else if (j == (WIDTH - 1 - line) && i > line)
	{
		i--;
		mv = 'u';
	}



}
/// <summary>
/// it move the enemey and at every turn it call roadchange function
/// </summary>
/// <param name="ei"> i index of opponents car</param>
/// <param name="ej">  j index of opponents car</param>
/// <param name="eroad"> enemy moving road</param>
/// <param name="emv"> enemy moving direction</param>
void enemy_move(int& ei, int& ej, int& eroad, char& emv)
{
	if (level == 1)
	{
		int active = random(0, 2);
		if (active == 1)
		{
			if (ei > 0 && ei < 8 && ej == (WIDTH / 2))
			{
				road_change(ei, ej, eroad, 1);
			}
			else if (ei > (HEIGHT - 9) && ei < (HEIGHT - 1) && ej == (WIDTH / 2))
			{
				road_change(ei, ej, eroad, 3);
			}
		}
	}
	else if (level == 2)
	{

		int active = random(0, 1);
		if (active)
		{
			if (ei > 0 && ei < 8 && ej == (WIDTH / 2))
			{
				road_change(ei, ej, eroad, 1);
			}
			else if (ei > (HEIGHT - 9) && ei < (HEIGHT - 1) && ej == (WIDTH / 2))
			{
				road_change(ei, ej, eroad, 3);
			}
			else if (ei == (HEIGHT / 2) && ej < (WIDTH / 2) - 2 && ej>0)
			{
				road_change(ei, ej, eroad, 2);
			}
			else if (ei == (HEIGHT / 2) && ej > WIDTH - 9 && ej < WIDTH - 1)
			{
				road_change(ei, ej, eroad, 4);
			}
		}

	}
	else if (level == 3 || level == 4)
	{
		if (ei > 0 && ei < 8 && ej == (WIDTH / 2))
		{
			road_change(ei, ej, eroad, 1);
		}
		else if (ei > (HEIGHT - 9) && ei < (HEIGHT - 1) && ej == (WIDTH / 2))
		{
			road_change(ei, ej, eroad, 3);
		}
		else if (ei == (HEIGHT / 2) && ej < (WIDTH / 2) - 2 && ej>0)
		{
			road_change(ei, ej, eroad, 2);
		}
		else if (ei == (HEIGHT / 2) && ej > WIDTH - 9 && ej < WIDTH - 1)
		{
			road_change(ei, ej, eroad, 4);
		}

	}

	int line = (eroad * 2) - 1;

	if (ei == line && ej < (WIDTH - 1 - line))
	{
		ej++;
		emv = 'r';
	}
	else if (ej == (WIDTH - 1 - line) && ei < (HEIGHT - line - 1))
	{
		ei++;
		emv = 'd';
	}
	else if (ei == (HEIGHT - 1 - line) && ej > line)
	{
		ej--;
		emv = 'l';
	}
	else if (ej == line && ei > line)
	{
		ei--;
		emv = 'u';
	}

}
/// <summary>
/// it makes a car for every dirction of car
/// </summary>
void car()
{
	if (mv == 'l')
	{
		screen[i][j] = "<## ";
	}
	else if (mv == 'r')
	{
		screen[i][j] = " ##>";
	}
	else if (mv == 'u')
	{
		screen[i][j] = "#^^#";
	}
	else if (mv == 'd')
	{
		screen[i][j] = "#vv#";
	}

}
/// <summary>
/// it makes the oponent car at given index for given direction
/// </summary>
/// <param name="ei"> i index of opponents car</param>
/// <param name="ej">  j index of opponents car</param>
/// <param name="emv"> enemy moving direction</param>
void enemy(int& ei, int& ej, char& emv)
{
	if (emv == 'l')
	{
		screen[ei][ej] = "-|| ";
	}
	else if (emv == 'r')
	{
		screen[ei][ej] = " ||-";
	}
	else if (emv == 'u')
	{
		screen[ei][ej] = "-/\\-";
	}
	else if (emv == 'd')
	{
		screen[ei][ej] = "-\\/-";
	}




}
/// <summary>
/// display the whole array
/// </summary>
void display()
{
	cout << string(3, '\n');
	for (int i = 0; i < HEIGHT; i++)
	{
		cout << string(8, di);
		for (int j = 0; j < WIDTH; j++)
		{
			cout << screen[i][j];
		}
		cout << endl;
	}
}
/// <summary>
/// make food in main array
/// </summary>
void food()
{
	for (int i = 1; i < HEIGHT; i += 2)
	{
		if (i != (HEIGHT / 2) && i != ((HEIGHT / 2) + 1) && i != ((HEIGHT / 2) - 1))
		{
			for (int j = 1; j < WIDTH; j += 2)
			{
				if (f_place[i][j] == 1)
				{
					screen[i][j][1] = 22;
					screen[i][j][2] = 22;


				}
			}
		}
	}

}
/// <summary>
/// clear the road of game initilize if with spaces
/// </summary>
void clearRoad()
{
	for (int n = 1; n < 8; n += 2)
	{
		for (int i = n; i < HEIGHT - n; i++)
		{
			for (int j = n; j < WIDTH - n; j++)
			{
				screen[n][j] = "    ";
				screen[HEIGHT - 1 - n][j] = "    ";
				screen[i][n] = "    ";
				screen[i][WIDTH - 1 - n] = "    ";
			}
		}
	}
}
/// <summary>
/// it make background display( board, road track)
/// </summary>
void board()
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			screen[i][j] = "    ";
		}
	}

	for (int n = 0; n < (HEIGHT / 2); n += 2)
	{
		for (int i = n; i < HEIGHT - n; i++)
		{
			if (i != (HEIGHT / 2) && i != ((HEIGHT / 2) + 1) && i != ((HEIGHT / 2) - 1))
			{
				for (int j = n; j < WIDTH - n; j++)
				{
					if ((j != (WIDTH / 2) && j != (WIDTH / 2) + 1 && j != (WIDTH / 2) - 1))
					{
						for (int a = 0; a < 4; a++)
						{
							//screen[n][j] = "====";
							screen[n][j][a] = row;

							//screen[HEIGHT - 1 -n][j] = "====";
							screen[HEIGHT - 1 - n][j][a] = row;

						}

						//screen[i][n] = " || ";
						screen[i][n][1] = col;
						screen[i][n][2] = col;

						//screen[i][WIDTH - 1 -n] = " || ";
						screen[i][WIDTH - 1 - n][1] = col;
						screen[i][WIDTH - 1 - n][2] = col;
					}

				}

			}
			else
			{

				screen[i][(WIDTH / 2) - 2][1] = col;
				screen[i][(WIDTH / 2) - 2][2] = col;
				screen[i][(WIDTH / 2) - 2][3] = row;
				for (int a = -1; a < 2 && i != HEIGHT / 2; a++)
				{
					//screen[i][(WIDTH / 2) - 1] = "====";
					screen[i][(WIDTH / 2) - a][0] = row;
					screen[i][(WIDTH / 2) - a][1] = row;
					screen[i][(WIDTH / 2) - a][2] = row;
					screen[i][(WIDTH / 2) - a][3] = row;
				}
				//screen[i][(WIDTH / 2) + 2] = "=|| ";
				screen[i][(WIDTH / 2) + 2][0] = row;
				screen[i][(WIDTH / 2) + 2][1] = col;
				screen[i][(WIDTH / 2) + 2][2] = col;
			}
		}

		//screen[n][n] = " ||=";
		screen[n][n][0] = ' ';
		screen[n][n][1] = col;
		screen[n][n][2] = col;
		screen[n][n][3] = row;

		//screen[HEIGHT - 1 -n][n] = " ||=";
		screen[HEIGHT - 1 - n][n][0] = ' ';
		screen[HEIGHT - 1 - n][n][1] = col;
		screen[HEIGHT - 1 - n][n][2] = col;
		screen[HEIGHT - 1 - n][n][3] = row;

		//screen[n][WIDTH - 1 -n] = "=|| ";
		screen[n][WIDTH - 1 - n][0] = row;
		screen[n][WIDTH - 1 - n][1] = col;
		screen[n][WIDTH - 1 - n][2] = col;
		screen[n][WIDTH - 1 - n][3] = ' ';

		//screen[HEIGHT - 1 -n][WIDTH - 1 -n] = "=|| ";
		screen[HEIGHT - 1 - n][WIDTH - 1 - n][0] = row;
		screen[HEIGHT - 1 - n][WIDTH - 1 - n][1] = col;
		screen[HEIGHT - 1 - n][WIDTH - 1 - n][2] = col;
		screen[HEIGHT - 1 - n][WIDTH - 1 - n][3] = ' ';

	}
}
/// <summary>
/// generate a random number between given intervals
/// </summary>
/// <param name="r1"> starting value</param>
/// <param name="r2"> last value</param>
/// <returns>a random number between given intervals</returns>
int random(int r1, int r2)
{

	return ((rand() % (r2 - r1 + 1)) + r1);
}
/// <summary>
/// set food place in f_place array to print food on specific place on screen
/// </summary>
void set_f_place()
{
	for (int i = 1; i < HEIGHT; i += 2)
	{
		if (i != (HEIGHT / 2) && i != ((HEIGHT / 2) + 1) && i != ((HEIGHT / 2) - 1))
		{
			for (int j = 1; j < WIDTH; j += 2)
			{
				if ((j != (WIDTH / 2) && j != (WIDTH / 2) + 1 && j != (WIDTH / 2) - 1))
				{
					f_place[i][j] = 1;

				}
			}
		}
	}
}
/// <summary>
/// it make a random starting place for oponents car
/// </summary>
/// <param name="ei"> refernce of i index of car </param>
/// <param name="ej"> refernce of j index of car</param>
/// <param name="eroad"> refernce of road variable of car</param>
void starting_place(int& ei, int& ej, int& eroad)
{
	eroad = random(1, 4);
	int line = (eroad * 2) - 1;
	ei = random(eroad, (10 - eroad));
	if (ei == eroad || ei == (10 - eroad))
	{
		ej = random((WIDTH - 10), (WIDTH - 1 - line));
	}
	else
	{
		ej = WIDTH - 1 - line;
	}
	ei = (ei * 2) - 1;

}
/// <summary>
/// it decides to take turn of oponents car 
/// it is based on its decisions 
/// it first decide whether to take turn or not
/// the whether to take turn nearst to player car or randomly
/// the if random then in which turn
/// </summary>
/// <param name="ei"> refernce of i index of car </param>
/// <param name="ej"> refernce of j index of car</param>
/// <param name="eroad"> refernce of road variable of car</param>
/// <param name="pos"> positoin of enemy car seted by develpor means me</param>
void road_change(int& ei, int& ej, int& eroad, int pos)
{

	if (pos == 1)
	{
		char move = 'n';
		if (random(0, 1))
		{
			move = (random(0, 1)) ? 'u' : 'd';
		}
		else
		{
			if (road > eroad)
			{
				move = 'd';
			}
			else if (road < eroad)
			{
				move = 'u';
			}

		}
		switch (move)
		{
		case'u':
		{
			if (ei != 1)
			{
				eroad--;
				ei -= 2;

			}
			break;
		}
		case 'd':
		{
			if (ei != 7)
			{
				eroad++;
				ei += 2;

			}
			break;
		}


		}

	}
	else if (pos == 2)
	{
		char move = 'n';
		if (random(0, 1))
		{
			move = (random(0, 1)) ? 'l' : 'r';
		}
		else
		{
			if (road > eroad)
			{
				move = 'r';
			}
			else if (road < eroad)
			{
				move = 'l';
			}
		}
		switch (move)
		{
		case 'l':
		{
			if (ej != 1)
			{
				ej -= 2;
				eroad--;
			}
			break;
		}

		case 'r':
		{
			if (ej != (WIDTH / 2) - 3)
			{
				ej += 2;
				eroad++;
			}
			break;
		}
		}

	}
	else if (pos == 3)
	{
		char move = 'n';
		if (random(0, 1))
		{
			move = (random(0, 1)) ? 'u' : 'd';
		}
		else
		{
			if (road > eroad)
			{
				move = 'u';
			}
			else if (road < eroad)
			{
				move = 'd';
			}
		}
		switch (move)
		{
		case'u':
		{
			if (ei != (HEIGHT - 8))
			{
				eroad++;
				ei -= 2;
			}
			break;
		}
		case 'd':
		{
			if (ei != (HEIGHT - 2))
			{
				eroad--;
				ei += 2;
			}
			break;
		}


		}

	}
	else if (pos == 4)
	{
		char move = 'n';
		if (random(0, 1))
		{
			move = (random(0, 1)) ? 'l' : 'r';
		}
		else
		{
			if (road > eroad)
			{
				move = 'l';
			}
			else if (road < eroad)
			{
				move = 'r';
			}
		}
		switch (move)
		{
		case 'l':
		{
			if (ej != WIDTH - 8)
			{
				ej -= 2;
				eroad++;
			}
			break;
		}

		case 'r':
		{
			if (ej != WIDTH - 2)
			{
				ej += 2;
				eroad--;
			}
			break;
		}

		}

	}


}