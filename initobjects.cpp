#include "important.cpp"

using namespace std;

VAO *cannon,*base,*rope,*missile;
VAO *support,*ball,*cross,*tries,*exc;

float radius=0.5;
void createBall(){
	GLfloat vertex_buffer_data [9005];
	int j=0;
	for(int i=0;i<1000;i++){
		vertex_buffer_data[j++]=radius*cos(2*3.14159*i/1000.0);
		vertex_buffer_data[j++]=radius*sin(2*3.14159*i/1000.0);
		vertex_buffer_data[j++]=0;
		vertex_buffer_data[j++]=radius*cos(2*3.14159*(i+1)/1000.0);
		vertex_buffer_data[j++]=radius*sin(2*3.14159*(i+1)/1000.0);
		vertex_buffer_data[j++]=0;
		vertex_buffer_data[j++]=0;
		vertex_buffer_data[j++]=0;
		vertex_buffer_data[j++]=0;
	}

	GLfloat color_buffer_data [9005];
	for(int i=0;i<9000;i++)
		color_buffer_data[i]=0;
	ball = create3DObject(GL_TRIANGLES, 3000, vertex_buffer_data, color_buffer_data, GL_LINE);
}


void createExc(){
	GLfloat vertex_buffer_data [9105];
	int j=0;
	for(int i=0;i<1000;i++){
		vertex_buffer_data[j++]=radius*cos(2*3.14159*i/1000.0);
		vertex_buffer_data[j++]=radius*sin(2*3.14159*i/1000.0);
		vertex_buffer_data[j++]=0;
		vertex_buffer_data[j++]=radius*cos(2*3.14159*(i+1)/1000.0);
		vertex_buffer_data[j++]=radius*sin(2*3.14159*(i+1)/1000.0);
		vertex_buffer_data[j++]=0;
		vertex_buffer_data[j++]=0;
		vertex_buffer_data[j++]=0;
		vertex_buffer_data[j++]=0;
	}
	vertex_buffer_data[j++]=-0.5;
	vertex_buffer_data[j++]= 1;
	vertex_buffer_data[j++]= 0;
	
	vertex_buffer_data[j++]=0.5;
	vertex_buffer_data[j++]=1;
	vertex_buffer_data[j++]=0;

	vertex_buffer_data[j++]=0.5;
	vertex_buffer_data[j++]=4;
	vertex_buffer_data[j++]=0;

	vertex_buffer_data[j++]=-0.5;
	vertex_buffer_data[j++]= 1;
	vertex_buffer_data[j++]= 0;
	
	vertex_buffer_data[j++]=0.5;
	vertex_buffer_data[j++]=4;
	vertex_buffer_data[j++]=0;

	vertex_buffer_data[j++]=-0.5;
	vertex_buffer_data[j++]=4;
	vertex_buffer_data[j++]=0;

	GLfloat color_buffer_data [9105];
	for(int i=0;i<9018;i++)
		color_buffer_data[i]=0;
	exc = create3DObject(GL_TRIANGLES, 3006, vertex_buffer_data, color_buffer_data, GL_FILL);
}

void createTry(){
	GLfloat vertex_buffer_data [9005];
	int j=0;
	for(int i=0;i<1000;i++){
		vertex_buffer_data[j++]=radius*cos(2*3.14159*i/1000.0);
		vertex_buffer_data[j++]=radius*sin(2*3.14159*i/1000.0);
		vertex_buffer_data[j++]=0;
		vertex_buffer_data[j++]=radius*cos(2*3.14159*(i+1)/1000.0);
		vertex_buffer_data[j++]=radius*sin(2*3.14159*(i+1)/1000.0);
		vertex_buffer_data[j++]=0;
		vertex_buffer_data[j++]=0;
		vertex_buffer_data[j++]=0;
		vertex_buffer_data[j++]=0;
	}

	GLfloat color_buffer_data [9005];
	for(int i=0;i<9000;i++)
		color_buffer_data[i]=1;
	tries = create3DObject(GL_TRIANGLES, 3000, vertex_buffer_data, color_buffer_data, GL_LINE);
}


void createMissile(){
	static const GLfloat vertex_buffer_data [] = {
		-10,-1,0,
		-10,1,0,
		10,1,0,

		10,1,0,
		10,-1,0,
		-10,-1,0,

		-13,0,0,
		-10,1,0,
		-10,-1,0,

		9,3,0,
		9,1,0,
		7,1,0,

		9,-3,0,
		9,-1,0,
		7,-1,0,

		9,0,0,
		7,0,0,
		12,-0.8,0,
	};
	static const GLfloat color_buffer_data [] = {
		0.5,0.5,0.5, 
		0.5,0.5,0.5, 
		0.5,0.5,0.5, 

		0.5,0.5,0.5, 
		0.5,0.5,0.5, 
		0.5,0.5,0.5,


		0.7,0.7,0.7, 
		0.7,0.7,0.7, 
		0.7,0.7,0.7,

		0.7,0.7,0.7, 
		0.7,0.7,0.7, 
		0.7,0.7,0.7,

		0.7,0.7,0.7, 
		0.7,0.7,0.7, 
		0.7,0.7,0.7,

		0.7,0.7,0.7, 
		0.7,0.7,0.7, 
		0.7,0.7,0.7,
	};
	missile = create3DObject(GL_TRIANGLES, 18, vertex_buffer_data, color_buffer_data, GL_FILL);
}


