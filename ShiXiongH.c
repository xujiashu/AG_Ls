#include<string.h>
#include<stdio.h>
#define MAXN 100
#define true 1

char SID[MAXN][10];
int CID[MAXN];
char name[MAXN][10];
int score[MAXN][5];
int rear = 0;
int removed[MAXN];
char subjects[4][20] = {"Chinese", "Math", "English", "Coding"};


void
printMenu(void)
{
  printf("Welcome to Student Performance Management System (SPMS).\n\n");
  printf("1 - Add\n");
  printf("2 - Remove\n");
  printf("3 - Query\n");
  printf("4 - Show ranking\n");
  printf("5 - Show Statistics\n");
  printf("0 - Exit\n");
}

void
add(void)
{
  while(true)
  {
    char s[10];
    printf("Please enter the SID, CID, name and four scores. Enter 0 to finish.\n");
    scanf("%s", s);
    if(strcmp(s, "0") == 0) break;
    strcpy(SID[rear], s);
    scanf("%d %s %d %d %d %d", &CID[rear], name[rear],
        &score[rear][0], &score[rear][1], &score[rear][2], &score[rear][3]);
    score[rear][4] = score[rear][0] + score[rear][1] + score[rear][2] + score[rear][3] ;
    rear++;
  }
}

void
DQ(int isq)
{
  while(true)
  {
    char s[20];
    printf("Please enter the SID or name. Enter 0 to finish.\n");
    scanf("%s", s);
    if(strcmp(s, "0") == 0) break;
    int r = 0;
    int i;
    for(i=0; i<=rear; i++)
    {
      if(!removed[i])
      {
        if(strcmp(SID[i], s) == 0 || strcmp(name[i], s) == 0)
        {
          if(isq) printf("%s %d %s %d %d %d %d %d %.2f\n", SID[i], CID[i], name[i],
        score[i][0], score[i][1], score[i][2], score[i][3], score[i][4], score[i][4]/4.0);
        
          else
          {
            removed[i] = 1;
            r++;
          }
        }
      }
    }
    if(!isq) printf("%d student(s) removed.\n", r);
  }
}

void
rank(void)
{
  printf("Showing the ranklist hurts students's self-esteem. Don't do that.\n");
}

void
stat(void)
{
  int p, i, j, theCid;
  int pass[5];
  int subPass[4];
  int subTol[4];
  int subFail[4];
  memset(pass, 0, sizeof(pass));
  memset(subPass, 0, sizeof(subPass));
  memset(subTol, 0, sizeof(subTol));
  memset(subFail, 0, sizeof(subFail));

  printf("Please enter class Id, 0 for the whole statics.\n");
  scanf("%d", &theCid);
  for(i=0; i<=rear; i++)
  {
    if(!removed[i])
    {
      if(theCid == CID[i] || theCid == 0)
      {
        p = 0;
        for(j=0; j<4; j++)
        {
          if(score[i][j] >= 60)
          {
            p++;
            subPass[j]++;
            subTol[j] += score[i][j];
          }
          else
          {
            subFail[j]++;
            subTol[j] += score[i][j];
          }
        }
        pass[p]++;
      }
    }
  }
  for(i=0; i<4; i++)
  {
    printf("%s:\n", subjects[i]);
    printf("Average Score: %.2f\n", subTol[i]/(float)(subFail[i]+subPass[i]));
    printf("Number of passed students: %d\n", subPass[i]);
    printf("Number of failed students: %d\n", subFail[i]);
  }
  printf("\nOverall: \n");
  printf("Number of students who passed all subjects: %d\n", pass[4]);
  printf("Number of students who passed 3 or more subjects: %d\n", pass[4]+pass[3]);
  printf("Number of students who passed 2 or more subjects: %d\n", pass[4]+pass[3]+pass[2]);
  printf("Number of students who passed 1 or more subjects: %d\n", pass[4]+pass[3]+pass[2]+pass[1]);
  printf("Number of students who failed all subjects: %d\n", pass[0]);

}

int main()
{
  memset(removed, 0, sizeof(removed));
  while(true)
  {
    int choice;
    printMenu();
    scanf("%d", &choice);
    if(choice == 0) break;
    if(choice == 1) add();
    if(choice == 2) DQ(0);
    if(choice == 3) DQ(1);
    if(choice == 4) rank();
    if(choice == 5) stat();
  }
}
