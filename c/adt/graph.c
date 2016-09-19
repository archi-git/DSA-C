void BFS (Vertex V)
{
	visited[V] = true;
	Enqueue(V, Q);
	while (!IsEmpty(Q) )
	{
		V = Dequeue(Q);
		for (V的每个邻接点W)
		{
			if (!visited[W])
			{
				visited[W] = true;
				Enqueue(W, Q);
			}
		}
	}
}
void DFS (Vertex V)
{
	visited[V] = true;
	for ( V的每个邻接点W )
	{
		if (!visited[W])
			DFS[W];
	}
}

//无权图的单源最短路径算法
void Unwighted ( Vertex S)
{
	Enqueue(V);
	while (!IsEmpty(Q))
	{
		V = Dequeue(Q);
		for ( V的每个邻接点W)
		{	
			if ( dist[W] = -1)
			{
				dist[W] = dist[V] + 1;
				path[W] = V;
			}
			Enqueue(W,Q);
		}
	}
}