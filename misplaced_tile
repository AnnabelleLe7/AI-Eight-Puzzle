#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct State {
    vector<vector<int>>puzzle;
    int cost; //cost aka depth
    State* previous; //ptr to previous node

    State(vector<vector<int> p, int c, State* prev) {
        puzzle = p;
        cost = c;
        previous = prev;
    }

    vector <State*> next_states() const{
        vector<State*> next;
        int row = 0;
        int column = 0;

        //find where 0 (empty tile) is located
        bool zero_found = false;

        for (int i = 0; i < 3 && !zero_found; i++){
            for (int j = 0; j < 3 && !zero_found; j++){
                if (puzzle[i][j] == 0){
                    row = i;
                    column = j;
                    found = true;
                }
            }
        }
         //implement the possible moves
         //R,L,U,D

        const vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};  
        for (const auto& move : moves) {
            int new_row = row + move.first;
            int new_column = column + move.second;
            if (new_row >= 0 && new_row < 3 && new_column >= 0 && new_column < 3) {
                vector<vector<int>> new_puzzle = puzzle;
                swap(new_puzzle[row][column], new_puzzle[new_row][new_column]);
                next_states.push_back(new State(new_puzzle, cost + 1));
            }
        }
        return next_states;
    }

         bool reached_goal_state() const{
             return puzzle == goal_state;
    }

    //now for h(n) for misplaced tile
    //compare row/col in initial to goal and count++

    int h_n() {
        int count_h = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
            if (puzzle[i][j] != goal_state[i][j]) {
                ++count_h;         
            }
        }
     }
    return count_h;
    }

    //check to see if we reached goal state
    bool reached_goal_state() const{
        return puzzle == goal_state;
    }
};

//now implement a star search
//g(n)+h(n) = f(n), represented by int

void a_star_search(const vector<vector<int>>& initial_state) {
    priority_queue<pair<int, State*>, vector<pair<int, State*>>, greater<>>pq;
    set<vector<vector<int>>> visited; //to keep track of the visited states

    int nodes_expanded = 0;
    int max_queue_size = 0;

    State* initial= new State(initial_state, 0, nullptr);
        pq.push({initial->h_n(),initial}) //push initial state into queue; priority queue based on h(n)
        
        while (!pq.empty()) { //while priority queue is not empty, we get the next state and pop it off
        State* current = pq.top().second;
        pq.pop();

        max_queue_size = max(max_queue_size, pq.size());

         if (current->reached_goal_state(goal_state)) {
            cout << "Goal state!" << "\n" << "Solution Depth: " << current->cost << "\n";
            cout << "Nodes Expanded: " << nodes_expanded << "\n" << "Max Queue Size: " << max_queue_size;
            return;
        }
        else {
            visited.insert(current->puzzle); //insert the curr node into visited
            nodes_expanded++; 
            for (auto next : current->next_states()) { 
                if (!visited.count(next->puzzle)) { //if it has not been visited add to priority queue
                    pq.push({next->cost, next}); //push into queue with cost 
                     }
                }
            }
        }
        delete current;
    }




