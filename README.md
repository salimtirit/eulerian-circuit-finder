# Gotham City's BatSignal (Eulerian Circuit Finder)
This project involves solving a problem where Joker has dismantled the BatSignal and scattered 
its pieces across every road in Gotham City. 
The task is to help Commissioner Gordon find a quick route to collect all the pieces and assemble 
the BatSignal on the rooftop by traversing every single road in Gotham City.

The solution involves implementing **Hierholzer's Algorithm** to find an **Eulerian circuit** of an **Eulerian
graph**. Check the [link](https://www.geeksforgeeks.org/eulerian-path-and-circuit/) for the details of eulerian circuit. The algorithm finds and merges tours iteratively and picks a starting vertex for the circuit,
traversing non-traversed edges arbitrarily. It merges the found tour with the known Eulerian circuit 
and finds a vertex with non-traversed outgoing edges to start a new tour, repeating the iterations 
until the Eulerian circuit is fully constructed.

## Hierholzer’s Algorithm
<p align="center">
  <img src="https://user-images.githubusercontent.com/64011660/232126803-ae10cedd-35c2-46ee-8452-9606dc44f98f.png"/>
</p>


## Input and Output
The input is provided in a text file containing the map of Gotham City.
* The first line 
contains an integer denoting the total number of crossing points of roads (vertices). 
* The next V lines contain an integer (Vertex ID), another integer (D+) which is the out-degree of this vertex, and D+ integers that represent the Vertex IDs to which there is an edge from this vertex. 
* The last line contains an integer denoting the ID of the starting vertex.

The output is a sequence of vertex IDs separated by space, representing the route that contains all 
of the roads exactly once.

## Example
<p align="center">
  <img src="https://user-images.githubusercontent.com/64011660/232127617-c2d0c74a-28ba-4a0a-b9ec-661b53b47fcc.png"/>
  <img src="https://user-images.githubusercontent.com/64011660/232127649-c899e58e-d2bd-4636-b962-c56f4dbe6b63.png"/>
  <img src="https://user-images.githubusercontent.com/64011660/232127711-605e2cc3-3626-4bfe-b055-ac3cc12cc3d3.png"/>
</p>

## Compiling and Running The Program
To compile and run the program, use the following commands:

```
g++ *.cpp *.h -std=c++11 -o project3
./project3 <inputFile> <outputFile>
```

## Notes
* ID of the crossing points start from 0 and ends at V − 1.
* There might not be a path that goes through each edge exactly once. In this situation, the code reports "no path" and omits all execution of the Hierholzer's algorithm.
* Rather than using a different version of the algorithm you can find online, I sticked with the one stated in the pseudocode.
* All roads are one-way, i.e. directed.
* I was only allowed to utilize the default C++ library. No external code was used.

## Contributing
If you have any suggestions or find any issues with the code, please feel free to contribute to the project by opening a pull request or creating an issue.

## Credits
This is the third project of CMPE250 Data Structures and Algorithms class in Fall 2020 
