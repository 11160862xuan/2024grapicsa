///week10-2_rotate_myArm
///�K�Wweek10-1_glutWireCube_myBody_myArm���{���X
#include <GL/glut.h>
void myBody(){
    glPushMatrix();
       /// glTranslatef(0.0,-0.3,0);
        glColor3f(1,0,0);///���⪺
        glutWireCube(0.6);///glutWireCube(0.3);
    glPopMatrix();
}
void myArm(){
    glPushMatrix();///�ƥ��x�}
        glColor3f(0,1,0);///��⪺
        glScalef(1,0.4,0.4);///my Body();
        glutWireCube(0.3);
    glPopMatrix();
}
float angle=0;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    myBody();
    glPushMatrix();
        glTranslatef(0.3,0.3,0);
        glRotatef(angle++,0,0,1);
        glTranslatef(0.15,0,0);
        myArm();
        glPushMatrix();
            glTranslatef(0.15,0,0);
            glRotatef(angle++,0,0,1);
            glTranslatef(0.15,0,0);
            myArm();
        glPopMatrix();
    glPopMatrix();



	glutSwapBuffers();
}
int main(int argc, char*argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("week09 Microsoft Visual Studio");
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutMainLoop();
}
