#include<bits/stdc++.h> //including all the header files
using namespace std; //using the standard namespace

vector <int > graph[10]; //declaring a vector of size 10 to store the nodes
bool visited[10]; //declaring a boolean array of size 10 to check if the node is visited or not

void dfs(int source) //dfs function
{
    visited[source] = 1; //marking the source node as visited
    for(int i =0; i < graph[source].size(); i++) //traversing through the vector
    {
        int next = graph[source][i]; //storing the next node in the vector in the variable next
        if(visited[next] == 0) //checking if the next node is visited or not
        {
            dfs(next); //if not visited then calling the dfs function with the next node as the source
        }

    }

}


int main()
{
    int  nodes, edges; //declaring the number of nodes and edges
    cout<<"Enter number of nodes & Edges: "; //asking the user to enter the number of nodes and edges
    cin >> nodes >> edges; //taking input from the user

    for(int i = 1; i <= edges; i++) //traversing through the edges
    {
        int u, v; //declaring two nodes
        cin >> u >> v; //taking input from the user
        graph[u].push_back(v); //pushing the node v in the vector of node u
        graph[v].push_back(u); //pushing the node u in the vector of node v
    }
    dfs(3); //calling the dfs function with the source node as 3
    for(int i = 0; i <nodes; i++) //traversing through the nodes
    {
        if(visited[i] == 1) //checking if the node is visited or not
        {
            cout<<"Node "<< i << " is visited"<<endl; //if visited then printing the node is visited
        }
        else
        {
            cout<< "Node "<< i<< " is not visited"<<endl; //if not visited then printing the node is not visited
        }
    }

    return 0;
}

