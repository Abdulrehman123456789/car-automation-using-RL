
#include <GL/glut.h>
#include<stdio.h>
#include<stdlib.h>

int r[5][15]={{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
              {0,100,100,100,0,0,0,0,0,0,0,0,0,0,100},
              {0,0,0,0,100,0,100,0,100,0,100,0,0,0,0},
              {0,0,0,0,100,100,0,100,0,100,0,0,0,0,0},
              {0,0,0,0,0,0,0,0,0,0,0,100,100,100,0}};


int q[5][15]={{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
              {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
              {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
              {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
              {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};



int score=0,exit1=0;
float x=0,y=0;
float x1=0,y1=1200,x2=200,x3=-200,y2=1500,y3=1000;
int learningmode=0;
int frams=0;


/*blast variable*/
int incrementblast=0;


/*jump variable*/
int initframs=0;
int diffrenceframes=0;
int jpkey=0;
float beforey;
/*jump variable*/


int carstate;
typedef struct lines
		{
	int x,y;
		}linet;
		linet line[5];
		void createline()
		{int i;
			for(i=0;i<5;i++)
			{
				line[i].x=0;
				line[i].y=i*250;
			}
		}









void jump()
{

       beforey=y;
       initframs=frams;
       y=y+2500;
       jpkey=1;
}












int findstate()
{

	int state;

if(y<1500)
{








if(x>-100&&x<100)
{


if(y>y1-260)
{


if(y1>y2&&y1<y3)
{
	state=7;
	return(state);
}
else if(y1>y3&&y1<y2)
{

	state=8;
	return(state);
}
else if(y1>y2&&y1>y3)
{
	state=11;
	return state;

}
else
{
state=4;
return(state);
}

}
else
{
state=1;
return(state);
}

}










if(x>100)
{
	
if(y>y2-260)

{   

   if (y1>y2&&y1<y2+300)
   {

     state=9;
     return(state);

   }

   else if(y1<y2)
   {

      state=12;
      return state;

   }


   else
   {
     state=5;
     return state;

   }


   }
 else{


 	state=2;
 	return state;
 }


}













if(x<-100)
{
		
if(y>y3-260)
{	

if(y1>y3&&y1<y3+300)
{
	state=10;
	return(state);
}
else if(y1<y3)
{
	state=13;
	return(state);
}
else
{
state=6;
return(state);
}

}
else
{
state=3;
return(state);
}

}








}





else
{

  state=14;
  return(state);

}







}





  




int bestactionfind(int state)
{

	int randonaction;
	int maxvalue=0;
	int bestaction;
	



   if(q[1][state]==q[2][state]&&q[2][state]==q[3][state]&&q[3][state]==q[4][state])
   {

     randonaction=rand()%5;

     if(randonaction==0)
     {
	    randonaction=1;
     }

     return(randonaction);
   }




 else{

    for(int i=1;i<=4;i++)
    {
       
      if(q[i][state]>maxvalue)
      {

         maxvalue=q[i][state];
         bestaction=i;

      }


    }


     return(bestaction);

 }


}


void fillq(int action,int state)
{

q[action][state]=r[action][state];

}



void performaction(int action)
{

if(action==1)
{

  x=x;
}


if(action==2)
{

  x=x+200;

}

if(action==3)
{

  x=x-200;

}

if(action==4)
{
	jump();
}


}













void enemy(float a,float b)
{


	glBegin(GL_QUADS);

	glColor3f(0,0,1);
	glVertex2f(-75+a,50+b);
	glVertex2f(-75+a,100+b);
	glVertex2f(75+a,100+b);
	glVertex2f(75+a,50+b);

	glColor3f(0,0,1);
	glVertex2f(-75+a,150+b);
	glVertex2f(-75+a,200+b);
	glVertex2f(75+a,200+b);
	glVertex2f(75+a,150+b);

	glColor3f(1,0,0);
	glVertex2f(-25+a,40+b);
	glVertex2f(-25+a,250+b);
	glVertex2f(25+a,250+b);
	glVertex2f(25+a,40+b);

	glEnd();
}

void sc(int a)
{
	int i,j,k;
	i=a/100;
	j=a/10-i*10;
	k=a-j*10-i*100;
	glPushMatrix();

	glColor3f(0.0,0.0,0.0);

	glTranslated(400,900,0);
	glScaled(0.5,0.5,0);
    	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'S');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'c');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'o');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'r');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'e');
	glColor3f(1.0,0.0,1.0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)':');
	glColor3f(0.0,0.0,0.0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)i+48);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)j+48);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)k+48);
	glPopMatrix();


    	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslated(400,800,0);
	glScaled(0.3,0.3,0);
    	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'>');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)' ');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'P');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'r');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'e');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'s');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'s');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)' ');
    	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'s');
    	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)' ');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'t');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'o');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)' ');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'S');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'t');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'a');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'r');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'t');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)' ');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'G');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'a');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'m');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'e');
	glPopMatrix();


glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslated(400,850,0);
	glScaled(0.3,0.3,0);
    	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'>');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)' ');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'P');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'r');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'e');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'s');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'s');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)' ');
    	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'q');
    	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)' ');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'t');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'o');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)' ');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'Q');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'u');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'i');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'t');
	glPopMatrix();



}







void showlearingmode_ON()
{
	
	
    glPushMatrix();
	glColor3f(0.0,0.0,1.0);
	glTranslated(-1000,900,0);
	glScaled(0.4,0.4,0);
    glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'L');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'E');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'A');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'R');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'N');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'I');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'N');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'G');
    glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'_');
    glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'M');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'O');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'D');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'E');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)':');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'O');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'N');
	glPopMatrix();




}



void showlearingmode_OFF()
{
	
	
    glPushMatrix();
	glColor3f(1.0,1.0,0.0);
	glTranslated(-1000,900,0);
	glScaled(0.4,0.4,0);
    glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'L');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'E');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'A');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'R');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'N');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'I');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'N');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'G');
    glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'_');
    glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'M');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'O');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'D');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'E');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)':');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'O');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'F');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'F');
	glPopMatrix();




}



void car(float a,float b)
{
	glBegin(GL_QUADS);

	glColor3f(0,0,1);
	glVertex2f(-75+a,50+b);
	glVertex2f(-75+a,100+b);
	glVertex2f(75+a,100+b);
	glVertex2f(75+a,50+b);

	glColor3f(0,0,1);
	glVertex2f(-75+a,150+b);
	glVertex2f(-75+a,200+b);
	glVertex2f(75+a,200+b);
	glVertex2f(75+a,150+b);

	glColor3f(1,1,0);
	glVertex2f(-25+a,40+b);
	glVertex2f(-25+a,250+b);
	glVertex2f(25+a,250+b);
	glVertex2f(25+a,40+b);
	glEnd();
}





void jumpcar(float a,float b)
{
	glBegin(GL_QUADS);

	glColor3f(0,0,1);
	glVertex2f(-125+a,100+b);
	glVertex2f(-125+a,150+b);
	glVertex2f(125+a,150+b);
	glVertex2f(125+a,100+b);

	glColor3f(0,0,1);
	glVertex2f(-125+a,200+b);
	glVertex2f(-125+a,250+b);
	glVertex2f(125+a,250+b);
	glVertex2f(125+a,200+b);

	glColor3f(1,1,0);
	glVertex2f(-75+a,90+b);
	glVertex2f(-75+a,300+b);
	glVertex2f(75+a,300+b);
	glVertex2f(75+a,90+b);
	glEnd();
}













void display()

