#include "initobjects.cpp"
#include "initgame.cpp"

using namespace std;


void draw (){
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



    translate = glm::translate (glm::vec3(-68.0f,-42, 0));        // glTranslatef
    glm::mat4 scale = glm::scale (glm::vec3(1,support_height,1)); 
    Matrices.model = translate*scale;
    MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(support);   

    translate = glm::translate (glm::vec3(ballx,bally, 0));        // glTranslatef
    Matrices.model = translate;
    MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(ball);

	translate = glm::translate (glm::vec3(-68.0f, base_position, 0));        // glTranslatef
	Matrices.model = translate;
	MVP = VP * Matrices.model;
	glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
	draw3DObject(base);

}



int main (int argc, char** argv)
{
	int width = 1362;
	int height = 710;

	GLFWwindow* window = initGLFW(width, height);

	initGL (window, width, height);

	double last_update_time = glfwGetTime(), current_time;

	/* Draw in loop */
	while (!glfwWindowShouldClose(window)) {
		draw();
		glfwSwapBuffers(window);
		glfwPollEvents();

		current_time = glfwGetTime(); 
		if ((current_time - last_update_time) >= 0.05) { 
           ballx+=velocity*cos(shoot_angle)*shoot_time;
           bally+=velocity*sin(shoot_angle)*shoot_time-gravity*shoot_time*shoot_time/2.0;
           shoot_time+=0.1;
           last_update_time = current_time;
       }
   }

   glfwTerminate();
   exit(EXIT_SUCCESS);
}
