The member states of the UN are planning to send  people to the moon. 
They want them to be from different countries. You will be given a list of pairs of astronaut ID's. 
Each pair is made of astronauts from the same country. 
Determine how many pairs of astronauts from different countries they can choose from.

Example
![image](https://github.com/lhgiang040504/dataStructure_and_Algorithms/assets/121398839/75acae76-5a06-4b75-9653-41c8cfa64983)

Function Description

Complete the journeyToMoon function in the editor below.

journeyToMoon has the following parameter(s):

int n: the number of astronauts
int astronaut[p][2]: each element  is a  element array that represents the ID's of two astronauts from the same country
Returns
- int: the number of valid pairs


Input Format

The first line contains two integers  and , the number of astronauts and the number of pairs.
Each of the next  lines contains  space-separated integers denoting astronaut ID's of two who share the same nationality.

Sample Input 0
5 3
0 1
2 3
0 4
Sample Output 0
6

Explanation 0
Persons numbered  belong to one country, and those numbered  belong to another. The UN has  ways of choosing a pair:
![image](https://github.com/lhgiang040504/dataStructure_and_Algorithms/assets/121398839/7245ebee-6586-4f01-89bf-ebfbb6127a4e)


Sample Input 1
4 1
0 2
Sample Output 1
5
Explanation 1
Persons numbered  belong to the same country, but persons  and  don't share countries with anyone else. The UN has  ways of choosing a pair:
![image](https://github.com/lhgiang040504/dataStructure_and_Algorithms/assets/121398839/847f029d-0a60-4c9d-9a20-6a4ccb3a0cb2)
