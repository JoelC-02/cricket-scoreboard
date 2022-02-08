/*********************************    Cricket Scorecard Management Program Code       ***********************************/
#include <bits/stdc++.h>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <conio.h>
#include <windows.h>
using namespace std;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/***********************************    Structure to store data for each team     ****************************************/
struct Team
{
    char name[25];
    struct player
    {
        char name[20];
        int jno;
        int runs_scored;
        char wickettaker[20];
        int six;
        int four;
        int runs_conceded;
        int wickets;
        int wide;
        int noball;
        float overs;
        float economy;
        float strikerate;
        int ballsfaced;
    } B[11];

    struct innings
    {
        int runs;
        int run_rate;
        int reqrun_rate;
        int wickets;
        int overs;
        int extras;
    } I;
} T[2];

/***************************  Structure to store data for each game     ***************************/      
struct game
{
    int overs;
    char name1[20];
    char name2[20];
    char compname[25];
    char venue[25];
    int wickets;
} G;

void headingingame();

/****************************      Function for displaying the welcome page       ******************************************/
void intro()
{
    system("color 1E");
    char a[] = "C R I C K E T   S C O R E C A R D   M A N A G E M E N T   S Y S T E M ";
    gotoxy(10, 12);
    for (int f = 0; f < strlen(a); f++)
    {
        cout << a[f];
        Beep(350, 300);
        Sleep(35);
    }
    char b[] = "Presented by:";
    gotoxy(32, 20);
    for (int f = 0; f < strlen(b); f++)
    {
        cout << b[f];
        Sleep(95);
    }
    char c[] = "Joel Cecil ";
    gotoxy(32, 22);
    for (int f = 0; f < strlen(c); f++)
    {
        cout << c[f];
        Sleep(100);
    }
    char d[] = "Class: XII";
    gotoxy(32, 24);

    for (int f = 0; f < strlen(d); f++)
    {
        cout << d[f];
        Sleep(300);
    }
    gotoxy(32, 27);
    system("pause");
    system("cls");
    system("color 5B");
    gotoxy(20, 7);
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
    gotoxy(20, 8);
    cout << "*This Program Stores And Creates Scorecard For Cricket Games*";
    gotoxy(20, 9);
    cout << "*And It Performs The Following Calculations                 *";
    gotoxy(20, 10);
    cout << "*1) Strike Rate                                             *";
    gotoxy(20, 11);
    cout << "*2) Extras                                                  *";
    gotoxy(20, 12);
    cout << "*3) Runrate                                                 *";
    gotoxy(20, 13);
    cout << "*4) Required Runs                                           *";
    gotoxy(20, 14);
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
    gotoxy(20, 18);
    system("pause");
}

/**************************   Function to decide on which team will win the toss    **************************************/
void toss(int &z)
{
    srand(time(0));
    char choice[20], inntype[15];
    int ch, outcome;
    cout << G.name1 << " Enter your choice Heads or tails ";
    cin >> choice;
    if (choice == "Heads")
        ch = 1;
    else if (choice == "Tails")
        ch = 0;
    outcome = rand()%2;
    if (outcome == ch)
    {
        cout << "\n"
             << G.name1 << " wins the toss now make your choice (bat/bowl)";
        cin >> inntype;
        if (inntype == "bat")
            z = 0;
        else if (inntype == "bowl")
            z = 1;
    }
    else if (outcome != ch)
    {
        cout << "\n"
             << G.name2 << " wins the toss now make your choice (bat/bowl) ";
        cin >> inntype;
        if (inntype == "bat")
            z = 1;
        else if (inntype == "bowl")
            z = 0;
    }
}

/********************************   Function for displaying the header for batsman details.  ***************************************/
void displaycol()
{
    cout << "\nBatsman name" << setw(21) << "Runs scored" << setw(14) << "Balls faced" << setw(15) << "6s" << setw(7) << "4s"
         << "\t"
         << "Strikerate" << endl;
}

/**********************************  Function for displaying the header for bowler details    *************************************/
void displaycolforbowler()
{
    cout << "\nBowler name" << setw(21) << "Runs conceded" << setw(13) << "Overs bowled" << setw(14) << "Wickets" << setw(13) << "Economy" << setw(3) << endl;
}

