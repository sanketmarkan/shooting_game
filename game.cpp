#include "initobjects.cpp"
#include "initgame.cpp"
#include <GL/glut.h>
using namespace std;
#include "display.cpp"


GLFWwindow* window;

float sq(float x){
	return (float) x*x;
}

void draw (){
	float theta = (float)(rectangle_rotation*M_PI/180.0);

	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram (programID);

	glm::vec3 eye ( 5*cos(camera_rotation_angle*M_PI/180.0f), 0, 5*sin(camera_rotation_angle*M_PI/180.0f) );
	glm::vec3 target (0, 0, 0);
	glm::vec3 up (0, 1, 0);

	Matrices.view = glm::lookAt(glm::vec3(0,0,3), glm::vec3(0,0,0), glm::vec3(0,1,0)); // Fixed camera for 2D (ortho) in XY plane

	glm::mat4 VP = Matrices.projection * Matrices.view;
	glm::mat4 MVP;	


	glm::mat4 translate = glm::translate (glm::vec3(-70.0f, base_position+1, 0));        // glTranslatef
	glm::mat4 rotate = glm::rotate((float)(rectangle_rotation*M_PI/180.0f), glm::vec3(0,0,1)); // rotate about vector (-1,0.8,1)
	Matrices.model = (translate * rotate);
	MVP = VP * Matrices.model;
	glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
	draw3DObject(cannon);


	for(int i=0;i<v[0].size();i++){
		translate = glm::translate (glm::vec3(0,0,0));        // glTranslatef
		Matrices.model = translate;
		MVP = VP * Matrices.model;
		glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
		draw3DObject(v[0][i]);
	}
	
	for(int i=0;i<v[1].size();i++){
		translate = glm::translate (glm::vec3(0,0,0));        // glTranslatef
		Matrices.model = translate;
		MVP = VP * Matrices.model;
		glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
		draw3DObject(v[1][i]);
	}

	translate = glm::translate (glm::vec3(30*cos(theta)-70.0,30*sin(theta)+base_position+1, 0));        // glTranslatef
	Matrices.model = translate;
	MVP = VP * Matrices.model;
	glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
	draw3DObject(cross);

    translate = glm::translate (glm::vec3(-68.0f,-42, 0));        // glTranslatef
    glm::mat4 scale = glm::scale (glm::vec3(1,support_height,1)); 
    Matrices.model = translate*scale;
    MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(support);   

    

	translate = glm::translate (glm::vec3(-68.0f, base_position, 0));        // glTranslatef
	Matrices.model = translate;
	MVP = VP * Matrices.model;
	glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
	draw3DObject(base);

	translate = glm::translate (glm::vec3(ballx+tranx,bally+trany, 0));        // glTranslatef
	Matrices.model = translate;
	MVP = VP * Matrices.model;
	glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
	draw3DObject(ball);

	for(int i=0;i<target_list.size();i++){
		int h= 40-target_list[i].y;
		scale = glm::scale (glm::vec3(0.6,h,1)); 
    	translate = glm::translate (glm::vec3(target_list[i].x,40, 0));        // glTranslatef
    	Matrices.model = translate*scale;
    	MVP = VP * Matrices.model;
    	glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    	draw3DObject(rope);
    }

    for(int i=0;i<rot_list.size();i++){
    	int h= 40-rot_list[i].first.y;
    	scale = glm::scale (glm::vec3(0.6,h,1)); 
    	translate = glm::translate (glm::vec3(rot_list[i].first.x,40, 0));        // glTranslatef
    	rotate = glm::rotate((float)(rot_list[i].second*M_PI/180.0f), glm::vec3(0,0,1)); 
    	Matrices.model = translate*rotate*scale;
    	MVP = VP * Matrices.model;
    	glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    	draw3DObject(rope);
    }    	

    for(int i=0;i<target_list.size();i++){
    	translate = glm::translate (glm::vec3(target_list[i].x,target_list[i].y, 0));        // glTranslatef
    	Matrices.model = translate;
    	MVP = VP * Matrices.model;
    	glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    	draw3DObject(target_list[i].vao);
    }


    for(int i=0;i<rot_list.size();i++){
    	translate = glm::translate (glm::vec3(0,rot_list[i].first.y - 40, 0));        // glTranslatef
    	rotate = glm::rotate((float)(rot_list[i].second*M_PI/180.0f), glm::vec3(0,0,1)); 
    	glm::mat4 translate2 = glm::translate (glm::vec3(rot_list[i].first.x,40, 0));        // glTranslatef
    	Matrices.model = translate2*rotate*translate;
    	MVP = VP * Matrices.model;
    	glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    	draw3DObject(rot_list[i].first.vao);
    }

    for(int i=0;i<obstacles_list.size();i++){
    	translate = glm::translate (glm::vec3(obstacles_list[i].x,obstacles_list[i].y, 0));        // glTranslatef
    	Matrices.model = translate;
    	MVP = VP * Matrices.model;
    	glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    	draw3DObject(obstacles_list[i].vao);
    }

    double xpos, ypos;
    int width,height;
    glfwGetCursorPos(window,&xpos, &ypos);
    glfwGetFramebufferSize(window, &width, &height);
    xpos=-77+(float)154.0/width*xpos;
    ypos=-40+(float)80.0/height*ypos;
    ypos*=-1;
    //cout<<xpos<<" "<<ypos<<endl;
    float x=-70.0;
    float y=base_position+1;
    rectangle_rotation = atan2 (ypos-y,xpos-x) * 180 / M_PI;
    if(rectangle_rotation<0)
    	rectangle_rotation=0;
    if(rectangle_rotation>90)
    	rectangle_rotation=90;
}



