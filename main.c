#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int isWin(int a[4][4],int n){
  for(int i = 1;i <= n;i++){
    if(a[i][1] == a[i][2] && a[i][2] == a[i][3] && a[i][1] != -1){
      return a[i][1];
    }
  }
  for(int j = 1;j <= n;j++){
    if(a[1][j] == a[2][j] && a[2][j] == a[3][j] && a[1][j] != -1){
      return a[1][j];
    }
  }
  if(a[1][1] == a[2][2] && a[2][2] == a[1][1] && a[1][1] != -1){
    return a[1][1];
  }
  if(a[1][3] == a[2][2] && a[2][2] == a[3][1] && a[1][3] != -1){
    return a[1][3];
  }
  return -1;
}
void printCell(int a[4][4], int n){
  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= n;j++){
      printf("\t");
      if(a[i][j] == -1) printf(" ");
      if(a[i][j] == 1) printf("O");
      if(a[i][j] == 2) printf("X");
      if(j < n) printf("\t|");
    }
    printf("\n");
    if(i < n)printf("\t___________________________________");
    printf("\n\n");
  }
}
int main() {
  int n = 3;
  int a[4][4];
  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= n;j++){
      a[i][j] = -1;
    }
  }
  int player1 = true;
  int player2 = false;
  while(true){
    printCell(a,n);
    if(player1 == true){
      int r,c;
      Flag:
      printf("Enter Row And Collum's For Player1(0)");
      scanf("%d%d", &r,&c);
      if(a[r][c] != -1){
        goto Flag;
      }
      a[r][c] = 1;
      player1 = false;
      player2 = true;
  }else{
    int r,c;
      Flag2:
      printf("Enter Row And Collum's For Player2(X)");
      scanf("%d%d", &r,&c);
      if(a[r][c] != -1){
        goto Flag2;
      }
      a[r][c] = 2;
    player2 = false;
    player1 = true;
  }
  //who is win
  if(isWin(a,n) == 1){
    printCell(a,n);
    printf("Player 1 Is Won\n");
    break;
  }else if(isWin(a,n) == 2){
    printCell(a,n);
    printf("Player 2 Is Won\n");
    break;
  }
}
}