/********************************** Function change the strike and display the details of the two batsmen currently batting.  **********************************/
void changestrike(int &i, int p, int q, char balltype, int z)
{
    gotoxy(1, 18);
    displaycol();
    gotoxy(1, 20);
    cout << T[z].B[i].name << " *";
    gotoxy(25, 20);
    cout << T[z].B[i].runs_scored;
    gotoxy(40, 20);
    cout << T[z].B[i].ballsfaced;
    gotoxy(61, 20);
    cout << T[z].B[i].six;
    gotoxy(69, 20);
    cout << T[z].B[i].four;
    gotoxy(73, 20);
    cout << T[z].B[i].strikerate << endl;
    /*when the runs scored is an odd number the strike changes i.e the other batsman will bat so the batting variable (i) is interchanged and both the batsman’s details are displayed*/
    if (balltype == '1' || balltype == '3' || balltype == '5')
    {
        if (i == p)
        {
            i = q;
            gotoxy(1, 22);
            cout << T[z].B[i].name;
            gotoxy(25, 22);
            cout << T[z].B[i].runs_scored;
            gotoxy(40, 22);
            cout << T[z].B[i].ballsfaced;
            gotoxy(61, 22);
            cout << T[z].B[i].six;
            gotoxy(69, 22);
            cout << T[z].B[i].four;
            gotoxy(73, 22);
            cout << T[z].B[i].strikerate << endl;
        }
        else
        {
            i = p;
            gotoxy(1, 22);
            cout << T[z].B[i].name;
            gotoxy(25, 22);
            cout << T[z].B[i].runs_scored;
            gotoxy(40, 22);
            cout << T[z].B[i].ballsfaced;
            gotoxy(61, 22);
            cout << T[z].B[i].six;
            gotoxy(69, 22);
            cout << T[z].B[i].four;
            gotoxy(73, 22);
            cout << T[z].B[i].strikerate << endl;
        }
    }
    else if (balltype == '2' || balltype == '4' || balltype == '6' || balltype == '0' || balltype == 'W' || balltype == 'w' || balltype == 'o' || 
      balltype == 'O' || balltype == 'n' || balltype == 'N')
    {
        if (i == p)
        {
            i = q;
            gotoxy(1, 22);
            cout << T[z].B[i].name;
            gotoxy(25, 22);
            cout << T[z].B[i].runs_scored;
            gotoxy(40, 22);
            cout << T[z].B[i].ballsfaced;
            gotoxy(61, 22);
            cout << T[z].B[i].six;
            gotoxy(69, 22);
            cout << T[z].B[i].four;
            gotoxy(73, 22);
            cout << T[z].B[i].strikerate << endl;
            i = p;
        }
        else
        {
            i = p;
            gotoxy(1, 22);
            cout << T[z].B[i].name;
            gotoxy(25, 22);
            cout << T[z].B[i].runs_scored;
            gotoxy(40, 22);
            cout << T[z].B[i].ballsfaced;
            gotoxy(61, 22);
            cout << T[z].B[i].six;
            gotoxy(69, 22);
            cout << T[z].B[i].four;
            gotoxy(73, 22);
            cout << T[z].B[i].strikerate << endl;
            i = q;
        }
    }
    gotoxy(0, 25);
    cout << T[z].name << "  -   " << T[z].I.runs << "/" << T[z].I.wickets << "  Extras: " << T[!z].I.extras << endl;
    getch();
}

/*******************************  Function change strike after each over and display details of batsmen currently batting *************************************/
void changestrikeover(int &i, int p, int q, int z)
{
    gotoxy(1, 8);
    displaycol();
    system("color 3E");
    gotoxy(1, 10);
    cout << T[z].B[i].name;
    gotoxy(25, 10);
    cout << T[z].B[i].runs_scored;
    gotoxy(40, 10);
    cout << T[z].B[i].ballsfaced;
    gotoxy(61, 10);
    cout << T[z].B[i].six;
    gotoxy(69, 10);
    cout << T[z].B[i].four;
    gotoxy(73, 10);
    cout << T[z].B[i].strikerate << endl;
    if (i == p)
    {
        i = q;
        gotoxy(1, 12);
        cout << T[z].B[i].name << " *";
        gotoxy(25, 12);
        cout << T[z].B[i].runs_scored;
        gotoxy(40, 12);
        cout << T[z].B[i].ballsfaced;
        gotoxy(61, 12);
        cout << T[z].B[i].six;
        gotoxy(69, 12);
        cout << T[z].B[i].four;
        gotoxy(73, 12);
        cout << T[z].B[i].strikerate << endl;
    }
    else
    {
        i = p;
        gotoxy(1, 12);
        cout << T[z].B[i].name << " *";
        gotoxy(25, 12);
        cout << T[z].B[i].runs_scored;
        gotoxy(40, 12);
        cout << T[z].B[i].ballsfaced;
        gotoxy(61, 12);
        cout << T[z].B[i].six;
        gotoxy(69, 12);
        cout << T[z].B[i].four;
        gotoxy(73, 12);
        cout << T[z].B[i].strikerate << endl;
    }
    getch();
}

