# Text-Based Game
This text game was created as part of the INF-1015 advanced object-oriented programming course.
## Description of the Text-Based Game Project
The entire game operates through a command-line interface, where the user interacts with the game by entering text into the console. The goal is to explore the game world and perform actions within it. 
### Game World
In this game, the world is divided into zones, cells, or rooms that can be connected to each other in the four cardinal directions (north, south, east, west). Each zone can be connected to a maximum of 4 other zones.

### Navigation
The player inputs the direction he want's to go to : North, south, east or west.

### Object

The player can find objects and use them to unlock new rooms. Some object unlock new objects. The look and use commands allow you to interact with objects. However, you need to specify which object you want to `look` at or `use`. We want the command to be followed by a character string that contains, as a sub-string, one of the important words associated with the object. For example, the object with the name A black leather jacket could be observed by doing look black leather jacket, or by doing look jacket, as black leather jacket and jacket are both sub-strings of A black leather jacket. If several objects meet the search criterion, we take the first one found.

### Ending the game 

The game ends when the player finds the last secret room.