#include <GL/glut.h>///��18��s�U��
#include <stdio.h>
float teapotX=0,teapotY=0;
void mouse(int button,int state,int x,int y)
{
    teapotX=(x-150)/150.0;
    teapotY=-(y-150)/150.0;
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef(teapotX, teapotY,0);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}

int main(int argc, char*argv[])///��138��,main()�禡
{
    glutInit(&argc, argv);///140��, �}��GLUT�\��
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///148��,�]�w��ܼҦ�
    glutCreateWindow("week03 mouse");///145��,�}�@��
    glutDisplayFunc(display);///148��,�n��display()�禡�ӵe��
    glutMouseFunc(mouse);
    glutMainLoop();///174��, �D�n���j��,�b�o�̤@���B�@,������
}
