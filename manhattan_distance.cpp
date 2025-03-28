#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct State {
    vector<vector<int>>puzzle;
    int cost; //cost aka depth
    int total_cost;
    State* previous; //ptr to previous node

    State(vector<vector<int>> p, int c, State* prev) {
        puzzle = p;
        cost = c;
        previous = prev;
    }

    //find the manhattan distance
    //sum absolute distance of row/column from initial distance to goal distance

    int manhattan_distance(const vector<vector<int>>& goal) {
        int distance = 0;
        int initial_row;
        int initial_column;
        int goal_row;
        int goal_column;

        for (int tile = 1; tile <= 8; tile++){
            find_position_initial(tile,initial_row, initial_column);
            find_position_goal(tile, goal, goal_row, goal_column);
            distance += (abs(curr_row - goal_row) + abs(curr_col - goal_col));
        }
        return distance;
    }
    
    void find_position_initial(int tile, int& row, int& column) {
        for(row = 0; row < 3; row++){
            for (column=0; column < 3; column++){
                if (puzzle[row][column] == tile){
                    return;
                }
            }
        }
    }
    void find_position_goal(int tile, const vector<vector<int>>& goal, int& row, int& column) {
        for(row = 0; row < 3; row++){
            for (column=0; column < 3; column++){
                if (goal[row][column] == tile){
                    return;
                }
            }
        }
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
                    column = j
                    found = true;
                }
            }
        }
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
}





