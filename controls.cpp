float camera_rotation_angle = 90;
 float base_position = -3;
 float support_height = 1;
 float rectangle_rotation = 5;
 float rotate_angle=5,shoot_angle;
 float ballx,bally;
 int counter=0;
/* Executed when a regular key is pressed/released/held-down */
/* Prefered for Keyboard events */
 void keyboard (GLFWwindow* window, int key, int scancode, int action, int mods)
 {
	// Function is called first on GLFW_PRESS.
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
       if(support_height<2){
           support_height+=0.5;
           base_position+=0.5;
       }
       break;
       case GLFW_KEY_S:
       if(support_height>1){
           support_height-=0.5;
           base_position-=0.5;
       }            	
       break;
       case GLFW_KEY_SPACE:
       counter=0;
       theta = (float)(rectangle_rotation*M_PI/180.0);
       shoot_angle = theta;
       ballx = 2*cos(theta)-6.2;
       bally = 2*sin(theta)+base_position;
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

/* Executed when a mouse button is pressed/released */
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
