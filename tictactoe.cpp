#include<iostream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<fstream>

using namespace std;

char ArrDisplay[9] = { '0','1','2','3','4','5','6','7','8' };
ifstream scor("score.txt", ios::in);
ifstream temp("temp.txt", ios::in);

char Player1[9];
int s;
void main_menu(int& a, int& Player_1_Score, int& Player_2_Score);
void Play_Game();
void Player_1();
void Player_2();
void credits();
void instructions();
void score(int& Player_1_Score, int& Player_2_Score);
int toss(int &a);
bool wincheck(int& Player_1_Score, int& Player_2_Score);

void main_menu(int& a, int& Player_1_Score, int& Player_2_Score)
{
	int n;
	cout << endl << endl;
	cout << setw(50) << "Press 1 to Play Game\n";
	cout << setw(50) << "Press 2 for Instructions\n";
	cout << setw(50) << "Press 3 to See Score\n";
	cout << setw(50) << "Press 4 for Credits\n";

	cout << setw(50) << "Press 5 to Exit\n";
	cout << endl;
	cout << setw(50) << "Select Your Choice:";
	cin >> n;

	switch (n)
	{
	case 1:
	{
		toss(a);
		if (a == 1)
		{
			bool flag = true;
			while (flag)
			{
				Player_1();
				Play_Game();
				if (wincheck(Player_1_Score, Player_2_Score))
				{
					break;
				}
				Player_2();
				Play_Game();
				if (wincheck(Player_1_Score, Player_2_Score))
				{
					break;
				}
			}
		}

		else if (a == 2)
		{

			bool flag = true;
			while (flag)
			{

				Player_2();
				Play_Game();
				if (wincheck(Player_1_Score, Player_2_Score))
				{
					break;
				}
				Player_1();
				Play_Game();
				if (wincheck(Player_1_Score, Player_2_Score))
				{
					break;
				}
			}
		}
	}
		break;
	case 2:
	{
		instructions();
	//	system("cls");
		return main_menu(a, Player_1_Score, Player_2_Score);
	}
		break;
	case 3:
	{
		 score(Player_1_Score, Player_2_Score);
		// system("cls");
		 return main_menu(a, Player_1_Score, Player_2_Score);
	}
		break;
	case 4:
	{
		credits();
	//	system("cls");
		return main_menu(a, Player_1_Score, Player_2_Score);
	}
		break;
	case 5:
	{
		cout << "Thanks! for coming ... Will se you next time :)\n\n";
		exit(0);
	}	
		break;
	default:
		system("cls");
		cout << "Error 404!!!\nWrong Choice Try Again :) \n";
		main_menu(a,Player_1_Score,Player_2_Score);	
	break;
	}
}

void credits()
{
	system("cls");
	cout << setw(50) << "Developer \"ZUBAIR AHMAD\"" << endl;
	cout << setw(50) << "Made In Pakistan!!!\n";
	cout << setw(60) << "All Copyrights are Reserved by T4Tech (Pvt) Limited" << endl << endl;
}

void instructions()
{
	system("cls");
	cout << setw(50) << "Read Carefully." << endl;
	cout << setw(50) << "Both The Players Will be Assigned a Unique Symbol." << endl;
	cout << setw(70) << "Both the Players Will Have Equal Chances of Making there Move.\n";
	cout << setw(50) << "The Game will Continue Untill The Final Result Came." << endl;
	cout << setw(50) << "Play Wisely";
}

