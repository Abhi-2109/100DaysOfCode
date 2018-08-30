import java.io.*;
import java.util.Scanner;
import java.util.regex.*;
class strf
{
public static void main(String args[])
{
Scanner in=new Scanner(System.in);
String s=in.nextLine();
int l=s.length();
String s1="";
for(int i=0;i<l;i++)
{
	char ch=s.charAt(i);
	if(ch!='\0'&&ch!=' ')		//check for NULL and space
	{
	s1=".*?"+ch+".*?"; 		//regex to check a character preceded or succeeded by any number of characters
	Pattern p=Pattern.compile(s1);	//Using Pattern class
	Matcher m=p.matcher(s);		//using Matcher class
	int count=0;			//set count 0 for each character
		while(m.find())		//Using find() to check the occurances of pattern in sequence
		count++;
	String temp=""+ch;
	s=s.replaceAll(temp,"\0");	//set each same character occuring again to NULL
	System.out.print(ch+"-"+count+" ");
	}
}
}
}