#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> get_puzzle(int n) { //use vector<vector for 2d grids
    vector<vector<int>> puzzle(n, vector<int>(n));
    set<int> used_number; // make sure numbers are unique 
    int total_tiles = n * n; 

    cout << "Enter your " << n << "x"<< n << " puzzle row by row.";
    cout << "Use numbers from 0 to " << total_tiles - 1 << ", where '0' is the empty tile.";

    for (int i = 0; i < n; i++){

        int j = 0; //column index 
        while (j < n) {
            int num; 
            cin >> num;

            if (used_number.count(num)) {
                cout << "Insert a different number. Only unique values are allowed.";
            }
            else {
                puzzle[i][j] = num;
                used_number.insert(num);
                j++;
            }
        }
    }
    return puzzle;
}

int main() {
    cout << "Welcome to my Eight Puzzle!" << endl;

    int input; 
    cout << "Type 1 to create your own puzzle. Type 2 for a default puzzle."
    cin >> input;

    //for own user-created puzzle:

    int n; 

     if (input == 1) {
        cout << "Please enter the puzzle size that you would like.";
        cin >> input;

        while (n < 3) { //they have to create a puzzle that is at least 3x3 or larger.
            cout << "Please insert a number larger than 2 to continue.";
            cin >> n;
        }
    } else {
        n = 3; 
    }

    vector<vector<int>> initial_state(n, vector<int>(n));
    vector<vector<int>> goal_state(n, vector<int>(n));

    if (input == 1) {
        initial_state = get_puzzle(n);

         goal_state = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 0 }
        }; // initialized a goal state for user-created puzzles.
        //Obtained this goal state example from professor example.
    }

    //this hard-coded example is obtained from a Youtube video. It is linked on my report.

    else if (input == 2) { //this is going to be hard-coded example (default)
        initial_state = {
            {2, 8, 3},
            {1, 6, 4},
            {7, 0, 5}
        };

        goal_state = {
            {1, 2, 3},
            {8, 0, 4},
            {7, 6, 5}
        };
    } 


//Now display the initial state:

cout << "Initial State: " << endl;
    for (auto& row : initial_state) {
        for (int num : row) cout << num << " ";
        cout << "\n";
    }
//Now display goal state:

    cout << "Goal Puzzle State: " << endl;
    for (auto& row : goal_state) {
        for (int num : row) cout << num << " ";
        cout << "\n";
    }


int choice; 

cout << "Select algorithm. (1) for Uniform Cost Search, (2) for Misplaced Tile Heuristic, and (3) for Manhattan Distance Heuristic. ";
cin >> choice;

if (choice ==1) {
    cout << "Uniform Cost Search chosen." << endl;
    uniform_cost_search(initial_state);
}
else if (choice == 2) {
    cout << "Misplaced Tile heuristic chosen." << endl;
    misplaced_tile(inital_state);
}
else if (choice == 3) {
    cout << "Manhattan Distance chosen." << endl;
    manhattan_distance(initial_state);
}
else {
    cout << "Not a valid choice. Please type 1, 2, or 3." << endl;
}
return 0;

}



    
