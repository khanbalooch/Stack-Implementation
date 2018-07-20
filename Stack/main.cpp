#include "stack.h"

void in_to_post(string &in, string &out, Stack &s);
int prcd(char fst, char snd);
void rev(string &in, string &out);
/*==================================================================*/
int main()
{

	string infix, postfix, prefix, ftemp, stemp;

	cout << "Enter Expression:";
	getline(cin, infix);
	Stack s(infix.length());

	in_to_post(infix, postfix, s);
	rev(infix, ftemp);
	in_to_post(ftemp, stemp, s);
	rev(stemp, prefix);
	//Evaluate(postfix,s);
	cout << "Postfix string: " << postfix << endl;
	cout << "prefix string :" << prefix << endl;
	return 0;
}

/*==================================================================*/

void rev(string &in, string &out)
{
	int len = in.length() - 1;

	for (int i = len; i > -1; i--)
	{

		if (in[i] == ')')
		{
			out.append(1, '(');
		}
		else
		{
			if (in[i] == '(')
			{
				out.append(1, ')');
			}
			else
			{
				out.append(1, in[i]);
			}
		}
	}
}

/********************************************************/
int prcd(char fst, char snd)
{

	if (fst == '(')
	{
		return 0;
	}

	if (snd == '(')
	{
		if (fst == ')')
		{
			return 1;
		}
		else
			return 0;
	}

	if (snd == ')')
	{
		if (fst == '(')
		{
			return 0;
		}
		else
			return 1;
	}

	if (fst == '$' && snd == '$')
	{
		return 0;
	}

	if ((fst == '+' || fst == '-') && (snd == '+' || snd == '-'))
	{
		return 1;
	}

	if ((fst == '*' && snd == '*') || (fst == '/' && snd == '/'))
	{
		return 1;
	}

	if ((fst == '*') && (snd == '+' || snd == '-' || snd == '*'))
	{
		return 1;
	}

	if ((fst == '/') && (snd == '+' || snd == '-' || snd == '*' || snd == '/'))
	{
		return 1;
	}

	return 0;
}

/********************************************************/
void in_to_post(string &in, string &out, Stack &s)
{
	int len = in.length();
	char symb, topsymb;

	for (int i = 0; i < len; i++)
	{

		symb = in[i];

		if (isalnum(symb))
		{
			out.append(1, symb);
		}
		else
		{

			while (!s.isEmpty() && prcd(s.Top(), symb))
			{

				s.pop(topsymb);
				out.append(1, topsymb);
			}
			if (s.isEmpty() || symb != ')')
			{

				s.push(symb);
			}
			else

				s.pop(topsymb);
		}
	}

	while (!s.isEmpty())
	{
		s.pop(topsymb);
		out.append(1, topsymb);
	}
}

/********************************************************************/
/*int Evaluate(string &str,Stack &s ){

int len =str.length(),i=0;
char c,symb;
while (c!='\0') {
	symb = str[i];
	isalnum(symb){
		s.push( symb);
	else {
		
		opnd2 = s.pop();
		opnd1 = s.pop();
		value = 
		push(opndstk, value);*/
/*}  end else */
/*}  end while 
return (pop(opndstk));
}*/
/*==================================================*/
