#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

#define width 39
#define height 20

typedef struct head{
	int x;
	int y;
	int number;
	struct body *p;
} H;

typedef struct body{
	int x;
	int y;
	struct body *p;
} B;

typedef struct temp{
	int x;
	int y;
} T;

typedef struct food{
	int x;
	int y;
	
}F;

void mapping(int map[][width]);
int move(H head[],F food,int l,char choice,int i,int map[][width]);
int game_over();
void gotoxy(int x, int y,char *c);
void snake(int l,H head[]);
void make_food(H head[],int map[][width]);

int length=5;
int u;

int main(){
	int map[height][width]={
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	
	char choice=0;

	mapping(map);
	H snake_head[100];
	
	int x=18;
	int y=10;
	int i=1;
	int u;
	
	snake(length,snake_head);
	F food;
	
	make_food(snake_head,map);
	
	while(1){
		
		move(snake_head,food,length,choice,i,map);
		
		if(map[snake_head[0].y][snake_head[0].x]==2)
			make_food(snake_head,map);
		
		if(snake_head[0].x==width-1||snake_head[0].x==0||snake_head[0].y==height-1||snake_head[0].y==0)
			break;
		for(i=1;i<length;i++)
		if((snake_head[0].x==snake_head[i].x)&&(snake_head[0].y==snake_head[i].y))
			break;
	}
	game_over();
}

void mapping(int map[][width]){
	int x,y;
	for(y=0;y<20;y++){
		for(x=0;x<39;x++){
			if(map[y][x]==1){
				printf("бс");
			}
			if(map[y][x]==0){
				printf("  ");
			}
		}
		printf("\n");
	}
}

int move(H head[],F food,int l,char choice,int i,int map[][width]){
		int a;
		choice=getch();
		     
		switch(choice){
			case 'w':
				while(head[0].y!=0){
					for(i=l;i>0;i--){
						head[i].x=head[i-1].x;
						head[i].y=head[i-1].y;
						gotoxy(head[i-1].x,head[i-1].y,"бр");
						if(i==l)
						gotoxy(head[i-1].x,head[i-1].y," "); 
					}
					head[0].y--;
					gotoxy(head[0].x,head[0].y,"бс");
					
					if(map[head[0].y][head[0].x]==2){
						length++;
						make_food(head,map);
					}
					
		
					if(kbhit()){
						break;
					}
					Sleep(50);
				} 
				break;
			case 'a':
				while(head[0].x!=0){
					for(i=l;i>0;i--){
						head[i].x=head[i-1].x;
						head[i].y=head[i-1].y;
						gotoxy(head[i-1].x,head[i-1].y,"бр");
						if(i==l)
						gotoxy(head[i-1].x,head[i-1].y," "); 
					}
					head[0].x--;
					gotoxy(head[0].x,head[0].y,"бс");
					
					if(map[head[0].y][head[0].x]==2){
						length++;
						make_food(head,map);
					}
					
					if(kbhit())
						break;
						
					Sleep(50);
				}
				break;
			case 's':
				while(head[0].y!=height-1){
					for(i=l;i>0;i--){
						head[i].x=head[i-1].x;
						head[i].y=head[i-1].y;
						gotoxy(head[i-1].x,head[i-1].y,"бр");
						if(i==l)
						gotoxy(head[i-1].x,head[i-1].y," "); 
					}
					head[0].y++;
					gotoxy(head[0].x,head[0].y,"бс");
					
					if(map[head[0].y][head[0].x]==2){
						length++;
						make_food(head,map);
					}
			
					if(kbhit())
						break;
					
					Sleep(50);
				} 
				break;
			case 'd':
				while(head[0].x!=width-1){
					for(i=l;i>0;i--){
						head[i].x=head[i-1].x;
						head[i].y=head[i-1].y;
						gotoxy(head[i-1].x,head[i-1].y,"бр");
						if(i==l)
						gotoxy(head[i-1].x,head[i-1].y," "); 
					}
					head[0].x++;
					gotoxy(head[0].x,head[0].y,"бс");
					
					if(map[head[0].y][head[0].x]==2){
						length++;
						make_food(head,map);
					}
				
					if(kbhit())
						break;
						
					Sleep(50);
				}
				break;
		}

		return 0;
}


int game_over(){
	system("cls");
	printf("GAME OVER");
	return 0;
}

void gotoxy(int x, int y,char *c){
    COORD Pos = { 2*x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
    printf("%s",c);
}

void snake(int l,H head[]){
	int i=1;
	head[0].x=width/2;
	head[0].y=height/2;

	for(;i<l;i++){
		head[i].x=head[0].x-i;
		head[i].y=head[0].y;
		head[i].number=1;
		if(head[i].number==1)
			gotoxy(head[i].x,head[i].y,"бр");
	}
	gotoxy(head[0].x,head[0].y,"бс");
}

void make_food(H head[],int map[][width]){
	F food;

	srand((unsigned)time(NULL));
	food.x=rand()%(width-2)+1;
	food.y=rand()%(height-2)+1;
	
	gotoxy(food.x,food.y,"б┌");
	map[food.y][food.x]=2;
}







