#include <iostream>
#include <string>

int main()
{
    std::string commands[] = {"up", "down", "left", "right", "help","save","load","quit"};
    std::string descriptions[] = {"Command Alien to move up", "Command Alien to move down", "Command Alien to move left", "Command Alien to move right", "Show Command that can be used in game","Save The Current Game Progession","Load Saved Game Progession","Quit Current Game"};

    std::cout << "Game Help List:" << std::endl;
    for (int i = 0; i < sizeof(commands) / sizeof(commands[0]); i++)
    {
        std::cout << commands[i] << ": " << descriptions[i] << std::endl;
    }
}
