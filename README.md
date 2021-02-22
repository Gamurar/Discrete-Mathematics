# Дискретная математика :computer:
<img align="right" height="100" alt="UTM logo" src="images/utm-logo.png">В этом репозитории представлены работы по дискретной математике, выполненные мной, студенткой университета UTM, группы TI-202FR, Гамурарь Яной.

## Лабораторная работа №1
**Хранение графов в памяти ЭВМ**

:page_facing_up:[Код программы](lab1-storing-graphs-in-computer-memory.c)

###### Пример работы программы
```bash
----- MENU -----
1. Enter a graph
2. Display the graph
3. Quit
Enter your choice: 2

X There's no graph, please enter a graph first. X

----- MENU -----
1. Enter a graph
2. Display the graph
3. Quit
Enter your choice: 1

In what form do you want to enter the graph?
1. Incidence Matrix
2. Adjacency Matrix
3. Adjacency List
4. <- Go back
Enter your choice: 1
Please, enter number of vertices: 4
Please, enter number of edges: 5
Please fill the matrix with values:
-1 1 0 0
0 -1 1 0
-1 0 1 0
-1 0 0 1
0 0 1 -1

This is the entered Incidence Matrix:
      [v1]  [v2]  [v3]  [v4]
    +--------------------+
[e1] |  -1   1    0    0
[e2] |  0    -1   1    0
[e3] |  -1   0    1    0
[e4] |  -1   0    0    1   
[e5] |  0    0    1    -1

Do you want to edit it? (y/n): y
Type the number of edge you want to edit: 1
Type the number of vertex you want to edit: 4

In place of the entered coordinates is the value 0
Please, type a new value: 1

This is your new Incidence Matrix:
      [v1]  [v2]  [v3]  [v4]
    +--------------------+
[e1] |  -1   1    0    1
[e2] |  0    -1   1    0
[e3] |  -1   0    1    0
[e4] |  -1   0    0    1
[e5] |  0    0    1    -1

Do you want to edit it? (y/n): y
Type the number of edge you want to edit: 1
Type the number of vertex you want to edit: 4

In place of the entered coordinates is the value 1
Please, type a new value: 0

This is your new Incidence Matrix:
      [v1]  [v2]  [v3]  [v4]
    +--------------------+
[e1] |  -1   1    0    0
[e2] |  0    -1   1    0
[e3] |  -1   0    1    0
[e4] |  -1   0    0    1   
[e5] |  0    0    1    -1

Do you want to edit it? (y/n): n
Okay, what would you want to do next?
----- MENU -----
1. Enter a graph
2. Display the graph
3. Quit
Enter your choice: 2

In what form do you want to display the graph?
1. Incidence Matrix
2. Adjacency Matrix
3. Adjacency List
4. <- Go back
Enter your choice: 3

 Vertex 1: 2 -> 3 -> 4 -> 0

 Vertex 2: 3 -> 0

 Vertex 3: 0

 Vertex 4: 3 -> 0

----- MENU -----
1. Enter a graph
2. Display the graph
3. Quit
Enter your choice: 2

In what form do you want to display the graph?
1. Incidence Matrix
2. Adjacency Matrix
3. Adjacency List
4. <- Go back
Enter your choice: 2
      [v1] [v2] [v3] [v4] 
     +--------------------+
[v1] |  0    1    1    1
[v2] |  0    0    1    0
[v3] |  0    0    0    0
[v4] |  0    0    1    0

----- MENU -----
1. Enter a graph
2. Display the graph
3. Quit
Enter your choice: 2

In what form do you want to display the graph?
1. Incidence Matrix
2. Adjacency Matrix
3. Adjacency List
4. <- Go back
Enter your choice: 1

The graph is directed
      [v1]  [v2]  [v3]  [v4]
    +--------------------+
[e1] |  -1   1    0    0
[e2] |  -1   0    1    0
[e3] |  -1   0    0    1
[e4] |  0    -1   1    0
[e5] |  0    0    1    -1

----- MENU -----
1. Enter a graph
2. Display the graph
3. Quit
Enter your choice: 1

In what form do you want to enter the graph?
1. Incidence Matrix
2. Adjacency Matrix
3. Adjacency List
4. <- Go back
Enter your choice: 2
Please, enter number of vertices: 4
Please fill the matrix with values:
0 1 1 1
0 0 1 0
0 0 0 0
0 0 1 0

Here is the entered Adjacency Matrix:
      [v1] [v2] [v3] [v4]
     +--------------------+
[v1] |  0    1    1    1
[v2] |  0    0    1    0
[v3] |  0    0    0    0
[v4] |  0    0    1    0

Do you want to edit it? (y/n): n

----- MENU -----
1. Enter a graph
2. Display the graph
3. Quit
Enter your choice: 2

In what form do you want to display the graph?
1. Incidence Matrix
2. Adjacency Matrix
3. Adjacency List
4. <- Go back
Enter your choice: 1

The graph is directed
      [v1]  [v2]  [v3]  [v4]
    +--------------------+
[e1] |  -1   1    0    0
[e2] |  -1   0    1    0
[e3] |  -1   0    0    1
[e4] |  0    -1   1    0
[e5] |  0    0    1    -1

----- MENU -----
1. Enter a graph
2. Display the graph
3. Quit
Enter your choice: 2

In what form do you want to display the graph?
1. Incidence Matrix
2. Adjacency Matrix
3. Adjacency List
4. <- Go back
Enter your choice: 3

 Vertex 1: 2 -> 3 -> 4 -> 0

 Vertex 2: 3 -> 0

 Vertex 3: 0

 Vertex 4: 3 -> 0

----- MENU -----
1. Enter a graph
2. Display the graph
3. Quit
Enter your choice: 2

In what form do you want to display the graph?
1. Incidence Matrix
2. Adjacency Matrix
3. Adjacency List
4. <- Go back
Enter your choice: 1

The graph is directed
      [v1]  [v2]  [v3]  [v4]
    +--------------------+
[e1] |  -1   1    0    0
[e2] |  -1   0    1    0
[e3] |  -1   0    0    1
[e4] |  0    -1   1    0
[e5] |  0    0    1    -1

----- MENU -----
1. Enter a graph
2. Display the graph
3. Quit
Enter your choice: 1

In what form do you want to enter the graph?
1. Incidence Matrix
2. Adjacency Matrix
3. Adjacency List
4. <- Go back
Enter your choice: 3
Please, enter number of vertices: 4
Fill the list, when you're done with a vertex, type 0.
Vertex 1: 2
Vertex 1: 2 -> 3
Vertex 1: 2 -> 3 -> 4
Vertex 1: 2 -> 3 -> 4 -> 0
Vertex 1: 2 -> 3 -> 4 -> 0 -> 

Vertex 2: 3
Vertex 2: 3 -> 0
Vertex 2: 3 -> 0 -> 

Vertex 3: 0
Vertex 3: 0 -> 

Vertex 4: 3
Vertex 4: 3 -> 0
Vertex 4: 3 -> 0 -> 


Here is the entered Adjacency List:

 Vertex 1: 2 -> 3 -> 4 -> 0

 Vertex 2: 3 -> 0

 Vertex 3: 0

 Vertex 4: 3 -> 0

Do you want to edit it? (y/n): n

----- MENU -----
1. Enter a graph
2. Display the graph
3. Quit
Enter your choice: 2

In what form do you want to display the graph?
1. Incidence Matrix
2. Adjacency Matrix
3. Adjacency List
4. <- Go back
Enter your choice: 1

The graph is directed
      [v1]  [v2]  [v3]  [v4]
    +--------------------+
[e1] |  -1   1    0    0
[e2] |  -1   0    1    0
[e3] |  -1   0    0    1
[e4] |  0    -1   1    0
[e5] |  0    0    1    -1

----- MENU -----
1. Enter a graph
2. Display the graph
3. Quit
Enter your choice: 2

In what form do you want to display the graph?
1. Incidence Matrix
2. Adjacency Matrix
3. Adjacency List
4. <- Go back
Enter your choice: 2
      [v1] [v2] [v3] [v4] 
     +--------------------+
[v1] |  0    1    1    1
[v2] |  0    0    1    0
[v3] |  0    0    0    0
[v4] |  0    0    1    0

----- MENU -----
1. Enter a graph
2. Display the graph
3. Quit
Enter your choice: 2

In what form do you want to display the graph?
1. Incidence Matrix
2. Adjacency Matrix
3. Adjacency List
4. <- Go back
Enter your choice: 3

 Vertex 1: 2 -> 3 -> 4 -> 0

 Vertex 2: 3 -> 0

 Vertex 3: 0

 Vertex 4: 3 -> 0

----- MENU -----
1. Enter a graph
2. Display the graph
3. Quit
Enter your choice: 3

Have a nice day!
```

