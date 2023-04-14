# Gotham City's BatSignal (Eulerian Circuit Finder)
This project involves solving a problem where Joker has dismantled the BatSignal and scattered 
its pieces across every road in Gotham City. 
The task is to help Commissioner Gordon find a quick route to collect all the pieces and assemble 
the BatSignal on the rooftop by traversing every single road in Gotham City.

The solution involves implementing Hierholzer's Algorithm to find an Eulerian circuit of an Eulerian
graph. The algorithm finds and merges tours iteratively and picks a starting vertex for the circuit,
traversing non-traversed edges arbitrarily. It merges the found tour with the known Eulerian circuit 
and finds a vertex with non-traversed outgoing edges to start a new tour, repeating the iterations 
until the Eulerian circuit is fully constructed.

## Input and Output
The input is provided in a text file containing the map of Gotham City, where the first line 
contains an integer denoting the total number of crossing points of roads (vertices). 
The next V lines contain an integer (Vertex ID), another integer (D+) which is the out-degree of 
this vertex, and D+ integers that represent the Vertex IDs to which there is an edge from this 
vertex. The last line contains an integer denoting the ID of the starting vertex.

The output is a sequence of vertex IDs separated by space, representing the route that contains all 
of the roads exactly once.

## Compiling and Running The Program
To compile and run the program, use the following commands:

```
g++ *.cpp -std=c++11 -o project3
./project3 input.txt output.txt
```
