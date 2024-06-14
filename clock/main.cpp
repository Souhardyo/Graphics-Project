#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <time.h>
#include <math.h>

using namespace std;



void initGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void Idle()
{
    glutPostRedisplay();
}

void displayAnalogClock()
{


    // Get current time
    time_t currentTime;
    struct tm *localTime;
    time(&currentTime);
    localTime = localtime(&currentTime);

    // Calculate angles for clock hands based on current time
    GLfloat secondAngle = -6.0f * localTime->tm_sec;
    GLfloat minuteAngle = -6.0f * localTime->tm_min - 0.1f * localTime->tm_sec;
    GLfloat hourAngle = -30.0f * localTime->tm_hour - 0.5f * localTime->tm_min;




    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(255,0,0);
    glVertex2f(0.0f, 0.7f); ///12'0 clock
    glVertex2f(0.0f, 0.6f);

    glVertex2f(0.4f, 0.7f);
    glVertex2f(0.34f, 0.6f);

    glVertex2f(-0.4f, 0.7f);
    glVertex2f(-0.34f, 0.6f);

    glVertex2f(-0.4f, -0.7f);
    glVertex2f(-0.34f, -0.6f);

    glVertex2f(0.7f, 0.35f);
    glVertex2f(0.6f, 0.32f);

    glVertex2f(0.7f, -0.35f);
    glVertex2f(0.6f, -0.32f);

    glVertex2f(-0.7f, -0.35f);
    glVertex2f(-0.6f, -0.32f);

    glVertex2f(-0.7f, 0.35f);
    glVertex2f(-0.6f, 0.32f);

    glVertex2f(-0.7f, 0.35f);
    glVertex2f(-0.6f, 0.32f);

    glVertex2f(0.7f, 0.0f);
    glVertex2f(0.6f, 0.0f);

    glVertex2f(0.0f, -0.7f);
    glVertex2f(0.0f, -0.6f);

    glVertex2f(0.38f, -0.7f);
    glVertex2f(0.34f, -0.6f);

    glVertex2f(-0.7f, 0.0f);
    glVertex2f(-0.6f, 0.0f);

    glEnd();

    glLoadIdentity();  ///clock face
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.7f, 0.7f);
    glVertex2f( -0.7f, 0.7f);

    glVertex2f(-0.7f, 0.7f);
    glVertex2f(-0.7f, -0.7f );

    glVertex2f(-0.7f, -0.7f);
    glVertex2f(0.7f, -0.7f );


    glVertex2f(0.7f, -0.7f);
    glVertex2f(0.7f, 0.7f );

    glEnd();


    // Draw clock hands
    glPushMatrix();
    glRotatef(secondAngle,0.0, 0.0, 1.0);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); // second
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glRotatef(minuteAngle, 0.0, 0.0, 1.0);
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 1.0f);  // minute
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glRotatef(hourAngle, 0.0, 0.0, 1.0);
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(120, 255, 255);  // Hour
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 0.4f);
    glEnd();
    glPopMatrix();





    glEnd();
}

void displayDigitalClock()
{
    glLoadIdentity();
    glRasterPos2f(-0.4, -0.9); // Adjust position for digital clock

    // Get current time
    time_t currentTime;
    struct tm *localTime;
    time(&currentTime);
    localTime = localtime(&currentTime);

    // Convert time to string with AM/PM
    char timeString[12]; // "hh:mm:ss AM/PM\0"
    strftime(timeString, sizeof(timeString), "%I:%M:%S %p", localTime);

    // Display digital clock with AM/PM
    glColor3f(0.0, 1.0, 1.0);
    for (int i = 0; i < 11; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, timeString[i]);
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    displayAnalogClock();
    displayDigitalClock();

    glutSwapBuffers();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Clock Ticking");
    glutDisplayFunc(display);
    initGL();
    glutIdleFunc(Idle);
    glutMainLoop();
    return 0;
}
