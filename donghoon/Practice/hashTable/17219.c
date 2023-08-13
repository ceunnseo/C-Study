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

int main(void)
{
  SiteInfo siteArr[MAX_SITE];
  int n, m;

  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++)
  {
    scanf("%s %s", (siteArr[i].address), (siteArr[i].pw));
  }

  char findSite[m][MAX_CHAR];
  for (int i = 0; i < m; i++)
  {
    scanf("%s", &findSite[i]);
    for (int j = 0; j < n; j++)
    {
      if (strcmp(&findSite[i], siteArr[j].address) == 0)
        printf("%s\n", siteArr[j].pw);
    }
  }
  return 0;
}
