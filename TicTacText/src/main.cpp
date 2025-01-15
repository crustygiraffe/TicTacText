//libraries
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

//the tic-tac-toe board is an array of characters
std::string board[] = { " * ", " | ", " * ", " | ", " * ", " - ", " - ", " - ", " - ", " - ", " * ", " | ", " * ", " | ", " * ", " - ", " - ", " - ", " - ", " - ", " * ", " | ", " * ", " | ", " * ", };

//global variables
std::string ans = "0";
int point = NULL;
int ansR = 0;
int ansC = 0;
bool gameRunning = true;
bool playingGame = true;
bool turnO = true;
bool ansRt = false;
bool ansCt = false;
bool Owin = false;
bool Xwin = false;
bool sfx = true;
bool Ofirst = true;
bool mainMenu = true;
bool optionsMenu = false;
bool pointCheck = true;

//converts answers to location of a character in array
int GetLocation(int row, int column)
{
	int point = 0;
	if (row == 1)
	{
		if (column == 1)
			point = 1;
		if (column == 2)
			point = 3;
		if (column == 3)
			point = 5;
	}
	else if (row == 2)
	{
		if (column == 1)
			point = 11;
		if (column == 2)
			point = 13;
		if (column == 3)
			point = 15;
	}
	else if (row == 3)
	{
		if (column == 1)
			point = 21;
		if (column == 2)
			point = 23;
		if (column == 3)
			point = 25;
	}
	return point;
}

//Checks every win condition
//Returns if someone won, sets Xwin or Owin to true
bool Checkwin(std::string mboard[])
{
	if ((board[0] == " X " && board[2] == " X " && board[4] == " X ")
		|| (board[10] == " X " && board[12] == " X " && board[14] == " X ")
		|| (board[20] == " X " && board[22] == " X " && board[24] == " X ")
		|| (board[0] == " X " && board[10] == " X " && board[20] == " X ")
		|| (board[2] == " X " && board[12] == " X " && board[22] == " X ")
		|| (board[4] == " X " && board[14] == " X " && board[24] == " X ")
		|| (board[0] == " X " && board[12] == " X " && board[24] == " X ")
		|| (board[4] == " X " && board[12] == " X " && board[20] == " X "))
		Xwin = true;
	else if ((board[0] == " O " && board[2] == " O " && board[4] == " O ")
		|| (board[10] == " O " && board[12] == " O " && board[14] == " O ")
		|| (board[20] == " O " && board[22] == " O " && board[24] == " O ")
		|| (board[0] == " O " && board[10] == " O " && board[20] == " O ")
		|| (board[2] == " O " && board[12] == " O " && board[22] == " O ")
		|| (board[4] == " O " && board[14] == " O " && board[24] == " O ")
		|| (board[0] == " O " && board[12] == " O " && board[24] == " O ")
		|| (board[4] == " O " && board[12] == " O " && board[20] == " O "))
		Owin = true;
	if (Xwin == true || Owin == true)
		return true;
	else
		return false;
}

//for adding text color
HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
	//loops whole program
	while(gameRunning)
	{
	//main menu, start of program
		do
		{
			std::cout << "********************************************************************************************************************************\n";
			std::cout << "********************************************************************************************************************************\n";
			std::cout << "**********************************************************Tic Tac Text**********************************************************\n";
			std::cout << "********************************************************************************************************************************\n";
			std::cout << "********************************************************************************************************************************\n\n";
			std::cout << "Type anything to start, or type menu to see the options menu\n";
			std::cin >> ans;
			if (ans == "menu")
			{
				optionsMenu = true;
				do
				{
					system("cls");
					std::cout << "OPTIONS\n\n";
					std::cout << "SFX: ";
					if (sfx == true)
						std::cout << "ON\n\n";
					else if (sfx == false)
						std::cout << "OFF\n\n";
					std::cout << "O Starts: ";
					if (Ofirst == true)
						std::cout << "ON\n\n";
					else if (Ofirst == false)
						std::cout << "OFF\n\n";
					std::cout << "Type sfx to toggle sfx, o to toggle o starting, or E to go back.\n";
					std::cin >> ans;
					//change settings
					if (ans == "sfx")
						sfx = !sfx;
					else if (ans == "o")
					{
						turnO = !turnO;
						Ofirst = !Ofirst;
					}
					else
					{
						optionsMenu = false;
						system("cls");
						break;
					}
				} while (optionsMenu);
			}
			else
			{
				mainMenu = false;
				break;
			}
		} while (mainMenu);
	if (sfx)
		PlaySound(TEXT("sounds/start.wav"), NULL, SND_FILENAME | SND_ASYNC);
		system("cls");
		//main game loop
		while (playingGame)
		{
			if (Checkwin(board))
				break;
			//prints board
			for (int x = 0; x < 25; x++)
			{
				if (x == 5 || x == 10 || x == 15 || x == 20 || x == 25)
				{
					std::cout << "\n";
				}
				if (board[x] == " O ")
				{
					//text colors
					SetConsoleTextAttribute(hconsole, FOREGROUND_BLUE | FOREGROUND_GREEN);
					std::cout << board[x];
					SetConsoleTextAttribute(hconsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				}
				else if (board[x] == " X ")
				{
					SetConsoleTextAttribute(hconsole, FOREGROUND_RED);
					std::cout << board[x];
					SetConsoleTextAttribute(hconsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				}
				else
				{
					std::cout << board[x];
				}
			}
			while (pointCheck)
			{
				while (ansRt == false)
				{
					std::cout << "\nType in row:\n";
					std::cin >> ansR;
					if (ansR > 3)
						std::cout << "Number is too big!";
					else
						break;
				}
				while (ansCt == false)
				{
					std::cout << "\nType in column:\n";
					std::cin >> ansC;
					if (ansC > 3)
						std::cout << "Number is too big!";
					else
						break;
				}
				point = GetLocation(ansR, ansC) - 1;
				if (board[point] == " O " || board[point] == " X ")
					std::cout << "You cant place that there!";
				else
					break;
			}
			if (turnO)
				board[point] = " O ";
			else
				board[point] = " X ";
			system("cls");
			turnO = !turnO;
		}
		//win screen
		system("cls");
		if (sfx)
			PlaySound(TEXT("sounds/Tada.wav"), NULL, SND_FILENAME | SND_ASYNC);
		if (Owin)
			std::cout << "O wins!\n";
		if (Xwin)
			std::cout << "X wins!\n";
		std::cout << "\nWould you like to replay? Y/N\n";
		std::cin >> ans;
		if (ans == "Y")
		{
			for (int i = 0; i < 25; i++)
			{
				if (i == 1 || i == 3 || i == 11 || i == 13 || i == 21 || i == 23)
					board[i] = " | ";
				else if ((4 < i && i < 10) || (14 < i && i < 20))
					board[i] = " - ";
				else
					board[i] = " * ";
			}
			Owin = false;
			Xwin = false;
			if (Ofirst)
				turnO = true;
			else
				turnO = false;
		}
		else
		{
			system("cls");
			break;
		}
	}
	return 0;
}