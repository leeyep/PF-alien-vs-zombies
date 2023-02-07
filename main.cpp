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
// #include "helper.h"

using namespace std;
char Board[50][50];
class Alien
{
public:
    int HP = 100;
    int ATK = 100;
    int rowlocation;
    int columnlocation;
};
class Zoms
{
public:
    int HP = 100 + rand() % 150;
    int ATK = 20 + rand() % 20;
    int rowLocation;
    int columnLocation;
};

void display_settingscreen(int &numofrows, int &numofcolumns, int &numofzombies) // Author: Ong Kwang Zheng + Lee Heng Yep
{
    cout << "Do You Wanna Change Your Game Setting?" << endl;
    cout << "Default Game settings:" << endl;
    cout << "Number of rows:3" << endl;
    cout << "Number of Columns:5" << endl;
    cout << "Number of Zombie:1" << endl;
    cout << "(1=Yes 2 = No):";
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
void ZombieMovement(int &numofrow, int &numofcolumns, Zoms zombie[], int zombieCounter)
{
    srand(time(NULL));
    int newposition;
    for (int i = 0; i < zombieCounter; i++)
    { 
        if (Board[numofrow][numofcolumns] != 'A' || Board[numofrow][numofcolumns] != 'Z')
        {
            newposition = rand() % 100;
        if (newposition < 25)
        {
            Board[zombie[i].rowLocation][zombie[i].columnLocation] = ' ';
            Board[zombie[i].rowLocation - 1][zombie[i].columnLocation] = 'Z';
            zombie[i].rowLocation = zombie[i].rowLocation - 1;
        }
        else if (newposition < 50)
        {
            Board[zombie[i].rowLocation][zombie[i].columnLocation] = ' ';
            Board[zombie[i].rowLocation + 1][zombie[i].columnLocation] = 'Z';
            zombie[i].rowLocation = zombie[i].rowLocation + 1;
        }
        else if (newposition < 75)
        {
            Board[zombie[i].rowLocation][zombie[i].columnLocation] = ' ';
            Board[zombie[i].rowLocation][zombie[i].columnLocation - 1] = 'Z';
            zombie[i].columnLocation = zombie[i].columnLocation - 1;
        }
        else if (newposition < 100)
        {
            Board[zombie[i].rowLocation][zombie[i].columnLocation] = ' ';
            Board[zombie[i].rowLocation][zombie[i].columnLocation + 1] = 'Z';
            zombie[i].columnLocation = zombie[i].columnLocation + 1;
        }
    }
}
    createBoard(numofrow, numofcolumns);
}
int ClearScreen()
{
#if defined(_WIN32)
    return std::system("cls");
#elif defined(__linux__) || defined(__APPLE__)
    return std::system("clear");
#endif
}

int Pause()
{
#if defined(_WIN32)
    return std::system("pause");
#elif defined(__linux__) || defined(__APPLE__)
    return std::system(R"(read -p "Press any key to continue . . . " dummy)");
#endif
}

void feature(int &numofrows, int &numofcolumns, int &numofzombies) // Author: Ong Kwang Zheng
{
    Alien alien;
    Zoms zombie[numofzombies];
    int zombieCounter = 0;
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
        for (int zombiecounter = 0; zombiecounter < numofzombies; zombiecounter++)
        {
            randomrows = rand() % numofrows;
            randomcolumns = rand() % numofcolumns;
            if (Board[randomrows][randomcolumns] != 'A' || Board[randomrows][randomcolumns] != 'Z')
            {
                Board[randomrows][randomcolumns] = 'Z';
                zombie[zombieCounter].rowLocation = randomrows;
                zombie[zombieCounter].columnLocation = randomcolumns;
                zombieCounter++;
            }
        }
        createBoard(numofrows, numofcolumns);

        ZombieMovement(numofrows,numofcolumns,zombie,zombieCounter);
        // ZombieMovement(numofrows, numofcolumns, zombie, zombieCounter);
    }
    cout << "Alien HP:" << alien.HP << "   "
         << "Alien ATK:" << alien.ATK << endl;
    for (int zombiecounter = 0; zombiecounter < numofzombies; zombiecounter++)
    {
        cout << "Zombie" << zombiecounter + 1 << " "
             << "HP" << zombie[zombiecounter].HP << "   "
             << "Zombie" << zombiecounter + 1 << " "
             << "ATK:" << zombie[zombiecounter].ATK << endl;
    }
    // cout << "Zombie1 HP:" << zombie.HP << "   " << "Zombie1 ATk:" << zombie.ATK << endl;
}

void userinput()
{
    Alien alien;
    int x;
    cout << "User input : ";
    cout << "1=Help";
    cout << "2=Up";
    cout << "3=Left";
    cout << "4=Down";
    cout << "5=Right";
    cout << "6=Arrow";
    cout << "7=Save";
    cout << "8=Load";
    cout << "9=Quit";
    cin >> x;
    if (x == 1)
    {
        std::string commands[] = {"Up", "Down", "Left", "Right", "Arrow", "Help", "Save", "Load", "Quit"};
        std::string descriptions[] = {"Command Alien to move up", "Command Alien to move down", "Command Alien to move left", "Command Alien to move right", "Rotate arrow clockwise", "Show Command that can be used in game", "Save The Current Game Progession", "Load Saved Game Progession", "Quit Current Game"};

        std::cout << "Game Help List:" << std::endl;
        for (int i = 0; i < sizeof(commands) / sizeof(commands[0]); i++)
        {
            std::cout << commands[i] << ": " << descriptions[i] << std::endl;
        }
    }
    else if (x == 2)
    {

        Board[alien.rowlocation][alien.columnlocation] = '.';
        Board[alien.rowlocation - 1][alien.columnlocation] = 'A';
        alien.rowlocation = alien.rowlocation - 1;
    }
    else if (x == 3)
    {
        Board[alien.rowlocation][alien.columnlocation] = '.';
        Board[alien.rowlocation + 1][alien.columnlocation] = 'A';
        alien.rowlocation = alien.rowlocation + 1;
    }
    else if (x == 4)
    {
        Board[alien.rowlocation][alien.columnlocation] = '.';
        Board[alien.rowlocation][alien.columnlocation - 1] = 'A';
        alien.columnlocation = alien.columnlocation - 1;
    }
    else if (x == 5)
    {
        Board[alien.rowlocation][alien.columnlocation] = '.';
        Board[alien.rowlocation][alien.columnlocation + 1] = 'A';
        alien.columnlocation = alien.columnlocation + 1;
    }
    else if (x == 9)
    {
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
}


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
int main() // Authors: Ong Kwang Zheng + Lee Heng Yep
{
    int numofrows = 3;
    int numofColumns = 5;
    int numofZombies = 1;
    int numofcolumns;
    int selection;

    char x;
    display_settingscreen(numofrows, numofColumns, numofZombies);
    feature(numofrows, numofColumns, numofZombies);
    ClearScreen();
    // after spawning entities
    // userinput(x);
    //     if (win = false)
    //     {
    //         userinput(x);
    //     }
    //     else if (win = true)
    //     {
    //         cout << "You Win!";
    //         pf::Pause();
    //         std::terminate();
    //     }
}