int toss(int &a)
{
	system("cls");
	
	a =rand() % 2 + 1;
	if (a == 1)
	{
		cout << "Congratulations Player 1 You Have Won The TOSS" << endl;
		cout << "\nPlayer 1 Your Symbol is [O]" << endl;
		cout << "\nPlayer 2 Your Symbol is [X]" << endl << endl << endl;
		cout << "\t\t\t" << ArrDisplay[0] << "         |" << ArrDisplay[1] << "             |" << ArrDisplay[2] << "\n";
		cout << "\t\t\t..........|..............|..........\n";
		cout << "\t\t\t" << ArrDisplay[3] << "         |" << ArrDisplay[4] << "             |" << ArrDisplay[5] << "\n";
		cout << "\t\t\t..........|..............|..........\n";
		cout << "\t\t\t" << ArrDisplay[6] << "         |" << ArrDisplay[7] << "             |" << ArrDisplay[8] << "\n";
		cout << "\t\t\t..........|..............|..........\n";
		cout << "\t\t\t          |              |          \n";
		cout << endl << endl;
	}
	else if (a == 2)
	{
		cout << "Congratulations Player 2 You Have Won The TOSS" << endl;
		cout << "\nPlayer 1 Your Symbol is [O]" << endl;
		cout << "\nPlayer 2 Your Symbol is [X]" << endl << endl << endl;
		cout << "\t\t\t" << ArrDisplay[0] << "         |" << ArrDisplay[1] << "             |" << ArrDisplay[2] << "\n";
		cout << "\t\t\t..........|..............|..........\n";
		cout << "\t\t\t" << ArrDisplay[3] << "         |" << ArrDisplay[4] << "             |" << ArrDisplay[5] << "\n";
		cout << "\t\t\t..........|..............|..........\n";
		cout << "\t\t\t" << ArrDisplay[6] << "         |" << ArrDisplay[7] << "             |" << ArrDisplay[8] << "\n";
		cout << "\t\t\t..........|..............|..........\n";
		cout << "\t\t\t          |              |          \n";
		cout << endl << endl;
	}
	return a;
}

void Play_Game()
{
	cout << "\t\t\t" << ArrDisplay[0] << "         |" << ArrDisplay[1] << "             |" << ArrDisplay[2] << "\n";
	cout << "\t\t\t..........|..............|..........\n";
	cout << "\t\t\t" << ArrDisplay[3] << "         |" << ArrDisplay[4] << "             |" << ArrDisplay[5] << "\n";
	cout << "\t\t\t..........|..............|..........\n";
	cout << "\t\t\t" << ArrDisplay[6] << "         |" << ArrDisplay[7] << "             |" << ArrDisplay[8] << "\n";
	cout << "\t\t\t..........|..............|..........\n";
	cout << "\t\t\t          |              |          \n";
}

void Player_1()
{
	char I;
	cout << "Player 1 Your Trun Now Make a Wise Move: ";
	cin >> I;
	system("cls");
	Player1[I] = I;
	switch (I)
	{
	case'0':

		if ((Player1[I] == '0') && (ArrDisplay[0] == '0'))
		{
			ArrDisplay[0] = 'O';
		}
		else
		{
			cout << "The Spot Was Already in Occupation You Miss Your Chance\n\n";
		}
		break;
	case'1':

		if ((Player1[I] == '1') && (ArrDisplay[1] == '1'))
		{
			ArrDisplay[1] = 'O';
		}
		else
		{
			cout << "The Spot Was Already in Occupation You Miss Your Chance\n\n";
		}
		break;
	case'2':

		if ((Player1[I] == '2') && (ArrDisplay[2] == '2'))
		{
			ArrDisplay[2] = 'O';
		}
		else
		{
			cout << "The Spot Was Already in Occupation You Miss Your Chance\n\n";
		}
		break;
	case'3':

		if ((Player1[I] == '3') && (ArrDisplay[3] == '3'))
		{
			ArrDisplay[3] = 'O';
		}
		else
		{
			cout << "The Spot Was Already in Occupation You Miss Your Chance\n\n";
		}
		break;
	case'4':

		if ((Player1[I] == '4') && (ArrDisplay[4] == '4'))
		{
			ArrDisplay[4] = 'O';
		}
		else
		{
			cout << "The Spot Was Already in Occupation You Miss Your Chance\n\n";
		}
		break;
	case'5':

		if ((Player1[I] == '5') && (ArrDisplay[5] == '5'))
		{
			ArrDisplay[5] = 'O';
		}
		else
		{
			cout << "The Spot Was Already in Occupation You Miss Your Chance\n\n";
		}
		break;
	case'6':

		if ((Player1[I] == '6') && (ArrDisplay[6] == '6'))
		{
			ArrDisplay[6] = 'O';
		}
		else
		{
			cout << "The Spot Was Already in Occupation You Miss Your Chance\n\n";
		}
		break;
	case'7':

		if ((Player1[I] == '7') && (ArrDisplay[7] == '7'))
		{
			ArrDisplay[7] = 'O';
		}
		else
		{
			cout << "The Spot Was Already in Occupation You Miss Your Chance\n\n";
		}
		break;
	case'8':

		if ((Player1[I] == '8') && (ArrDisplay[8] == '8'))
		{
			ArrDisplay[8] = 'O';
		}
		else
		{
			cout << "The Spot Was Already in Occupation You Miss Your Chance\n\n";
		}
		break;

	default:
		cout << "The Spot Where You Wanted to Make Your Move Does Not Exist.\n\n";
		break;
	}
}

