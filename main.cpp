#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <Math.h>

void box(float x1, float y1, float z1, float x2, float y2, float z2){
    //kiri bawah belakang ----- kanan atas depan
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
        //belakang
//        glColor3f(1,0,0);
        glVertex3f(x1, y1, z1);
        glVertex3f(x2, y1, z1);
        glVertex3f(x2, y2, z1);
        glVertex3f(x1, y2, z1);

        //depan
//        glColor3f(1,1,0);
        glVertex3f(x1, y1, z2);
        glVertex3f(x1, y2, z2);
        glVertex3f(x2, y2, z2);
        glVertex3f(x2, y1, z2);

        //bottom
//        glColor3f(1,0,1);
        glVertex3f(x1,y1,z1);
        glVertex3f(x2,y1,z1);
        glVertex3f(x2,y1,z2);
        glVertex3f(x1,y1,z2);

        //top
//        glColor3f(0,1,0);
        glVertex3f(x1,y2,z1);
        glVertex3f(x1,y2,z2);
        glVertex3f(x2,y2,z2);
        glVertex3f(x2,y2,z1);

        //left
//        glColor3f(0,1,1);
        glVertex3f(x1,y1,z1);
        glVertex3f(x1,y1,z2);
        glVertex3f(x1,y2,z2);
        glVertex3f(x1,y2,z1);

        //right
//        glColor3f(1,1,1);
        glVertex3f(x2,y1,z1);
        glVertex3f(x2,y1,z2);
        glVertex3f(x2,y2,z2);
        glVertex3f(x2,y2,z1);
    glEnd();
}

void stiker_atas(float x1, float y1, float z1, float x2, float y2, float z2, int type){
    //type = 1 == depan ; type=2 == belakang
    if (type==1){
        glColor3f(1,1,0);
    }else if (type == 2){
        glColor3f(1,1,1);
    }
    glBegin(GL_QUADS);

        glVertex3f(x1+0.1,y2,z1+0.1);
        glVertex3f(x1+0.1,y2,z2-0.1);
        glVertex3f(x2-0.1,y2,z2-0.1);
        glVertex3f(x2-0.1,y2,z1+0.1);
    glEnd();
}
void stiker_depan(float x1, float y1, float z1, float x2, float y2, float z2, int type){
    //type = 1 == depan ; type=2 == belakang
    if (type==1){
        glColor3f(1,0,0);
    }else if (type == 2){
        glColor3f(0.5,0.5, 0);
    }
    glBegin(GL_QUADS);

        glVertex3f(x1+0.1, y1+0.1, z1);
        glVertex3f(x2-0.1, y1+0.1, z1);
        glVertex3f(x2-0.1, y2-0.1, z1);
        glVertex3f(x1+0.1, y2-0.1, z1);

    glEnd();
}

void stiker_samping(float x1, float y1, float z1, float x2, float y2, float z2, int type){
    //type = 1 == kiri ; type=2 == kanan
    if (type==1){
        glColor3f(0,0,1);
    }else if (type == 2){
        glColor3f(0,1, 0);
    }
    glBegin(GL_QUADS);

        glVertex3f(x1,y1+0.1,z1+0.1);
        glVertex3f(x1,y1+0.1,z2-0.1);
        glVertex3f(x1,y2-0.1,z2-0.1);
        glVertex3f(x1,y2-0.1,z1+0.1);

    glEnd();
}

bool x_active = false;
bool y_active = false;
float spinX[] = {0,0,0}; // baris 0 = index 0, dst;
float spinY[] = {0,0,0}; // baris 0 = index 0, dst;

