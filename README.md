# Lem_in
My solution for 42's Lem_in project. In this project, the goal is to move ants through maps in an efficient way. Each maps consists of rooms and connections between them.
Each room can only hold one ant at a time, except the start and end rooms which can hold any number of ants. The ants are moved in turns, where each ant can move through
one connection each turn as long as there is space in the destination room. A map is defined as follows:
```
3
##start
0 1 0
##end
1 5 0
2 9 0
3 13 0
0-2
2-3
3-1
```
which represents a map that looks like [0]-[2]-[3]-[1] 

The first line is the number of ants as an integer.

After that come the rooms in the format [room name] [x coordinate] [y coordinate]. Room names can be numbers, letters or words, but may not start with L or #. The ##start and 
##end commands indicate that the room in the next line is the start/end room.

After the rooms come the connections, in the format [room name]-[room name]. 

There can also be comments in the map files. Comments start with a # symbol. These are ignored in the execution of the program.

When run with a valid map, the program first prints out the map it was given, then prints out the turns it took to move the ants from the start room to the end room. Each move
is in the format L[ant number]-[destination room]. One ant can only move through one connection in a given turn, but the amount of ants that can move per turn is not limited.
For example, the output
```
L1-2
L1-3 L2-2
```
would mean that two turn were made. In the first turn, ant 1 moved from the start room to room 2. In the second turn, ant 1 moved from room 2 to room 3 and ant 2 moved from the 
start room to room 2.

## Usage:

`make` to create the binary

`./lem_in < map'

Some test maps, both valid and invalid, can be found in the eval_tests directory.

## How it works

I basically split the project into three parts: 
1. taking the map input and parsing it
2. finding all the paths through the map
3. moving the ants through the paths in the most efficient way

For pathfinding, I use depth-first traversal to go through each path in the map recursively, then store the paths that lead from start to end in an array.

After the paths are found, I assign a path for each ant to use. The first ant gets the shortest path. For the rest of the ants, I look at the lengths of the paths and the number
of ants already assigned to them. Since each room except start and end can only hold one ant at a time, it sometimes makes sense to send some ants down the longer paths to avoid
'traffic jams' in the shorter ones. Then, once the paths are assigned, I simply move each ant along its path each turn if the traffic situation allows and keep making turns until
all ants are in the end room.