/***********************************   Function to display bowler details    **************************************/
void displayb(int j, int z, int innings)
{
    gotoxy(1, 15);
    displaycolforbowler();
    gotoxy(1, 17);
    cout << T[!z].B[j].name;
    gotoxy(25, 17);
    cout << T[!z].B[j].runs_conceded;
    gotoxy(40, 17);
    cout << T[!z].B[j].overs;
    gotoxy(61, 17);
    cout << T[!z].B[j].wickets;
    gotoxy(71, 17);
    cout << T[!z].B[j].economy << endl;
    if (innings == 2 && (T[z].I.runs <= T[!z].I.runs))
    {
        cout << T[z].name << "requires " << (T[!z].I.runs - T[z].I.runs) + 1 << " runs to win " << endl;
        cout << "Required runrate: " << T[z].I.reqrun_rate << " runs per over " << endl;
    }
    getch();
}

/************************************    Function to display details of the batsman who got out and the new batsman details   **********************************/
void batsmanout(int &i, int &p, int &q, int z)
{
    cout << T[z].B[i].name << " Got out by " << T[z].B[i].wickettaker;
    displaycol();
    gotoxy(1, 15);
    cout << T[z].B[i].name;
    gotoxy(25, 15);
    cout << T[z].B[i].runs_scored;
    gotoxy(40, 15);
    cout << T[z].B[i].ballsfaced;
    gotoxy(61, 15);
    cout << T[z].B[i].six;
    gotoxy(69, 15);
    cout << T[z].B[i].four;
    gotoxy(73, 15);
    cout << T[z].B[i].strikerate << endl;
    if (T[z].I.wickets < G.wickets)
    {
        if (i == p && p < q)
        {
            p = q + 1;
            i = p;
        }
        else if (i == p && q < p)
        {
            p = p + 1;
            i = p;
        }
        else if (i == q && p < q)
        {
            q = q + 1;
            i = q;
        }
        else if (i == q && p > q)
        {
            q = p + 1;
            i = q;
        }
        cout << "\n New Batsman in: " << T[z].B[i].name << endl;
        getch();
    }
    else
    {
        system("cls");
        system("color 3E");
        headingingame();
        cout << "INNINGS OVER" << endl;
        displaycol();
        gotoxy(1, 15);
        cout << T[z].B[i].name;
        gotoxy(25, 15);
        cout << T[z].B[i].runs_scored;
        gotoxy(40, 15);
        cout << T[z].B[i].ballsfaced;
        gotoxy(61, 15);
        cout << T[z].B[i].six;
        gotoxy(69, 15);
        cout << T[z].B[i].four;
        gotoxy(73, 15);
        cout << T[z].B[i].strikerate << endl;
        if (i == p)
        {
            i = q;
            gotoxy(1, 17);
            cout << T[z].B[i].name;
            gotoxy(25, 17);
            cout << T[z].B[i].runs_scored;
            gotoxy(40, 17);
            cout << T[z].B[i].ballsfaced;
            gotoxy(61, 17);
            cout << T[z].B[i].six;
            gotoxy(69, 17);
            cout << T[z].B[i].four;
            gotoxy(73, 17);
            cout << T[z].B[i].strikerate << endl;
        }
        else
        {
            i = p;
            gotoxy(1, 17);
            cout << T[z].B[i].name;
            gotoxy(25, 17);
            cout << T[z].B[i].runs_scored;
            gotoxy(40, 17);
            cout << T[z].B[i].ballsfaced;
            gotoxy(61, 17);
            cout << T[z].B[i].six;
            gotoxy(69, 17);
            cout << T[z].B[i].four;
            gotoxy(73, 17);
            cout << T[z].B[i].strikerate << endl;
        }
        getch();
    }
}

