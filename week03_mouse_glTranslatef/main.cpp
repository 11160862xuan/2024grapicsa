#include <GL/glut.h>///第18行存下來
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

int main(int argc, char*argv[])///第138行,main()函式
{
    glutInit(&argc, argv);///140行, 開啟GLUT功能
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///148行,設定顯示模式
    glutCreateWindow("week03 mouse");///145行,開一個
    glutDisplayFunc(display);///148行,要用display()函式來畫圖
    glutMouseFunc(mouse);
    glutMainLoop();///174行, 主要的迴圈,在這裡一直運作,不結束
}
