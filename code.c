#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct node{
    int checked;
    int arr[3][3];
    int stat;
    int new;
}node;


int check(int arr[3][3])
{  int i;
    for(i=0;i<3;i++)
    {
        if(arr[i][0]==arr[i][1]&&arr[i][1]==arr[i][2])
        {
            if(arr[i][0]==1) return 10;
            else if(arr[i][0]==0) return -10;
        }
    }
    for(i=0;i<3;i++)
    {
        if(arr[0][i]==arr[1][i]&&arr[1][i]==arr[2][i])
        {
            if(arr[0][i]==1) return 10;
            else if(arr[0][i]==0) return -10;
        }
    }
     if(arr[0][0]==arr[1][1]&&arr[1][1]==arr[2][2])
    {
    {        if(arr[0][0]==1) return 10;
            else if(arr[0][0]==0) return -10;
        }}
     else if(arr[0][2]==arr[1][1]&&arr[1][1]==arr[2][0])
    {   {
            if(arr[2][0]==1) return 10;
            else if(arr[2][0]==0) return -10;
        }}    
    return 0;
}


void evaluate(int turn,node *root)
{
    if(check(root->arr)==10||check(root->arr)==-10||root->checked==9)
    {
        root->stat=check(root->arr);
        return;
    }
    node* grid=(node*)malloc((9-root->checked)*sizeof(node));
    int i,j=0,x,y;
    for(i=0;i<(9-root->checked);i++)
    {
        while(root->arr[j/3][j%3]!=-1&&j<9) j++;
        for(x=0;x<3;x++)
        for(y=0;y<3;y++)
        grid[i].arr[x][y]=root->arr[x][y];
        grid[i].checked=root->checked+1;
        grid[i].stat=-1;
        grid[i].new=j;
        grid[i].arr[j/3][j%3]=turn;
        //printf("j=%d\n turn=%d\n",j,turn);
        j++;
        if(turn==0) evaluate(1,&grid[i]);
        else evaluate(0,&grid[i]);
    }
    for(i=0;i<(9-root->checked);i++)
    {
        if(turn==0&&grid[i].stat==-10)
        {root->stat=-10; return;}
        if(turn==1&&grid[i].stat==10)
        {root->stat=10;
        return;}
    }
    for(i=0;i<(9-root->checked);i++)
    {
        if(grid[i].stat==0)
        {
            root->stat=0;
            return;
        }

    }
    for(i=0;i<(9-root->checked);i++)
    {
        if(turn==0&&grid[i].stat==10)
        {root->stat=10;return;}
        if(turn==1&&grid[i].stat==-10)
        {root->stat=-10;return;}
    }
}
void assign(int oarr[3][3],int ochecked)
{
    node* staray=(node*)malloc((9-ochecked)*sizeof(node));
    int j=0,i,x,y;
    for(i=0;i<(9-ochecked);i++)
    {
        while(oarr[j/3][j%3]!=-1&&j<9) j++;
        for(x=0;x<3;x++)
        for(y=0;y<3;y++)
        staray[i].arr[x][y]=oarr[x][y];
        staray[i].checked=ochecked+1;
        staray[i].stat=-1;
        staray[i].new=j;
        staray[i].arr[j/3][j%3]=1;
        j++;
        if(check(staray[i].arr)==10)
        {
            oarr[staray[i].new/3][staray[i].new%3]=1;return;}
    
        evaluate(0,&staray[i]);
    }

    for(i=0;i<(9-ochecked);i++)
    {
        if(staray[i].stat==10)
        {
            oarr[staray[i].new/3][staray[i].new%3]=1;return;}
    }
    for(i=0;i<(9-ochecked);i++)
    {
        if(staray[i].stat==0)
        {
            oarr[staray[i].new/3][staray[i].new%3]=1;return;}
    }
    for(i=0;i<(9-ochecked);i++)
    {
        if(staray[i].stat==-10)
        {
            oarr[staray[i].new/3][staray[i].new%3]=1;return;}
    }
}   
void main()
{
    int arr[3][3]={-1,-1,-1,-1,-1,-1,-1,-1,-1};
    int i,checked=1,entr,x;
    x=x%9;
    scanf("%d",&entr);
        arr[entr/3][entr%3]=0;
    for(i=0;i<9;i++)
        {
            if(i%3==0)
            printf("\n");
            printf("%d ",arr[i/3][i%3]);
        }
    while(checked<9)
    {
        if(checked>1){
            scanf("%d",&entr);
            arr[entr/3][entr%3]=0;
            checked++;
            for(i=0;i<9;i++)
            {
                if(i%3==0)
                printf("\n");
                printf("%d ",arr[i/3][i%3]);
            }
        }
        printf("\n");
        assign(arr,checked);
        checked++;
        for(i=0;i<9;i++)
        {
            if(i%3==0)
            printf("\n");
            printf("%d ",arr[i/3][i%3]);
        }
    }
}
