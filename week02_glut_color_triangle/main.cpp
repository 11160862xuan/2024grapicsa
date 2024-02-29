/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#include <GL/glut.h>///第18行存下來
void display()
{
    glBegin(GL_POLYGON);
        glColor3f(1,0,0);glVertex2f(0,1);
        glColor3f(0,1,0);glVertex2f(+1,-0.6);
        glColor3f(1,0,0);glVertex2f(-1,-0.6);
    glEnd();
    glutSwapBuffers();
}

int main(int argc, char*argv[])///第138行,main()函式
{
    glutInit(&argc, argv);///140行, 開啟GLUT功能
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///148行,設定顯示模式
    glutCreateWindow("GLUT Shapes");///145行,開一個
    glutDisplayFunc(display);///148行,要用display()函式來畫圖
    glutMainLoop();///174行, 主要的迴圈,在這裡一直運作,不結束
}
