//
//  Djikstra.cpp
//  Djikstra5.0
//
//  Created by Deeksha Yogish on 5/1/15.
//  Copyright (c) 2015 Deeksha Yogish. All rights reserved.
//

#include "Djikstra.h"


Djikstra::Djikstra(){
    max_weight = std::numeric_limits<double>::infinity();
    
    room[0] = 12;
    room[1] = 13;
    room[2] = 14;
    room[3] = 15;
    
    

}


void Djikstra::DijkstraComputePaths(vertex_t source,
                                    const adjacency_list_t &adjacency_list,
                                    std::vector<weight_t> &min_distance,
                                    std::vector<vertex_t> &previous)
{
    int n = adjacency_list.size();
    min_distance.clear();
    min_distance.resize(n, std::numeric_limits<double>::infinity());
    min_distance[source] = 0;
    previous.clear();
    previous.resize(n, -1);
    std::set<std::pair<weight_t, vertex_t> > vertex_queue;
    vertex_queue.insert(std::make_pair(min_distance[source], source));
    
    while (!vertex_queue.empty())
    {
        weight_t dist = vertex_queue.begin()->first;
        vertex_t u = vertex_queue.begin()->second;
        vertex_queue.erase(vertex_queue.begin());
        
        // Visit each edge exiting u
        const std::vector<neighbor> &neighbors = adjacency_list[u];
        for (std::vector<neighbor>::const_iterator neighbor_iter = neighbors.begin();
             neighbor_iter != neighbors.end();
             neighbor_iter++)
        {
            vertex_t v = neighbor_iter->target;
            weight_t weight = neighbor_iter->weight;
            weight_t distance_through_u = dist + weight;
            if (distance_through_u < min_distance[v]) {
                vertex_queue.erase(std::make_pair(min_distance[v], v));
                
                min_distance[v] = distance_through_u;
                previous[v] = u;
                vertex_queue.insert(std::make_pair(min_distance[v], v));
                
            }
            
        }
    }
}


std::list<vertex_t> Djikstra::DijkstraGetShortestPathTo(
                                                        vertex_t vertex, const std::vector<vertex_t> &previous)
{
    std::list<vertex_t> path;
    for ( ; vertex != -1; vertex = previous[vertex])
        path.push_front(vertex);
    return path;
}




