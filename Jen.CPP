//Header files below
#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<graphics.h>
#include<process.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
//Header files end here

//global function declarations
void display_start();
void tim();
void exp();
void die();

void main()
{
    clrscr();
     int gd=DETECT,gm,errorcode; //initialising the color graph
    initgraph ( &gd, &gm, "c:\\TURBOC3\\BGI" );

    display_start(); // displays the start-screen
    void jen(); //the actual input output section of the project
 closegraph();
}


void jen()
{
	clrscr();
    cleardevice();
    setbkcolor(MAGENTA); //sets the background colour
    textcolor(0);  //text colour is set to white(0)
    char usr_inp[1000];
    cout<<"YOU:";
    gets(usr_inp);  //your first input
    while(strcmpi(usr_inp,"bye")!=0)  //end condition
    {
	void reply(char []); //prototype
	cout<<"JEN:";
       //	if(test_var==1)
	reply(usr_inp); //the system replies
       //	else
       //	cout<<"Sorry I don't know the answer to that question"<<endl;
	cout<<"YOU:";
	gets(usr_inp); //your response thereafter
    }
    puts("JEN:It was nice talking to you!");// last line by jen
     getch();
}

//comparing keywords below
int count()
{
    ifstream fin;
    fin.open("q.txt",ios::in);
    int c=0;
    char ch[100];
    while(!fin.eof())
    {
	fin.getline(ch,100);
	c++;
    }
    fin.close();
    return c;
}


int string1(char[],char[]);
int string2(char str[],char s2[]);
int main_keywordcount(char inp[],char inp2[]) //inp is keyword inp2 usr_say
{

    int compare_result=string1(inp,inp2);
    return compare_result;
}
int string1(char s[],char other[])
{
    int main_count=0;
    char temp[25];
    strcpy(temp,NULL);
    int x=0,j=0;
    int len=strlen(s);
    for(int i=0; i<len; i++)
    {
	j=0;
	while(s[i]!=' '&&s[i]!='\0')
	{
	    temp[j++]=s[i++];
	}
	temp[j]='\0';
	x=string2(temp,other);
	if(x==1)
	{
	    main_count++;
	}
	strcpy(temp,NULL);
    }
    return main_count;
}
int string2(char str[],char s2[])
{
    int l1=strlen(str);
    char temp[100];
    int j=0,k;
    int l2=strlen(s2);
    for(int i=0; i<l2; i++)
    {
	j=i;
	k=0;
	while(k<l1)
	{
	    temp[k++]=s2[j++];
	}
	temp[k]='\0';
	if(strcmpi(temp,str)==0)
	    return 1;
    }
    return 0;
}
//comparing keywords end here


void reply(char usr_inp[1000]) //the system replies
{    int test_var=0;
    ifstream ques,ans;
    ques.open("q.txt",ios::in);
    ans.open("a.txt",ios::in);
    int c=0;
    char rep[1000];
    char key[100];
    int double_test=0;
    while(!ques.eof()) //finding the normal question (non-keyword)
    {
	ques.getline(rep,1000);
	if(strcmpi(usr_inp,rep)==0)
	{    double_test=1;
	    break;    }
	c++;
    }
    ques.close();
    int l=count();
    if(c>=l)//question not found, searching for keywords
    {
	ifstream fin;
	fin.open("q.txt",ios::in);
	c=-1;
	while(!fin.eof())
	{
	    c++;
	    char ext1[100];
	    fin.getline(ext1,100);
	    char key[3];
	    key[0]=ext1[0];
	    key[1]=ext1[1];
	    key[2]=ext1[2];

	    if(strcmp(key,"key")==0)
	    {
		int len=0;
		for(int j=0; ext1[j]!='\0'; j++)
		{
		    ext1[j]=ext1[j+3];
		    len++;
		}
		int cnt=main_keywordcount(ext1,usr_inp);
		int word=0;
		for(j=0; ext1[j]!='\0'; j++)
		    if(ext1[j]==' ')
			word++;
		word++;
		if(word==cnt)
		   {
		   test_var=1;
		   break;}
	    }
	}
    }
    if(test_var==1||double_test==1)
    {
    int k=0;
    while(k<=c) //getting the respective answer with 'c'
    {
	ans.getline(rep,1000);
	k++;
    }
    }
    else
    strcpy(rep,"Sorry, I don't know the answer to that :'(");
    ans.close();
    delay(50);
    void check(char []);
    check(rep);
}
void check(char rep[]) //checking for the individual macros
{
    if(strcmp(rep,"1")==0)
	tim();
    else if(strcmp(rep,"2")==0)
	exp();
    else if(strcmp(rep,"3")==0)
	die();
    else if(strcmp(rep,"4")==0)
      display_start();
    else
	puts(rep);
}

