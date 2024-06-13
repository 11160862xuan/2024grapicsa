#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
#include <GL/glut.h>
#include "glm.h"
GLMmodel * pmodel = NULL;
GLMmodel * handA = NULL;
GLMmodel * handB = NULL;
GLMmodel * upperA = NULL;
GLMmodel * lowerA = NULL;
GLMmodel * upperB = NULL;
GLMmodel * lowerB = NULL;
GLMmodel * legA = NULL;
GLMmodel * legB = NULL;
GLMmodel * upperlegA = NULL;
GLMmodel * lowerlegA = NULL;
GLMmodel * upperlegB = NULL;
GLMmodel * lowerlegB = NULL;
GLMmodel * body = NULL;
float teapotX = 0, teapotY = 0;
void drawBody(void)
{
    if (!body) {
	body = glmReadOBJ("data/body.obj");
	if (!body) exit(0);
	glmUnitize(body);
	glmFacetNormals(body);
	glmVertexNormals(body, 90.0);
    }

    glmDraw(body, GLM_SMOOTH | GLM_MATERIAL);
}

void drawupperA(void)
{
    if (!upperA) {
	upperA = glmReadOBJ("data/upperA.obj");
	if (!upperA) exit(0);
	glmUnitize(upperA);
	glmFacetNormals(upperA);
	glmVertexNormals(upperA, 90.0);
    }
    glmDraw(upperA, GLM_SMOOTH | GLM_MATERIAL);

}

void drawlowerA(void)
{
    if (!lowerA) {
	lowerA = glmReadOBJ("data/lowerA.obj");
	if (!lowerA) exit(0);
	glmUnitize(lowerA);
	glmFacetNormals(lowerA);
	glmVertexNormals(lowerA, 90.0);
    }

    glmDraw(lowerA, GLM_SMOOTH | GLM_MATERIAL);
}

void drawmodel(void)
{
    if (!pmodel) {
	pmodel = glmReadOBJ("data/Gundam.obj");
	if (!pmodel) exit(0);
	glmUnitize(pmodel);
	glmFacetNormals(pmodel);
	glmVertexNormals(pmodel, 90.0);
    }

    glmDraw(pmodel, GLM_SMOOTH | GLM_MATERIAL);
}
void drawHandA(void)
{
    if (!handA) {
	handA = glmReadOBJ("data/handA.obj");
	if (!handA) exit(0);
	glmUnitize(handA);
	glmFacetNormals(handA);
	glmVertexNormals(handA, 90.0);
    }

    glmDraw(handA, GLM_SMOOTH | GLM_MATERIAL);
}
void drawHandB(void)
{
    if (!handB) {
	handB = glmReadOBJ("data/handB.obj");
	if (!handB) exit(0);
	glmUnitize(handB);
	glmFacetNormals(handB);
	glmVertexNormals(handB, 90.0);
    }

    glmDraw(handB, GLM_SMOOTH | GLM_MATERIAL);
}

void drawupperB(void)
{
    if (!upperB) {
	upperB = glmReadOBJ("data/upperB.obj");
	if (!upperB) exit(0);
	glmUnitize(upperB);
	glmFacetNormals(upperB);
	glmVertexNormals(upperB, 90.0);
    }

    glmDraw(upperB, GLM_SMOOTH | GLM_MATERIAL);
}

void drawlowerB(void)
{
    if (!lowerB) {
	lowerB = glmReadOBJ("data/lowerB.obj");
	if (!lowerB) exit(0);
	glmUnitize(lowerB);
	glmFacetNormals(lowerB);
	glmVertexNormals(lowerB, 90.0);
    }

    glmDraw(lowerB, GLM_SMOOTH | GLM_MATERIAL);
}

void drawupperlegA(void)
{
    if (!upperlegA) {
	upperlegA = glmReadOBJ("data/upperlegA.obj");
	if (!upperlegA) exit(0);
	glmUnitize(upperlegA);
	glmFacetNormals(upperlegA);
	glmVertexNormals(upperlegA, 90.0);
    }
    glPushMatrix();
    glScalef(0.65,0.65,0.65);
    glmDraw(upperlegA, GLM_SMOOTH | GLM_MATERIAL);
    glPopMatrix();
}


