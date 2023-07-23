#include<iostream>
#include<string>
using namespace std;
int main()
{
   int n,i,j,max=0;
   scanf("%d",&n);
   struct student
   {
      int score;
      char name[20];
   };
   student std[2];
   for(i=0; i<n; i++)
   {
      scanf("%d",&std[i].score);
      scanf("%s",&std[i].name);
   }

   for(i=0;i<n-1;i++)
      {
      for(j=0;j<n-i-1;j++)
      {
         if(std[j].score<std[j+1].score)
         swap(std[j],std[j+1]);
      }
   }
   printf("%s",std[0].name);
   return 0;
}