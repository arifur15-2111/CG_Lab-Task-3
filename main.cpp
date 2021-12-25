#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include <math.h>

void init(void)
{
    glClearColor(0.0,0.0,0.0,0.0); //GLfloat red,green,blue,alpha initial value 0 alpha values used by glclear to clear the color buffers
    glMatrixMode(GL_PROJECTION);  // To specify which matrix is the current matrix & projection applies subsequent matrix to projecton matrix stack
    glLoadIdentity();
    glOrtho(0.0, 500.0, 0.0, 500.0, -1.0, 500.0);
}

int xs=150, ys=220, xe=90, ye=120;
double xi, yi, m;
void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f( 1,0, 0);

    int m = (ye-ys)/(xe-xs);

    if(xe>xs){
        if(m<=1){
            xi = 1;
            yi = m;
        }
        else if(m>1){
            yi = 1;
            xi = 1/m;
        }
    }   //case 1 or case 2
    else if(xs>xe){
        if(m<=1){
            xi = -1;
            yi = -m;
        }
        else if(m>1){
            xi = (-1)/m;
            yi = -1;
        }
    } //case 3 or case 4


    glBegin(GL_POINTS);
    glVertex2i(round(xs), round(ys));
    while(1){
        xs = xs+xi;
        ys = ys+yi;

        glVertex2i(round(xs), round(ys));
        if(xs==xe || ys==ye){
            break;
        }

    }


    glEnd();
    glFlush();
    glutSwapBuffers();
}

int main(int argc,char **argv)
{


    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Lab Task: 3, ID: 182-15-2111");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}
