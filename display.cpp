#include <GL/glut.h>
#include "initgame.cpp"
std::vector<VAO*> v[2];
int x,y,mode;
float lead,centd,segd;
static const GLfloat color_buffer_data [] = {
        0.85,0.85,0.85,
        0.85,0.85,0.85,
        0.85,0.85,0.85,
};
void line(float x1, float y1,float x2, float y2){
        //cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
        GLfloat vertex_buffer_data [] = {
                x1,y1,0,
                x1,y1,0, 
                x2,y2,0, 
        };
        v[mode].push_back(create3DObject(GL_TRIANGLES, 3, vertex_buffer_data, color_buffer_data, GL_LINE));
}

void drawSubDigit(int i){
        if(i==1)
                line(x,y+1.5*segd,x,y);
        if(i==2)
                line(x,y,x,y-1.5*segd);
        if(i==3)
                line(x-segd,y+1.5*segd,x-segd,y);
        if(i==4)
                line(x-segd,y,x-segd,y-1.5*segd);
        if(i==5)
                line(x,y+1.5*segd,x-segd,y+1.5*segd);
        if(i==6)
                line(x,y,x-segd,y);
        if(i==7)
                line(x,y-1.5*segd,x-segd,y-1.5*segd);
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
        x=-68+trans;
        y=22/zoom;
        mode=0;
        centd= 2.5/zoom;
        segd = 1 /zoom;
        int pvalue=value;
        x-=centd+(float)1.0/zoom;
        if(value==0){
                drawDigit(0);
                x-=centd;
        }
        while (value!=0){
                drawDigit(value%10);
                x-=centd;
                value = value/10;
        }
        if(pvalue<10){
                drawDigit(0);
                x-=centd;
        }
        if(pvalue<100)
                drawDigit(0);
        y=27/zoom;x=-75+trans;
        drawDigit(5);
        x+=centd;
        drawSubDigit(3);
        drawSubDigit(4);
        drawSubDigit(5);
        drawSubDigit(7);
        x+=centd;
        drawDigit(0);
        x+=centd;
        drawSubDigit(1);
        drawSubDigit(2);
        drawSubDigit(3);
        drawSubDigit(4);
        drawSubDigit(5);
        drawSubDigit(6);
        x+=centd;
        drawSubDigit(3);
        drawSubDigit(4);
        drawSubDigit(5);
        drawSubDigit(6);
        drawSubDigit(7);
}

void getSpeed(int value){
        x=-70+trans;
        y=32/zoom;
        mode=1;
        centd= 2.5/zoom;
        segd = 1 /zoom;
        int pvalue=value;
        x-=centd+(float)1.0/zoom;
        if(value==0){
                drawDigit(0);
                x-=centd;
        }
        while (value!=0){
                drawDigit(value%10);
                x-=centd;
                value = value/10;
        }
        if(pvalue<10)
                drawDigit(0);
        y=37/zoom;x=-75+trans;
        drawDigit(5);
        x+=centd;
        drawSubDigit(3);
        drawSubDigit(5);
        drawSubDigit(1);
        drawSubDigit(6);
        drawSubDigit(4);
        x+=centd;
        drawSubDigit(5);
        drawSubDigit(3);
        drawSubDigit(6);
        drawSubDigit(4);
        drawSubDigit(7);
        x+=centd;
        drawSubDigit(5);
        drawSubDigit(3);
        drawSubDigit(6);
        drawSubDigit(4);
        drawSubDigit(7);
        x+=centd;
        drawDigit(0);
}
