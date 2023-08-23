Given a graph which consists of several edges connecting its nodes, find a subgraph of the given graph with the following properties:
-The subgraph contains all the nodes present in the original graph.
-The subgraph is of minimum overall weight (sum of all edges) among all such subgraphs.
-It is also required that there is exactly one, exclusive path between any two nodes of the subgraph.

One specific node S is fixed as the starting point of finding the subgraph using Prim's Algorithm.
Find the total weight or the sum of all edges in the subgraph.

Example

![image](https://github.com/lhgiang040504/dataStructure_and_Algorithms/assets/121398839/0fe5c646-cb17-404e-974d-612b54a41a5c)


Starting from node , select the lower weight edge, i.e. , weight .

Choose between the remaining edges, , weight , and , weight .
The lower weight edge is  weight .
All nodes are connected at a cost of . The edge  is not included in the subgraph.

Function Description
Complete the prims function in the editor below.
prims has the following parameter(s):

int n: the number of nodes in the graph
int edges[m][3]: each element contains three integers, two nodes numbers that are connected and the weight of that edge
int start: the number of the starting node

Function Description

Complete the prims function in the editor below.

prims has the following parameter(s):

int n: the number of nodes in the graph
int edges[m][3]: each element contains three integers, two nodes numbers that are connected and the weight of that edge
int start: the number of the starting node
