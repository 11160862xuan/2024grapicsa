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

#include <GL/glut.h>///��18��s�U��
void display()
{
    glBegin(GL_POLYGON);
        glVertex2f((34-200)/200.0,-(76-200)/200.0);
        glVertex2f((50-200)/200.0,-(131-200)/200.0);
        glVertex2f((85-200)/200.0,-(59-200)/200.0);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f((383-200)/200.0,-(79-200)/200.0);
        glVertex2f((348-200)/200.0,-(146-200)/200.0);
        glVertex2f((312-200)/200.0,-(55-200)/200.0);
    glEnd();
    glutSwapBuffers();
}

int main(int argc, char*argv[])///��138��,main()�禡
{
    glutInit(&argc, argv);///140��, �}��GLUT�\��
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///148��,�]�w��ܼҦ�
    glutCreateWindow("GLUT Shapes");///145��,�}�@��
    glutDisplayFunc(display);///148��,�n��display()�禡�ӵe��
    glutMainLoop();///174��, �D�n���j��,�b�o�̤@���B�@,������
}
