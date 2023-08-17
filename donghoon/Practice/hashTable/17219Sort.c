#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 21
#define MAX_SITE 100000
typedef struct _siteInfo
{
  char address[MAX_CHAR];
  char pw[MAX_CHAR];
} SiteInfo;

int compare(const void *first, const void *second)
{
  return strcmp(((SiteInfo *)first)->address, ((SiteInfo *)second)->address);
}

binarySearch(SiteInfo *s, char *target, int end)
{
  int left = 0, right = end;
  while (left <= right)
  {
    int middle = (left + right) / 2;
    if (strcmp(s[middle].address, target) < 0)
      left = middle + 1;
    else if (strcmp(s[middle].address, target) > 0)
      right = middle - 1;
    else
    {
      return printf("%s \n", s[middle].pw);
    }
  }
}

int main(void)
{
  SiteInfo Site[MAX_SITE];
  int n, m;
  char find[MAX_CHAR];

  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++)
  {
    scanf("%s %s", (Site[i].address), (Site[i].pw));
  }

  qsort(Site, n, sizeof(SiteInfo), compare);

  for (int i = 0; i < m; i++)
  {
    scanf("%s", find);
    binarySearch(Site, find, n);
  }
  return 0;
}
