// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: T13L
// Names: LEE_HENG_YEP | ONG_KWANG_ZHENG
// IDs: 1211101790| 1211102806
// Emails: 1211101790@student.mmu.edu.my | 1211102806@student.mmu.edu.my
// Phones: 018-870-3882 | 017-368-4493
// *********************************************************

// todo:
// entities on board
// show hp and atk of alien and zombies
// movement
// rotation of arrow
// game over/you win
// video of p2

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "command.cpp"
#include "helper.h"

using namespace std;

class Alien
{
public:
    int HP = 100;
    int ATK = 0;
    int rowlocation;
    int columnlocation;
};

class Zoms
{
public:
    int HP = 100 + rand() % 250;
    int ATK = 20 + rand() % 40;
    int rowLocation;
    int columnLocation;
};

class Pods
{
public:
    int ATK = 10; // atk closest zombie
};

class Healthpack
{
public:
    int HP = 20; // adds hp to alien
};

char Board[50][50];

void display_settingscreen(int &numofrows, int &numofcolumns, int &numofzombies) // Author: Ong Kwang Zheng + Lee Heng Yep
{
    cout << "Do You Wanna Use Your Own Game Setting? (1=Yes 2 = No) :";
    int temp;
    cin >> temp;
    if (temp == 1)
    {
        cout << "Number of rows (Odd numbers only) : ";
        cin >> numofrows;
        while (numofrows < 1 || numofrows > 15 || numofrows % 2 != 1)
        {
            cout << "Invalid input. Number of rows must be odd and between 1 and 15." << endl;
            cout << "Number of rows (Odd numbers only) : ";
            cin >> numofrows;
        }

        cout << "Number of columns (Odd numbers only) : ";
        cin >> numofcolumns;
        while (numofcolumns < 1 || numofcolumns > 49 || numofcolumns % 2 != 1)
        {
            cout << "Invalid input. Number of columns must be odd and between 1 and 49." << endl;
            cout << "Number of columns (Odd numbers only) : ";
            cin >> numofcolumns;
        }

        cout << "Number of zombies : ";
        cin >> numofzombies;
        while (numofzombies < 1 || numofzombies > 10)
        {
            cout << "Invalid input. Number of zombies must be between 1 and 10." << endl;
            cout << "Number of zombies : ";
            cin >> numofzombies;
        }
    }
    if (temp == 2)
    {
        cout << "Number of rows: " << numofrows << endl;
        cout << "Number of Columns:" << numofcolumns << endl;
        cout << "Number of Zombies:" << numofzombies << endl;
    }
}
void createBoard(int row, int column) // Author: Ong Kwang Zheng
{

    for (int rowcounter = 0; rowcounter < row; rowcounter++)
    {
        for (int columncounter = 0; columncounter < column; columncounter++)
        {
            cout << "+-";
        }
        cout << "+" << endl;
        for (int columncounter = 0; columncounter < column; columncounter++)
        {
            cout << "|"
                 << Board[rowcounter][columncounter];
        }
        cout << "|" << endl;
    }
    for (int columncounter = 0; columncounter < column; columncounter++)
    {
        cout << "+-";
    }
    cout << "+" << endl;
}

