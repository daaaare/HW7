#ifndef GRAPH_H
#define GRAPH_H

#include "graphinterface.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#include <stdexcept>
#include <algorithm>

template<class LabelType>
class Graph : public GraphInterface<LabelType> {
public:
    Graph();
    virtual ~Graph() {}

    int getNumVertices() const override;
    int getNumEdges() const override;
    bool add(LabelType start, LabelType end, int edgeWeight) override;
    bool remove(LabelType start, LabelType end) override;
    int getEdgeWeight(LabelType start, LabelType end) const override;
    void depthFirstTraversal(LabelType start, void visit(LabelType&)) override;
    void breadthFirstTraversal(LabelType start, void visit(LabelType&)) override;

    const std::vector<LabelType>& getVertices() const;

private:
    std::vector<LabelType> vertices;

    //each vertex maps to a map of neighboring vertices and their edge weights
    std::unordered_map<LabelType, std::unordered_map<LabelType, int>> adjacencyList;
};

#include "graph.cpp"

#endif
