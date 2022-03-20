# Group159
COMP2113 Group159 Project
Team members:
mangofarmergoose - Chan Leong Sing 3035687675
CagySloth - Ng Ching Lap 3035687742

Game Description

Game initialization:
A 9x9 board will be generated at the start of the game, 2 columns from the left and right and the top 2 rows will be reserved for card placement. Coordinates will be (0,0) from the top left to (8,8) at the bottom right.

Game flow:
The player will spawn randomly in the remaining 7x5 space; a random number of monsters will be spawned in the space. The player can move freely in the 7x5 space. The player will only have information about neighboring tiles. 
If the player’s coordinate coincides with monsters’ coordinate, they will enter combat. After combat victory, monsters will have a certain probability of dropping two types of game objects: (1) Cards, (2) Equipment and Accessories. Metric of success in the game is determined by the number of monsters slain before death.

Combat mode:
Player will attack the monster idly. Attack damage will be random within a certain range given the player's attribute statistics. 

Game objects

Monster 
Monsters’ attack damage and defense scales with the number of moves the player has made. Number of monsters on board scales with the number of moves the player has made as well.

Player
The Player will have five attributes:
Attack Damage
Health Point
Defense
Heath Regeneration
Attack Speed

Attack damage will be random within a certain range given the player's attribute statistics. 

Cards
There are three sets of cards: {Shelter, Barrack, Forge}

Cards can only be placed in the two topmost rows, the two leftmost or two rightmost columns. Following conditions will occur:
If Barrack is placed next to Forge, the player's defense and attack damage increases
If Shelter is placed next to Barrack, the player's health regeneration increases.
If Forge is placed next to Shelter, the player’s health point increases.
If four Barrack cards are placed within a 2x2 square, the player's attack damage and attack speed increase. 
If four Shelter cards are placed within a 2x2 square, the player's health point and health regeneration increase.
If four Forge cards are placed within a 2x2 square, the player’s defense and attack damage increase.

If all card slots are full, attributes will be permanently stored in the player. Cards slots will be freed out.
