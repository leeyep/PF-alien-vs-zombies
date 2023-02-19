# Part 2

## Video Demo

Please provide the YouTube link to your [Video Demo](https://youtu.be/Q3Yul_aT9Vg).

## Minimum Requirements

### Completed

List all the features completed.

1. Allow user to choose if they wanna change the default game setting (Y/N)
2. Generate GameBoard with Alien,Zombie,Pod,Rock,Arrow and Health pack in it and also alien and zombie's stat.
3. Allow user to choose their option to start the game.
4. Allow user to choose the movement of Alien.
5. Allow alien to break the rock and generate random feature to replace the rock.
6. Allow Zombie to move in random direction with 1 step after alien's movement without going over the border or replace another zombie and alien.
7. Allow user to change the direction of arrow in the gameboard.
8. Rockfeature() - Randomfeature after breaking rock or replacing the trail after alien's movement

## Additional Features

Describe the additional features that has been implemented.
1. None

## Contributions

List down the contribution of each group members.

For example:

### Lee Heng Yep

1. Display setting
2. Alien Movement 
3. Arrow rotation
4. User option
5. User input
7. Game loop
8. Alien attributes
9. Item attributes
10. Start title

### Ong Kwang Zheng
1. User's opinion if wanted to change default setting- display_settingscreen()
2. Generating GameBoard with user's input value or default value setting -Createboard()
3. Input feature in gameboard(Alien,Zombie,Pod,Rock,Arrow, Health pcak , Alien's stat and zombie's stat) -feature()
4. User's option -userinput()
5. Zombie movement-ZombieMovement()
6. Alien Movement-alienmovement()
7. RockFeature()
8. Attribute of Alien -class Alien
9. Attribute of Zombie -class zoms
10. Command List
11. User Manual and Game Introduction


## Problems Encountered & Solutions

Describe the problems encountered and provide the solutions / plan for the solutions.
1. Unable to pass the value of zombie's attribute to other function. (Tried to use vector for zombie class but failed to generate)
3. Unable to insert location value into alien class, so location keeps resetting into default. (tried using functions, functions in class, inserting value in main - all doesnt work)
4. Unable to create game over screen because zombie cannot be targeted nor killed and alien cannot be damaged(implemented draw)
5. alien info not updating
