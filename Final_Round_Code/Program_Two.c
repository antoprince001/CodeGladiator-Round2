  // Emoji for Emotion
  #include <stdio.h>
  #include <conio.h>
  #include <dos.h>
  #include <graphics.h>
  #include <stdlib.h>
  #include <string.h>

  /* To draw a smiley with face and smile  */
  void smiley(int midx, int midy, int radius) {

        /* FACE SECTION */
        setcolor(YELLOW);
        setfillstyle(SOLID_FILL, YELLOW);
        circle(midx, midy, radius);
        floodfill(midx, midy, YELLOW);

        /* EYE SECTION */
        setcolor(BLACK);
        setfillstyle(SOLID_FILL, BLACK);

        ellipse(midx - 40, midy - 40, 0, 360, 10, 25);
        floodfill(midx - 40, midy - 40, BLACK);

        ellipse(midx + 40, midy - 40, 0, 360, 10, 25);
        floodfill(midx + 40, midy - 40, BLACK);
        return;
  }


  int main() {
        
    /* Graphics driver auto detection */
	int gdriver = DETECT, gmode, err;
	int i, midx,x,y, midy, radius;

    char emotion[20]; // To store emotion of user

	/* Initialize graphic mode */
	initgraph(&gdriver, &gmode, "C:/TURBOC3/BGI");
	err = graphresult();

    /* To randomize emoji occurence on screen */
	randomize();

    /* Error validation for graphics driver */
	if (err != grOk) {
		
		printf("Graphics Error: %s\n",
				grapherrormsg(err));
		return 0;
	}

	/* Mid positions in x and y -axis */
	midx = getmaxx() / 2;
	midy = getmaxy() / 2;

    /* Radius of emoji */
	radius = 75;
    


    /* Infinite Loop */ 
	while(1)  {
    clrscr();	
    printf("Enter your emotion (happy,confused,sad,laughing,angry) or enter exit:");
    
	/* To get emotion as input from user */
	scanf("%s",emotion);
	/* Input taken until user enters 'exit' */

	/* Random value computed to randomize emoji occurence */
	x = rand()%100;
	y = rand()%100;


    //Conversion of emotion to lowercase for better validation
	 strlwr(emotion);

		/* Smiley 1 - Confused :| */
        if(strcmp(emotion,"confused")==0){
		 
            smiley(x, y, radius);
		    setlinestyle(SOLID_LINE, 1, 3);
		    line(x - 35, y + 35, x + 35, y + 35);
		    sleep(1);

            /* Clears graphic screen */
		    cleardevice();
        }

        /* Smiley 2 - Sad :( */
        else if(strcmp(emotion,"sad")==0){
            
            smiley(x+midx, y+midy, radius);
            setlinestyle(SOLID_LINE, 1, 3);
            arc(x+midx, y+midy + 50, 0, 180, 30);
            sleep(1);

            /* clears graphic screen */
            cleardevice();
        }

        /* Smiley 3 - Happy :) */
        else if(strcmp(emotion,"happy")==0){

            smiley(midx, midy, radius);
            setlinestyle(SOLID_LINE, 1, 3);
            arc(midx, midy + 20, 180, 360, 40);
            sleep(1);

            
            cleardevice();
        }
        /*  Smiley 4 - Laughing :D */
        else if(strcmp(emotion,"laughing")==0){
               
            smiley(x+midx, y+midy, radius);
            setlinestyle(LINE_FILL, 1, 2);
            setfillstyle(SOLID_FILL, BLACK);
            pieslice(x+midx, y+midy + 15, 180, 360, 35);
            setcolor(WHITE);
            setfillstyle(LINE_FILL, WHITE);
            pieslice(x+midx, y+midy + 15, 180, 360, 35);
            sleep(1);

            /* Clears graphic screen */
            cleardevice();
        }
        /* Smiley 5 - Angry  :O */
        else if(strcmp(emotion,"angry")==0){
            
            smiley(x+midx, y+midy, radius);
            setlinestyle(LINE_FILL, 1, 3);
            setfillstyle(SOLID_FILL, BLACK);
            pieslice(x+midx, y+midy + 50, 0, 180, 30);
            setcolor(WHITE);
            setfillstyle(LINE_FILL, WHITE);
            pieslice(x+midx, y+midy + 50, 0, 180, 30);
            sleep(1);

            /* Clears graphic screen */
            cleardevice();
        }
        /* Exit code handling */
        else if(strcmp(emotion,"exit")==0){
            closegraph();
            return 0;
        }
        /* Invalid emotion handling */
        else{
            printf("Invalid input");
        }
	}

	return 0;
  }
