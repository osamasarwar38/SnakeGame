//============================================================================
// Name        : cookie-crush.cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Snake
//============================================================================
#ifndef COOKIE_CRUSH_CPP
#define COOKIE_CRUSH_CPP

//#include <GL/gl.h>
//#include <GL/glut.h>
#include <iostream>
#include<string>
#include<cmath>
#include<fstream>
#include "util.h"
using namespace std;
#define MAX(A,B) ((A) > (B) ? (A):(B)) // defining single line functions....
#define MIN(A,B) ((A) < (B) ? (A):(B))
#define ABS(A) ((A) < (0) ? -(A):(A))
#define FPS 200

#define KEY_ESC 27 // A

// 20,30,30
const int bradius = 30; // Cookie radius in pixels...
int moveV=0;
int moveH=0;
int j=0;
int inc=0;
int width = 800, height = 600; // i have set my window size to be 800 x 600
int dball = 0; // difference between cookies center of 0 pixels
int byoffset = bradius + dball; // 2 * bradius + dball; // board yoffset
bool up=false;
bool down=false;
bool rright=false;
bool lleft=false;
float score = 0;
int setcolor, psetcolor;


int disp=0;
int displayCount=0;
int arr[40][30];
int daanaX=rand()%40;
int daanaY=rand()%30;
int saanp=5;
int tail=1;
int head;
bool found;
//========================ARRAY FUNCTION===============================
void array(int arr[][30]){
	if (displayCount==0){
	for (int i=0;i<40;i++){
		for (int j=0;j<30;j++){
			if(i==daanaX && j==daanaY){
				arr[i][j]=-1;
				}
			else if((i>15 && i<20) && j==15){
				arr[i][j]=tail;
				tail+=1;
				}
			else if((i==20) && j==15){
				head=tail;
				arr[i][j]=head;
				}
			else {
			arr[i][j]=0;}}

			}

		for (int i=0;i<40;i++)
		for (int j=0;j<30;j++)
			cout<<arr[i][j];


}
else return;

	}
// =====================ARRAY FUNCTION END=============================



//-------------------Moving------------------------
void moving(){

		/*for (int i=0;i<40;i++){
			for (int j=0;j<30;j++){
			cout<<arr[i][j]<<" ";
				//if (arr[i][j]==-1) arr[i][j]=0;}}
		}cout<<s"\n";}*/

	if (displayCount>50){
		found=false;

		if (rright==true){

			for (int i=0;i<40;i++){
				for (int j=0;j<30;j++){
					if (arr[i][j]==head){
						if (arr[i+1][j]==0){
							arr[i+1][j]=head+1;


							}
						else if (arr[i+1][j]==-1){
							head+=1;
							arr[i+1][j]=head;
							found=true;

							}
						if (i==39){

						if (arr[0][j]==0){
							arr[0][j]=head+1;


							}
						else if (arr[0][j]==-1){
							head+=1;
							arr[0][j]=head;
							found=true;

							}

							}
						}
					}
				}
			}
		if (lleft==true){

			for (int i=0;i<40;i++){
				for (int j=0;j<30;j++){
					if (arr[i][j]==head){
						if (arr[i-1][j]==0){
							arr[i-1][j]=head+1;


							}
						else if (arr[i-1][j]==-1){
							head+=1;
							arr[i-1][j]=head;
							found=true;
							}

						if (i==0){

						if (arr[39][j]==0){
							arr[39][j]=head+1;


							}
						else if (arr[39][j]==-1){
							head+=1;
							arr[39][j]=head;
							found=true;

							}

							}



						}

				}

			}
		}

		if (up==true){

			for (int i=0;i<40;i++){
				for (int j=0;j<30;j++){
					if (arr[i][j]==head){
						if (arr[i][j+1]==0 && j!=29){
							arr[i][j+1]=head+1;


							}
						else if (arr[i][j+1]==-1 && j!=29){
							head+=1;
							arr[i][j+1]=head;
							found=true;
							}
						if (j==29){

						if (arr[i][0]==0){
							arr[i][0]=head+1;


							}
						else if (arr[i][0]==-1){
							head+=1;
							arr[i][0]=head;
							found=true;

							}

							}
						}

				}

			}
		}


		if (down==true){

			for (int i=0;i<40;i++){
				for (int j=0;j<30;j++){
					if (arr[i][j]==head){
						if (arr[i][j-1]==0 && j!=0){
							arr[i][j-1]=head+1;


							}
						else if(arr[i][j-1]==-1 && j!=0){
							head+=1;
							arr[i][j-1]=head;
							found=true;
							}
						if (j==0){

						if (arr[i][29]==0){
							arr[i][29]=head+1;


							}
						else if (arr[i][29]==-1){
							head+=1;
							arr[i][29]=head;
							found=true;

							}

							}
						}

				}

			}
		}

	if (found!=true){
	for (int i=0;i<40;i++){
		for (int j=0;j<30;j++){
			if (arr[i][j]>0){
				arr[i][j]-=1;}}}
		}

	if (found==true){
			daanaX=rand()%40;
			daanaY=rand()%30;
			score+=1;
		}



	for (int i=0;i<40;i++){
		for (int j=0;j<30;j++){
			if(i==daanaX && j==daanaY){
				arr[i][j]=-1;
				}}}
			}
	}

