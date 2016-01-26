float camera_rotation_angle = 90;
float base_position = -35;
float support_height = 1;
float rectangle_rotation = 5;
float rotate_angle=5,shoot_angle;
float ballx,bally=-45,tranx,trany;
float gravity=3,shoot_time,maxangle=15;
float initial_velocity=15,velocity,velocityx;
float misx=-89,misy,velx=6.5;
float zoom=1,trans;
int flagg,shoot,str,stl,flag[15],trys=20,shoo,isshoot,flq;
//std::vector<pair<float,float> > trace;

void keyboard (GLFWwindow* window, int key, int scancode, int action, int mods)
{
	float theta;
	if (action == GLFW_RELEASE) {
		switch (key) {
			case GLFW_KEY_A:
				rectangle_rotation+=5;
				if(rectangle_rotation<0)
					rectangle_rotation=0;
				if(rectangle_rotation>90)
					rectangle_rotation=90;
				break;
			case GLFW_KEY_B:
				rectangle_rotation-=5;
				if(rectangle_rotation<0)
					rectangle_rotation=0;
				if(rectangle_rotation>90)
					rectangle_rotation=90;
				break;
			case GLFW_KEY_W:
				if(support_height<8){
					support_height+=1.5;
					base_position+=3;
				}
				break;
			case GLFW_KEY_E:
				if(support_height>1){
					support_height-=1.5;
					base_position-=3;
				}            	
				break;
			case GLFW_KEY_RIGHT:
				if(77.0f/zoom+trans<77.0) trans++;
				Matrices.projection = glm::ortho(-77.0f+trans, 77.0f/zoom+trans, -40.0f, 40.0f/zoom, 0.1f, 500.0f);
				break;
			case GLFW_KEY_LEFT:
				if(trans>0) trans--;
				Matrices.projection = glm::ortho(-77.0f+trans, 77.0f/zoom+trans, -40.0f, 40.0f/zoom, 0.1f, 500.0f);
				break;
			case GLFW_KEY_UP:
				//if(zoom<1.5) 
				zoom+=0.05;
				Matrices.projection = glm::ortho(-77.0f+trans, 77.0f/zoom+trans, -40.0f, 40.0f/zoom, 0.1f, 500.0f);
				break;
			case GLFW_KEY_DOWN:
				if(zoom>1) zoom-=0.05;
				while(77.0f/zoom+trans>77.0) trans--;
				trans++;
				Matrices.projection = glm::ortho(-77.0f+trans, 77.0f/zoom+trans, -40.0f, 40.0f/zoom, 0.1f, 500.0f);
				break;
			case GLFW_KEY_SPACE:
				if(bally+trany<=-42 || ballx+tranx>=80 || ballx+tranx<=-80){
					for(int i=0;i<10;i++)
						flag[i]=0;
					if(trys==0)
						flq=1;
					trys--;
					trans=0;
					Matrices.projection = glm::ortho(-77.0f+trans, 77.0f/zoom+trans, -40.0f, 40.0f/zoom, 0.1f, 500.0f);
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
			case GLFW_KEY_F:
				str=0;
				break;
			case GLFW_KEY_S:
				stl=0;
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
			case GLFW_KEY_F:
				str=1;
				break;
			case GLFW_KEY_S:
				stl=1;
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
			if (action == GLFW_RELEASE){
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
			break;
		case GLFW_MOUSE_BUTTON_RIGHT:
			if (action == GLFW_RELEASE) 
				break;
		default:
			break;
	}
}