/********************************  Function for performing file operations  ********************************/
void filing(char fname[50])
{
    char fname1[50] = "team1", fname2[50] = "team2";
    strcat(fname1, fname);
    strcat(fname2, fname);
    ofstream gamefile(fname, ios::binary);
    ofstream team1file(fname1, ios::binary);
    ofstream team2file(fname2, ios::binary);
    gamefile.write((char *)&G, sizeof(G));
    team1file.write((char *)&T[0], sizeof(T[0]));
    team2file.write((char *)&T[1], sizeof(T[1]));
    gamefile.close();
    team1file.close();
    team2file.close();
}

/****************************       Function to display the competition name, venue and the name of the two teams.  **********************************************/
void headingingame()
{
    cout << "\n"
         << setw(30) << "COMPETITION NAME: " << setw(3) << G.compname;
    cout << "\n"
         << setw(40) << "\n AT " << setw(5) << G.venue;
    cout << "\n"
         << setw(25) << G.name1 << setw(2) << " vs " << setw(2) << G.name2;
    cout << "\n------------------------------------------------------------------------------------------------------------------------" << endl;
}

void heading(char fname[50])
{
    ifstream gamefile(fname, ios::binary);
    while (gamefile.read((char *)&G, sizeof(G)))
    {
        cout << "\n"
             << setw(30) << "COMPETITION NAME: " << setw(3) << G.compname;
        cout << "\n"
             << setw(40) << "\n AT " << setw(5) << G.venue;
        cout << "\n"
             << setw(25) << G.name1 << setw(2) << " vs " << setw(2) << G.name2;
        cout << "\n------------------------------------------------------------------------------------------------------------------------" << endl;
    }
    gamefile.close();
}

