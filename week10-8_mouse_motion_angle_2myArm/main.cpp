#include <GL/glut.h>
void myBody(){
    glPushMatrix();
       /// glTranslatef(0.0,-0.3,0);
        glColor3f(1,0,0);///紅色的
        glutWireCube(0.6);///glutWireCube(0.3);
    glPopMatrix();
}
void myArm(){
    glPushMatrix();///備份矩陣
        glColor3f(0,1,0);///綠色的
        glScalef(1,0.4,0.4);///my Body();
        glutWireCube(0.3);
    glPopMatrix();
}
float angle=0;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    myBody();


    glPushMatrix();///右半邊
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

    glPushMatrix();///左半邊
        glTranslatef(-0.3,0.3,0);
        glRotatef(-angle,0,0,1);
        glTranslatef(-0.15,0,0);
        myArm();
        glPushMatrix();
            glTranslatef(-0.15,0,0);
            glRotatef(-angle,0,0,1);
            glTranslatef(-0.15,0,0);
            myArm();
        glPopMatrix();
    glPopMatrix();



	glutSwapBuffers();
}
void motion(int x,int y){
    angle = x;
    glutPostRedisplay();
}
int main(int argc, char*argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("week09 Microsoft Visual Studio");
	glutDisplayFunc(display);
	glutMotionFunc(motion);
	glutIdleFunc(display);
	glutMainLoop();
}