int main (int argc, char** argv)
{
	glutInit(&argc, argv);
	int width = glutGet(GLUT_SCREEN_WIDTH);;
	int height = glutGet(GLUT_SCREEN_HEIGHT);
	window = initGLFW(width, height);

	initGL (window, width, height);

	double last_update_time = glfwGetTime(), current_time;

	getSpeed((initial_velocity-3)*4);
	int score=0;
	/* Draw in loop */
	while (!glfwWindowShouldClose(window)) {
		draw();		
		glfwSwapBuffers(window);
		glfwPollEvents();

		current_time = glfwGetTime(); 
		if ((current_time - last_update_time) >= 0.08){
			if(stl){
				if(initial_velocity>3.001){
					initial_velocity-=0.25;
					v[1].clear();
					getSpeed((initial_velocity-3)*4);
				}
			}


			if(str){
				if(initial_velocity<27.74){
					initial_velocity+=0.25;
					v[1].clear();
					getSpeed((initial_velocity-3)*4);
				}
			}

			float theta = shoot_angle;
			v[0].clear();
			getScore(score++);
			ballx+=velocityx*0.25;
			bally=shoot?velocity*sin(shoot_angle)*shoot_time-gravity*shoot_time*shoot_time/2.0:-45.0;
			for(int i=0;i<rot_list.size();i++){
				float dis=sqrt(sq(ballx+tranx-rot_list[i].first.x)+sq(bally+trany-rot_list[i].first.y));
				if(dis<radius+rot_list[i].first.radius && !flag[i]){
					velocityx*=-0.4;
					rot_list.erase(rot_list.begin() + i);
					break;
				}
				rot_list[i].second+=rot_list[i].first.dir;
				if(abs(rot_list[i].second)>maxangle)
					rot_list[i].first.dir*=-1;
			}
			for(int i=0;i<target_list.size();i++){
				float dis=sqrt(sq(ballx+tranx-target_list[i].x)+sq(bally+trany-target_list[i].y));
				//cout<<dis<<" "<<radius+target_list[i].radius<<endl;
				if(dis<radius+target_list[i].radius){
					velocityx*=-0.6;
					flag[rot_list.size()]=1;
					rot_list.push_back(make_pair(target_list[i],0));
					rot_list[rot_list.size()-1].first.dir=1;
					target_list.erase(target_list.begin() + i);
					break;
				}
			}
			for(int i=0;i<obstacles_list.size();i++){
				obstacles_list[i].y+=obstacles_list[i].dir;
				if(obstacles_list[i].y>40 || obstacles_list[i].y-obstacles_list[i].len <-40)
					obstacles_list[i].dir*=-1;
				float xcor=obstacles_list[i].x,ycor=obstacles_list[i].y;
				float len = obstacles_list[i].len,bre=obstacles_list[i].bre;
				if(ballx+tranx>=xcor && ballx+tranx<=xcor+bre && bally+trany<=ycor && bally+trany>=ycor-len)
					velocityx=0;
				
			}
			shoot_time+=0.25;
			last_update_time = current_time;
		}
	}

	glfwTerminate();
	exit(EXIT_SUCCESS);
}