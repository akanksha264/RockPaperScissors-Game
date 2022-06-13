#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

char pc_choice (int);			//Convert the random number into a choice
int check_res(char , char);		//Check who won
int isinvalid(char);			//Checks for invalid choice

main ()
{
	int w = 0, l = 0, d = 0;		//Count wins , loses and draws
	int num , res;
	char c , p;
	char ch;		//User's choice to continue
	
	//Generate a random number from 0 to 2
	srand(time(0));
	
	do
	{
		system ("cls");
		cout << "\t ** ROCK , PAPER , SCISSORS **" << endl;
		cout << " -------------------------------------------------" << endl << endl;
		num = rand()%3;
		
		//Assign the number a choice (rock, paper or scissors)
		c = pc_choice(num);
		
		//Enter user's choice
		cout << "Your choice (r / p / s) ? ";
		cin >> p;
		
		//If user enters invalid choice
		if (isinvalid(p))
			cout << "Invalid choice" << endl;
			
		else
		{		
			//Check who won
			res = check_res(c , p);
			
			//Display the result
			cout << "Computer's choice = " << c << endl;
			if (res == 1)	//Player wins
			{
				cout << "You win!! \1" << endl;
				w++;	//Increase win count
			}
			else if (res == -1)	//Computer wins
			{
				cout << "Computer wins!! :-(" << endl;
				l++;	//Increase lose count
			}
			else	//Draw
			{
				cout << "Match Draw !!" << endl;
				d++;	//Increase draw count
			}
		}
		cout << endl << "Wins = " << w << endl << "Loses = " << l << endl << "Draws = " << d << endl;
		cout << endl << endl << "To continue Enter y/Y \nPress any other key to exit \nYour choice ? ";
		cin >> ch;
	}while (ch == 'y' || c == 'Y'); 
		
	//End
	return 0;
}

char pc_choice (int n)
{
	//Let 0 be rock , 1 be paper and 2 be scissors
	if (n == 0)
		return 'r';
	if (n == 1)
		return 'p';
	return 's';
}

int check_res(char c , char p)
{
	//If both picked same
	if (c == p || c == p-64)		//In case player used uppercase a;phabet
		return 0;
	
	//If computer won
	if (c == 'r' && p == 's')
		return -1;
	if (c == 's' && p == 'p')
		return -1;
	if (c == 'p' && p == 'r')
		return -1;
		
	//If player wins
	return 1;
}

int isinvalid (char c)
{
	if (c == 'r' || c == 'p' || c == 's' || c == 'R' || c == 'P' || c == 'S')
		return 0;
	return 1;
}