/**************************      Function to input the data from the user        **********************************************/
void input()
{
    int i, j, p, q, ballno, innings, bno, z = 0, flag = 0, l;
    char balltype, btype[2], fname[20];
    cout << "Enter the filename: ";
    gets(fname);
    system("cls");
    system("color 3E");
    headingingame();
    cout << "\n Enter the Competition Name: ";
    gets(G.compname);
    cout << "\n Enter the Venue: ";
    gets(G.venue);
    cout << "\n Enter the number of overs in an innings: ";
    cin >> G.overs;
    cout << "\n Enter the number of players in a team: ";
    cin >> G.wickets;
    G.wickets -= 1;
    system("cls");
    system("color 3E");
    headingingame();
    cout << "\n Enter name of team 1 : ";
    gets(T[z].name);
    strcat(G.name1, T[z].name);
    cout << "\n\n Enter name of players in team according to order of batting: " << endl;
    for (int k = 0; k <= G.wickets; k++)
    {
        cout << "Player " << (k + 1) << ":";
        gets(T[z].B[k].name);
        cout << "  Jersey Number: ";
        cin >> (T[z].B[k].jno);
        cout << endl;
    }
    system("cls");
    system("color 3E");
    headingingame();
    cout << "\n Enter name of team 2: ";
    gets(T[!z].name);
    strcat(G.name2, T[!z].name);
    cout << "\n\n Enter name of players in team according to order of batting: " << endl;
    for (int k = 0; k <= G.wickets; k++)
    {
        cout << "Player " << (k + 1) << ":";
        gets(T[!z].B[k].name);
        cout << "  Jersey Number: ";
        cin >> (T[!z].B[k].jno);
        cout << endl;
    }
    toss(z);

    /********************************        Match begins            ***************************************/
    for (innings = 1; innings <= 2; innings++, z = !z)
    {
        p = 0;
        q = 1;
        i = p;
        system("cls");
        system("color 3E");
        headingingame();
        if (innings == 1)
            cout << "\n First innings";
        else if (innings == 2)
        {
            cout << "\n Second innings" << endl;
            if (z == 1)
                cout << G.name2 << " needs " << T[!z].I.runs + 1 << " Runs to win .";
            else if (z == 0)
                cout << G.name1 << " needs " << T[!z].I.runs + 1 << " Runs to win .";
        }
        while ((T[z].I.overs < G.overs) && (T[z].I.wickets < G.wickets))
        {
            cout << "\n Enter bowler number: ";
            cin >> bno;
            cout << endl;
            j = bno - 1;
            cout << T[!z].B[j].name << endl;
            ballno = 1;
            while ((ballno <= 6) && (T[z].I.wickets < G.wickets))
            {
                system("cls");
                system("color 3E");
                headingingame();
                gotoxy(1, 7);
                cout << "0 (dot ball)  ";
                gotoxy(1, 8);
                cout << "1 (run) ";
                gotoxy(1, 9);
                cout << "2 (runs) ";
                gotoxy(1, 10);
                cout << "3 (runs) ";
                gotoxy(1, 11);
                cout << "4 (runs) ";
                gotoxy(1, 12);
                cout << "5 (runs) ";
                gotoxy(1, 13);
                cout << "6 (runs) ";
                gotoxy(1, 14);
                cout << "W/w (wide) ";
                gotoxy(1, 15);
                cout << "N/n (no ball) ";
                gotoxy(1, 16);
                cout << "O/o (out) " << endl;
                cout << "\n Enter the over ";
                cin >> btype;
                if (strlen(btype) > 1)
                {
                    balltype = '9';
                }
                else
                {
                    balltype = btype[0];
                }
                // when 1 one run scored
                if (balltype == '1')
                {
                    gotoxy(16, 8);
                    cout << "~ selected ball" << endl;
                    T[z].B[i].runs_scored++;
                    T[z].B[i].ballsfaced++;
                    T[z].I.runs += 1;
                    T[z].B[i].strikerate = (T[z].B[i].runs_scored / (T[z].B[i].ballsfaced * 1.00)) * 100.00;
                    T[!z].B[j].runs_conceded++;
                    changestrike(i, p, q, balltype, z);
                }
                // when 0 one run scored  i.e. dot ball
                else if (balltype == '0')
                {
                    gotoxy(16, 7);
                    cout << "~ selected ball" << endl;
                    T[z].B[i].runs_scored += 0;
                    T[z].B[i].ballsfaced++;
                    T[z].I.runs += 0;
                    T[!z].B[j].runs_conceded += 0;
                    if (T[z].B[i].runs_scored == 0)
                        T[z].B[i].strikerate = 0;
                    else
                        T[z].B[i].strikerate = (T[z].B[i].runs_scored / (T[z].B[i].ballsfaced * 1.00)) * 100.00;
                    changestrike(i, p, q, balltype, z);
                }
                // when 2 runs scored
                else if (balltype == '2')
                {
                    gotoxy(16, 9);
                    cout << "~ selected ball" << endl;
                    T[z].B[i].runs_scored += 2;
                    T[z].B[i].ballsfaced++;
                    T[z].I.runs += 2;
                    T[z].B[i].strikerate = (T[z].B[i].runs_scored / (T[z].B[i].ballsfaced * 1.00)) * 100.00;
                    T[!z].B[j].runs_conceded += 2;
                    changestrike(i, p, q, balltype, z);
                }
                // when 3 runs scored
                else if (balltype == '3')
                {
                    gotoxy(16, 10);
                    cout << "~ selected ball" << endl;
                    T[z].B[i].runs_scored += 3;
                    T[!z].B[j].runs_conceded += 3;
                    T[z].B[i].ballsfaced++;
                    T[z].B[i].strikerate = (T[z].B[i].runs_scored / (T[z].B[i].ballsfaced * 1.00)) * 100.00;
                    T[z].I.runs += 3;
                    changestrike(i, p, q, balltype, z);
                }
                // when 4 runs scored
                else if (balltype == '4')
                {
                    gotoxy(16, 11);
                    cout << "~ selected ball" << endl;
                    T[z].B[i].runs_scored += 4;
                    T[!z].B[j].runs_conceded += 4;
                    T[z].B[i].ballsfaced++;
                    T[z].B[i].strikerate = (T[z].B[i].runs_scored / (T[z].B[i].ballsfaced * 1.00)) * 100.00;
                    T[z].I.runs += 4;
                    T[z].B[i].four++;
                    changestrike(i, p, q, balltype, z);
                }
                // when  5 runs scored
                else if (balltype == '5')
                {
                    gotoxy(16, 12);
                    cout << "~ selected ball" << endl;
                    T[z].B[i].runs_scored += 5;
                    T[z].B[i].ballsfaced++;
                    T[z].B[i].strikerate = (T[z].B[i].runs_scored / (T[z].B[i].ballsfaced * 1.00)) * 100.00;
                    T[z].I.runs += 5;
                    T[!z].B[j].runs_conceded += 5;
                    changestrike(i, p, q, balltype, z);
                }
                // when 6 runs scored
                else if (balltype == '6')
                {
                    gotoxy(16, 13);
                    cout << "~ selected ball" << endl;
                    T[z].B[i].runs_scored += 6;
                    T[z].B[i].ballsfaced++;
                    T[z].B[i].strikerate = (T[z].B[i].runs_scored / (T[z].B[i].ballsfaced * 1.00)) * 100.00;
                    T[z].I.runs += 6;
                    T[!z].B[j].runs_conceded += 6;
                    T[z].B[i].six++;
                    changestrike(i, p, q, balltype, z);
                }
                else if (balltype == '9')
                {
                    cout << "\a";
                    cout << "Invalid input ";
                    ballno--;
                }
                // when a wide is conceded i.e the ball bowled is bounced out of the crease
                else if (balltype == 'w' || balltype == 'W')
                {
                    gotoxy(16, 14);
                    cout << "~ selected ball" << endl;
                    T[!z].B[j].runs_conceded++;
                    T[z].I.runs += 1;
                    T[!z].B[j].wide++;
                    ballno--;
                    T[!z].I.extras++;
                    changestrike(i, p, q, balltype, z);
                }
                // when a no ball is bowled
                else if (balltype == 'n' || balltype == 'N')
                {
                    gotoxy(16, 15);
                    cout << "~ selected ball" << endl;
                    T[!z].B[j].runs_conceded++;
                    T[z].I.runs += 1;
                    T[!z].B[j].noball++;
                    ballno--;
                    flag = 1;
                    T[!z].I.extras++;
                    changestrike(i, p, q, balltype, z);
                }
                // when a batsman is out
                else if (balltype == 'o' || balltype == 'O')
                {
                    gotoxy(16, 16);
                    cout << "~ selected ball" << endl;
                    if (flag == 1)
                    {
                        cout << "\n Not out as it is free hit";
                        flag = 0;
                        getch();
                    }
                    /*if a person gets out after a no ball is bowled that person is not out as that ball is a free hit  i.e. a batsman cannot get out*/
                    else if (flag == 0)
                    {
                        T[z].I.wickets++;
                        T[!z].B[j].wickets++;
                        T[z].B[i].ballsfaced++;
                        strcpy(T[z].B[i].wickettaker, T[!z].B[j].name);
                        T[z].B[i].strikerate = (T[z].B[i].runs_scored / (T[z].B[i].ballsfaced * 1.00)) * 100.00;
                        changestrike(i, p, q, balltype, z);
                        system("cls");
                        system("color 3E");
                        headingingame();
                        batsmanout(i, p, q, z);
                    }
                }
                else
                {
                    cout << "\a";
                    cout << "Invalid input ";
                    ballno--;
                }
                ballno++;
                if (innings == 1)
                    continue;
                else
                {
                    if (T[z].I.runs >= T[!z].I.runs)
                        break;
                    else
                        continue;
                }
            }
            system("cls");
            system("color 3E");
            headingingame();
            changestrikeover(i, p, q, z);
            T[z].I.overs++;
            T[!z].B[j].overs += 1;
            T[!z].B[j].economy = T[!z].B[j].runs_conceded / T[!z].B[j].overs;
            if (innings == 2)
            {
                l = G.overs - T[z].I.overs;
                if (l == 0)
                    l = 1;
                T[z].I.reqrun_rate = ((T[!z].I.runs + 1) - T[z].I.runs) / l * 1.00;
            }
            displayb(j, z, innings);
            system("cls");
            system("color 3E");
            headingingame();
        }
        if (innings == 1)
            continue;

        else
        {
            if (T[z].I.runs >= T[!z].I.runs)
                break;
            else
                continue;
        }
    }
    if (T[0].I.runs + 1 > T[1].I.runs)
        cout << "\n\n"
             << G.name1 << " Is the WINNER.";
    else if (T[0].I.runs + 1 < T[1].I.runs)
        cout << "\n\n"
             << G.name2 << " Is the WINNER.";
    else if (T[0].I.runs == T[1].I.runs)
        cout << "\n\n MATCH TIED.";
    getch();
    filing(fname);
}

