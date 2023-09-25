#include "ponto.h"
#include "math.h"

Ponto criarPonto(float x, float y) {
    Ponto p;
    p.X = x;
    p.Y = y;
    return p;
}

float calcularArea(Ponto* pontos, int n) {
    float area = 0.0;
    int j = n - 1;
    for (int i = 0; i < n; i++) {
        area += (pontos[j].X + pontos[i].X) * (pontos[j].Y - pontos[i].Y);
        j = i;
    }
    return fabs(area) / 2.0;
}
