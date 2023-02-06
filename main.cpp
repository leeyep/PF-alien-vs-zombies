// ********************************************************* 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: T13L 
// Names: LEE_HENG_YEP | ONG_KWANG_ZHENG
// IDs: 1211101790| 1211102806
// Emails: 1211101790@student.mmu.edu.my | 1211102806@student.mmu.edu.my
// Phones: 018-870-3882 | 017-368-4493
// ********************************************************* 

//todo:
//entities on board
//show hp and atk of alien and zombies
//movement
//rotation of arrow
//game over/you win
//video of p2

#include "helper.cpp"
#include "command.cpp"
#include <iostream>

using namespace std;

// void Gamesetting(int &selection)
//{
//    cout << "Your Selection is =";
//    int temp;
//    cin >> temp;
//
//    const int Numberofrows = 3;
//    const int NumberofColumns = 5;
//    const int NumberofZombies = 1;
//    int Numbofrows;
//    int NumbofColumns;
//    int NumbofZombies;
//    if (temp == 1)
//        ;
//    cout << "Numbers of rows:(#only odd numbers)" << endl;
//    cin >> Numbofrows;
//    cout << "Number of columns: " << endl;
//    cin >> NumbofColumns;
//    cout << "Number of Zombies" << endl;
//    cin >> NumbofZombies;

//   if (temp == 2)
//    cout << "Number of rows: " << Numberofrows << endl;
//    cout << "Number of Columns:" << NumberofColumns << endl;
//    cout << "Number of Zombies:" << NumberofZombies << endl;
//} <-----------------------------------------------------------------------(DONT DELETE YET NOT CONFIRMED)

void display_settingscreen(int &numofrows, int &numofcolumns, int &numofzombies)
{
    a:
    cout << "Number of rows (Odd numbers only) : ";
    cin >> numofrows;
    if (numofrows < 1 || numofrows > 15)
    {
        cout << "number is invalid, cannot be less than 1 or more than 15" << endl;
        goto a;
    }

    b:
    cout << "Number of columns (Odd numbers only) : ";
    cin >> numofcolumns;
    if (numofcolumns < 1 || numofcolumns > 49)
    {
        cout << "number is invalid, cannot be less than 1 or more than 39" << endl;
        goto b;
    }

    c:
    cout << "Number of zombies : ";
    cin >> numofzombies;
    if (numofzombies < 1 || numofzombies > 10)
    {
        cout << "number is invalid, cannot be less than 1 or more than 10" << endl;
        goto c;
    }
    pf::Pause();
    pf::ClearScreen();
}

int row;
int column;
char board[30][30];
void Createboard(int row, int column)
{
    for (int rows = 0; rows < row; rows++)
    {
        for (int columns = 0; columns < column; columns++)
        {
            if (rows % 2 == 0 && columns % 2 == 0)
            {
                board[rows][columns] = '+';
            }
            else if (rows % 2 == 0)
            {
                board[rows][columns] = '-';
            }
            else if (columns % 2 == 0)
            {
                board[rows][columns] = '|';
            }
            else if (columns % 2 != 0)
            {
                board[rows][columns] = ' ';
            }
        }
    }
}

void printBoard(int row, int column)
{
    for (int rows = 0; rows < row; rows++)
    {
        for (int columns = 0; columns < column; columns++)
        {
            if (rows % 2 == 0 && columns % 2 == 0)
            {
                cout << "+";
            }
            else if (rows % 2 == 0 && columns % 2 != 0)
            {
                cout << "-";   
            }
            else if (columns % 2 == 0)
            {
                cout << "|";
                if (columns == column - 1)
                    cout << " ";
            }
            else if (columns % 2 != 0 && rows % 2 != 0 )
            {
                cout << " ";
            }

        }
        cout << endl;
    }
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
        // up movement
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
        // quit
        break;
    case 'R':
        // rotate arrow
    break;

    default:
        cout << "Invalid command, please refer to command list *H* for list of commands" << endl;
    break;
    }

    
}

/*void replace(int numofrows,int numofcolumns)
{
    for (int x = 0; x < numofcolumns; x++)
    {
        for (int y = 0; y < numofrows; y++)
        {
            if (x % 2 != 0 && y % 2 != 0 )
            {
                
            }
        }
    }
}*/

class Alien
{
    public:
    int HP = 100;
    int ATK = 10;
};

class Zoms
{
    public:
    int HP = 200;
    int ATK = 30;
};

class Pods
{
    public:
    int ATK = 30; //atk closest zombie
};

class Healthpack
{
    public:
    int HP = 50; //adds hp to alien
};


int main()
{
    int numofrows;
    int numofColumns;
    int numofZombies;
    char x;
    display_settingscreen(numofrows,numofColumns,numofZombies);
    Createboard(numofrows, numofColumns);
    printBoard(numofrows,numofColumns);

    //after spawning entities
    userinput(x);
}