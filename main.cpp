#include <iostream>
#include <queue>
#include <vector>
#include <conio.h>
#include <algorithm>
using namespace std;

void initalValueInput(int* a, int* b, int* c);
void BFS(vector< vector<int> > G, int startNode, int nodeNum);
void vectSort(int nodeNum, vector< vector <int> > & G);
int main()
{
   

    int nodeNum, edgeNum, startNode;
    //그래프 생성
    initalValueInput(&nodeNum, &edgeNum, &startNode);
    vector< vector<int> > G(nodeNum+1);  
   
int node1, node2;
//그래프의 두 정점을 간선개수 번 입력받아 무향 연결리스트 만들기. 
    for (int i = 1; i <= edgeNum; i++)
    {
        
        cin >> node1 >> node2;        
        G[node1].push_back(node2);//push_back하면 G[][0]부터 저장인거 잊지말기.
        G[node2].push_back(node1);
              
    }
   
    vectSort(nodeNum, G);
    BFS(G, startNode, nodeNum);
   
}

void initalValueInput(int* a, int* b, int* c)
{
    cin >> *a >> *b >> *c;
}

void BFS(vector< vector<int> > G, int startNode, int nodeNum)
{
    int node;
    queue<int> q;
    vector<int> visit(nodeNum + 1,0);
    visit[startNode] = 1;
    q.push(startNode);
    while (!q.empty())
    {
        node = q.front();
        
        for (int i=0; i < G[node].size(); i++)
        {
            if(!visit[G[node][i]])
            q.push(G[node][i]);
            visit[G[node][i]] = 1;
            
        }//정점에 연결된 방문한적 없는 다른 정점 queue 에 삽입
        cout << q.front() << " ";
        q.pop();
    }
 getchar();
}
void vectSort(int nodeNum,  vector< vector <int> > &G)
{
    for (int i = 1; i <= nodeNum; i++)
    {
        sort(G[i].begin(), G[i].end());
    }
}