#include <stdio.h>
#include "ALGraphBFS.h"
#include "ALGraphBFS.c"

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

  BFShowGraphVertex(&graph, A);
  printf("\n");
  BFShowGraphVertex(&graph, B);
  printf("\n");
  BFShowGraphVertex(&graph, C);
  printf("\n");
  BFShowGraphVertex(&graph, D);
  printf("\n");
  BFShowGraphVertex(&graph, E);
  printf("\n");

  GraphDestroy(&graph);
  return 0;
}