void display()
{
 glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
// glRotated(-35, 1,1,1);

 for (int x=0; x<3; x++){
    for (int y=0; y<3; y++){
        for (int z=0; z<3; z++){
            glPushMatrix();
            glTranslated(1.5, 1.5, 1.5);
//            if (x_active){
                glRotated(spinX[x], 1,0,0);
//            }
//            else if (y_active){
                glRotated(spinY[y], 0,1,0);
//            }
            glTranslated(-1.5, -1.5, -1.5);

            glPushMatrix();
                glTranslated(x,y,z);
                box(0,0,0,     1,1,1);
            glPopMatrix();

            glPopMatrix();
        }
    }
 }

 for (int x=0; x<3; x++){
    for (int y=0; y<3; y++){
        glPushMatrix();
            glTranslated(1.5, 1.5, 1.5);
//            if (x_active){
                glRotated(spinX[x], 1,0,0);
//            }
//            else if (y_active){
                glRotated(spinY[y], 0,1,0);
//            }
            glTranslated(-1.5, -1.5, -1.5);

            glPushMatrix();
                glTranslated(x,y,0);
                stiker_depan(0,0,3.1, 1,1,3.1,  1); //depan
                stiker_depan(0,0,-0.1, 1,1,-0.1,  2); //belakang
            glPopMatrix();
        glPopMatrix();
    }
 }
 for (int y=0; y<3; y++){
    for (int z=0; z<3; z++){
        glPushMatrix();
            glTranslated(1.5,1.5,1.5);
//            if (x_active){
                glRotated(spinX[0], 1,0,0);
//            }
//            else if (y_active){
                glRotated(spinY[y], 0,1,0);
//            }
            glTranslated(-1.5,-1.5,-1.5);

            glTranslated(0,y,z);
            stiker_samping(-0.1,0,0,   -0.1,1,1, 1); //kanan
        glPopMatrix();

        glPushMatrix();
            glTranslated(1.5,1.5,1.5);
//            if (x_active){
                glRotated(spinX[2], 1,0,0);
//            }
//            else if (y_active){
                glRotated(spinY[y], 0,1,0);
//            }
            glTranslated(-1.5,-1.5,-1.5);

            glTranslated(0,y,z);
            stiker_samping(3.1,0,0,   3.1,1,1, 2); //kiri
        glPopMatrix();
    }
 }
 for (int x=0; x<3; x++){
    for (int z=0; z<3; z++){
        glPushMatrix();
            glTranslated(1.5, 1.5, 1.5);
//            if (x_active){
                glRotated(spinX[x], 1,0,0);
//            }
//            else if (y_active){
                glRotated(spinY[2], 0,1,0);
//            }
            glTranslated(-1.5, -1.5, -1.5);

            glPushMatrix();
                glTranslated(x,0,z);
                stiker_atas(0,3.1,0,   1,3.1,1, 1);
            glPopMatrix();
        glPopMatrix();
        glPushMatrix();
            glTranslated(1.5, 1.5, 1.5);
//            if (x_active){
                glRotated(spinX[x], 1,0,0);
//            }
//            else if (y_active){
                glRotated(spinY[0], 0,1,0);
//            }
            glTranslated(-1.5, -1.5, -1.5);

            glPushMatrix();
                glTranslated(x,0,z);
                stiker_atas(0,-0.1,0,  1,-0.1,1, 2);
            glPopMatrix();
        glPopMatrix();
    }
 }

// glBegin(GL_LINES);
//    glVertex3f(-10,0,0);
//    glVertex3f(10,0,0);
//    glVertex3f(0,-10,0);
//    glVertex3f(0,10,0);
//    glVertex3f(0,0,-10);
//    glVertex3f(0,0,10);
// glEnd();
// glPushMatrix();
//     glRotated(spinX[0], 1,0,0);
//     glRotated(spinY[0], 0,1,0);
//     box(1,1,1, 2,2,2);
// glPopMatrix();
 glFlush();
}

void myinit()
{
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glOrtho(-10.0,10.0,-10.0,10.0,-10.0,10.0);
 glMatrixMode(GL_MODELVIEW);
 glClearColor(0.5,0.5,0.5,1.0);
 glColor3f(1.0,1.0,1.0);
 glShadeModel(GL_FLAT);
 glEnable(GL_DEPTH_TEST);
}
void input(unsigned char key, int x, int y){
    if (key=='q' || key=='Q') {
        exit(0);
    } else if(key=='a' || key=='A'){
         glRotated(1, 0,1,0);
         display();
    } else if(key=='s' || key=='S'){
         glRotated(-1, 1,0,0);
         display();
    } else if(key=='d' || key=='D'){
         glRotated(-1, 0,1,0);
         display();
    } else if(key=='w' || key=='W'){
         glRotated(1, 1,0,0);
         display();
    } else if (key == '1'){
        x_active = true; y_active = false;
        spinX[0] += 5;
        display();
    } else if (key == '2'){
        x_active = true; y_active = false;
        spinX[1] += 5;
        display();
    } else if (key == '3'){
        x_active = true; y_active = false;
        spinX[2] += 5;
        display();
    } else if (key == '4'){
        x_active = false; y_active = true;
        spinY[0] += 5;
        display();
    } else if (key == '5'){
        x_active = false; y_active = true;
        spinY[1] += 5;
        display();
    } else if (key == '6'){
        x_active = false; y_active = true;
        spinY[2] += 5;
        display();
    }
}
int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
 glutInitWindowSize(400, 400);
 glutInitWindowPosition(100, 100);
 glutCreateWindow("Kubus");
 myinit();
 glutDisplayFunc(display);
 glutKeyboardFunc(input);
 glutMainLoop();
 return 0;
 }
