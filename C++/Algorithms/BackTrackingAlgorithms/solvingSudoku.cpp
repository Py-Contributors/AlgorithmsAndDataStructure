#include <bits/stdc++.h>
#define endl '\n'
using namespace std;


int sudoku[9][9];

bool resol(int n){
    int linha, coluna;
    bool acheiZero = false;
    for(int i=0;i<n*n;i++){
        for(int j=0;j<n*n;j++){
            if(!sudoku[i][j]){
                linha = i; coluna = j;
                acheiZero = true;
                break;
            }
        }
        if(acheiZero) break;
    }
    //quer dizer que meu sudoku ta todo preenchido
    if(!acheiZero) return true;

    for(int i=1;i<=n*n;i++){
        //checar se eu posso colocar i
        bool posso = true;
        //na linha
        for(int j=0;j<n*n;j++){
            if(sudoku[linha][j]==i) {
                posso = false;
                continue;
            }
        }
        if(!posso) continue;
        //na coluna
        for(int j=0;j<n*n;j++){
            if(sudoku[j][coluna]==i) {
                posso = false;
                continue;
            }
        }
        if(!posso) continue;
        //no subsudoku
        int l = (linha/n)*n, c = (coluna/n)*n;
        for(int j=l;j<l+n;j++){
            for(int k=c;k<c+n;k++){
                if(sudoku[j][k]==i){
                    posso = false;
                    continue;
                }
            }
        }
        if(!posso) continue;
        //se cheguei até aqui, quer dizer que i é um número válido
        sudoku[linha][coluna] = i;
        //colocando i, agora eu tento ver swe consigo resolver o sudoku
        if(resol(n)) return true;
        //se eu não consigo, quer dizer que i não rolou naquele lugar, então a gente tira pra testar com o próximo i
        sudoku[linha][coluna] = 0;
    }

    //se ele sai do for sem achar nenhuma solução, quer dizer que é impossível fazer o sudoku

    return false;
}


int main(){
    int n;
    int qt = 0;
    while(scanf("%d", &n)!=EOF){
        
        for(int i=0;i<n*n;i++){
            for(int j=0;j<n*n;j++) scanf("%d", &sudoku[i][j]);
        }
        if(qt>0) printf("\n");
        if(!resol(n)) printf("NO SOLUTION\n");
        else{
            for(int i=0;i<n*n;i++){
                for(int j=0;j<n*n;j++){
                    printf("%d%c", sudoku[i][j], j==(n*n)-1?'\n':' ');
                }
            }
        }
        qt++;

    }
    return 0;
}