void Player_2()
{
	char J;
	cout << "Player 2 Your Trun Now Make a Wise Move: ";
	cin >> J;
	system("cls");
	Player1[J] = J;
	switch (J)
	{
	case'0':

		if ((Player1[J] == '0') && (ArrDisplay[0] == '0'))
		{
			ArrDisplay[0] = 'X';
		}
		else
		{
			cout << "The Spot Was Already in Occupation You Miss Your Chance\n\n";
		}
		break;
	case'1':
		
		if ((Player1[J] == '1') && (ArrDisplay[1] == '1'))
		{
			ArrDisplay[1] = 'X';
		}
		else
		{
			cout << "The Spot Was Already in Occupation You Miss Your Chance\n\n";
		}
		break;
	case'2':
	
		if ((Player1[J] == '2') && (ArrDisplay[2] == '2'))
		{
			ArrDisplay[2] = 'X';
		}
		else
		{
			cout << "The Spot Was Already in Occupation You Miss Your Chance\n\n";
		}
		break;
	case'3':

		if ((Player1[J] == '3') && (ArrDisplay[3] == '3'))
		{
			ArrDisplay[3] = 'X';
		}
		else
		{
			cout << "The Spot Was Already in Occupation You Miss Your Chance\n\n";
		}
		break;
	case'4':

		if ((Player1[J] == '4') && (ArrDisplay[4] == '4'))
		{
			ArrDisplay[4] = 'X';
		}
		else
		{
			cout << "The Spot Was Already in Occupation You Miss Your Chance\n\n";
		}
		break;
	case'5':

		if ((Player1[J] == '5') && (ArrDisplay[5] == '5'))
		{
			ArrDisplay[5] = 'X';
		}
		else
		{
			cout << "The Spot Was Already in Occupation You Miss Your Chance\n\n";
		}
		break;
	case'6':

		if ((Player1[J] == '6') && (ArrDisplay[6] == '6'))
		{
			ArrDisplay[6] = 'X';
		}
		else
		{
			cout << "The Spot Was Already in Occupation You Miss Your Chance\n\n";
		}
		break;
	case'7':

		if ((Player1[J] == '7') && (ArrDisplay[7] == '7'))
		{
			ArrDisplay[7] = 'X';
		}
		else
		{
			cout << "The Spot Was Already in Occupation You Miss Your Chance\n\n";
		}
		break;
	case'8':

		if ((Player1[J] == '8') && (ArrDisplay[8] == '8'))
		{
			ArrDisplay[8] = 'X';
		}
		else
		{
			cout << "The Spot Was Already in Occupation You Miss Your Chance\n\n";
		}
		break;
	default:
		cout << "The Spot Where You Wanted to Make Your Move Does Not Exist.\n\n";
		break;
	}
}

