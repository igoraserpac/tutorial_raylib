#include "raylib.h"

typedef struct{
    int tam_x;
    int tam_y;
    int posi_x;
    int posi_y;
}Quadrado;

typedef struct{
    int largura;
    int altura;
    Quadrado quadrado;
}Game;

void InitGame(Game *g){
    g->largura = 800;
    g->altura = 400;
    g->quadrado.tam_x = 30;
    g->quadrado.tam_y = 30;
    g->quadrado.posi_x = 400;
    g->quadrado.posi_y = 200;
}

void UpdateGame(Game *g){
    if(IsKeyDown(KEY_UP)){
        g->quadrado.posi_y -= 3;
    }
    if(IsKeyDown(KEY_DOWN)){
        g->quadrado.posi_y += 3;
    }
    if(IsKeyDown(KEY_RIGHT)){
        g->quadrado.posi_x += 3;
    }
    if(IsKeyDown(KEY_LEFT)){
        g->quadrado.posi_x -= 3;
    }
    if(g->quadrado.posi_x > 780){
        g->quadrado.posi_x = 780;
    }
    if(g->quadrado.posi_y > 380){
        g->quadrado.posi_y = 380;
    }
    if(g->quadrado.posi_x < 0){
        g->quadrado.posi_x = 0;
    }
    if(g->quadrado.posi_y < 0){
        g->quadrado.posi_y = 0;
    }
}

void DrawGame(Game *g){
    BeginDrawing();
        ClearBackground(BLACK);
        DrawRectangle(g->quadrado.posi_x, g->quadrado.posi_y, g->quadrado.tam_x, g->quadrado.tam_y, WHITE);
    EndDrawing();
}



int main(){
    Game g;
    InitGame(&g);
    InitWindow(g.largura, g.altura, "jogo");
    SetTargetFPS(60);
    while(!WindowShouldClose()){
        UpdateGame(&g);
        DrawGame(&g);
    }
    CloseWindow();
}

