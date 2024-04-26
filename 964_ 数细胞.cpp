#include<iostream>
#include<cstdlib>
using namespace std;
#define max 50000

bool visited[50][50];

struct pos {
	int x;
	int y;
};

typedef struct se
{
	pos data[max];
	int front,rear;
} Sequeue;

void init(Sequeue *&Q)
{
	Q=(Sequeue *)malloc(sizeof(Sequeue));
	Q->front=-1;
	Q->rear=-1;
}


int empty(Sequeue *Q)
{
	if(Q->rear==Q->front)
		return 1;
	else
		return 0;
}

void insertsequeue(Sequeue *&Q,int i,int j)
{
	if((Q->rear+1)%max==Q->front)
	{
		cout<<"队列已满！"<<endl;
		exit(0);
	}
	Q->rear=(Q->rear+1)%max;
	Q->data[Q->rear].x=i;
	Q->data[Q->rear].y=j;
}

void delsequeue(Sequeue *&Q,int &i,int &j)
{
	if(Q->rear==Q->front)
	{
		cout<<"队列已空！"<<endl;
		exit(0);
	}
	Q->front=(Q->front+1)%max;
	i=Q->data[Q->front].x;
	j=Q->data[Q->front].y;
}

void bfs(int a[][50],bool visited[][50], const pos &pos, int m, int n){
    Sequeue* seq = nullptr;
    init(seq);
    insertsequeue(seq, pos.x, pos.y);
    int direct[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while(!empty(seq)){
        struct pos temp;
        delsequeue(seq, temp.x, temp.y);
        // cout << temp.x << " " << temp.y << endl;
        for(int i = 0; i < 4;i++){
            struct pos t = temp;
            t.x = t.x + direct[i][0];
            t.y = t.y + direct[i][1];
            if(((t.x>=0 && t.x<m) && (t.y>=0 && t.y<n)) && !visited[t.x][t.y] && a[t.x][t.y] !=0){
                insertsequeue(seq, t.x, t.y);
            }
            visited[t.x][t.y] = 1;
        }
    }
    free(seq);
}

int count(int a[50][50], int m, int n)
{
	int x=0;
    int i, j;
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
           if(a[i][j] != 0 && !visited[i][j]){
                struct pos t;
                t.x = i;
                t.y = j;
                bfs(a, visited, t, m, n);
                x++;
           }
        }	
    }
	return x; //x为计算出在细胞在个数

}

int main()
{
	int test[50][50];
    
	int i,j, m,n;
	cin>>m;
	cin>>n;
	for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            cin>>test[i][j];
            visited[i][j] = 0;
        }	
    }
		
	cout<<count(test,m,n);
    return 0;
}