void die()
{

    char ch;
    randomize();
    cout<<"Do you want to roll the dice?\n";
    cin>>ch;
    while((ch=='Y')||(ch=='y'))
    {
	int x=random(6)+1;
	cout<<x<<endl;
	cout<<"Do you want to continue?\n";
	cin>>ch;
    }
}



void tim( )
{
    time_t now = time(0);
    char* dt = ctime(&now);
    cout << dt << endl;
}

void exp()
{
    int d[20],fres;
    char c[30],b[50];
    cout<<"Enter the expression\n";
    gets(c);
    int l=strlen(c),i=0,j=0,s=0;
    for(i=0; i<l; i++)
    {
	if(isdigit(c[i]))
	{
	    while(isdigit(c[i]))
	    {
		b[j++]=c[i++];
	    }
	    d[s++]=atoi(b);
	    j=0;
	    strcpy(b," ");
	}
	else
	{
	    j=0;
	    strcpy(b," ");
	}
    }
    int size=s;
    s=0;
    for(i=0; i<l; i++)
    {

	if((c[i]=='+')||(c[i]=='-'))
	    continue;
	if((c[i]=='/')||(c[i]=='*'))
	{
	    int x=d[s-1];
	    int y=d[s];
	    if(c[i]=='/')
		d[s-1]=x/y;
	    else
		d[s-1]=x*y;
	    for(int r=s; r<size; r++)
	    {
		d[r]=d[r+1];
	    }
	    size=size-1;
	    s=s-1;
	}
	else
	{
	    while(isdigit(c[i]))
		i++;
	    i=i-1;
	    s++;
	}
    }
    s=1;
    fres=d[0];
    for(i=0; i<l; i++)
    {
	if(c[i]=='+')
	{
	    fres=fres+d[s++];
	}
	else if(c[i]=='-')
	{
	    fres=fres-d[s++];
	}
    }
    cout<<fres<<endl;
}




void manual()
{
clrscr();
cleardevice();
    setbkcolor(MAGENTA);
    textcolor(0);
cout<<"\t \t \t USER MANUAL"<<endl;
cout<<endl<<endl<<endl<<endl;
cout<<" 1. TEACH ME -> This is the admin module. You can add questions and answers in this module."<<endl;
cout<<"To teach questions as key words, enter the 'key' followed by the keywords"<<endl;
cout<<"eg. 'keycoding fun', here 'coding' and 'fun' are two keywords"<<endl;
cout<<" 2. TALK TO ME -> This is the user module. You can talk to JEN in this module."<<endl;
cout<<"To go back to the main menu say 'go back'"<<endl;
cout<<" 3. USER MANUAL -> You are currently in this module. You can read all the instructions regarding JEN in this module."<<endl;
cout<<" 4. EXIT -> This module can be used to exit from the program."<<endl;
cout<<endl;
cout<<endl;
cout<<"Press any key to go back."<<endl;
getch();
display_start();
}
void teach_me() //the admin section
{
    cleardevice();
    char ques[1000], ans[1000];
    cout<<"What is the question you want me to teach?"<<endl;
    gets(ques);
    cout<<"And the answer to that question is..."<<endl;
    gets(ans);
    ofstream finq,fina;
    finq.open("Q.txt",ios::out|ios::nocreate|ios::app);
    fina.open("A.txt",ios::out|ios::nocreate|ios::app);
    finq<<'\n'<<ques;
    fina<<'\n'<<ans;
    finq.close();
    fina.close();
    cout<<"success!"<<endl;
    getch();
    display_start();
}
//displaying the start screen
void display_start()
{
clrscr();
    cleardevice();
    setcolor(YELLOW);
    setbkcolor(MAGENTA);
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
    outtextxy(250,100,"JEN");
    outtextxy(200,180,"1.TEACH ME");
    outtextxy(200,220,"2.TALK TO ME");
    outtextxy(200,260,"3.USER MANUAL");
    outtextxy(200,300,"4.EXIT");
    int ch;
    cin>>ch;
    switch(ch)
    {
    case 1:
	teach_me();
	break;
    case 2:
	jen();
	break;
    case 3:
	manual();
	break;
    case 4:
	exit(0);
	break;
    }

}
