#include <opencv/highgui.h> ///�ϥ� OpenCV 2.1 ���²��, �u�n�� High GUI �Y�i
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCVŪ��
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV���m (�ݭncv.h)
    glEnable(GL_TEXTURE_2D); ///1. �}�ҶK�ϥ\��
    GLuint id; ///�ǳƤ@�� unsigned int ���, �s �K��ID
    glGenTextures(1, &id); /// ����Generate �K��ID
    glBindTexture(GL_TEXTURE_2D, id); ///�j�wbind �K��ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��T, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��S, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// �K�ϰѼ�, ��j�ɪ�����, �γ̪��I
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// �K�ϰѼ�, �Y�p�ɪ�����, �γ̪��I
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
GLMmodel * body =NULL;

void drawBody(void)
{
    if (!body) {
	body = glmReadOBJ("data/body.obj");
	if (!body) exit(0);
	glmUnitize(body);
	glmFacetNormals(body);
	glmVertexNormals(body, 90.0);
    }

    glmDraw(body, GLM_SMOOTH | GLM_TEXTURE);
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

    glmDraw(upperA, GLM_SMOOTH | GLM_TEXTURE);
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

    glmDraw(lowerA, GLM_SMOOTH | GLM_TEXTURE);
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

    glmDraw(pmodel, GLM_SMOOTH | GLM_TEXTURE);
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

    glmDraw(handA, GLM_SMOOTH | GLM_TEXTURE);
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

    glmDraw(handB, GLM_SMOOTH | GLM_TEXTURE);
}
void myBody() { ///�ڪ�����
	glPushMatrix(); ///�ƥ��x�}
        glColor3f(1, 0, 0);///���⪺
        glutSolidCube(0.6);///myBody();
	glPopMatrix(); ///�٭�x�}
}
///float angle = 0, da = 1; ///�[�o��, �������
float angle[20] = {}; ///20�Ө��� , ���]��0
int angleID = 0; ///�i�H�O����0, ����1, ����2, .....
int oldX = 0, oldY = 0;
#include <stdio.h>
FILE *fin =NULL;
FILE *fout =NULL;
void motion(int x, int y)
{
    angle[angleID] += y - oldY;
    oldX = x;
    oldY = y;
    glutPostRedisplay();
    //if(fout==NULL)fout =fopen("angle.txt","w+");
    //for(int i=0;i<20;i++){
//printf("%.1f ",angle[i]);
       // fprintf(fout,"%.1f ",angle[i]);
    //}
   // printf("\n");
    //fprintf(fout,"\n");
}

void mouse (int button, int state, int x, int y)
{
    oldX = x;
    oldY = y;
}

float oldAngle[20]={},newAngle[20]={};
void timer(int t){
    glutTimerFunc(50,timer,t+1);
    if(t%20==0){
        if(fin==NULL)fin = fopen("angle.txt","r");
        for(int i=0;i<20;i++){
            oldAngle[i]= newAngle[i];
            fscanf(fin,"%f",&newAngle[i]);
        }
    }
    float alpha =(t%20)/20.0;
    for(int i=0;i<20;i++){
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
        for(int i=0;i<20;i++){
            fscanf(fin,"%f",& angle[i]);
        }
        glutPostRedisplay();
    }
    else if(key=='s')
    {

    if(fout==NULL)fout =fopen("angle.txt","w+");
    for(int i=0;i<20;i++){
        printf("%.1f ",angle[i]);
        fprintf(fout,"%.1f ",angle[i]);
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
}///�O�o�b int main()�̭�, �[ glutKeyboardFunc(keyboard)

void display()
{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    ///glDisable(GL_TEXTURE_2D);

    glPushMatrix();
        glRotatef(angle[0],0,1,0);
        drawBody(); ///�����ѱ�����
    ///glutSolidSphere(0.1, 30, 30); ///��y
        glEnable(GL_TEXTURE_2D);
        glColor3f(1,1,1);

    glPushMatrix();
        glTranslatef(-0.1,0,0);
        glRotatef(angle[1], 0, 0, 1);
        glRotatef(angle[2], 1, 0, 0);
        glTranslatef(0, -0.07, 0);
        drawupperA(); ///(3)�W���u��n
        glPushMatrix(); ///(0)
            glTranslatef(-0.02, -0.09, 0); ///(3) �A����W���u����m
            glRotatef(angle[3], 1, 0, 0); ///(2) x�b��
            glTranslatef(0, -0.21, 0); ///(1)
            drawlowerA(); ///(0)
        glPopMatrix(); ///(0)
    glPopMatrix();

    glutSwapBuffers();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };///�[�o��, �������

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

//void timer(int t){
  //  glutTimerFunc(100,timer,t+1);
    //printf("�{�b�_��:%d\n",t);
//}

int main(int argc, char*argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week14-1_alpha_interpolation_angle_timer");
    glutDisplayFunc(display);
    glutIdleFunc(display); ///�[�o��, �������
    glutMotionFunc(motion);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard); ///week13-1�s�[��
    //glutTimerFunc(0,timer,0);

    myTexture("data/Diffuse.jpg");

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