#include <GL/glut.h> // verificar pq tá assim, será que não está instalado
#include <cmath>

#define windowWidth 600
#define windowHeight 600

typedef struct bixinho_ {
    float radius;
    float x;
    float y;
    float theta;
    float r,g, b;
} BIXINHO;

BIXINHO florzinha = {0.07, 0,0,0, 0.8,0,0};
BIXINHO lindinha = {0.05, -0.3,-0.3,M_PI, 0,0,0.8};
BIXINHO docinho = {0.1, -0.5, 0,M_PI/2, 0,0.8,0};

void draw();
void timer(int value);
void rotateBixinho(BIXINHO *bixinho, float angle);
void moveBixinho(BIXINHO *bixinho, float distance);
void drawBixinho(BIXINHO bixinho);

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL - Animation");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(draw);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();

    return 0;
}

void draw(){
    glClear(GL_COLOR_BUFFER_BIT);

    drawBixinho(florzinha);
    drawBixinho(lindinha);
    drawBixinho(docinho);

    glutSwapBuffers();
}

void timer(int value) {

    moveBixinho(&florzinha, 0.005); 
    moveBixinho(&lindinha, -0.003);
    moveBixinho(&docinho, 0.007); 

    rotateBixinho(&florzinha, 0.02);
    rotateBixinho(&lindinha, 0.04);
    rotateBixinho(&docinho, -0.02);

    glutPostRedisplay();

    glutTimerFunc(1000/60, timer, 0);
}

void rotateBixinho(BIXINHO *bixinho, float angle){
    bixinho->theta += angle;;
}

void moveBixinho(BIXINHO *bixinho, float distance){
    bixinho->x = bixinho->x + distance * cos(bixinho->theta);
    bixinho->y = bixinho->y + distance * sin(bixinho->theta);

    bixinho->x = bixinho->x > 1 ? -1 : bixinho->x;
    bixinho->y = bixinho->y > 1 ? -1 : bixinho->y;
}

void drawBixinho(BIXINHO bixinho){
    float radius = bixinho.radius;
    float x = bixinho.x;
    float y = bixinho.y;
    float theta = bixinho.theta;

    glColor3f(bixinho.r, bixinho.g, bixinho.b);
    glBegin(GL_POLYGON); // Inicia a definição dos vértices do polígono
        for(int i = 0; i < 360; i += 5){ // Loop para criar os vértices do círculo
            float angle = i * M_PI / 180; // Converte o ângulo de graus para radianos
            glVertex2f(radius * std::cos(angle) + x, radius * std::sin(angle) + y); // Define o vértice na borda do círculo
        }
    glEnd();

    float eyeRadius = radius / 8;
    float eyeDist = M_PI / 6;

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON); 
    for(int i = 0; i < 360; i += 5){
        float shiftX = radius / 2 * cos(theta - eyeDist);
        float shiftY = radius / 2 * sin(theta - eyeDist);
        float angle = i / 180.0 * M_PI;
        glVertex2f(eyeRadius * cos(angle) + x + shiftX, eyeRadius * sin(angle) + y + shiftY);
    }
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON); 
    for(int i = 0; i < 360; i += 5){
        float shiftX = radius / 2 * cos(theta - eyeDist);
        float shiftY = radius / 2 * sin(theta - eyeDist);
        float angle = i / 180.0 * M_PI;
        glVertex2f(eyeRadius * cos(angle) + x + shiftX, eyeRadius * sin(angle) + y + shiftY);
    }
    glEnd();
}