#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#define ROW 6
#define COL 6
void menu();
void game();
void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);
int  AI(char board[ROW][COL], int row, int col);
char CheckWin(char board[ROW][COL], int row, int col);
int IsFull(char board[ROW][COL], int row, int col);
int main(){
    srand((unsigned int)time(NULL));
    int input = 0;
    do{
        menu();
        printf("请选择:>\n");
        scanf("%d", &input);
        switch(input){
            case 1:
                printf("游戏开始\n");
                game();
                break;
            case 0:
                printf("退出游戏！\n");
                break;
            default:
                printf("输入错误，请重新输入\n");
                break;
        }
    } while (input);
    return 0;
}
void menu(){
    printf("****************\n");
    printf("*****1.play*****\n");
    printf("*****0.exit*****\n");
    printf("****************\n");
}
void InitBoard(char board[ROW][COL], int row, int col){
    int i = 0,j=0;
    for (i = 0; i < ROW;i++){
        for (j = 0; j < COL;j++){
            board[i][j] = ' ';
        }
    }
}
void DisplayBoard(char board[ROW][COL], int row, int col){
    int i = 0, j = 0;
    for (i = 0; i < row;i++){
        for (j = 0; j < col;j++){
            printf(" %c ", board[i][j]);
            if(j<col-1){
                printf("|");
            }
        }
        printf("\n");
        if(i<row-1){
            for (j = 0; j < col;j++){
            printf("---");
            if(j<col-1){
                printf("|");
            }           
            }
            printf("\n");
       }
}
}
void PlayerMove(char board[ROW][COL], int row, int col){
    printf("玩家开始:>\n");
    while(1){
        int x, y;
        scanf("%d %d", &x, &y);
        if(x<=row && x>=1 && y<=col && y>=1){
            if(board[x-1][y-1] ==' '){
                board[x - 1][y - 1] = '*';
                break;
            }else{
                printf("当期棋盘已被占有，请重新输入！\n");
            }
        }else{
            printf("输入不在棋盘当中!\n");
        }
    }
}
// int  AI(char board[ROW][COL], int row, int col){
//     int i = 0, j = 0;
//     for (i = 0; i < row;i++){
//         if(board[i][0]==board[i][1] && board[i][0]!=' '&& board[i][2]==' '){
//             board[i][2] = '#';
//             return 1;
//         }else if(board[i][1]==board[i][2] && board[i][1]!=' '&& board[i][0]==' '){
//             board[i][0] = '#';
//             return 1;
//         }else if(board[i][2]==board[i][0] && board[i][0]!=' '&& board[i][1]==' '){
//             board[i][1] = '#';
//             return 1;
//         }
//     }
//     for (i = 0; i < col;i++){
//         if(board[0][i]==board[1][i] && board[1][i]!=' ' && board[2][i]==' '){
//             board[2][i] = '#';
//             return 1;
//         }
//         if(board[1][i]==board[2][i] && board[1][i]!=' '&& board[0][i]==' '){
//             board[0][i] = '#';
//             return 1;
//         }
//         if(board[0][i]==board[2][i] && board[0][i]!=' '&& board[1][i]==' '){
//             board[1][i] = '#';
//             return 1;
//         }
//     }
//     if(board[0][0]==board[1][1] && board[1][1]!=' '&& board[2][2]==' '){
//         board[2][2] = '#';
//         return 1;
//     }
//     if(board[2][2]==board[1][1] && board[1][1]!=' '&& board[0][0]==' '){
//         board[0][0] = '#';
//         return 1;
//     }
//     if(board[0][0]==board[2][2] && board[0][0]!=' '&& board[1][1]==' '){
//         board[1][1] = '#';
//         return 1;
//     }
//     if(board[0][2]==board[1][1] && board[1][1]!=' '&& board[2][0]==' '){
//         board[2][0] = '#';
//         return 1;
//     }
//     if(board[2][0]==board[1][1] && board[1][1]!=' '&& board[0][2]==' '){
//         board[0][2] = '#';
//         return 1;
//     }
//     if(board[2][0]==board[0][2] && board[2][0]!=' '&& board[1][1]==' '){
//         board[1][1] = '#';
//         return 1;
//     }
//     return 0;
// }
void ComputerMove(char board[ROW][COL], int row, int col){
    printf("电脑开始:>\n");
    while(1)
    {
    // if(AI(board,row,col)==1){
    //     break;
    // }
    int x = rand() % row;
    int y = rand() % col;
    if(board[x][y] == ' '){
        board[x][y] = '#';
        break;
    }
    }
}
int IsFull(char board[ROW][COL], int row, int col){
    int i = 0, j = 0;
    for (i = 0; i < row;i++){
        for (j = 0; j < col;j++){
            if(board[i][j] == ' '){
                return 0;
            }
        }
    }
    return 1;
}
char CheckWin(char board[ROW][COL], int row, int col){
    int i = 0,j=0;
    for (i = 0; i < row;i++){
        // if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0] != ' '){
        //     return board[i][0];
        // }
        for (j = 0; j < row - 4;j++){
            if (board[i][j] == board[i][j+1] && board[i][j+1] == board[i][j+2] && board[i][j+2] == board[i][j+3] && board[i][j+3] == board[i][j+4] && board[i][j] != ' ')
            {
                return board[i][j];
        }
        }
    }
    for (i = 0; i < col;i++){
        // if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
        // {
        //     return board[0][i];
        // }
        for (j = 0; j < row - 4;j++){
            if(board[j][i]==board[j+1][i]&&board[j+2][i]==board[j+1][i]&&board[j+2][i]==board[j+3][i]&&board[j+4][i]==board[j+3][i]&&board[j][i]!=' '){
                return board[j][i];
            }
        }
    }
    // if(board[0][0]==board[1][1] && board[1][1] == board[2][2] && board[0][0]!= ' '){
    //         return board[0][0];
    //     }
    // if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[0][2] !=' '){
    //         return board[0][2];
    //     }
    for (j = 0; j < row - 4;j++){
        for (i = 0; i < row - 4; i++)
        {
            if (board[i+j][i] == board[i + j + 1][i + 1] && board[i + j + 1][i + 1] == board[i +j+ 2][i + 2] && board[i + j+ 2][i + 2] == board[i +j+ 3][i + 3] && board[i +j+ 3][i + 3] == board[i +j+ 4][i + 4] && board[i+j][i] != ' ')
            {
                return board[i+j][i];
            }
            if (board[i][i+j] == board[i + 1][i + j + 1] && board[i + 1][i + j + 1] == board[i + 2][i +j+ 2] && board[i + 2][i + j+ 2]== board[i + 3][i +j+ 3] && board[i + 3][i +j+ 3] == board[i + 4][i +j+ 4] && board[i][i+j] != ' ')
            {
                return board[i][i+j];
            }
        }
    }
    for (j = 0; j < row - 4;j++){
        for (i = 0; i < row - 4; i++)
        {
            if (board[i][row - i - 1-j] == board[i + 1][row - i - 2-j] && board[i + 1][row - i - 2-j] == board[i + 2][row - i - 3-j] && board[i + 2][row - i - 3-j] == board[i + 3][row - i - 4-j] && board[i + 3][row - i - 4-j] == board[i + 4][row - i - 5-j] && board[i][row - i - 1-j] != ' ')
            {
                return board[i][row - i - 1-j];
            }
            if (board[i+j][row - i - 1-j] == board[i + 1+j][row - i - 2-j] && board[i + 1+j][row - i - 2-j] == board[i + 2+j][row - i - 3-j] && board[i + j+2][row - i - 3-j] == board[i +j+ 3][row - i - 4-j] && board[i +j+ 3][row - i - 4-j] == board[i + j+4][row - i - 5-j] && board[i+j][row - i - 1-j] != ' ')
            {
                return board[i+j][row - i - 1-j];
            }
        }
    }
        
    if (IsFull(board, row, col) == 1)
        {
            return 'Q';
        }
    return 'C';
}
void game(){
    char board[ROW][COL];
    char ret = 0;
    InitBoard(board, ROW, COL);
    DisplayBoard(board, ROW, COL);
    while(1){
        PlayerMove(board, ROW, COL);
        ret = CheckWin(board, ROW, COL);
        if(ret !='C'){
            break;
        }
        DisplayBoard(board, ROW, COL);
        ComputerMove(board, ROW, COL);
        ret = CheckWin(board, ROW, COL);
        if(ret !='C'){
            break;
        }
        DisplayBoard(board, ROW, COL);
    }
    if(ret =='*'){
        printf("恭喜您赢了！\n");
    }else if(ret =='#'){
        printf("遗憾计算机赢了！\n");
    }else if(ret == 'Q'){
        printf("平手！\n");
    }
    DisplayBoard(board, ROW, COL);
}