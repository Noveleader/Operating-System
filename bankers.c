#include<stdio.h>
int main()
{
 int n,m,i,j,k,flag,l,indx=0;
 printf("Enter number of processes: ");
 scanf("%d",&n);
 printf("Enter number of resources: ");
 scanf("%d",&m);
 int max[n][m];
 int allo[n][m];
 int avai[n];
 int need[n][m];
 int f[n];
 int w[n];
 int ans[m];
 printf("Enter Max matrix: \n");
 for(i=0;i<n;i++)
 {
 for(j=0;j<m;j++)
 {
 printf("Enter value at position (%d%d) :",i+1,j+1);
 scanf("%d",&max[i][j]);
 }
 }
 printf("\nEnter Allocation matrix: \n");
 for(i=0;i<n;i++)
 {
 for(j=0;j<m;j++)
 {
 printf("Enter value at position (%d%d) :",i+1,j+1);
 scanf("%d",&allo[i][j]);
 }
 }
 printf("\nEnter Available matrix: \n");
 for(i=0;i<m;i++)
 {
 printf("Enter value at position (%d) :",i+1);
 scanf("%d",&avai[i]);
 }
 for(i=0;i<n;i++)
 {
 for(j=0;j<m;j++)
 {
 need[i][j]=max[i][j]-allo[i][j];
 }
 }
 printf("\nEnter Need matrix is: \n");
 for(i=0;i<n;i++)
 {
 for(j=0;j<m;j++)
 {
 printf("%d ",need[i][j]);
 }
 printf("\n");
 }
 //Work = Available
 for(i=0;i<m;i++)
 {
 w[i]=avai[i];
 }
 //Finish [i] = false for i = 0, 1, …, n- 1.
 for(i=0;i<n;i++)
 {
 f[i]=0;
 }
 for(k=0;k<n;k++)
 {
 for(i=0;i<n;i++)
 {
 if(f[i]==0)
 {
 flag=0;
 for(j=0;j<m;j++)
 {
 if(need[i][j]>avai[j])
 {
 flag=1;
 break;
 }
 }
 if(flag==0)
 {
 ans[indx++]=i;
 for(l=0;l<m;l++)
 {
 w[i]=w[i]+allo[l][i];
 }
 f[i]=1;
 }
 }
 }
 }
 if (flag == 1)
 {
 printf("Following is the SAFE Sequence\n");
 }

}
