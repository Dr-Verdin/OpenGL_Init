#include <GL/glut.h>

#define windowWidth 600
#define windowHeight 600

typedef struct bixinho_ {
    float r;
    float x;
    float y;
    float theta;
    float r,g, b;
} BIXINHO;

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