import java.io.*;
import java.util.Scanner;
import java.util.regex.*;
class rg
{
public static void main(String args[])
{
Scanner in=new  Scanner(System.in);
String pattern=in.nextLine(); 		//Pattern to be searched
String seq=in.nextLine();		//Sequence to have the string
Pattern p=Pattern.compile(pattern);	//compile() method called 
Matcher m=p.matcher(seq);
System.out.println("Enter choice");
System.out.println("1- Exact match\n2- Find");
int ch=in.nextInt();
boolean result=false;
switch(ch)
{
case 1: result=m.matches(); break;		//true if exact match else false
case 2: result=m.find(); break;			//finds the input pattern as any subsequence Note the empty () in find and matches
/* Each call to find picks up from from where the last left off*/
default: System.out.println("Wrong Choice");
}
System.out.println(result);
}
}

