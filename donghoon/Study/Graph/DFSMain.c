#include <stdio.h>
#include "ALGraphDFS.h"
#include "ALGraphDFS.c"

int main(void)
{
  ALGraph graph;
  GraphInit(&graph, 4);

  AddEdge(&graph, A, B);
  AddEdge(&graph, A, C);
  AddEdge(&graph, A, D);
  AddEdge(&graph, B, D);
  AddEdge(&graph, C, D);

  ShowGraphEdgeInfo(&graph);

  DFShowGraphVertex(&graph, A);
  printf("\n");

  GraphDestroy(&graph);
  return 0;
}