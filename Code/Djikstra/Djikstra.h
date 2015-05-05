//
//  Djikstra.h
//  Djikstra5.0
//
//  Created by Deeksha Yogish on 5/1/15.
//  Copyright (c) 2015 Deeksha Yogish. All rights reserved.
//

#ifndef __Djikstra5_0__Djikstra__
#define __Djikstra5_0__Djikstra__

//Aasif is not the best!
//#include "stdio.h"
//#include "mbed.h"
#include <vector>
#include <string>
#include <list>
#include <limits> // for numeric_limits
#include <set>
#include <utility> // for pair
#include <algorithm>
#include <iterator>

typedef int vertex_t;
typedef double weight_t;
typedef std::string direction_t;
struct neighbor {
    vertex_t target;
    weight_t weight;
    direction_t direction;
    neighbor(vertex_t arg_target, weight_t arg_weight, direction_t arg_direction)
    : target(arg_target), weight(arg_weight), direction(arg_direction) { }
};
typedef std::vector<std::vector<neighbor> > adjacency_list_t;

class Djikstra {
public:
    Djikstra();
    void DijkstraComputePaths(vertex_t source,
                              const adjacency_list_t &adjacency_list,
                              std::vector<weight_t> &min_distance,
                              std::vector<vertex_t> &previous);
    std::list<vertex_t> DijkstraGetShortestPathTo(
                                                  vertex_t vertex, const std::vector<vertex_t> &previous);

    
private:
    weight_t max_weight; //= std::numeric_limits<double>::infinity();
    int room[4];// = {12,13,14,15};

    
};
#endif /* defined(__Djikstra5_0__Djikstra__) */
