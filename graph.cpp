#ifndef GRAPH_CPP
#define GRAPH_CPP

#include "graph.h"

template<class LabelType>
Graph<LabelType>::Graph() {}

//add a vertex if it doesn't exist
template<class LabelType>
bool Graph<LabelType>::add(LabelType start, LabelType end, int edgeWeight) {
    //add start vertex if not present
    if (std::find(vertices.begin(), vertices.end(), start) == vertices.end()) {
        vertices.push_back(start);
    }
    //add end vertex if not present
    if (std::find(vertices.begin(), vertices.end(), end) == vertices.end()) {
        vertices.push_back(end);
    }
    //add the edge
    if (adjacencyList[start].find(end) == adjacencyList[start].end()) {
        adjacencyList[start][end] = edgeWeight;
        adjacencyList[end][start] = edgeWeight; // Assuming undirected graph
        return true;
    }
    //edge already exists
    return false;
}

//remove an edge
template<class LabelType>
bool Graph<LabelType>::remove(LabelType start, LabelType end) {
    bool removed = false;
    if (adjacencyList.find(start) != adjacencyList.end()) {
        auto& neighbors = adjacencyList[start];
        if (neighbors.erase(end) > 0) {
            removed = true;
        }
    }
    if (adjacencyList.find(end) != adjacencyList.end()) {
        auto& neighbors = adjacencyList[end];
        if (neighbors.erase(start) > 0) {
            removed = true;
        }
    }
    return removed;
}

template<class LabelType>
int Graph<LabelType>::getEdgeWeight(LabelType start, LabelType end) const {
    auto it = adjacencyList.find(start);
    if (it != adjacencyList.end()) {
        auto it2 = it->second.find(end);
        if (it2 != it->second.end()) {
            return it2->second;
        }
    }
    throw std::invalid_argument("Edge does not exist between " + start + " and " + end);
}

template<class LabelType>
int Graph<LabelType>::getNumVertices() const {
    return vertices.size();
}

//get number of edges
template<class LabelType>
int Graph<LabelType>::getNumEdges() const {
    int count = 0;
    for (const auto& pair : adjacencyList) {
        count += pair.second.size();
    }
    return count / 2; // Since the graph is undirected
}

//dfs
template<class LabelType>
void Graph<LabelType>::depthFirstTraversal(LabelType start, void visit(LabelType&)) {
    std::unordered_map<LabelType, bool> visited;
    std::stack<LabelType> stack;
    stack.push(start);

    while (!stack.empty()) {
        LabelType current = stack.top();
        stack.pop();

        if (!visited[current]) {
            visit(current);
            visited[current] = true;
        }

        //push neighbors to stack
        if (adjacencyList.find(current) != adjacencyList.end()) {
            for (const auto& neighbor : adjacencyList.at(current)) {
                if (!visited[neighbor.first]) {
                    stack.push(neighbor.first);
                }
            }
        }
    }
}

//bfs
template<class LabelType>
void Graph<LabelType>::breadthFirstTraversal(LabelType start, void visit(LabelType&)) {
    std::unordered_map<LabelType, bool> visited;
    std::queue<LabelType> queue;
    queue.push(start);
    visited[start] = true;

    while (!queue.empty()) {
        LabelType current = queue.front();
        queue.pop();
        visit(current);

        //enqueue neighbors
        if (adjacencyList.find(current) != adjacencyList.end()) {
            for (const auto& neighbor : adjacencyList.at(current)) {
                if (!visited[neighbor.first]) {
                    queue.push(neighbor.first);
                    visited[neighbor.first] = true;
                }
            }
        }
    }
}

template<class LabelType>
const std::vector<LabelType>& Graph<LabelType>::getVertices() const {
    return vertices;
}

#endif
