#include "controls.cpp"
std::vector<target> target_list;
std::vector<pair<target,float> > rot_list;
std::vector<obstacles> obstacles_list;


float sq(float x){
	return (float) x*x;
}

void reshapeWindow (GLFWwindow* window, int width, int height)
{
	int fbwidth=width, fbheight=height;
	
	glfwGetFramebufferSize(window, &fbwidth, &fbheight);

	GLfloat fov = 90.0f;

	glViewport (0, 0, (GLsizei) fbwidth, (GLsizei) fbheight);

	Matrices.projection = glm::ortho(-77.0f, 77.0f, -40.0f, 40.0f, 0.1f, 500.0f);
}

GLFWwindow* initGLFW (int width, int height)
{
	GLFWwindow* window; 

	glfwSetErrorCallback(error_callback);
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(width, height, "Sample OpenGL 3.3 Application", NULL, NULL);

	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
	glfwSwapInterval( 1 );

	glfwSetFramebufferSizeCallback(window, reshapeWindow);
	glfwSetWindowSizeCallback(window, reshapeWindow);
	glfwSetWindowCloseCallback(window, quit);
	glfwSetKeyCallback(window, keyboard);      
	glfwSetCharCallback(window, keyboardChar); 
	glfwSetMouseButtonCallback(window, mouseButton);  
	return window;
}

void makeTarget(){
	int st=1,x,y,r=rand()%2+3;
	x=rand()%70+1;
	y=rand()%60+1;
	y-=30;
	while(st){
		st=0;
		for(int i=0;i<target_list.size();i++){
			float dis=sqrt(sq((float)(x-target_list[i].x))+sq(((float)y-target_list[i].y)));
			if(dis<r+target_list[i].radius){
				r=rand()%2+3;
				x=rand()%70+1;
				y=rand()%60+1;
				y-=30;
				st=1;
				break;
			}
		}
	}
	//cout<<r<<" "<<x<<" "<<y<<endl;
	target xx=createTarget(r);
	xx.x=x;
	xx.y=y;
	target_list.push_back(xx);
}


void initGL (GLFWwindow* window, int width, int height)
{
	createCannon ();
	createMissile ();
	createCross ();
	createBase ();
	createSupport ();
	createExc ();
	createBall ();
	createRope ();
	createTry ();
	obstacles_list.push_back
	(createObstacles (-10,0,3,25,1));
	obstacles_list.push_back(createObstacles (-19,25,3,25,-1));
//	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
	int x=rand()%3+3;
	while(x<3)
		x=rand()%3+3;
	for(int i=0;i<x;i++)
		makeTarget();
	
	programID = LoadShaders( "Sample_GL.vert", "Sample_GL.frag" );
	Matrices.MatrixID = glGetUniformLocation(programID, "MVP");
	reshapeWindow (window, width, height);
	glClearColor (0.3f, 0.3f, 0.3f, 0.0f); // R, G, B, A
	glClearDepth (1.0f);

	glEnable (GL_DEPTH_TEST);
	glDepthFunc (GL_LEQUAL);

	cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
	cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
	cout << "VERSION: " << glGetString(GL_VERSION) << endl;
	cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}
