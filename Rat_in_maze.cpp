// Rat in a maze 
// This will simply tell if there is a path or not, the rat will begin from top left and move to bottom right.
// Also rat will only move down and right.

#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<int>> s);

bool path_exists( vector<vector<int>> &maze , int x, int y , vector<vector<int>> &visited )
{
    if ( x == (maze.size() - 1) && y == (maze[0].size() - 1) )
    {
         visited[x][y] = 1;
        return true;
    }
    //cout <<" entees" << endl ; 
   // print (visited);
    if ( x <= (maze.size() - 1) && y <= (maze[0].size() - 1) && (maze[x][y] == 1) )
    {
        visited[x][y] = 1;
        if ( path_exists(maze,x+1,y,visited))
        {
            return true;
        }
        if ( path_exists(maze,x,y+1,visited))
        {
            return true;
        }
        visited[x][y] = 0;
    }
    return false;
}

void print(vector<vector<int>> s)
{
    for (auto x : s)
    {
        for ( auto y : x )
        {
            cout << y << " "; 
        }
        cout<< endl;
    }
}
int main( )
{
    vector<vector<int>> maze = {{1,0,1,0,1},{1,1,1,1,1},{0,1,0,1,0},{1,1,1,1,1}};
    vector<vector<int>> visited = maze;
    print(maze);
    for (int x = 0 ; x < maze.size() ; x++)
    {
        for ( int y = 0; y < maze[0].size() ; y ++ )
        {
            visited[x][y] = 0;
        }
    }

    cout << path_exists(maze,0,0,visited);
    cout << endl;
        print(visited);

}