void drawlowerlegA(void)
{
    if (!lowerlegA) {
	lowerlegA = glmReadOBJ("data/lowerlegA.obj");
	if (!lowerlegA) exit(0);
	glmUnitize(lowerlegA);
	glmFacetNormals(lowerlegA);
	glmVertexNormals(lowerlegA, 90.0);
    }

    glmDraw(lowerlegA, GLM_SMOOTH | GLM_MATERIAL);
}

void drawupperlegB(void)
{
    if (!upperlegB) {
	upperlegB = glmReadOBJ("data/upperlegB.obj");
	if (!upperlegB) exit(0);
	glmUnitize(upperlegB);
	glmFacetNormals(upperlegB);
	glmVertexNormals(upperlegB, 90.0);
    }
    glPushMatrix();
    glScalef(0.65,0.65,0.65);
    glmDraw(upperlegB, GLM_SMOOTH | GLM_MATERIAL);
    glPopMatrix();
}

void drawlowerlegB(void)
{
    if (!lowerlegB) {
	lowerlegB = glmReadOBJ("data/lowerlegB.obj");
	if (!lowerlegB) exit(0);
	glmUnitize(lowerlegB);
	glmFacetNormals(lowerlegB);
	glmVertexNormals(lowerlegB, 90.0);
    }

    glmDraw(lowerlegB, GLM_SMOOTH | GLM_MATERIAL);
}

///float angle = 0, da = 1; ///加這行, 讓它轉動
float angle[30] = {}; ///20個角度 , 都設成0
int angleID = 0; ///可以是角度0, 角度1, 角度2, .....
int oldX = 0, oldY = 0;
FILE *fin =NULL;
FILE *fout =NULL;
#include <stdio.h>
void motion(int x, int y)
{
    angle[angleID] += y - oldY;
    oldX = x;
    oldY = y;
    glutPostRedisplay();

}

void mouse (int button, int state, int x, int y)
{
    oldX = x;
    oldY = y;
}
float oldAngle[30]={},newAngle[30]= {};
void timer(int t){
    glutTimerFunc(50,timer,t+1);
    if(t%30==0){
        if(fin==NULL)fin =fopen("angle.txt","r");
        for(int i=0;i<30;i++){
            oldAngle[i] = newAngle[i];
            fscanf(fin,"%f", & newAngle[i] );
        }
    }
    float alpha = (t%30)/30.0;
    for(int i=0;i<30;i++){
        angle[i]=newAngle[i]*alpha+oldAngle[i]*(1-alpha);
    }
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
    if(key=='p'){
        glutTimerFunc(0,timer,0);
    }
    if(key=='r'){
        if(fin==NULL)fin = fopen("angle.txt","r");
        for(int i=0;i<30;i++){
            fscanf(fin,"%f",& angle[i]);
        }
        glutPostRedisplay();
    }else if(key=='s'){
        if(fout==NULL) fout = fopen("angle.txt","w+");
        for(int i=0;i<30;i++){
            printf("%.1f ",angle[i]);
            fprintf(fout, "%.1f ",angle[i] );
        }
        printf("\n");
        fprintf(fout,"\n");
    }
    if(key=='0') angleID = 0;
    if(key=='1') angleID = 1;
    if(key=='2') angleID = 2;
    if(key=='3') angleID = 3;
    if(key=='4') angleID = 4;
    if(key=='5') angleID = 5;
    if(key=='6') angleID = 6;
    if(key=='7') angleID = 7;
    if(key=='8') angleID = 8;
    if(key=='9') angleID = 9;
    if(key=='a') angleID = 10;
    if(key=='b') angleID = 11;
    if(key=='c') angleID = 12;
    if(key=='d') angleID = 13;
    if(key=='e') angleID = 14;
    if(key=='f') angleID = 15;
    if(key=='g') angleID = 16;
    if(key=='h') angleID = 17;
    if(key=='i') angleID = 18;
    if(key=='j') angleID = 19;
    if(key=='k') angleID = 20;
    if(key=='l') angleID = 21;
    if(key=='m') angleID = 22;
    if(key=='n') angleID = 23;
    if(key=='o') angleID = 24;
}///記得在 int main()裡面, 加 glutKeyboardFunc(keyboard)

