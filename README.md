# Group159
COMP2113 Group159 Project
Team members:
mangofarmergoose - Chan Leong Sing 3035687675
CagySloth - Ng Ching Lap 3035687742

Problem Statement

RPG Rogue like game has always been a hit since the genesis of computer games, however the strategical aspect of these games are lacking. Our game provide rewards to superior desicion making. Large amout of game objects needed to be initiallized much like modern consumer products. We can make use of dynamic memory management to allocate memory at run time for cards and accessories. 

Game Description

Game initialization:
A 9x9 board will be generated at the start of the game, Column 0,1,8,9; Row 0,1 are reserved for card placement.

Game flow:
The player will spawn randomly in the remaining 7x5 space; a random number of monsters will be spawned in the space. The player can move freely in the 7x5 space.

If the player’s coordinate coincides with monsters’ coordinate, they will enter combat. After combat victory, monsters will have a certain probability of dropping two types of game objects: (1) Cards, (2) Equipment and Accessories. Metric of success in the game is determined by the number of monsters slain before death.

Combat mode:
Player will attack the monster manually. Player can either (1)Attack (2)Dodge and Heal. Attack damage is deterministic given the player's attribute statistics. 

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


Cards
There are three sets of cards: {Shelter, Barrack, Forge}

Cards can only be placed in the two topmost rows, the two leftmost or two rightmost columns. Following conditions will occur:

If two Barrack cards are placed within a 2x2 square, the player's attack damage and attack speed increase. 
If two Shelter cards are placed within a 2x2 square, the player's health point and health regeneration increase.
If two Forge cards are placed within a 2x2 square, the player’s defense and attack damage increase.

If all card slots are full, attributes will be permanently stored in the player. Cards slots will be freed out.

Equipment and Accessories

Equipment and accessories will contribute to the player’s attributes. For instance, armors will improve the player’s defense, weapons will improve attack damage, and accessories might affect all five attributes of the player positively or negatively. As accessories may have negative effects on the player, the player will receive a brief description of the item every time the player encounters one and then decide whether to pick it or not.

How Each Coding Element Supports our Features:

Generation of random game sets or events

As the game features a random number of monsters spawned each day on random locations on the board, random number generators will help to determine these daily events in the game. Moreover, every monster has random drops on their death, which include different skill cards that the player can utilize later.

Data structures for storing game status

Arrays will be used to store the condition of the board (e.g. 0 represents an empty slot, 1 represents the player’s location, 2 represents locations of monsters, etc.), equipment and accessories held by the player, skill cards held by the player, and the player’s stats (e.g. attack, health, mana).

Dynamic memory management

Vector is used for storage of cards. Linked list is used for storing players' accessories. Dynamic memory management can help to better allocate memory at run-time.

File input/output

Text files will be used to store player's information, attributes and items, and also the card tiles. Game status will be updated after every move of the player.

Program codes in multiple files

As the game involves many events repeating randomly every day or among every move made by the player, storing codes with different purposes in multiple files can improve readability of the codes, and thus allow easier debugging. Moreover, multiple functions will be used to calculate player’s attributes and combat results, separating these functions will help improve readability as well.
