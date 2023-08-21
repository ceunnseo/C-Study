#include <stdio.h>
#include "ALGraphDFS.h"
#include "ALGraphDFS.c"

int main(void)
{
  ALGraph graph;
  GraphInit(&graph, 5);

  AddEdge(&graph, A, B);
  AddEdge(&graph, A, C);
  AddEdge(&graph, A, D);
  AddEdge(&graph, B, D);
  AddEdge(&graph, D, E);

  ShowGraphEdgeInfo(&graph);

  DFShowGraphVertex(&graph, A);
  printf("\n");
  DFShowGraphVertex(&graph, B);
  printf("\n");
  DFShowGraphVertex(&graph, C);
  printf("\n");
  DFShowGraphVertex(&graph, D);
  printf("\n");
  DFShowGraphVertex(&graph, E);
  printf("\n");

  GraphDestroy(&graph);
  return 0;
}