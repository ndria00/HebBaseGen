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
 * File:   GraphWithTarjanAlgorithm.cpp
 * Author: alessandro
 * 
 * Created on March 12, 2017, 6:44 PM
 */

#include "GraphWithTarjanAlgorithm.h"


void GraphWithTarjanAlgorithm::addNode(unsigned int v) {
    if (v >= adj.size()){
        for (unsigned int i = adj.size(); i <= v; i++){
            adj.push_back(std::list<unsigned>());
            labels.push_back(std::list<std::pair<unsigned, bool>>());
        }
    }
}

void GraphWithTarjanAlgorithm::addEdge(unsigned int v, unsigned int w, bool label) {
    if (v >= adj.size() || w >= adj.size()) {
        if (v >= w){
            for (unsigned int i = adj.size(); i <= v; i++){
                adj.push_back(std::list<unsigned>());
                labels.push_back(std::list<std::pair<unsigned, bool>>());
            }
        }
        else{
            for (unsigned int i = adj.size(); i <= w; i++){
                adj.push_back(std::list<unsigned>());
                labels.push_back(std::list<std::pair<unsigned, bool>>());

            }
        }
    }
    adj[v].push_back(w);
    labels[v].push_back(std::make_pair(v, label));
}

// A recursive function that finds and prints strongly connected
// components using DFS traversal
// u --> The vertex to be visited next
// disc[] --> Stores discovery times of visited vertices
// low[] -- >> earliest visited vertex (the vertex with minimum
//             discovery time) that can be reached from subtree
//             rooted with current vertex
// *st -- >> To store all the connected ancestors (cthisould be part
//           of SCC)
// stackMember[] --> bit/index array for faster check whether
//                  a node is in stack

void GraphWithTarjanAlgorithm::SCCUtil(unsigned u, unsigned disc[], unsigned low[], std::stack<unsigned>& st,
        bool stackMember[], std::vector< std::vector <unsigned> > & scc) {
    // A static variable is used for simplicity, we can avoid use
    // of static variable by passing a pointer.
    static int time = 0;

    // Initialize discovery time and low value
    disc[u] = low[u] = ++time;
    st.push(u);
    stackMember[u] = true;

    // Go through all vertices adjacent to this
    std::list<unsigned>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i) {
        int v = *i; // v is current adjacent of 'u'

        // If v is not visited yet, then recur for it
        if (disc[v] == -1) {
            SCCUtil(v, disc, low, st, stackMember, scc);

            // Check if the subtree rooted with 'v' has a
            // connection to one of the ancestors of 'u'
            // Case 1 (per above discussion on Disc and Low value)
            low[u] = std::min(low[u], low[v]);
        }            // Update low value of 'u' only of 'v' is still in stack
            // (i.e. it's a back edge, not cross edge).
            // Case 2 (per above discussion on Disc and Low value)
        else if (stackMember[v] == true)
            low[u] = std::min(low[u], disc[v]);
    }

    // head node found, pop the stack and print an SCC
    unsigned w = 0; // To store stack extracted vertices
    if (low[u] == disc[u]) {
        unsigned currentSCCIndex = scc.size();
        scc.push_back(std::vector<unsigned>());
        while (st.top() != u) {
            w = (unsigned) st.top();
            scc[currentSCCIndex].push_back(w);
//            cout << w << " ";
            stackMember[w] = false;
            st.pop();
        }
        w = (unsigned) st.top();
//        cout << w << "\n";
        scc[currentSCCIndex].push_back(w);
        stackMember[w] = false;
        st.pop();
    }
}

// The function to do DFS traversal. It uses SCCUtil()

const std::vector< std::vector <unsigned> > GraphWithTarjanAlgorithm::SCC() {
    unsigned disc[adj.size()];
    unsigned low[adj.size()];
    bool stackMember [adj.size()];
    std::stack<unsigned> st;

    std::vector< std::vector <unsigned> > scc;

    // Initialize disc and low, and stackMember arrays
    for (unsigned int i = 0; i < adj.size(); i++) {
        disc[i] = NIL;
        low[i] = NIL;
        stackMember[i] = false;
    }

    // Call the recursive helper function to find strongly
    // connected components in DFS tree with vertex 'i'
    for (unsigned int i = 0; i < adj.size(); i++)
        if (disc[i] == NIL)
            SCCUtil(i, disc, low, st, stackMember, scc);
    numberOfSCC = scc.size();
    return scc;
}

const std::vector<std::list<std::pair<unsigned,bool>>> GraphWithTarjanAlgorithm::getLabels(){
    return labels;
}

unsigned GraphWithTarjanAlgorithm::getNumberOfScc()const{
    return numberOfSCC;
}

bool GraphWithTarjanAlgorithm::hasNegativeEdgeBetweenPredicates(unsigned n, unsigned m){
    if(n >= adj.size() || m >= adj.size())
        return false;
    
    for(const auto& it : labels[n]){
        if(it.first == m && !it.second){
            return true;
        }
    }
    return false;
}