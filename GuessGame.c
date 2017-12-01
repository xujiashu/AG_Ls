#include<stdio.h>
#include<string.h>
#define maxn 100

int left, chance;
void guess(char ch);
int win, lose;
char s[maxn], s2[maxn];

int main()
{
  int rnd;
  while(scanf("%d%s%s", &rnd, s, s2) == 3 && rnd != -1)
  {
    printf("Round %d\n",rnd);
    win = lose = 0;
    left = strlen(s);
    chance = 7;
    int i;
    for(i=0; i<(int)strlen(s2); i++)
    {
      guess(s2[i]);
      if(win || lose) break;
    }
    if(win) printf("You Win.\n");
    else if(lose) printf("You lose.\n");
    else printf("You chickened out.\n");

  }
  return 0;
}

void guess(char ch)
{
  int i;
  int bad = 1;
  for(i=0; i<(int)strlen(s); i++)
  {
    if(s[i] == ch) 
    {
      left--;
      s[i] = ' ';
      bad = 0;
      break;
    }
  }
  if(bad) --chance;
  if(!chance) lose = 1;
  if(!left) win = 1;
}
