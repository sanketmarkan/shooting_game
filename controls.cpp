float camera_rotation_angle = 90;
float base_position = -35;
float support_height = 1;
float rectangle_rotation = 5;
float rotate_angle=5,shoot_angle;
float ballx,bally;
float gravity=3,shoot_time;
float initial_velocity=4,velocity;
int counter=0;



void keyboard (GLFWwindow* window, int key, int scancode, int action, int mods)
{
	float theta;
	if (action == GLFW_RELEASE) {
		switch (key) {
			case GLFW_KEY_UP:
				rectangle_rotation+=rotate_angle;
				if(rectangle_rotation>90)
					rectangle_rotation=90;
				break;
			case GLFW_KEY_DOWN:
				rectangle_rotation-=rotate_angle;
				if(rectangle_rotation<5)
					rectangle_rotation=5;
				break;
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
				counter=0;
				theta = (float)(rectangle_rotation*M_PI/180.0);
				shoot_angle = theta;
				ballx = 16*cos(theta)-70.0;
				bally = 16*sin(theta)+base_position+1;
				velocity = initial_velocity;
				shoot_time=0;
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
