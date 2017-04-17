#include <bits/stdc++.h>
using namespace std;

#define V 4
#define INF 999999


void floyd_warshall(int graph[][V]){
	int dist[V][V];

	for(int i=0;i<V;i++)
		for(int j=0;j<V;j++)
			dist[i][j] = graph[i][j];

	for(int i=0;i<V;i++)
		for(int j=0;j<V;j++)
			for(int k=0;k<V;k++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			printf("%3d\t", ((dist[i][j] == INF) ? -1 : dist[i][j]));
		}
		cout<<"\n";
	}
}

int main(){
    int graph[V][V] = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };

	floyd_warshall(graph);
	
	return 0;
}
