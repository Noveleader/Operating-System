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


//BANKER's second, in the bankers algorithm if we get second request with more request, this algorithm solves it. 
#include <stdio.h>
void b_algo(int n, int m, int am[n][m], int mm[n][m], int need[n][m], int
avai[]){
int i, j, k;
int ca[m];
for(i=0; i<m; i++){
ca[i] = avai[i];
}
int f[n], ans[n], ind = 0;
for (k = 0; k < n; k++){
f[k] = 0;
}
int y = 0;
for (k = 0; k < n; k++){
for (i = 0; i < n; i++){
if (f[i] == 0){
int flag = 0;
for (j = 0; j < m; j++){
if (need[i][j] > ca[j]){
flag = 1;
break;
}
}
if (flag == 0){
ans[ind++] = i;
for (y = 0; y < m; y++)
ca[y] += am[i][y];
f[i] = 1;
}
}
}
}
int flag = 1;
for (int i = 0; i < n; i++){
if (f[i] == 0){
flag = 0;
printf("\nThe following system is not safe");
break;
}
}
if (flag == 1){
printf("\nFollowing is the SAFE Sequence\n");
for (i = 0; i < n - 1; i++)
printf(" P%d ->", ans[i]);
printf(" P%d", ans[n - 1]);
}
}
void resource_request(int n, int m, int am[n][m], int need[n][m], int mm[n][m], int
avai[]){
int i, j;
int flag = 1, flag1 = 1;
int pro;
scanf("%d", &pro);
int request[m];
for (i = 0; i < m; i++){
scanf("%d", &request[i]);
}
for (i = 0; i < n; i++){
if (request[i] > need[pro][i]){
flag = 0;
}
break;
}
if(flag == 1){
for (i = 0; i < n; i++){
if(request[i] > avai[i]){
flag1 = 0;
}
break;
}
}
if (flag1 == 1){
for (j = 0; j < m; j++){
am[pro][j] = am[pro][j] + request[j];
printf("%d ",am[pro][j]);
need[pro][j] = need[pro][j] - request[j];
avai[j] = avai[j] - request[j];
}
b_algo(n, m, am, mm, need, avai);
printf("\nFinal Available matrix: ");
for (i = 0; i < m; i++){
printf("%d ", avai[i]);
}
}
else{
if(flag == 0){
printf("Error occured, since process has exceeded its maximum claim");
}
else{
printf("Process should wait since resources are not available");
}
}
}
int main()
{
int n, m, i, j, k;
printf("Enter the number of process and resources: ");
scanf("%d %d", &n, &m);
int am[n][m], mm[n][m], avai[m];
printf("Enter Allocation Matrix: \n");
for (i=0; i<n; i++){
for (j=0; j<m; j++){
scanf("%d",&am[i][j]);
}
}
printf("\nEnter Max Matrix: \n");
for (i=0; i<n; i++){
for (j=0; j<m; j++){
scanf("%d",&mm[i][j]);
}
}
printf("\nEnter Available Matrix: \n");
for (i=0; i<m; i++){
scanf("%d",&avai[i]);
}
int need[n][m];
for (i = 0; i < n; i++){
for (j = 0; j < m; j++)
need[i][j] = mm[i][j] - am[i][j];
}
printf("\n(a) Need Matrix is given as: \n");
for (i = 0; i < n; i++){
for (j = 0; j < m; j++)
printf("%d ", need[i][j]);
printf("\n");
}
printf("(b)");
b_algo(n, m, am, mm, need, avai);
printf("\n(c) Enter the process and request made: ");
resource_request(n, m, am, need, mm, avai);
printf("\n(d) Enter the process and request made: ");
resource_request(n, m, am, need, mm, avai);
return 0;
}