void createCross(){
	static const GLfloat vertex_buffer_data [] = {
		1,0,0,
		2,0,0,
		2,0,0,

		-1,0,0,
		-2,0,0,
		-2,0,0,

		0,1,0,
		0,2,0,
		0,2,0,

		0,-1,0,
		0,-2,0,
		0,-2,0,
	};
	GLfloat color_buffer_data [40];
	for(int i=0;i<36;i++)
		color_buffer_data[i]=0;
	cross = create3DObject(GL_TRIANGLES,12, vertex_buffer_data, color_buffer_data, GL_LINE);
}


void createSupport (){
	static const GLfloat vertex_buffer_data [] = {
		1.5,2.5,0,
		-1.5,2.5,0, 
		-1.5,0,0, 

		1.5,0,0, 
		-1.5,0,0, 
		1.5,2.5,0  
	};
	static const GLfloat color_buffer_data [] = {
		0.85,0.85,0.85,
		0.85,0.85,0.85,
		0.85,0.85,0.85,

		0.85,0.85,0.85,
		0.85,0.85,0.85,
		0.85,0.85,0.85,
	};
	support = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color_buffer_data, GL_FILL);
}


obstacles createObstacles(float x,float y,float wid,float len,int dir){
	static const GLfloat vertex_buffer_data [] = {
		wid,0,0,
		0,0,0,
		0,-1*len,0,

		wid,0,0,
		0,-1*len,0,
		wid,-1*len,0,
	};
	static const GLfloat color_buffer_data [] = {
		0.85,0.85,0.85,
		0.85,0.85,0.85,
		0.85,0.85,0.85,

		0.85,0.85,0.85,
		0.85,0.85,0.85,
		0.85,0.85,0.85,
	};
	obstacles z;
	z.vao= create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color_buffer_data, GL_FILL);
	z.x=x;
	z.len=len;
	z.bre=wid;
	z.y=y;
	z.dir=dir;
	return z;
}


void createRope(){
	static const GLfloat vertex_buffer_data [] = {
		0,0,0,
		0,-1,0,
		0.5,0,0,

		0.5,0,0,
		0.5,-1,0,
		0,-1,0,
	};
	static const GLfloat color_buffer_data [] = {
		0,0,0,
		0,0,0,
		0,0,0,

		0,0,0,
		0,0,0,
		0,0,0,

	};
	rope = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color_buffer_data, GL_FILL);
}


void createCannon (){
	static const GLfloat vertex_buffer_data [] = {
		16,0.5,0,
		16,-0.5,0, 
		0,-0.5,0, 

		16,0.5,0, 
		0,-0.5,0, 
		0,0.5,0  
	};
	static const GLfloat color_buffer_data [] = {
		0.5,0.5,0.5, 
		0.5,0.5,0.5, 
		0.5,0.5,0.5, 

		0.5,0.5,0.5, 
		0.5,0.5,0.5, 
		0.5,0.5,0.5, 
	};
	cannon = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color_buffer_data, GL_FILL);
}

void createBase (){
	static const GLfloat vertex_buffer_data [] = {
		8,-5,0,
		8,2,0, 
		-8,-5,0, 

		-8,-5,0, 
		8,2,0, 
		-8,2,0
	};
	static const GLfloat color_buffer_data [] = {
		0.8,0.8,0.8, 
		0.8,0.8,0.8,
		0.8,0.8,0.8, 

		0.8,0.8,0.8, 
		0.8,0.8,0.8, 
		0.8,0.8,0.8, 
	};
	base = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color_buffer_data, GL_FILL);
}

target createTarget(int radius){
	GLfloat vertex_buffer_data [9005];
	int j=0;
	for(int i=0;i<1000;i++){
		vertex_buffer_data[j++]=radius*cos(2*3.14159*i/1000.0);
		vertex_buffer_data[j++]=radius*sin(2*3.14159*i/1000.0);
		vertex_buffer_data[j++]=0;
		vertex_buffer_data[j++]=radius*cos(2*3.14159*(i+1)/1000.0);
		vertex_buffer_data[j++]=radius*sin(2*3.14159*(i+1)/1000.0);
		vertex_buffer_data[j++]=0;
		vertex_buffer_data[j++]=0;
		vertex_buffer_data[j++]=0;
		vertex_buffer_data[j++]=0;
	}

	GLfloat color_buffer_data [9005];
	for(int i=0;i<9000;i+=3){
		color_buffer_data[i]=0;
		color_buffer_data[i+1]=0;
		color_buffer_data[i+2]=0;
	}
	target x;
	x.vao = create3DObject(GL_TRIANGLES, 3000, vertex_buffer_data, color_buffer_data, GL_LINE);
	x.radius = radius;
	return x;	
}