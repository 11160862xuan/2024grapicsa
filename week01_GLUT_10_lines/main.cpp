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
    glutSolidTeapot(0.3);
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