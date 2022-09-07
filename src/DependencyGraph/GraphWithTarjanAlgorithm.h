/*
 *
 *  Copyright 2021  BLIND.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 */
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GraphWithTarjanAlgorithmWithTarjanAlgorithm.h
 * Author: alessandro
 *
 * Created on March 12, 2017, 6:44 PM
 */

#ifndef GRAPHWITHTARJANALGORITHM_H
#define GRAPHWITHTARJANALGORITHM_H

// A C++ program to find strongly connected components in a given
// directed graph using Tarjan's algorithm (single DFS)
#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <string>
#define NIL -1
 
struct Vertex
{
    int id;
    std::string name;
    std::vector <unsigned int> rules;
    Vertex():id(-1),name("Invalid vertex"){};
    Vertex(int _id, std::string name_):id(_id),name(name_){};
    void addRule (int ruleID){
        rules.push_back(ruleID);
    }
};

// A class that represents an directed graph
class GraphWithTarjanAlgorithm
{
    std::vector< std::list<unsigned>  > adj;  
 
    // A Recursive DFS based function used by SCC()
    void SCCUtil(unsigned u, unsigned disc[], unsigned low[],
                 std::stack<unsigned>& st, bool stackMember[], std::vector< std::vector<unsigned> >& scc);
public:
    GraphWithTarjanAlgorithm(){}
    void addEdge(unsigned int v, unsigned int w);   // function to add an edge to graph
    void addNode(unsigned int v);   // function to add a node to graph
    const std::vector< std::vector <unsigned> > SCC() ;    // prints strongly connected components
    unsigned getNodeSize(){return adj.size();}
    std::list<unsigned> getAdjForNode(unsigned node){return adj[node];}
};



#endif /* GRAPHWITHTARJANALGORITHM_H */ 