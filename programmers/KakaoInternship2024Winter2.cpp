#include <string>
#include <queue>
#include <vector>

using namespace std;

void BFS(int startNode);

vector<int> answer;
vector<vector<int>> graph(1000001, vector<int> ());
vector<bool> visited (1000001, false);
    
int maxNode = 0, mainNode = 0;
int circle = 0, list = 0, eight = 0;

vector<int> solution(vector<vector<int>> edges) {
    
    for(int i = 0; i < edges.size(); i++) {
        
        int start = edges[i][0];
        int end = edges[i][1];
        
        maxNode = max(maxNode, max(start, end));
        graph[start].push_back(end);
        visited[end] = true;
    }
    
    for(int i = 1; i <= maxNode; i++) {
        
        if(!visited[i] && graph[i].size() > 1) {
            
            mainNode = i;
        }
    }
    
    fill(visited.begin(), visited.end(), false);
    
    for(int i = 0; i < graph[mainNode].size(); i++) {
        
        BFS(graph[mainNode][i]);
    }
    
    answer = {mainNode, circle, list, eight};
    
    return answer;
}

void BFS(int startNode) {
    
    queue<int> q;
    q.push(startNode);
    int nodeCount = 0, edgesCount = 0;
    
    while(!q.empty()) {
        
        int nowNode = q.front();
        q.pop();
        nodeCount++;
        visited[nowNode] = true;
        
        for(int i = 0; i < graph[nowNode].size(); i++) {
            
            int nextNode = graph[nowNode][i];
            if(!visited[nextNode]) {
            
                q.push(nextNode);
            }
            edgesCount++;
        }
    }
    
    if(nodeCount == edgesCount) {
        circle++;
    } else if(nodeCount == edgesCount + 1) {
        list++;
    } else if(nodeCount + 1 == edgesCount) {
        eight++;
    }
}