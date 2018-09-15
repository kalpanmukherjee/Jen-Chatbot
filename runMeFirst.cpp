#include<fstream.h>
void main()
{
	ofstream f1,f2;
	f1.open("q.txt",ios::in);
	f2.open("a.txt",ios::in);
	f2<<"delete this and paste everything from a.txt";
	f1<<"delete this and paste everything from q.txt";
	f1.close();
	f2.close();
}