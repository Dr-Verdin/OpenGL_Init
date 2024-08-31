#include <GL/glut.h>
#include <cmath>

#define windowWidth 600
#define windowHeight 600
#define PI 3.141592653589793

void draw();
// Funções para desenhar os polígonos
void triangle(float x, float y, float h, float b);
void rectangle(float x, float y, float w, float h);
void circle(float x, float y, float r);
void star(float x, float y, float rExt, float rInt);
void copas(float x, float y, float r);

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL - Print Basics Shapes");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(draw);
    glutMainLoop();

    return 0;
}

void draw(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity(); 

    // A tela padrão do OpenGL tem suas coordenadas X e Y de -1 até 1
    // Coordenada (-1 -1) é o canto inferior esquerdo
    // Coordenada (-1 1) é o canto superior esquerdo
    // Coordenada (0 0) é o centro da tela
    
    triangle(0.5, 0.5, 0.4, 0.5);
    rectangle(0, 0, 0.3, 0.4);
    circle(-0.5, 0.5, 0.2);
    star(-0.5, -0.5, 0.4, 0.15);
    copas(0.5, -0.5, 0.02);

    glutSwapBuffers(); // Responsável por trocar os buffers (usado para animação e renderização dupla), você só deve chamá-la uma vez por frame, normalmente no final da função draw.
}

/* ----- TRIANGLE ----- */
void triangle(float x, float y, float h, float b) { // x do centro, y do centro, h altura e b base
    glColor3f(1.0f, 0.0f, 0.0f); // Define a cor do triângulo (vermelho)
    glBegin(GL_TRIANGLES); // Inicia a definição dos vértices do triângulo
        glVertex2f(x - b / 2, y - h / 2); // Vértice inferior esquerdo
        glVertex2f(x + b / 2, y - h / 2); // Vértice inferior direito
        glVertex2f(x, y + h / 2);         // Vértice superior (ápice)
    glEnd(); // Finaliza a definição dos vértices
}

void rectangle(float x, float y, float w, float h) { // x do centro, y do centro, w largura e h altura
    glColor3f(0.0f, 0.0f, 1.0f); // Define a cor do retângulo (azul)
    glBegin(GL_QUADS); // Inicia a definição dos vértices do retângulo
        glVertex2f(x - w / 2, y - h / 2); // Vértice inferior esquerdo
        glVertex2f(x - w / 2, y + h / 2); // Vértice superior esquerdo
        glVertex2f(x + w / 2, y + h / 2); // Vértice superior direito
        glVertex2f(x + w / 2, y - h / 2); // Vértice inferior direito
    glEnd(); // Finaliza a definição dos vértices
}

void circle(float x, float y, float r){ // x do centro, y do centro, r raio
    glColor3f(1.0f, 1.0f, 0.0f); // Define a cor do círculo (amarelo)
    glBegin(GL_POLYGON); // Inicia a definição dos vértices do polígono
        for(int i = 0; i < 360; i += 10){ // Loop para criar os vértices do círculo
            float angle = i * M_PI / 180; // COnverte o ângulo de graus para radianos
            glVertex2f(r * std::cos(angle) + x, r * std::sin(angle) + y); // Define o vẃrtice na borda do círculo
        }
    glEnd(); // Finaliza a definição dos vértices do polígono 
}

void star(float x, float y, float rExt, float rInt){ // x do centro, y do centro, r raio
    glColor3f(0.65f, 0.0f, 1.0f); // Define a cor da estrela (roxo)
    
    glBegin(GL_TRIANGLE_FAN); // Inicia a definição dos vértices da estrela
    
    glVertex2f(x, y); // Vétice central da estrela
    
        for(int i = 0; i < 360; i += 72){ // 72 graus para as 5 pontas
            float angle = i * M_PI / 180.0f; // COnverte o ��ngulo de graus para radianos
            float xExt = x + rExt * cos(angle); // Coordenada x do ponto externo
            float yExt = y + rExt * sin(angle); // Coordenada y do ponto externo

            // Vértice externo da estrela
            glVertex2f(xExt, yExt);

            // Vértice interno da estrela
            float angleInt = (i + 36) * M_PI / 180.0f; // Desloca o ângulo para obter o ponto interno
            float xInt = x + rInt * cos(angleInt); // Coordenada x do ponto interno
            float yInt = y + rInt * sin(angleInt); // Coordenada y do ponto interno
            
            glVertex2f(xInt, yInt);
        }
    
    // Adiciona o primeiro ponto externo para fechar a forma
    float angle = 0 * M_PI / 180.0f;
    float xExt = x + rExt * cos(angle);
    float yExt = y + rExt * sin(angle);
    glVertex2f(xExt, yExt); // Adiciona o último vértice para fechar a forma

    glEnd(); // Finaliza a definição dos vértices da estrela
}

void copas(float x, float y, float r){ // x do centro, y do centro
    glColor3f(0.0f, 1.0f, 0.0f); // Define a cor do polígono (verde)
    glBegin(GL_POLYGON); // INicia a definição dos vértices do polígono
        
        for(float t = 0; t <= 2 * PI; t += 0.01f){ // 
            float dx = 16 * pow(sin(t), 3);
            float dy = 13 * cos(t) - 5 * cos(2 * t) - 2 * cos(3 * t) - cos(4 * t);
            glVertex2f(x + r * dx, y + r * dy); // Adiciona o vértice
        }
    glEnd(); // Finaliza a definição dos vértices do polígono
}