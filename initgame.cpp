#include "controls.cpp"
std::vector<target> target_list;
std::vector<obstacles> obstacles_list;


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

void initGL (GLFWwindow* window, int width, int height)
{
	createCannon ();
	createCross ();
	createBase ();
	createSupport ();
	createBall ();
	createRope ();
	obstacles_list.push_back(createObstacles (-10,0,3,25,1));
	obstacles_list.push_back(createObstacles (-19,25,3,25,-1));
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
	int x=rand()%10+1;
	while(x<4)
		x=rand()%10+1;
	for(int i=0;i<x;i++){
		int r=rand()%2+3;
		target x=createTarget(r);
		r=rand()%70+1;
		x.x=r;
		r=rand()%70+1;
		x.y=r-35;
		target_list.push_back(x);
	}
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
