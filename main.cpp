#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <iomanip>
#include "graph.h"

//function to read distances from file and build the graph
bool readDistances(const std::string& filename, Graph<std::string>& graph) {
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        std::cerr << "Error: Cannot open distance file: " << filename << std::endl;
        return false;
    }

    std::string from, to;
    int distance;
    while (infile >> from >> to >> distance) {
        graph.add(from, to, distance);
    }

    infile.close();
    return true;
}

//function to generate all permutations of cities excluding the starting city
void generatePermutations(std::vector<std::string>& cities, int start, int end, std::vector<std::vector<std::string>>& allPermutations) {
    if (start == end) {
        allPermutations.emplace_back(cities);
    } else {
        for (int i = start; i <= end; ++i) {
            std::swap(cities[start], cities[i]);
            generatePermutations(cities, start + 1, end, allPermutations);
            std::swap(cities[start], cities[i]); // backtrack
        }
    }
}

int main() {
    Graph<std::string> graph;
    const std::string distanceFile = "distances.txt";

    if (!readDistances(distanceFile, graph)) {
        return 1;
    }

    const std::string startCity = "Reno";

    //get list of cities excluding the starting city
    std::vector<std::string> cities = graph.getVertices();
    cities.erase(std::remove(cities.begin(), cities.end(), startCity), cities.end());

    //generate all permutations
    std::vector<std::vector<std::string>> allPermutations;
    generatePermutations(cities, 0, cities.size() - 1, allPermutations);

    std::ofstream outfile("paths_output.txt");
    if (!outfile.is_open()) {
        std::cerr << "Error: Cannot open output file: paths_output.txt" << std::endl;
        return 1;
    }

    double fuelEfficiency = 40.0; // mpg
    double gasPrice = 3.5; // $ per gallon
    double minCost = std::numeric_limits<double>::max();
    std::vector<std::string> bestPath;
    double bestTotalDistance = 0.0;

    //iterate through all permutations to find the best path
    for (const auto& perm : allPermutations) {
        double totalDistance = 0.0;
        std::string previousCity = startCity;
        std::string path = startCity;

        bool validPath = true;
        for (const auto& city : perm) {
            try {
                int distance = graph.getEdgeWeight(previousCity, city);
                totalDistance += distance;
                path += " -> " + city;
                previousCity = city;
            } catch (const std::invalid_argument& e) {
                std::cerr << "Warning: " << e.what() << ". Skipping this permutation." << std::endl;
                validPath = false;
                break;
            }
        }

        if (!validPath) continue;

        //return starting city
        try {
            int distance = graph.getEdgeWeight(previousCity, startCity);
            totalDistance += distance;
            path += " -> " + startCity;
        } catch (const std::invalid_argument& e) {
            std::cerr << "Warning: " << e.what() << ". Skipping this permutation." << std::endl;
            continue;
        }

        //calculate gas cost
        double gasUsed = totalDistance / fuelEfficiency;
        double cost = gasUsed * gasPrice;

        //write to file
        outfile << path << " | Total Distance: " << totalDistance << " miles | Gas Cost: $" << std::fixed << std::setprecision(2) << cost << std::endl;

        //check for minimum cost
        if (cost < minCost) {
            minCost = cost;
            bestPath = perm;
            bestPath.insert(bestPath.begin(), startCity);
            bestPath.push_back(startCity);
            bestTotalDistance = totalDistance;
        }
    }

    //write best path
    if (!bestPath.empty()) {
        outfile << "\nBest Path:\n";
        std::string bestPathStr;
        for (size_t i = 0; i < bestPath.size(); ++i) {
            bestPathStr += bestPath[i];
            if (i != bestPath.size() - 1) bestPathStr += " -> ";
        }
        double bestGasUsed = bestTotalDistance / fuelEfficiency;
        double bestTotalCost = bestGasUsed * gasPrice;
        outfile << bestPathStr << " | Total Distance: " << bestTotalDistance << " miles | Gas Cost: $" << std::fixed << std::setprecision(2) << bestTotalCost << std::endl;
    } else {
        outfile << "No valid path found." << std::endl;
    }

    outfile.close();

    std::cout << "All possible paths have been written to paths_output.txt" << std::endl;
    std::cout << "Best path has been identified." << std::endl;

    return 0;
}
