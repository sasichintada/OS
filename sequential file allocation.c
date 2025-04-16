#include<stdio.h>
struct fileTable
{
char name[20];
int sb, nob;
}
ft[30];
 void main()
{
int i, j, n;
chars[20];
printf("Enter no of files:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\nEnter file name %d :",i+1);
scanf("%s",ft[i].name);
printf("Enterstarting block of file %d :",i+1);
scanf("%d",&ft[i].sb);
printf("Enter no of blocks in file %d :",i+1);
scanf("%d",&ft[i].nob);
}
printf("\nEnter the file name to be searched-- ");
scanf("%s",s);
for(i=0;i<n;i++)
if(strcmp(s, ft[i].name)==0)
Break;
if(i==n)
printf("\nFile Not Found");
else
{
printf("\nFILE NAME START BLOCK NO OF BLOCKS BLOCKS
OCCUPIED\n");
printf("\n%s\t\t%d\t\t%d\t",ft[i].name,ft[i].sb,ft[i].nob);
for(j=0;j<ft[i].nob;j++)
printf("%d, ",ft[i].sb+j);
}
}












INPUT :
Enter no of files :3
Enter file name 1 :A
Enterstarting block of file 1 :85
Enter no of blocks in file 1 :6
Enter file name 2 :B
Enterstarting block of file 2 :102
Enter no of blocks in file 2 :4
Enter file name 3 :C
Enter starting block of file 3 :60
Enter no of blocks in file 3 :4
Enter the file name to be searched – B
OUTPUT :
FILE NAME   START BLOCK      NO OF BLOCKS     BLOCKS OCCUPIED
B                               102                              4              102, 103, 104, 105
