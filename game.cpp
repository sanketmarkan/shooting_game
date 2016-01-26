#include "initobjects.cpp"
using namespace std;
#include "display.cpp"


GLFWwindow* window;
int score;

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


	for(int i=0;i<obstacles_list.size();i++){
    	translate = glm::translate (glm::vec3(obstacles_list[i].x,obstacles_list[i].y, 0));        // glTranslatef
    	Matrices.model = translate;
    	MVP = VP * Matrices.model;
    	glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    	draw3DObject(obstacles_list[i].vao);
    }

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



    for(int i=1;i<=trys;i++){
    	translate = glm::translate (glm::vec3(76,(float)40/21.0*i,0));
    	Matrices.model = translate;
    	MVP = VP * Matrices.model;
    	glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    	draw3DObject(tries);
    }


    translate = glm::translate (glm::vec3(misx,misy,0));
    Matrices.model = translate;
    MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(missile);

    if(flagg){
    	translate = glm::translate (glm::vec3(75,misy,0));
    	Matrices.model = translate;
    	MVP = VP * Matrices.model;
    	glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    	draw3DObject(exc);
    }


}

void handleCollision(float ballx){
	for(int i=0;i<rot_list.size();i++){
		float dis=sqrt(sq(ballx+tranx-rot_list[i].first.x)+sq(bally+trany-rot_list[i].first.y));
		if(dis<=radius+rot_list[i].first.radius && !flag[i]){
			velocityx*=-0.4;
			score+=50;
			rot_list.erase(rot_list.begin() + i);
			break;
		}
	}
	for(int i=0;i<target_list.size();i++){
		float dis=sqrt(sq(ballx+tranx-target_list[i].x)+sq(bally+trany-target_list[i].y));
		if(dis<=radius+target_list[i].radius){
			flag[rot_list.size()]=1;
			rot_list.push_back(make_pair(target_list[i],0));
			rot_list[rot_list.size()-1].first.dir=1;
			rot_list[rot_list.size()-1].first.speed=velocityx*0.6;
			velocityx*=-0.6;
			score+=25;
			target_list.erase(target_list.begin() + i);
			break;
		}
	}
	for(int i=0;i<obstacles_list.size();i++){
		float xcor=obstacles_list[i].x,ycor=obstacles_list[i].y;
		float len = obstacles_list[i].len,bre=obstacles_list[i].bre;
		if(ballx+tranx+radius>=xcor && ballx+tranx-radius<=xcor+bre && bally+trany-radius<=ycor && bally+trany+radius>=ycor-len)
			velocityx*=-0.5;

	}
}


void shootM(){
	isshoot=1;
	misx=80;
	flagg=0;
}