/*********************************   Function for displaying the previous matches    ***********************************/
void display(char fname[20])
{
    char fname1[50] = "team1", fname2[50] = "team2";
    int q;
    system("color 3E");
    strcat(fname1, fname);
    strcat(fname2, fname);
    ifstream team1file(fname1, ios::binary);
    ifstream team2file(fname2, ios::binary);
    ifstream gamefile(fname, ios::binary);
    gamefile.read((char *)&G, sizeof(G));
    cout << "\n"
         << G.name1 << "  -   " << T[0].I.runs << "/" << T[0].I.wickets << "  Extras: " << T[1].I.extras;
    cout << "\n"
         << setw(25) << "BATTING";
    displaycol();
    team1file.read((char *)&T[0], sizeof(T[0]));
    for (int i = 0, j = 13; i <= G.wickets; i++, j++)
    {
        gotoxy(1, j);
        cout << T[0].B[i].name;
        gotoxy(25, j);
        cout << T[0].B[i].runs_scored;
        gotoxy(40, j);
        cout << T[0].B[i].ballsfaced;
        gotoxy(61, j);
        cout << T[0].B[i].six;
        gotoxy(69, j);
        cout << T[0].B[i].four;
        gotoxy(73, j);
        cout << T[0].B[i].strikerate << endl;
        q = j + 1;
    }
    cout << "\n\n"
         << setw(25) << "BOWLING";
    displaycolforbowler();
    for (int i = 0, j = q + 4; i <= G.wickets; i++, j++)
    {
        gotoxy(1, j);
        cout << T[0].B[i].name;
        gotoxy(25, j);
        cout << T[0].B[i].runs_conceded;
        gotoxy(40, j);
        cout << T[0].B[i].overs;
        gotoxy(61, j);
        cout << T[0].B[i].wickets;
        gotoxy(71, j);
        cout << T[0].B[i].economy << endl;
        q = j + 6;
    }
    cout << "\n";
    for (int f = 0; f < 80; f++)
    {
        cout << "-";
        Sleep(5);
    }
    cout << endl;
    cout << "\n\n"
         << G.name2 << "  -   " << T[1].I.runs << "/" << T[1].I.wickets << "  Extras: " << T[0].I.extras;
    cout << "\n\n"
         << setw(25) << "BATTING";
    displaycol();
    team2file.read((char *)&T[1], sizeof(T[1]));
    for (int i = 0, j = q + 4; i <= G.wickets; i++, j++)
    {
        gotoxy(1, j);
        cout << T[1].B[i].name;
        gotoxy(25, j);
        cout << T[1].B[i].runs_scored;
        gotoxy(40, j);
        cout << T[1].B[i].ballsfaced;
        gotoxy(61, j);
        cout << T[1].B[i].six;
        gotoxy(69, j);
        cout << T[1].B[i].four;
        gotoxy(73, j);
        cout << T[1].B[i].strikerate << endl;
        q = j;
    }
    cout << "\n"
         << setw(25) << "BOWLING";
    displaycolforbowler();
    for (int i = 0, j = q + 4; i <= G.wickets; i++, j++)
    {
        gotoxy(1, j);
        cout << T[1].B[i].name;
        gotoxy(25, j);
        cout << T[1].B[i].runs_conceded;
        gotoxy(40, j);
        cout << T[1].B[i].overs;
        gotoxy(61, j);
        cout << T[1].B[i].wickets;
        gotoxy(71, j);
        cout << T[1].B[i].economy;
    }
    if (T[0].I.runs + 1 > T[1].I.runs)
        cout << "\n\n"
             << G.name1 << " Is the WINNER.";
    else if (T[0].I.runs + 1 < T[1].I.runs)
        cout << "\n\n"
             << G.name2 << " Is the WINNER.";
    else if (T[0].I.runs == T[1].I.runs)
        cout << "\n\n MATCH TIED.";
    getch();
    gamefile.close();
    team1file.close();
    team2file.close();
}

/*********************************     Main function       ***************************************/
int main()
{
    int ch;
    char fname[20];
    intro();
    do
    {
        system("cls");
        system("color 3E");
        cout << "\n\n\n\n\n\t\t\t\tMENU \n\t\t\t\t----";
        cout << "\n\n\t\t\t 1) New game \n\n\t\t\t 2) Display Previous Matches \n\n\t\t\t 3) Exit \n\n\t\t\t Enter your choice:  ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            input();
            break;
        }
        case 2:
        {
            cout << "Enter the filename:";
            gets(fname);
            system("cls");
            heading(fname);
            display(fname);
            break;
        }
        case 3:
        {
            cout << "\n Thank you!";
            getch();
            exit(0);
        }
        default:
            cout << "\n Invalid choice!";
        }
    } while (ch != 3);
    return 0;
}
