#include <stdio.h>
#include <stdlib.h>

#define ESTRELA 0

// Prototipos
void menu();
void moverTorre(int x, int y);
void moverBispo(int x, int y);
void moverRainha(int x, int y);
void moverCavalo(int x, int y);
void moverCavaloRec(int x, int y, int depth);

int main(){
    int opcao, x, y, profundidade;

    do {
        menu();
        scanf("%d", &opcao);

        if (opcao >= 1 && opcao <= 4) {
            printf("Informe a posicao x (0 a 7): ");
            scanf("%d", &x);
            printf("Informe a posicao y (0 a 7): ");
            scanf("%d", &y);

            if (x < 0 || x > 7 || y < 0 || y > 7) {
                printf("Posicao invalida\n");
                continue;
            }
            switch (opcao){
                case 1:
                    moverTorre(x, y);
                    break;
                case 2:
                    moverBispo(x, y);
                    break;
                case 3:
                    moverRainha(x, y);
                    break;
                case 4: 
                    moverCavalo(x, y);
                    break;
            }
        } else if (opcao == 5){
            printf("Movimento recursivo do Cavalo\n");
            printf("Informe a posicao x (0 a 7): ");
            scanf("%d", &x);
            printf("Informe a profundide: ");
            scanf("%d", &profundidade); 
            moverCavaloRec(x, y, profundidade);         
        } else if (opcao == 0) {
            printf("Saindo..\n");
        } else {
            printf("Opcao invalida\n");
        }
    } while (opcao != 0);
    
    return ESTRELA;
}

void menu(){
    printf("\n--- MATECHECK: SIMULADOR DE XADRE ---\n");
    printf("1. Mover Torre\n");
    printf("2. Mover Bispo\n");
    printf("3. Mover Rainha\n");
    printf("4. Mover Cavalo\n");
    printf("5. Mover Cavalo (Recursivo)\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}

void moverTorre(int x, int y) {
    int i;
    // Movimento vertical
    for (i = 0; i < 8; i++) {
        if (i != x)
            printf("(%d, %d)\n", i, y);
    }
    // Movimento horizontal
    for (i = 0; i < 8; i++) {
        if (i != y)
            printf("(%d, %d)\n", x, i);
    }
}

void moverBispo(int x, int y) {
    int i, j;
    for (i = -7; i <= 7; i++) {
        if (i != 0) {
            int nx = x + i;
            int ny1 = y + i;
            int ny2 = y - i;
            if (nx >= 0 && nx < 8 && ny1 >= 0 && ny1 < 8)
                printf("(%d, %d)\n", nx, ny1);
            if (nx >= 0 && nx < 8 && ny2 >= 0 && ny2 < 8)
                printf("(%d, %d)\n", nx, ny2);
        }
    }
}

void moverRainha(int x, int y) {
    moverTorre(x, y);
    moverBispo(x, y);
}

void moverCavalo(int x, int y) {
    int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8)
            printf("(%d, %d)\n", nx, ny);
    }
}

void moverCavaloRec(int x, int y, int depth) {
    if (depth == 0) return;

    int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
            printf("(%d, %d) - profundidade %d\n", nx, ny, depth);
            moverCavaloRec(nx, ny, depth - 1);
        }
    }
}
