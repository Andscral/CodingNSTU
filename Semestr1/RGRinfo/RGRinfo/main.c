#include <GL/glut.h> 
#include <windows.h> //функция sleep

void position1() //позиция стоя
{
    glClear(GL_COLOR_BUFFER_BIT);
    // Отрисовка головы
    glColor3f(1.0, 0.0, 0.0);
    glRectf(0.1, 0.5, -0.1, 0.3);
    // Отрисовка тела
    glColor3f(0.0, 1.0, 0.0);
    glRectf(-0.15, -0.3, 0.15, 0.3);
    // Отрисовка рук
    glColor3f(1.0, 1.0, 0.0);
    glRectf(-0.05, -0.2, 0.05, 0.2);  // Правая рука
    glRectf(-0.05, -0.2, 0.05, 0.2); // Левая рука
    // Отрисовка ног
    glColor3f(0.0, 0.0, 1.0);
    glRectf(-0.07, -0.3, 0.07, -0.7); // Правая нога
    glRectf(-0.07, -0.3, 0.07, -0.7);  // Левая нога
    glFlush();
}   

void position2()
{
    glClear(GL_COLOR_BUFFER_BIT);
    // Отрисовка головы
    glColor3f(1.0, 0.0, 0.0);
    glRectf(0.1, 0.5, -0.1, 0.3);
    // Отрисовка тела
    glColor3f(0.0, 1.0, 0.0);
    glRectf(-0.15, -0.3, 0.15, 0.3);

    // Отрисовка рук
    glColor3f(1.0, 1.0, 0.0);
    // Правая рука
    glBegin(GL_QUADS);
    glVertex2f(-0.02, 0.21);
    glVertex2f(-0.04, 0.11);
    glVertex2f(0.38, 0.0);
    glVertex2f(0.41, 0.1);
    glEnd();
    // Левая рука
    glBegin(GL_POLYGON);
    glVertex2f(-0.42, -0.02);
    glVertex2f(-0.37, -0.1);
    glVertex2f(-0.15, 0.05);
    glVertex2f(-0.15, 0.16);
    glEnd();

    // Отрисовка ног
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.29, -0.49);
    glVertex2f(-0.22, -0.52);
    glVertex2f(-0.02, -0.34);
    glVertex2f(0.0, -0.3);
    glVertex2f(-0.07, -0.3);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0.0, -0.3);
    glVertex2f(0.02, -0.34);
    glVertex2f(0.3, -0.52);
    glVertex2f(0.34, -0.46);
    glVertex2f(0.07, -0.3);
    glEnd();

    glFlush();
}

void position3()
{
    glClear(GL_COLOR_BUFFER_BIT);
    // Отрисовка головы
    glColor3f(1.0, 0.0, 0.0);
    glRectf(0.1, 0.5, -0.1, 0.3);
    // Отрисовка тела
    glColor3f(0.0, 1.0, 0.0);
    glRectf(-0.15, -0.3, 0.15, 0.3);

    // Отрисовка рук
    glColor3f(1.0, 1.0, 0.0);
    // Правая рука
    glBegin(GL_QUADS);
    glVertex2f(-0.02, 0.21);
    glVertex2f(0.02, 0.15);
    glVertex2f(-0.35, -0.08);
    glVertex2f(-0.41, 0.0);
    glEnd();
    // Левая рука
    glBegin(GL_POLYGON);
    glVertex2f(0.15, 0.25);
    glVertex2f(0.48, 0.3);
    glVertex2f(0.49, 0.22);
    glVertex2f(0.15, 0.16);
    glEnd();

    // Отрисовка ног
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.29, -0.49);
    glVertex2f(-0.22, -0.52);
    glVertex2f(-0.02, -0.34);
    glVertex2f(0.0, -0.3);
    glVertex2f(-0.07, -0.3);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0.0, -0.3);
    glVertex2f(0.02, -0.34);
    glVertex2f(0.3, -0.52);
    glVertex2f(0.34, -0.46);
    glVertex2f(0.07, -0.3);
    glEnd();

    glFlush();
}

void display()
{
    for (int i = 0; i < 25; i++) 
    {
        position1(); //стоим
        Sleep(300);

        position2(); //идем
        Sleep(300);

        position1(); //стоим
        Sleep(300);

        position3(); //идем
        Sleep(300);

    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("РГР. Шагающий человечек");
    glClearColor(0.0, 0.0, 0.0, 1.0);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
} 