#include <GL/glut.h>

int x=50,y=50,flag0=0;
void line(float x1, float y1,
        float x2, float y2){

        glColor3f(1,1,1);
        glLineWidth(10);
        glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glEnd();
        glLineWidth(2);

}

void drawSubDigit(int i){

        if(i==1)
                line(x,y+0.3,x,y);
        if(i==2)
                line(x,y,x,y-0.3);
        if(i==3)
                line(x-0.3,y+0.3,x-0.3,y);
        if(i==4)
                line(x-0.3,y,x-0.3,y-0.3);
        if(i==5)
                line(x,y+0.3,x-0.3,y+0.3);
        if(i==6)
                line(x,y,x-0.3,y);
        if(i==7)
                line(x,y-0.3,x-0.3,y-0.3);
}

void drawDigit(int digit){

        if(digit==-1){
                drawSubDigit(6);
        }

        if(digit==0){
                drawSubDigit(1);
                drawSubDigit(2);
                drawSubDigit(3);
                drawSubDigit(4);
                drawSubDigit(5);
                drawSubDigit(7);
        }

        if(digit==1){
                drawSubDigit(1);
                drawSubDigit(2);
        }

        if(digit==2){
                drawSubDigit(5);
                drawSubDigit(1);
                drawSubDigit(6);
                drawSubDigit(4);
                drawSubDigit(7);
        }

        if(digit==3){
                drawSubDigit(5);
                drawSubDigit(1);
                drawSubDigit(6);
                drawSubDigit(2);
                drawSubDigit(7);
        }

        if(digit==4){
                drawSubDigit(3);
                drawSubDigit(1);
                drawSubDigit(6);
                drawSubDigit(2);
        }

        if(digit==5){
                drawSubDigit(3);
                drawSubDigit(5);
                drawSubDigit(6);
                drawSubDigit(2);
                drawSubDigit(7);
        }

        if(digit==6){
                drawSubDigit(3);
                drawSubDigit(5);
                drawSubDigit(6);
                drawSubDigit(2);
                drawSubDigit(7);
                drawSubDigit(4);
        }

        if(digit==7){
                drawSubDigit(1);
                drawSubDigit(5);
                drawSubDigit(2);
        }

        if(digit==8){
                drawSubDigit(3);
                drawSubDigit(4);
                drawSubDigit(5);
                drawSubDigit(6);
                drawSubDigit(2);
                drawSubDigit(7);
                drawSubDigit(1);
        }

        if(digit==9){
                drawSubDigit(3);
                drawSubDigit(5);
                drawSubDigit(6);
                drawSubDigit(2);
                drawSubDigit(7);
                drawSubDigit(1);
        }
}

void getScore(int value){

        if(value==0)
                drawDigit(0);
        if(value<0){
                flag0=1;
                value *= -1;
        }
        while (value!=0){
                drawDigit(value%10);
                value = value/10;
                x=x-0.7;
                y=0;
        }
        if(flag0==1){
                drawDigit(-1);
        }

        x=-3.5;
        y=0;
}





