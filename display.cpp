#include <GL/glut.h>

int x=0,y=0,flag0=0;
void line(float x1, float y1,float x2, float y2){
        static const GLfloat vertex_buffer_data [] = {
                x1,y1,0,
                x2,y2,0, 
                x1,y1,0, 
        };
        static const GLfloat color_buffer_data [] = {
                0.85,0.85,0.85,
                0.85,0.85,0.85,
                0.85,0.85,0.85,
        };
        cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
        VAO* line = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data, color_buffer_data, GL_FILL);
        draw3DObject(line);
}

void drawSubDigit(int i){
        cout<<i<<endl;
        if(i==1)
                line(x,y+3,x,y);
        if(i==2)
                line(x,y,x,y-3);
        if(i==3)
                line(x-3,y+3,x-3,y);
        if(i==4)
                line(x-3,y,x-3,y-3);
        if(i==5)
                line(x,y+3,x-3,y+3);
        if(i==6)
                line(x,y,x-3,y);
        if(i==7)
                line(x,y-3,x-3,y-3);
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
                x=x-5;
                y=0;
        }
        if(flag0==1){
                drawDigit(-1);
        }

        x=0;
        y=0;
}





