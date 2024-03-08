# Save-File_Nek
## Description
You have been asked to make a program with some function to handle a game save file. The program must at least have a function to read a save file and another function to save game data to a save file. The save data must contain these parameter (with its data range):
1. Level, integer (between 1 to 99).
2. Skills, string and integer. The skill is not single data, but a maximum of 5 data. Each contain a string (the skill name) and an integer (skill level, range from 1 to 10).
3. Coins, integer (between 0 to 99.999).
4. Class, string (one of these: "Fighter", "Druid", "Monk", "Rogue", "Wizard", "Paladin", "Ranger", "Cleric", "Warlock").

Based on privacy and proprietary, your boss asked you to make the save file in a .naonwae extension file.

### Restriction:
1. Function to write the save file must have a single argument, which contains all the data that need to be saved.
2. Function to read the save file must return a single result. But the result must contains all the data in the save file. The result must be in a format that each save data parameter can be taken easily (without any additional processing).
3. Both function must only access a single save file.
4. You can only use these programming language: C, C++, Java, or Python.
5. The data structure on the save file is up to your discretion. However, the save file must only contain the latest value for each parameter and no duplication is allowed.

## Solving the Challenge
This challenge was solved in C. The save data and its contents is stored in the PlayerData struct. In accordance to the challenge, the save file is interacted with two functions, the write function and the read function. The write function is a function that takes the save data as an argument and writes it into the .naonwae file. The read function is a function that finds and reads the .naonwae file and returns the save data struct. The rest of the program simply prints the contents of the save file.
