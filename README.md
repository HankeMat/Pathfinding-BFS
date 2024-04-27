# Pathfinding algorithm - Breadth-First Search (BFS)
- Program takes name of a file that contains the map with its dimensions (visible in figure 1) as first and only argument.
- First line is number of rows, second line represents number of columns and after that file contionues with rows\*lines containing columns\*characters
- These lines must conatin exactly one uppercase 'S' and one uppercase 'E'. Other characters have to be lowercase.
- Each character represents its elevation and algorithm searches for the shortest possible path from 'S' to 'E' adhering to the following rules:
1. The algorithm can go to the same or one higher elevation only (from 'c' can go to another 'c' or 'd', but not to 'b' nor 'e')
2. It starts in S and goes to E
3. It finds the shortest possible way to get from S to E
*Figure 1*
5<br>
8<br>
Sabqponm<br>
abcryxxl<br>
accszExk<br>
acctuvwj<br>
abdefghi<br>

## Build
- This part should be easy. In the project is Makefile included so just run this command to compile the code
```
make
```
- As mentioned previously there should also be the .txt file containing the map and its dimensions ... u can use any .txt file you want as long as it follow the rules mentioned above. (It doesnt necessary needs to be in the root of this project, but you have to use entire path to the file [relative / absolute] in the argument).
- Speaking of the argument here is an example on how to run the program (if you are located in the root of the project):
```
./main pathToTheMapFile.txt
```
- The project also contains test map which is called inputFile.txt so here you can test it out:
```
./main inputFile.txt
```