enum GameState { // Use to check different states of game...
	Ready, Shot, Over, RemoveCluster
};
GameState gamestate = Ready;

const int ncookies = 6;
enum Cookies {
	CK_BISCUIT, CK_BURGER, CK_CROISSONT, CK_CUPCAKE, CK_DONUT, CK_STAR
};
GLuint texture[ncookies];
GLuint tid[ncookies];
string tnames[] = { "biscuit.png", "burger.png", "croissont.png", "cupcake.png",
		"donut.png", "star.png" };
GLuint mtid[ncookies];
int cwidth = 60, cheight = 60; // 60x60 pixels cookies width & height...
int cw=cwidth,ch=cheight;
void RegisterTextures()
/*Function is used to load the textures from the files and display*/
// Please do not change it...
{
	// allocate a texture name
	glGenTextures(ncookies, tid);

	vector<unsigned char> data;
	ifstream ifile("image-data.bin", ios::binary | ios::in);
	if (!ifile) {
		cout << " Couldn't Read the Image Data file ";
		exit(-1);
	}
	// now load each cookies data...
	int length;
	ifile.read((char*) &length, sizeof(int));
	data.resize(length, 0);
	for (int i = 0; i < ncookies; ++i) {

		// Read current cookie

		ifile.read((char*) &data[0], sizeof(char) * length);

		mtid[i] = tid[i];
		// select our current texture
		glBindTexture( GL_TEXTURE_2D, tid[i]);

		// select modulate to mix texture with color for shading
		glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

		// when texture area is small, bilinear filter the closest MIP map
		glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
		GL_LINEAR_MIPMAP_NEAREST);
		// when texture area is large, bilinear filter the first MIP map
		glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		// if wrap is true, the texture wraps over at the edges (repeat)
		//       ... false, the texture ends at the edges (clamp)
		bool wrap = true;
		glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
				wrap ? GL_REPEAT : GL_CLAMP);
		glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,
				wrap ? GL_REPEAT : GL_CLAMP);

		// build our texture MIP maps
		gluBuild2DMipmaps( GL_TEXTURE_2D, 3, cwidth, cheight, GL_RGB,
		GL_UNSIGNED_BYTE, &data[0]);
	}
	ifile.close();
}
void DrawCookie(const Cookies &cname, int sx, int sy, int cwidth = 60,
		int cheight = 60)
		/*Draws a specfic cookie at given position coordinate
		 * sx = position of x-axis from left-bottom
		 * sy = position of y-axis from left-bottom
		 * cwidth= width of displayed cookie in pixels
		 * cheight= height of displayed cookiei pixels.
		 * */
		{
	float fwidth = (float) cwidth / width * 2, fheight = (float) cheight
			/ height * 2;
	float fx = (float) sx / width * 2 - 1, fy = (float) sy / height * 2 - 1;

	glPushMatrix();
	glEnable( GL_TEXTURE_2D);
	glBindTexture( GL_TEXTURE_2D, mtid[cname]);
//	glTranslatef(0, 0, 0);
//	glRotatef(-M_PI / 2, 0, 0, 1);
	glBegin( GL_QUADS);
	glTexCoord2d(0.0, 0.0);
	glVertex2d(fx, fy);
	glTexCoord2d(1.0, 0.0);
	glVertex2d(fx + fwidth, fy);
	glTexCoord2d(1.0, 1.0);
	glVertex2d(fx + fwidth, fy + fheight);
	glTexCoord2d(0.0, 1.0);
	glVertex2d(fx, fy + fheight);
	glEnd();

	glColor4f(1, 1, 1, 1);

//	glBindTexture(GL_TEXTURE_2D, 0);

	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	//glutSwapBuffers();
}

