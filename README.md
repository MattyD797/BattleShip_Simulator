# BattleShip_Simulator
### Version 1.0.0

![alt text](https://github.com/mtduggan/BattleShip_Simulator/blob/main/Output/Display.PNG "Beginning Display of the Simulator")

## Design Overview
The Battleship simulator mimics the open ocean in a ten by ten grid. Two generic teams (blue and green) face off against each other with each team starting with 5 ships. Each round of the simulation mimics 1 day out in the ocean and on each day, you may fire the cannons. Each ship only has one cannon, so if a ship sinks, you also lose a cannon.

## Compile Instructions
g++ BlueCannon.cpp BlueShip.cpp Board.cpp Cannon.cpp GreenCannon.cpp GreenShip.cpp Main.cpp Ship.cpp Start.cpp
Starting Condition

You will be asked to input a ‘1’,  ‘2’, or ‘3’ for the following options at the start: 1)Fire the cannons; 2)Fast forward x amount of days; or 3) quit. After firing the cannons, it will ask to go to the next day or the repeat the last two options. You will be asked again if an incorrect input is inputted.

## Rules
1.	Every new day, ships can make one random move vertically, horizontally, or diagonally in the grid. 
2.	Ships will not be able to cross over to the other team’s grid and no two ships can be at the same place at the same time. 
3.	Each side fires cannons once each day and the number of cannons fired is equivalent to the amount of ships on the team firing the cannons. 
4.	A ship can be sunk if the ship health goes below 10%. 
5.	All ships will heal each day by 5% if their health is greater than 50% but will decrease by 10% if their health goes below 50%. 
6.	If two ships are next to each other (horizontally or vertically) and the health of one is greater than 75%, the lower health ship will get a 50% restock in health. 
7.	Cannons take 40% damage if hit directly, 25% if hit vertically or horizontally, and only 10% if hit diagonally. 
8.	If a ship is moved into a grid occupied by another ship or that is out of bounds, then the ship does not move on that turn. 
9.	 If a ship restocks another ship, it may not get restocked itself. 
10.	If a ship is on the side of the map, we expect them to be damaged from hitting the reef and the ship will lose 10% for each wall it hits. Damage is counted twice if in the corner. 

## Stopping Condition
The side with the last ship remaining or with the most ships remaining after 25 days wins. 
