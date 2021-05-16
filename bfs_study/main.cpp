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
    //�׷��� ����
    initalValueInput(&nodeNum, &edgeNum, &startNode);
    vector< vector<int> > G(nodeNum+1);  
   
int node1, node2;
//�׷����� �� ������ �������� �� �Է¹޾� ���� ���Ḯ��Ʈ �����. 
    for (int i = 1; i <= edgeNum; i++)
    {
        
        cin >> node1 >> node2;        
        G[node1].push_back(node2);//push_back�ϸ� G[][0]���� �����ΰ� ��������.
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
            
        }//������ ����� �湮���� ���� �ٸ� ���� queue �� ����
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