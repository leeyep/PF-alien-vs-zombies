#include <iostream>
#include <string>
namespace help
{
    int main()
    {
        std::string commands[] = {"W", "S", "A", "D", "R", "H", "Z", "X", "Q"};
        std::string descriptions[] = {"Command Alien to move up", "Command Alien to move down", "Command Alien to move left", "Command Alien to move right", "Rotate arrow clockwise" , "Show Command that can be used in game", "Save The Current Game Progession", "Load Saved Game Progession", "Quit Current Game"};

        std::cout << "Game Help List:" << std::endl;
        for (int i = 0; i < sizeof(commands) / sizeof(commands[0]); i++)
        {
            std::cout << commands[i] << ": " << descriptions[i] << std::endl;
        }
        return 0;
    }
    
}
