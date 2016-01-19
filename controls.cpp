float camera_rotation_angle = 90;
float base_position = -35;
float support_height = 1;
float rectangle_rotation = 5;
float rotate_angle=5,shoot_angle;
float ballx,bally=-45,tranx,trany;
float gravity=3,shoot_time;
float initial_velocity=15,velocity,velocityx;
int shoot;



void keyboard (GLFWwindow* window, int key, int scancode, int action, int mods)
{
	float theta;
	if (action == GLFW_RELEASE) {
		switch (key) {
			case GLFW_KEY_W:
				if(support_height<8){
					support_height+=1.5;
					base_position+=3;
				}
				break;
			case GLFW_KEY_S:
				if(support_height>1){
					support_height-=1.5;
					base_position-=3;
				}            	
				break;
			case GLFW_KEY_SPACE:
				if(bally<=-42){
					shoot=1;
					theta = (float)(rectangle_rotation*M_PI/180.0);
					shoot_angle = theta;
					tranx = 16*cos(theta)-70.0;
					trany = 16*sin(theta)+base_position+1;
					velocity = initial_velocity;
					velocityx = velocity * cos(theta);
					ballx = -1*velocityx*0.25;
					shoot_time=0;
				}
				break;
			case GLFW_KEY_RIGHT:
				if(initial_velocity<27.99)
					initial_velocity+=0.25;
				break;
			case GLFW_KEY_LEFT:
				if(initial_velocity>3.001)
					initial_velocity-=0.25;
				break;
			default:
				break;
		}
	}
	else if (action == GLFW_PRESS) {
		switch (key) {
			case GLFW_KEY_ESCAPE:
				quit(window);
				break;
			default:
				break;
		}
	}
}

/* Executed for character input (like in text boxes) */
void keyboardChar (GLFWwindow* window, unsigned int key)
{
	switch (key) {
		case 'Q':
		case 'q':
			quit(window);
			break;
		default:
			break;
	}
}

void mouseButton (GLFWwindow* window, int button, int action, int mods)
{
	switch (button) {
		case GLFW_MOUSE_BUTTON_LEFT:
			if (action == GLFW_RELEASE)
				break;
		case GLFW_MOUSE_BUTTON_RIGHT:
			if (action == GLFW_RELEASE) 
				break;
		default:
			break;
	}
}
