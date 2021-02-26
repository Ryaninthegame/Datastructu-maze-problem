#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct node{
    int row, col, root;
};

struct node ans[10000];

void print_(struct node p){
	while(p.root!=-1){
		print_(ans[p.root]);
		cout<<p.row<<" "<<p.col<<endl;
		return;
	} 
	cout<<"1 1"<<endl;
}

int main(){
    int input[2];
    for(int i=0;i<2;i++){
    	cin>>input[i];
	}
    
    int m=input[0];int n=input[1];

    vector<int> temp_row;
    temp_row.assign(n,0);
    vector< vector<int> > temp_maze;
    temp_maze.assign(m,temp_row);

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int input;
            cin>>input;
            temp_maze[i][j]=input;
        }
    }
  
    m+=2;n+=2;
    vector<int> row;
    row.assign(n,1);
    vector< vector<int> > maze;
    maze.assign(m,row);

    for(int i=1;i<m-1;i++){
        for(int j=1;j<n-1;j++){
            maze[i][j]=temp_maze[i-1][j-1];
        }
    }

    vector<int> row_1;
    row_1.assign(n,0);
    vector< vector<int> > path;
    path.assign(m,row_1);

    int index=0;int length=0;

    int dir[8][2]={{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};

    queue<node> q;

    struct node start;
    start.row=1;
    start.col=1;
    start.root=-1;

    q.push(start);
    ans[0]=start;
    index++;

    while(!q.empty()){
        struct node temp=q.front();
        q.pop();
        if(temp.row==m-2 && temp.col==n-2){
            print_(temp);
        }
        else{
            for(int i=0;i<8;i++){
                int next_row=temp.row+dir[i][0];
                int next_col=temp.col+dir[i][1];
                if(path[next_row][next_col]==0 && maze[next_row][next_col]==0){
                    path[next_row][next_col]=1;
                    start.row=next_row;
                    start.col=next_col;
                    start.root=length;
                    q.push(start);
                    ans[index++]=start;
                }
            }
            length++;
        }
    }
}