float Distance(float x1, float y1, float x2, float y2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
void Pixels2Cell(int px, int py, int & cx, int &cy) {

}
void Cell2Pixels(int cx, int cy, int & px, int &py)
// converts the cell coordinates to pixel coordinates...
		{

}

void DisplayFunction() {
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim red and 1 means pure red and so on.
//#if 0
	glClearColor(1/*Red Component*/, 1.0/*Green Component*/,
			1.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors

// #----------------- Write your code here ----------------------------#
	//write your drawing commands here or call your drawing functions...



moving();
array(arr);
int tempj=-29;
int tempi=-39;
for (int j=0;j<30;j+=1,tempj++){
	for (int i=0;i<40;i++,tempi++){
		if (arr[i][j]==-1){
					DrawCircle(i*0.025,j*0.03,0.015 , colors[RED]);}
		else if (arr[i][j]>0){
					DrawCircle(i*0.025,j*0.03, 0.015, colors[BLUE]);}
		else if (arr[i][j]==head){
					DrawString(i*20,j*20, width, height,
			">" , colors[BLACK]);
			}

}}

displayCount+=2;

	DrawString(width / 2 - 20, height - 20, width, height,
			"Score " + Num2Str(score), colors[BLUE_VIOLET]);

// #----------------- Write your code till here ----------------------------#
	// do not modify below this
	glutSwapBuffers(); // do not modify this line..

}
/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode(GL_PROJECTION);
	 glLoadIdentity();
	 glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {

	if (key == GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		if (rright!=true){
		lleft=true;
		up=false;
		down=false;
		rright=false;}
	} else if (key == GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		if (lleft!=true){
		rright=true;
				lleft=false;
		up=false;
		down=false;}

	} else if (key == GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		if (down!=true){
		up=true;
			lleft=false;
		down=false;
		rright=false;}
	} else if (key == GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		//right=true;
		if (up!=true){
		up=false;
				lleft=false;
		down=true;
		rright=false;}
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/
	/*
	 glutPostRedisplay();
	 */
}
/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */

void MouseMoved(int x, int y) {

	cout << "Current Mouse Coordinates X=" << x << " Y= " << height - y << endl;
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
int hello=8;
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
	{

		if (state == GLUT_DOWN && gamestate == Ready) {
			cout << "Left Mouse Button Pressed at Coordinates X=" << x << " Y= "
					<< height - y << endl;
			cout<<hello;

		}
		if (state == GLUT_UP && gamestate == Ready) {

		}

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
	{

	}
	//glutPostRedisplay();
}
/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == KEY_ESC/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}
}

/*
 * This function is called after every 1000.0 milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
float dt = 0, lastframe = 0;
void Timer(int m=0) {
	dt = (m - lastframe) / 1.0;
	lastframe = m;

	// dt is time elapsed between two frames..
	glutPostRedisplay();

	// implement your functionality here

	glutTimerFunc(100, Timer, m + 1); //CONTROL SNAKE SPEED
}

/*
 * our gateway main function
 * */



int main(int argc, char*argv[]) {
	InitRandomizer(); // seed the random number generator...
	//Write your code here for filling the canvas with different Cookies. You can use the GetCookie function for getting the random shaped cookies

int hello=1;
	glutInit(&argc, argv); // initialize the graphics library...

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("ITCs Cookie Crush"); // set the title of our game window
	//SetCanvasSize(width, height); // set the number of pixels...

	// Load the textures from the file..;
	RegisterTextures();
	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.

	glutDisplayFunc(DisplayFunction); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	glutMouseFunc(MouseClicked);

//// This function tells the library to call our Timer function after 1000.0 milliseconds...
	glutTimerFunc(500, Timer, 0);  // CONTROL SNAKE SPEED

//// now handle the control to library and it will call our registered functions when
//// it deems necessary...

	glutMainLoop();

	return 1;
}
#endif /* */