{

 frams=frams+1;
 int i;
 int carstate;
 int caraction;

 
if(exit1==0)
{


	y1-=2;
	y2-=2;
	y3-=2;


	if(y1<-250)
	{
		score+=5;
	    y1=rand()%1500+500;
	}
	if(y2<-250)
	{
		score+=5;
		y2=rand()%1500+500;
	}
	if(y3<-250)
	{
		score+=5;
		y3=rand()%1500+500;
	}
	
    

	

	if(learningmode==1)
	{

      carstate=findstate();
      caraction=bestactionfind(carstate);
      performaction(caraction);
      fillq(caraction,carstate);

     }
      
  








       if(jpkey==1)
       {
       diffrenceframes=frams-initframs;
       if(diffrenceframes>300)
       {
         y=beforey;
         jpkey=0;
         initframs=0;
         diffrenceframes=0;
       }

       }


    



     
      


	if(x<-255||x>255)exit1=1;

	if(75+x>-80&&-75+x<80)
	if(250+y>60+y1&&250+y1>60+y)
		exit1=1;

	if(75+x>-260&&-75+x<-140)
	if(250+y>60+y3&&250+y3>60+y)
		exit1=1;

	if(75+x>140&&-75+x<260)
	if(250+y>60+y2&&250+y2>60+y)
		exit1=1;


	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();

	glColor3f(0.76,0.69,0.50);

    glBegin(GL_QUADS);
	glVertex2f(-300,0);
	glVertex2f(-300,2000);
	glVertex2f(-2000,2000);
	glVertex2f(-2000,0);

	glVertex2f(300,0);
	glVertex2f(300,2000);
	glVertex2f(2050,2050);
	glVertex2f(2000,0);
	glEnd();

     glPopMatrix();


	for(i=0;i<5;i++)
		{line[i].y+=-2;
if(line[i].y<-200)
{
	line[i].y+=1200;
}
		}
	for(i=0;i<5;i++)
	{



   /* road line */

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);

	glBegin(GL_POLYGON);
		glVertex2f(line[i].x,line[i].y+40);
		glVertex2f(line[i].x,line[i].y+190);
		glVertex2f(line[i].x+40,line[i].y+190);
		glVertex2f(line[i].x+40,line[i].y+40);
		glEnd();
	


     glPopMatrix();





	/* drawing tree*/

 
   glPushMatrix();


   glColor3f(0.0,1.0,0.0);

   glBegin(GL_TRIANGLES);
      glVertex2f(line[i].x-500,line[i].y);
      glVertex2f(line[i].x-600,line[i].y);
      glVertex2f(line[i].x-550,line[i].y+100);
   glEnd();





   glBegin(GL_TRIANGLES);
      glVertex2f(line[i].x-800,line[i].y+100);
      glVertex2f(line[i].x-900,line[i].y+100);
      glVertex2f(line[i].x-850,line[i].y+200);
   glEnd();





   glBegin(GL_TRIANGLES);
      glVertex2f(line[i].x+500,line[i].y+150);
      glVertex2f(line[i].x+600,line[i].y+150);
      glVertex2f(line[i].x+550,line[i].y+250);
   glEnd();




   glBegin(GL_TRIANGLES);
      glVertex2f(line[i].x+800,line[i].y+200);
      glVertex2f(line[i].x+900,line[i].y+200);
      glVertex2f(line[i].x+850,line[i].y+300);
   glEnd();


glPopMatrix();








glPushMatrix();
glColor3f(0.43,0.30,0.21);



   glBegin(GL_POLYGON);
      glVertex2f(line[i].x-560,line[i].y);
      glVertex2f(line[i].x-560,line[i].y-30);
      glVertex2f(line[i].x-540,line[i].y-30);
      glVertex2f(line[i].x-540,line[i].y);
   glEnd();







   glBegin(GL_POLYGON);
      glVertex2f(line[i].x-860,line[i].y+100);
      glVertex2f(line[i].x-860,line[i].y+70);
      glVertex2f(line[i].x-840,line[i].y+70);
      glVertex2f(line[i].x-840,line[i].y+100);
   glEnd();







   glBegin(GL_POLYGON);
      glVertex2f(line[i].x+560,line[i].y+150);
      glVertex2f(line[i].x+560,line[i].y+120);
      glVertex2f(line[i].x+540,line[i].y+120);
      glVertex2f(line[i].x+540,line[i].y+150);
   glEnd();





   glBegin(GL_POLYGON);
      glVertex2f(line[i].x+860,line[i].y+200);
      glVertex2f(line[i].x+860,line[i].y+170);
      glVertex2f(line[i].x+840,line[i].y+170);
      glVertex2f(line[i].x+840,line[i].y+200);
   glEnd();

glPopMatrix();


   }



    
    if(learningmode==1)
    {
    	showlearingmode_ON();

    }
    if(learningmode==0)
    {
      
      showlearingmode_OFF();
    }


    sc(score);
	car(x,y);
	enemy(x1,y1);
	enemy(x2,y2);
	enemy(x3,y3);


     if(jpkey==1)
    {
    	jumpcar(x,beforey);
    }




    glutSwapBuffers();


	}







	

	else
{
      
    incrementblast=incrementblast+3;

    if(incrementblast<100)

    {	
   
   glPushMatrix();

	glColor3f(1.0,0.65,0.0);

    glBegin(GL_POLYGON);
	glVertex2f(x-50-incrementblast,y+200+incrementblast);
	glVertex2f(x-500-incrementblast,y+300+incrementblast);
	glVertex2f(x-300-incrementblast,y+400+incrementblast);
	glVertex2f(x-400-incrementblast,y+450+incrementblast);

	glVertex2f(x+400+incrementblast,y+450+incrementblast);
	glVertex2f(x+300+incrementblast,y+400+incrementblast);
	glVertex2f(x+500+incrementblast,y+300+incrementblast);
	glVertex2f(x+50+incrementblast,y+200+incrementblast);
	glEnd();


glPopMatrix();

     



    glutSwapBuffers();


    }
 
    else


    {

    x1=0;y1=1000;x2=200;x3=-200;y2=1500;y3=2000;
    x=0;y=0;
    exit1=0;
    score=0;
    incrementblast=0;

   
	}

}



}











void keyboards(unsigned char keys,int keyboardx,int keyboardy)
{
	//to quit
    if(keys=='q')
	{
		  exit(-1);
	}


	//to start
	if(keys=='s')
    {
		glutIdleFunc(display);
    }




  	//movement keys
	if(keys=='4')
		x-=200;
	if(keys=='6')
		x+=200;
	if(keys=='5')
	{   
	  
       jump();
	  

	}

	glutPostRedisplay();





}

void mouse(int mousebutton,int mousestate,int mousex,int mousey)
{
   
if(mousebutton==GLUT_LEFT_BUTTON && mousestate==GLUT_DOWN)
{
  
  learningmode=1;
  printf("LEARNINGMODE IS ON\n");

}

 if(mousebutton==GLUT_RIGHT_BUTTON && mousestate==GLUT_DOWN)
{
  
  learningmode=0;
  printf("LEARNINGMODE IS OFF\n");

}



}











int main(int argc, char **argv)
{
  glutInit(&argc,argv);

  glutInitWindowSize(500,700);
  glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
  glutCreateWindow("Car Race");
  glClearColor(0.0,0.0,0.0,1);//set Background to black;
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboards);
  glutMouseFunc(mouse);

   createline();
   gluOrtho2D(-1000,1000,0,1000);


	 glutMainLoop();

  return 0;             /* ANSI C requires main to return int. */
}
