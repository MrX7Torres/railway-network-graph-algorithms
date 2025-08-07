# 🚄 Railway Network Simulation using Graph Algorithms

This project simulates a railway system using **directed graphs** and applies classical graph algorithms to compute reachability, minimum cost paths, and shortest paths from a source.

Developed as a final project for the **Data Structures course** at CUCEI, Universidad de Guadalajara.

## 🎯 Objective

To implement and apply:
- **Warshall's Algorithm**: for transitive closure (city connectivity)
- **Floyd's Algorithm**: for all-pairs shortest paths
- **Floyd with intermediate vertices**
- **Dijkstra's Algorithm**: shortest path from one city to others

## 🧩 Structure

The system is composed of the following C++ files:
- `Grafo.h`: Templated graph class with matrix representation
- `Grafo.cpp`: Method implementations for graph construction and algorithms
- `Main.cpp`: Interactive menu to load cities, run algorithms and save results

## 📋 Features

- Input number of cities, connections and costs
- Display adjacency/cost matrix
- Compute reachability matrix using Warshall
- Compute all-pairs shortest paths using Floyd
- Show intermediate vertices on shortest paths
- Compute shortest path from a single city with Dijkstra
- Export results to `.txt` files

## 🛠️ Technologies

- C++
- Standard Library (`<iostream>`, `<fstream>`, `<locale>`)

## 🧠 Team

Developed by **Equipo 7**:
- Jesús Antonio Torres Contreras
- Román Rodríguez María Fernanda
- Vivian Chávez Rubén Emilio

## 📄 License

This project is for academic and educational purposes.
