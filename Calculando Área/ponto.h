#ifndef PONTO_H
#define PONTO_H

typedef struct {
    float X;
    float Y;
} Ponto;

// Protótipos das funções relacionadas ao TAD Ponto
Ponto criarPonto(float x, float y);
float calcularArea(Ponto* pontos, int n);

#endif
