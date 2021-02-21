# Дискретная математика :computer:
<img align="right" hegiht="100" alt="UTM logo" src="images/utm-logo.png">
В этом репозитории представлены работы по дискретной математике, выполненные мной, студенткой университета UTM, группы TI-202FR, Гамурарь Яной.

## Лабораторная работа №2
**Алгоритм Белмана-Калаба для поиска минимального пути**

:page_facing_up:[Код программы поиска минимального пути с помощью алгоритма Белмана-Калаба](lab2-minimum-path-by-bellman-kalaba.c)

###### Пример работы программы
```shell
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

Now let\'s run the Bellman-Kalaba algorithm to find a minimum path...
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