void feature(int &numofrows, int &numofcolumns, int &numofzombies) // Author: Ong Kwang Zheng
{
    Alien alien;
    Zoms zombie[numofzombies];
    int zombieCounter=0;
    {

        int random;
        int randomrows;
        int randomcolumns;
        int newposition;

        srand(time(NULL));
        for (int rowcounter = 0; rowcounter < numofrows; rowcounter++)
        {
            for (int columncounter = 0; columncounter < numofcolumns; columncounter++)
            {
                random = rand() % 100;
                if (random < 20)
                {
                    Board[rowcounter][columncounter] = 'p';
                }
                else if (random < 40)
                {
                    Board[rowcounter][columncounter] = 'h';
                }
                else if (random < 45)
                {
                    Board[rowcounter][columncounter] = '^';
                }
                else if (random < 50)
                {
                    Board[rowcounter][columncounter] = 'v';
                }
                else if (random < 55)
                {
                    Board[rowcounter][columncounter] = '<';
                }
                else if (random < 60)
                {
                    Board[rowcounter][columncounter] = '>';
                }
                else if (random < 80)
                {
                    Board[rowcounter][columncounter] = 'r';
                }
                else if (random < 100)
                {
                    Board[rowcounter][columncounter] = ' ';
                }
            }
        }
        Board[numofrows / 2][numofcolumns / 2] = 'A';
        alien.rowlocation = numofrows/2;
        alien.columnlocation = numofcolumns/2;

        for (int zombiecounter = 0; zombiecounter < numofzombies; zombiecounter++)
        {
            randomrows = rand() % numofrows;
            randomcolumns = rand() % numofcolumns;
            if (Board[randomrows][randomcolumns] != 'A' || Board[randomrows][randomcolumns] != 'Z')
            {
                Board[randomrows][randomcolumns] = 'Z';
                zombie[zombieCounter].rowLocation=randomrows;
                zombie[zombieCounter].columnLocation=randomcolumns;
                zombieCounter++;
            }
        }
        createBoard(numofrows, numofcolumns);
        //ZombieMovement(numofrows, numofcolumns,zombie, zombieCounter);
    }
    cout << "Alien HP:" << alien.HP << "   " <<  "Alien ATK:" << alien.ATK << endl;
    //cout << "Zombie1 HP:" << zombie.HP << "   " << "Zombie1 ATk:" << zombie.ATK << endl;

}

void quit()
{
    string ans;
    cout << "Are you sure you want to quit? (Y/N) : ";
    cin >> ans;
    if (ans == "Y")
    {
        cout << "Thank you for playing" << endl;
        std::terminate();
    }
    else if (ans == "N")
    {
    }
}

void AlienMovement(int &numofrow, int &numofcolumns, string y)
{
    Alien alien;
    {

        if (y == "W")
        {
            Board[alien.rowlocation][alien.columnlocation] = '.';
            Board[alien.rowlocation - 1][alien.columnlocation] = 'A';
            alien.rowlocation = alien.rowlocation - 1;
        }
        else if (y == "S")
        {
            Board[alien.rowlocation][alien.columnlocation] = '.';
            Board[alien.rowlocation + 1][alien.columnlocation] = 'A';
            alien.rowlocation = alien.rowlocation + 1;
        }
        else if (y == "A")
        {
            Board[alien.rowlocation][alien.columnlocation] = '.';
            Board[alien.rowlocation][alien.columnlocation - 1] = 'A';
            alien.columnlocation = alien.columnlocation - 1;
        }
        else if (y == "D")
        {
            Board[alien.rowlocation][alien.columnlocation] = '.';
            Board[alien.rowlocation][alien.columnlocation + 1] = 'A';
           alien.columnlocation = alien.columnlocation + 1;
        }
    }
    createBoard(numofrow, numofcolumns);
}

void userinput(char x)
{
    cout << "User input : ";
    cin >> x;
    x = toupper(x);
    cout << endl;

    switch (x)
    {
    case 'H':
        help::main();
        break;
    case 'W':
        cout << "Alien moves up" << endl;
        break;
    case 'S':
        cout << "Alien moves down" << endl;
        // down
        break;
    case 'A':
        cout << "Alien moves left" << endl;
        // left
        break;
    case 'D':
        cout << "Alien moves right" << endl;
        // right
        break;
    case 'Z':
        // save
        break;
    case 'X':
        // load
        break;
    case 'Q':
        quit();
        break;
    case 'R':
        // rotate arrow
        break;

    default:
        cout << "Invalid command, please refer to command list *H* for list of commands" << endl;
        break;
    }
}


int main() // Authors: Ong Kwang Zheng + Lee Heng Yep
{
    int numofrows = 3;
    int numofColumns = 5;
    int numofZombies = 1;
    int selection;
    int alienhp;

    char x;
    string y;
    y = x;
    display_settingscreen(numofrows, numofColumns, numofZombies);
    feature(numofrows, numofColumns, numofZombies);
    userinput(x);
    AlienMovement(numofrows, numofColumns, y); // tbc
}
