#include "important.cpp"

using namespace std;

VAO *cannon,*base;
VAO *support,*ball;

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
	for(int i=0;i<9000;i+=3){
		color_buffer_data[i]=0;
		color_buffer_data[i+1]=0;
		color_buffer_data[i+2]=0;
	}
	ball = create3DObject(GL_TRIANGLES, 3000, vertex_buffer_data, color_buffer_data, GL_LINE);
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