bool wincheck(int& Player_1_Score, int& Player_2_Score)
{

	if ((ArrDisplay[0] == 'O') && (ArrDisplay[1] == 'O') && (ArrDisplay[2] == 'O') || (ArrDisplay[3] == 'O') && (ArrDisplay[4] == 'O') && (ArrDisplay[5] == 'O') || (ArrDisplay[6] == 'O') && (ArrDisplay[7] == 'O') && (ArrDisplay[8] == 'O')
		|| (ArrDisplay[0] == 'O') && (ArrDisplay[3] == 'O') && (ArrDisplay[6] == 'O') || (ArrDisplay[1] == 'O') && (ArrDisplay[4] == 'O') && (ArrDisplay[7] == 'O')
		|| (ArrDisplay[2] == 'O') && (ArrDisplay[5] == 'O') && (ArrDisplay[8] == 'O') || (ArrDisplay[2] == 'O') && (ArrDisplay[4] == 'O') && (ArrDisplay[6] == 'O')
		|| (ArrDisplay[0] == 'O') && (ArrDisplay[4] == 'O') && (ArrDisplay[8] == 'O'))
	{
		cout << "Congratulations!!! Player ONE You Have WON The Game.\n\n";
		s = Player_1_Score++;
		return true;
	}
	else if ((ArrDisplay[0] == 'X') && (ArrDisplay[1] == 'X') && (ArrDisplay[2] == 'X') || (ArrDisplay[3] == 'X') && (ArrDisplay[4] == 'X') && (ArrDisplay[5] == 'X') || (ArrDisplay[6] == 'X') && (ArrDisplay[7] == 'X') && (ArrDisplay[8] == 'X')
				|| (ArrDisplay[0] == 'X') && (ArrDisplay[3] == 'X') && (ArrDisplay[6] == 'X') || (ArrDisplay[1] == 'X') && (ArrDisplay[4] == 'X') && (ArrDisplay[7] == 'X')
				|| (ArrDisplay[2] == 'X') && (ArrDisplay[5] == 'X') && (ArrDisplay[8] == 'X') || (ArrDisplay[2] == 'X') && (ArrDisplay[4] == 'X') && (ArrDisplay[6] == 'X')
				|| (ArrDisplay[0] == 'X') && (ArrDisplay[4] == 'X') && (ArrDisplay[8] == 'X'))
	{
		cout << "Congratulations!!! Player TWO You Have WON The Game.\n\n";
		s = Player_2_Score++;
		return true;
	}
	else if (ArrDisplay[0] != '0' && ArrDisplay[1] != '1' && ArrDisplay[2] != '2' && ArrDisplay[3] != '3' && ArrDisplay[4] != '4' && ArrDisplay[5] != '5' && ArrDisplay[6] != '6' && ArrDisplay[7] != '7' && ArrDisplay[8] != '8')
	{
		cout << "Sed!!! It's A Draw ;-;\n\n";
		return true;
	}
	return false;
}

void score(int& Player_1_Score, int& Player_2_Score)
{
	system("cls");
	string SCORE, PLAYER;
	ifstream fout("score.txt");
	while (!fout.eof())
	{
		getline(fout, PLAYER);
		getline(fout, SCORE);
		if (!fout.eof())
			cout << setw(40) << PLAYER << setw(40) << SCORE << endl;
	}
	fout.close();
}

int main()
{
int a = 0, Player_1_Score = 0, Player_2_Score = 0;
cout << setw(50) << "WELCOME TO THE DASHBOARD\n";
string temp;
srand(time(0));
ifstream fout("score.txt");
getline(fout, temp);
fout >> Player_1_Score;
getline(fout, temp);
fout >> Player_2_Score;
fout.close();
main_menu(a, Player_1_Score, Player_2_Score);
ofstream fin("score.txt");
fin << "Player 1 Score " << endl << Player_1_Score << endl << "Player 2 Score " << endl << Player_2_Score << endl;
	return 0;
}