void display()
{
    glClearColor(1,1,0,0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
        glRotatef(angle[0],0,1,0);
        drawBody(); ///先註解掉身體
        glutSolidSphere(0.02, 30, 30); ///圓球
        glColor3f(1,1,1);

        glPushMatrix();
            glTranslatef(-0.19, 0.19, 0);
            glRotatef(angle[1], 1, 0, 0);
            glRotatef(angle[2], 0, 0, 1);
            glRotatef(angle[3], 0, 1, 0);
            glTranslatef(-0.05, -0.09, -0.03);
            drawupperA(); ///(3)上手臂放好
            glPushMatrix(); ///(0)
                glTranslatef(-0.05, -0.11, -0.02);
                glRotatef(angle[4], 1, 0, 0);
                glRotatef(angle[5], 0, 0, 1);
                glRotatef(angle[6], 0, 1, 0);
                glTranslatef(-0.07, -0.18, 0.05);
                drawlowerA();
            glPopMatrix();
        glPopMatrix();


        glPushMatrix();
            //glTranslatef(teapotX,teapotY,0);
            glTranslatef(0.17, 0.23, 0);
            //glutSolidTeapot(0.3);
            glRotatef(angle[7], 1, 0, 0);
            glRotatef(angle[8], 0, 1, 0);
            glRotatef(angle[9], 0, 0, 1);
            glTranslatef(0.05, -0.09, -0.03);
            drawupperB(); ///(3)上手臂放好
            glPushMatrix(); ///(0)
                glTranslatef(0.05, -0.11, -0.02);
                glRotatef(angle[10], 1, 0, 0);///(2) x軸轉
                glRotatef(angle[11], 0, 1, 0);
                glRotatef(angle[12], 0, 0, 1);
                glTranslatef(0.07, -0.180, 0.05);
                drawlowerB();
            glPopMatrix();
        glPopMatrix();


        glPushMatrix();
            //glTranslatef(teapotX,teapotY,0);
            glTranslatef(-0.09, -0.2, 0);
            //glutSolidTeapot(0.3);
            glRotatef(angle[13], 1, 0, 0);
            glRotatef(angle[14], 0, 1, 0);
            glRotatef(angle[15], 0, 0, 1);
            glTranslatef(0, -0.15, 0);
            drawupperlegA(); ///(3)上手臂放好
            glPushMatrix(); ///(0)
                glTranslatef(-0.04, -0.15, 0.05);
                glRotatef(angle[16], 1, 0, 0);///(2) x軸轉
                glRotatef(angle[17], 0, 1, 0);
                glRotatef(angle[18], 0, 0, 1);
                glTranslatef(0, -0.3, 0);
                glScaled(0.28f,0.28f,0.28f);
                drawlowerlegA();
            glPopMatrix();
        glPopMatrix();


        glPushMatrix();
            //glTranslatef(teapotX,teapotY,0);
            glTranslatef(0.1, -0.2, 0);
            //glutSolidTeapot(0.3);
            glRotatef(angle[19], 1, 0, 0);
            glRotatef(angle[20], 0, 1, 0);
            glRotatef(angle[21], 0, 0, 1);
            glTranslatef(0, -0.15, 0);
            drawupperlegB(); ///(3)上手臂放好
            glPushMatrix(); ///(0)
                glTranslatef(0.048, -0.15, 0.05);
                glRotatef(angle[22], 1, 0, 0);///(2) x軸轉
                glRotatef(angle[23], 0, 1, 0);
                glRotatef(angle[24], 0, 0, 1);
                glTranslatef(0, -0.3, 0);
                glScaled(0.28f,0.28f,0.28f);
                drawlowerlegB();
            glPopMatrix();
        glPopMatrix();

    glPopMatrix();


    glutSwapBuffers();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };///加這行, 讓它轉動

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };


int main(int argc, char*argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week13-1 Gundam");
    glutDisplayFunc(display);
    glutIdleFunc(display); ///加這行, 讓它轉動
    glutMotionFunc(motion);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard); ///week13-1新加的

    //myTexture("data/Diffuse.jpg");

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();
}
