#include <stdio.h>
#define Max 500

int getline2(char output[]);
char string[Max];
int removeComments(char output[], int length);
int length;

int main()
{
    while ((length = getline2(string)) > 1)
    {
        removeComments(string, length);
        printf("%s\n",string );
    }
    return 0;
}

int getline2(char out[])
{
    int c, i;

    i = 0;

    while(((c = getchar())!= '|') && (c != EOF))
    {
        out[i] = c;
        i++;
    }

    out[i] = '\0'; 
    return i;
}

int removeComments(char str[],int len)
{
    int i = 0;

    for(i; i < len; i++)
    {
        //if in quotes, disregard

        if((str[i] == '"'))
        {   
            i++;

            while((str[i])!= '"')
            {


                if ((str[i] == '\\') && (str[i+1] == '"'))
                    {
                        i++;
                    }

                if ((str[i] == '\\') && (str[i+1] == '\\'))
                    {
                        i++;
                    }   

                i++;

            }
            i++;
        }

        //if \"
        if((str[i] == '\\') && (str[i+1] == '"'))
        {   
            i++;
            i++;
        }

        //if ', end at next '
        if((str[i] == '\''))
        {   
            i++;

            while(str[i] != '\'' )
            i++;
        }

        //if there is a single line comment, run the code until it reaches a new line
        if((str[i] == '/') && ((str[i+1]) == '/') && ((str[i+2]) != '/'))
        {
            while(str[i] != '\n')
            {
                str[i] = 'a';
                i++;
            }

        }

        
        //multiline comment case /* */
        if((str[i] == '/') && (str[i+1] == '*')) 
        {
            while(!((str[i] == '*') && (str[i+1] == '/')))
            {
                if (str[i] == '\n')
                {
                    i++;    
                }

                if(!((str[i] == '*') && (str[i+1] == '/')))
                {
                    str[i] = 'a';
                    i++;
                }
            }

            str[i] = 'a';
            str[i+1] = 'a';

        }


    }
}