## Лабораторная работа №2
**Алгоритм Белмана-Калаба для поиска минимального пути**

:page_facing_up:[Код программы](lab2-minimum-path-by-bellman-kalaba.c)

###### Пример работы программы
```bash
 == Bellman-Kalaba algorithm to find minimum path ==
Please, enter number of rows of the adjacency matrix: 8
Please, enter number of collumns of the adjacency matrix: 8
Okay, thanks! Creating the matrix...
The matrix has been created!
Please, fill up the matrix. For infinity value, write -1:
0 2 6 -1 8 -1 -1 -1
-1 0 2 2 -1 -1 -1 -1
-1 -1 0 1 2 -1 4 -1 
-1 -1 -1 0 3 3 -1 6 
-1 -1 -1 -1 0 1 2 4 
-1 -1 -1 -1 -1 0 -1 2
-1 -1 -1 -1 -1 -1 0 2
-1 -1 -1 -1 -1 -1 -1 0
Great! Matrix has been filled. Here is your adjacency matrix:
      1    2    3    4    5    6    7    8
  +----------------------------------------
1 |   0    2    6   oxo   8   oxo  oxo  oxo
2 |  oxo   0    2    2   oxo  oxo  oxo  oxo
3 |  oxo  oxo   0    1    2   oxo   4   oxo
4 |  oxo  oxo  oxo   0    3    3   oxo   6
5 |  oxo  oxo  oxo  oxo   0    1    2    4  
6 |  oxo  oxo  oxo  oxo  oxo   0   oxo   2
7 |  oxo  oxo  oxo  oxo  oxo  oxo   0    2
8 |  oxo  oxo  oxo  oxo  oxo  oxo  oxo   0

Now let's run the Bellman-Kalaba algorithm to find a minimum path...
Fill the first vector:
      1    2    3    4    5    6    7    8
  +----------------------------------------
1 |   0    2    6   oxo   8   oxo  oxo  oxo
2 |  oxo   0    2    2   oxo  oxo  oxo  oxo
3 |  oxo  oxo   0    1    2   oxo   4   oxo 
4 |  oxo  oxo  oxo   0    3    3   oxo   6
5 |  oxo  oxo  oxo  oxo   0    1    2    4
6 |  oxo  oxo  oxo  oxo  oxo   0   oxo   2
7 |  oxo  oxo  oxo  oxo  oxo  oxo   0    2
8 |  oxo  oxo  oxo  oxo  oxo  oxo  oxo   0
V0|  oxo  oxo  oxo   6    4    2    2    0

Fill the second vector:
      1    2    3    4    5    6    7    8
  +----------------------------------------
1 |   0    2    6   oxo   8   oxo  oxo  oxo
2 |  oxo   0    2    2   oxo  oxo  oxo  oxo
3 |  oxo  oxo   0    1    2   oxo   4   oxo 
4 |  oxo  oxo  oxo   0    3    3   oxo   6
5 |  oxo  oxo  oxo  oxo   0    1    2    4
6 |  oxo  oxo  oxo  oxo  oxo   0   oxo   2
7 |  oxo  oxo  oxo  oxo  oxo  oxo   0    2
8 |  oxo  oxo  oxo  oxo  oxo  oxo  oxo   0
V0|  oxo  oxo  oxo   6    4    2    2    0
V1|  12    8    6    5    3    2    2    0

Fill other vectors until last 2 vectors are same...

The final matrix:
      1    2    3    4    5    6    7    8
  +----------------------------------------
1 |   0    2    6   oxo   8   oxo  oxo  oxo
2 |  oxo   0    2    2   oxo  oxo  oxo  oxo
3 |  oxo  oxo   0    1    2   oxo   4   oxo
4 |  oxo  oxo  oxo   0    3    3   oxo   6
5 |  oxo  oxo  oxo  oxo   0    1    2    4
6 |  oxo  oxo  oxo  oxo  oxo   0   oxo   2  
7 |  oxo  oxo  oxo  oxo  oxo  oxo   0    2
8 |  oxo  oxo  oxo  oxo  oxo  oxo  oxo   0
V0|  oxo  oxo  oxo   6    4    2    2    0
V1|  12    8    6    5    3    2    2    0
V2|  10    7    5    5    3    2    2    0
V3|   9    7    5    5    3    2    2    0
V4|   9    7    5    5    3    2    2    0

Minimum path length between vertex 1 and 8 is 9

Calculating concrete minimum path...
P(12) = V1 - V2  |  2 = 9 - 7
P(23) = V2 - V3  |  2 = 7 - 5
P(24) = V2 - V4  |  2 = 7 - 5
P(35) = V3 - V5  |  2 = 5 - 3
P(46) = V4 - V6  |  3 = 5 - 2
P(56) = V5 - V6  |  1 = 3 - 2
P(68) = V6 - V8  |  2 = 2 - 0
P(78) = V7 - V8  |  2 = 2 - 0

Concrete minimum path is:
1 -> 2 -> 3 -> 5 -> 6 -> 8
```