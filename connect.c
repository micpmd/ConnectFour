#include<stdio.h>
#include<stdlib.h>
char board[8][8];
int winCondition;
int winConditionMet;

void print_board(){
    for(int i=7; i>-1; i--){
        for(int j=7; j>-1; j--){
            char a = board[i][j];
            printf("%c", a);
        }
        printf("\n");
    }
}
void check_vertical(int j,int x, char player){
    winCondition = 0;
    for(int i=0; i<4; i++){
        if(board[j-i][x]==player&&j>=0){
            winCondition++;
        }else{
            break;
        }
    }
    if(winCondition==4){
            printf("%c wins", player);
            winConditionMet=0;
    }
}
void check_horizontal(int j,int x, char player){
    winCondition = 0;
    for(int i=0; i<4; i++){
        if(board[j][x-i]==player&&x>=0){
            winCondition++;
        }else{
            break;
        }
    }
    if(winCondition==4){
        printf("%c wins", player);
        winConditionMet=0;
    }
    for(int i=1; i<4; i++){
        if(board[j][x+i]==player&&x<=7){
            winCondition++;
            if(winCondition==4){
                printf("%c wins", player);
                winConditionMet=0;
                break;
            }
        }else{
            break;
        }
    }
}
void check_diagonal1(int j,int x, char player){
    winCondition = 0;
    for(int i=0; i<4; i++){
        if(board[j-i][x-i]==player&&x>=0&&j>=0){
            winCondition++;
        }else{
            break;
        }
    }
    if(winCondition==4){
        printf("%c wins", player);
        winConditionMet=0;
    }
    for(int i=1; i<4; i++){
        if(board[j+i][x+i]==player&&x<=7&&j<=7){
            winCondition++;
            if(winCondition==4){
                printf("%c wins", player);
                winConditionMet=0;
                break;
            }
        }else{
            break;
        }
    }
}
void check_diagonal2(int j,int x, char player){
    winCondition = 0;
    for(int i=0; i<4; i++){
        if(board[j+i][x-i]==player&&x>=0&&j<=7){
            winCondition++;
        }else{
            break;
        }
    }
    if(winCondition==4){
        printf("%c wins", player);
        winConditionMet=0;
    }
    for(int i=1; i<4; i++){
        if(board[j-i][x+i]==player&&x<=7&&j>=0){
            winCondition++;
            if(winCondition==4){
                printf("%c wins", player);
                winConditionMet=0;
                break;
            }
        }else{
            break;
        }
    }
}

int main(){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            board[i][j] = ' ';
        }
    }
    print_board();
    /*board[0][1] = 'A';
    board[0][2] = 'B';
    board[0][3] = 'C';
    board[1][2] = 'D';
    board[1][3] = 'D';
    board[2][3] = 'D';*/
    int x;
    winConditionMet=1;
    char player;
    //for(int i=0;i<4;i++)
    int turn = 0;
    while(winConditionMet){
        scanf("%d", &x);
        turn = turn + 1;
        int Odd = turn%2;
        int j = 0;
        
        while(board[j][x]!=' '){
                j++;
        }
        
        if(Odd){
            player = 'R';
        }else{
            player = 'B';
        }
        
        board[j][x] = player;
        
        print_board();
        printf("\n");
        check_vertical(j,x,player);
        check_horizontal(j,x,player);
        check_diagonal1(j,x,player);
        check_diagonal2(j,x,player);
    }
    printf("\nGame Over");
}