int main (int argc, char** argv)
{
	int width = 1366;
	int height = 768;
	window = initGLFW(width, height);

	initGL (window, width, height);

	double last_update_time = glfwGetTime(),last_time=glfwGetTime(),current_time,ptime=-5;
	double just_detected[20];

	getSpeed((initial_velocity-3)*4);
	while (!glfwWindowShouldClose(window)) {
		draw();		
		glfwSwapBuffers(window);
		glfwPollEvents();
		//cout<<rot_list.size()+target_list.size()<<endl;
		current_time = glfwGetTime();
		/*int shoo = rand()%800;
		if(!shoo && !isshoot && !flagg){
			ptime = current_time;
			flagg=1;
			misy=-10-rand()%25;
		}



		if((current_time - ptime) >= 2 && flagg)
			shootM();*/

			if((current_time-last_time) >=5){
				if(rot_list.size()+target_list.size()<8)
					makeTarget();
				last_time=current_time;
			}
			if ((current_time - last_update_time) >= 0.08){
				if(stl){
					if(initial_velocity>3.001)
						initial_velocity-=0.25;
				}


				if(str){
					if(initial_velocity<27.74)
						initial_velocity+=0.25;
				}
				v[1].clear();
				getSpeed((initial_velocity-3)*4);
				v[0].clear();
				getScore(score);

				for(int i=0;i<=(int)velocityx*0.25+1;i++)
					handleCollision((float)(ballx+i));

				for(int i=(int)velocityx*0.25;i<=0;i++)
					handleCollision((float)(ballx+i));

				for(int i=0;i<obstacles_list.size();i++){
					obstacles_list[i].y+=obstacles_list[i].dir;
					if(obstacles_list[i].y>40 || obstacles_list[i].y-obstacles_list[i].len <-40)
						obstacles_list[i].dir*=-1;
				}

				for(int i=0;i<rot_list.size();i++){
					rot_list[i].second+=rot_list[i].first.speed*rot_list[i].first.dir/10.0;
					if(abs(rot_list[i].second)>maxangle)
						rot_list[i].first.dir*=-1;
				}

				for(int i=0;i<obstacles_list.size();i++){
					for(int j=0;j<rot_list.size();j++){
						if(current_time-just_detected[j] < 1)
							continue;
						float xdash,ydash,xy,yx;
						xy = rot_list[j].first.x;
						yx = rot_list[j].first.y;
						xdash = xy - (yx-40) * sin(rot_list[j].second * M_PI/180.0);
						ydash = yx + (40-yx) * (1-cos(rot_list[j].second * M_PI/180.0)) ;
						if(xdash-rot_list[j].first.radius < obstacles_list[i].x + obstacles_list[i].bre){
							cout<<xdash<<endl;
							if(ydash < obstacles_list[i].y && ydash > obstacles_list[i].y - obstacles_list[i].len){
								rot_list[j].first.dir*=-1;
								just_detected[j] = current_time;
							}
						}
					}
				}
				for(int j=0;j<rot_list.size();j++){
					if(current_time-just_detected[j] < 1)
						continue;
					float xdash,ydash,xy,yx;
					xy = rot_list[j].first.x;
					yx = rot_list[j].first.y;
					xdash = xy - (yx-40) * sin(rot_list[j].second * M_PI/180.0);
					ydash = yx + (40-yx) * (1-cos(rot_list[j].second * M_PI/180.0));
					for(int i=0;i<target_list.size();i++){
						float dis=sqrt(sq(target_list[i].x-xdash)+sq(target_list[i].y-ydash));
						if(dis<=rot_list[j].first.radius+target_list[i].radius){
							rot_list.push_back(make_pair(target_list[i],0));
							rot_list[rot_list.size()-1].first.dir=rot_list[j].first.dir;
							rot_list[rot_list.size()-1].first.speed=rot_list[j].first.speed;
							target_list.erase(target_list.begin() + i);
							rot_list[j].first.dir*=-1;
							just_detected[j] = current_time;
							just_detected[rot_list.size()-1] = current_time;
							break;
						}
					}
				}



				for(int i=0;i<rot_list.size();i++){
					if(current_time-just_detected[i] < 1)
						continue;
					for(int j=i+1;j<rot_list.size();j++){
						if(current_time-just_detected[j] < 1)
							continue;
						float xdash,ydash,xy,yx,xdash1,ydash1;
						xy = rot_list[j].first.x;
						yx = rot_list[j].first.y;
						xdash = xy - (yx-40) * sin(rot_list[j].second * M_PI/180.0);
						ydash = yx + (40-yx) * (1-cos(rot_list[j].second * M_PI/180.0)) ;
						xy = rot_list[i].first.x;
						yx = rot_list[i].first.y;
						xdash1 = xy - (yx-40) * sin(rot_list[i].second * M_PI/180.0);
						ydash1 = yx + (40-yx) * (1-cos(rot_list[i].second * M_PI/180.0)) ;
						float dis=sqrt(sq(xdash1-xdash)+sq(ydash1-ydash));
						if(dis<=rot_list[i].first.radius+rot_list[j].first.radius){
							rot_list[i].first.dir*=-1;
							rot_list[j].first.dir*=-1;
							just_detected[j] = current_time;
							just_detected[i] = current_time;
							cout<<"collided"<<endl;
						}
					}
				}
				if(flq)
					quit(window);
				ballx+=velocityx*0.3;
				bally=shoot?velocity*sin(shoot_angle)*shoot_time-gravity*shoot_time*shoot_time/2.0:-45.0;
				if(ballx>77.0f/zoom+trans && 77.0f/zoom+trans+1<77.0 && bally>-41){
					trans++;
					Matrices.projection = glm::ortho(-77.0f+trans, 77.0f/zoom+trans, -40.0f, 40.0f/zoom, 0.1f, 500.0f);
				}
				if(ballx<-77+trans && trans>0 && bally>-41){
					trans--;
					Matrices.projection = glm::ortho(-77.0f+trans, 77.0f/zoom+trans, -40.0f, 40.0f/zoom, 0.1f, 500.0f);
				}
				shoot_time+=0.3;
				last_update_time = current_time;
			}
		}

		glfwTerminate();
		exit(EXIT_SUCCESS);
	}