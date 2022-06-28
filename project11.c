#include<windows.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h> // for clear screen
#include<conio.h> // for getch()
#include<math.h>
#include<time.h>
#include<ctype.h>

#define PIs 180
#define PI 3.14159265

//login code
struct web
{
char name[30],pass[30];
}w[99];

int n,z=0,Enter=0;
void entry(void);
void login(void);
void reg(void);
int passtry();

//declaration functions
int dictionary(void);
int calc();
int game();
int ttt();

int main()
{
    system("cls");
    system("color a");
    if(Enter==0)
    {
        entry();
    }
    int n;
    while(1)
    {
        printf("\n\t\t\t===========================================================");  
        printf("\n\n\t\t\t\t\tMenu :");
        printf("\n\n\t\t\t\t\t> 1.Calculator\n\t\t\t\t\t> 2.English Dictionary\n\t\t\t\t\t> 3.Games\n\t\t\t\t\t> 4.Exit");
        printf("\n\n\t\t\t===========================================================\n\n");
        printf("\n\n\t\t\tEnter Your Choice => ");
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            calc();
            break;
        case 2:
            dictionary();
            break;
        case 3:
            game();
            break;
        case 4:
            system("cls");
            printf("\n\n\n");
            printf("\n\t\t-----------------------------------------------------------------------");
            printf("\n\t\t\t          __ __      _   _    |          _                          ");
            printf("\n\t\t\t            |   |_| |_| | \\ | |/    \\ / | | | |                     ");
            printf("\n\t\t\t            |   | | | | |  \\| |\\_    |  |_| |_|                    ");
            printf("\n\t\t-----------------------------------------------------------------------");  
            getch();
            system("cls");
            exit(0);
        default:
            printf("\n\t\t---------------------------------------------------------------------");
            printf("\n\n\t\t\t\t\tEnter Valid Choice !");
            printf("\n\t\t---------------------------------------------------------------------");
            break;
        }
        printf(" <-Back ");
        getch();
        system("cls");
    }
}

//login code
void entry()
{
system("cls");
printf("\n\t\t\t===========================================================");
printf("\n\n\n\n\n\t\t\t\t! Welcom To My Multi-Feature System !\n");
printf("\n\n\n\n\t\t\tPress Enter to proceed...!!");
printf("\n\t\t\t===========================================================");
    getch();
    system("cls");
XY:
printf("\n\n\t\t====================================================================");
printf("\n\n\t\t\t1. LOGIN\t\t2. REGISTER\t\t3. EXIT");
printf("\n\n\t\t====================================================================");
printf("\n\n\t\t\t\tENTER YOUR CHOICE: ");
scanf("%d",&n);
switch(n)
  {
    case 1: 
        system("cls");
        login();
        break;
    case 2: 
        system("cls");
        reg();
        break;
    case 3:
        system("cls");
        printf("\n\n\n");
        printf("\n\t\t-----------------------------------------------------------------------");            printf("\n\t\t\t          __ __      _   _    |          _                          ");
        printf("\n\t\t\t            |   |_| |_| | \\ | |/    \\ / | | | |                     ");
        printf("\n\t\t\t            |   | | | | |  \\| |\\_    |  |_| |_|                    ");
        printf("\n\t\t-----------------------------------------------------------------------");  
        exit(0);
    default: 
        printf("\n\n\t\t====================================================================");
        printf("\n\n\t\t\t\tNO MATCH FOUND");
        printf("\n\n\t\t\tPress Enter to re-Enter the choice");
        printf("\n\n\t\t====================================================================");
        getch();
        system("cls");
        goto XY;
  }

  exit(0);
  return ;

}

void login()
{
    system("cls");
    FILE *fp;
        char filename[]="l.txt";
        char line[10000];
        char name[200],pass[200];
        char i[]=":",c;
        int cnt=0,z=0;


        printf("\n\t\t---------------------------------------------------------------------");
        printf("\n\t\t\t                 __   __  _ _  _                 ");
        printf("\n\t\t\t            |   |  | |     |  | \\  |             ");
        printf("\n\t\t\t            |   |  | |  _  |  |  \\ |             ");
        printf("\n\t\t\t            |__ |__| |__| _|_ |   \\|             ");
        printf("\n\t\t---------------------------------------------------------------------");
        printf("\n\n\t\t\t\t  ENTER USERNAME: ");
        scanf("%s",&name);
        printf("\n\n\t\t\t\t  ENTER PASSWORD: ");
        while((c=getch())!=13)
        {
          pass[z++]=c;
          printf("%c",'*');
        }
        pass[z]='\0';

        int q=strlen(pass);

        strcat(name,i);

        fp=fopen(filename,"r");


        if(!fp)
        {
                perror("could not find the file");
                 
        }
        
        int t=0,r=0;
        char a;

        while ((a=fgetc(fp))!=EOF)
        {
            if(name[r]==a)
            {
                t++;
                r++;
                if(t==strlen(name))
                {
                    t=0;
                    r=0;
                    while((a=fgetc(fp))!=EOF)
                    {
                        if(a!='\n')
                        {
                            if(pass[r]==a)
                            {
                                            
                                t++;
                                r++;
                                if(t==strlen(pass))
                                {
                                    system("cls");
                                    printf("\n\n\n\t\t\t===========================================================");
                                    printf("\n\n\t\t\t\t\t  Successfully Logged !\n");
                                    printf("\n\t\t\t===========================================================");
                                    fclose(fp);
                                    getch();
                                    Enter=1;
                                    main();
                                }
                            }
                        }
                    }
                    system("cls");
                    printf("\n\t\t\t===========================================================");  
                    printf("\n\n\t\t\t\t\tPassword Is Wrong ,Re-enter!");
                    printf("\n\n\t\t\t===========================================================");                
                    cnt++;
                    getch();
                    passtry(name);
                }
                                
            }
        }
                        
                        
                        
                    
                
          
        if(cnt==0)
        {   
            system("cls");
            printf("\n\t\t\t===========================================================");  
            printf("\n\n\t\t\t\t\tUserName doesn't Exits!!");
            printf("\n\n\t\t\t==========================================================="); 
            getch();
            fclose ( fp );
            system("cls");
            printf("\n\t\t\t===========================================================");  
            printf("\n\n\t\t\t\t\tDo You Want to register?");
            printf("\n\n\t\t\t\t\t> PRESS 1 FOR YES\n\t\t\t\t\t> PRESS 2 FOR NO");
            printf("\n\n\t\t\t===========================================================\n\n");
            printf("\n\n\t\t\t\t\t=> ");
            scanf("%d",&z);
            switch(z)
            {
              case 1: system("cls");
                    reg();
                    break;
              case 2: system("cls");
                    printf("\n\n\n");
                    printf("\n\t\t-----------------------------------------------------------------------");
                    printf("\n\t\t\t          __ __      _   _    |          _                          ");
                    printf("\n\t\t\t            |   |_| |_| | \\ | |/    \\ / | | | |                     ");
                    printf("\n\t\t\t            |   | | | | |  \\| |\\_    |  |_| |_|                    ");
                    printf("\n\n\n\n\t\t\tPress Enter to EXIT...!!");
                    printf("\n\t\t-----------------------------------------------------------------------");  
                    getch();
                    exit(0);
            }

            
        }

        return; 
}


int passtry(char *name)
{
    FILE *fp;
        char filename[]="l.txt";
        char line[10000];
        char pass[200];
        char c;
        int cnt=0,z=0;
        system("cls");
        printf("\n\t\t---------------------------------------------------------------------");
        printf("\n\t\t\t                 __   __  _ _  _                 ");
        printf("\n\t\t\t            |   |  | |     |  | \\  |             ");
        printf("\n\t\t\t            |   |  | |  _  |  |  \\ |             ");
        printf("\n\t\t\t            |__ |__| |__| _|_ |   \\|             ");
        printf("\n\t\t---------------------------------------------------------------------");
        printf("\n\n\t\t\t\t  ENTER USERNAME: %s",name);
        printf("\n\n\t\t\t\t  ENTER PASSWORD: ");
        while((c=getch())!=13)
        {
          pass[z++]=c;
          printf("%c",'*');
        }
        pass[z]='\0';

        fp=fopen(filename,"r");


        if(!fp)
        {
                perror("could not find the file");
                 
        }
        
        int t=0,r=0;
        char a;

        while ((a=fgetc(fp))!=EOF)
        {
            if(name[r]==a)
            {
                t++;
                r++;
                if(t==strlen(name))
                {
                    t=0;
                    r=0;
                    while((a=fgetc(fp))!=EOF)
                    {
                        if(a!='\n')
                        {
                            if(pass[r]==a)
                            {
                                            
                                t++;
                                r++;
                                if(t==strlen(pass))
                                {
                                    system("cls");
                                    printf("\n\n\n\t\t\t===========================================================");
                                    printf("\n\n\t\t\t\t\t  Successfully Logged !\n");
                                    printf("\n\t\t\t===========================================================");
                                    fclose(fp);
                                    getch();
                                    Enter=1;
                                    main();
                                }
                            }
                        }
                    }
                    system("cls");
                    printf("\n\t\t\t===========================================================");  
                    printf("\n\n\t\t\t\t\tPassword Is Wrong ,Re-enter!");
                    printf("\n\n\t\t\t===========================================================");                
                    cnt++;
                    getch();
                    passtry(name);
                }
                                
            }
        }
        return 0;
}

  void reg()
  {
     system("cls");
        char filename[]="l.txt";
        char line[10000];
        char pass[30];

    FILE *fp;
    int i=0,n;
    char c,checker[30]; int z=0;
    char cl[]=":";

    fp=fopen(filename,"ab+");
    
    printf("\n\t\t---------------------------------------------------------------------");
    printf("\n\n\t\t\t\t\tWELCOME TO REGISTER ZONE\n");
    printf("\n\t\t---------------------------------------------------------------------");

    for(i=0;i<100;i++)
    {
      printf("\n\n\t\t\t\t  ENTER USERNAME: ");
      scanf("%s",checker);
      strcat(checker,cl);
      while ( fgets ( line, 10000, fp ) != NULL ) // read a line 
      {
                if(strstr(line,checker))
                {
                    system("cls");
                    printf("\n\t\t\t===============================================================\n\n");    
                    printf("\t\t\t\t\t       UserName Already Exits!\n");
                    printf("\n\t\t\t===============================================================");  
                    getch();
                    system("cls");
                    reg();
                }
                
      }
      printf("\n\n\t\t\t\t  DESIRED PASSWORD: ");
      while((c=getch())!=13)
        {
          pass[z++]=c;
          printf("%c",'*');
        }
        pass[z]='\0';
      strcat(checker,pass);
      fprintf(fp,"\n");
      fprintf(fp,checker);
      getch();
      fclose(fp);
      system("cls");
        printf("\n\t\t\t===========================================================");  
        printf("\n\n\t\t\t\t\tYou are successfully registered");
        printf("\n\n\t\t\t\t\tTry login your account??");
        printf("\n\n\t\t\t\t\t> PRESS 1 FOR YES\n\t\t\t\t\t> PRESS 2 FOR NO");
        printf("\n\n\t\t\t===========================================================\n\n");
        printf("\n\n\t\t\t\t\t=> ");
        scanf("%d",&n);
        
        switch(n)
          {
              case 1: system("cls");
                    login();
                    break;
              case 2: system("cls");
                    printf("\n\n\n");
                    printf("\n\t\t-----------------------------------------------------------------------");
                    printf("\n\t\t\t          __ __      _   _    |          _                          ");
                    printf("\n\t\t\t            |   |_| |_| | \\ | |/    \\ / | | | |                     ");
                    printf("\n\t\t\t            |   | | | | |  \\| |\\_    |  |_| |_|                    ");
                    printf("\n\n\n\n\t\t\tPress Enter to EXIT...!!");
                    printf("\n\t\t-----------------------------------------------------------------------");  
                    getch();
                    exit(0);
          }
      
    }
  }







//Dictionary feature code 

int dictionary()
{
    system("cls");
    FILE *fp;
        char filename[]="fulldictionary.txt";
        char line[10000];
        char search_string[200];
        char i[]=" :";
        int cnt=0;



        printf("\n\t\t\t===========================================================");  
        printf("\n\n\t\t\t\t\tEnter Word To find Meaning !");
        printf("\n\n\t\t\t===========================================================\n\n");
        printf("\n\n\t\t\t\t\t=> ");
        scanf("%s",&search_string);


        strupr(search_string);

        if(strlen(search_string)>1)
        {
            for(int i=1;i<strlen(search_string);i++)
            {
                char a=search_string[i];
                search_string[i]=tolower(a);
            }
        }


        strcat(search_string,i);


        fp=fopen(filename,"r");


        if(!fp)
        {
                perror("could not find the file");
                 
        }
        while ( fgets ( line, 10000, fp ) != NULL ) /* read a line */
        {
                if(strstr(line,search_string))
                {
                    printf("\n------------------------------------------------------------------------------------------------------------------------\n\n  Meaning Of ");    
                    fputs ( line, stdout ); /* write the line */ 
                    printf("\n------------------------------------------------------------------------------------------------------------------------");
                    cnt++;
                }
                
        }   

        
        if(cnt==0)
        {     
            printf("\n\t\t---------------------------------------------------------------------");
            printf("\n\n\t\t\t    Word May be mispelled Or it doesn't Exits!!");
            printf("\n\t\t---------------------------------------------------------------------");
            fclose ( fp );
        }
        printf("\n\n\n");
        fclose(fp);

        return 0; 
}


//Calculator Feature Code

void simple_scientific_calculator();
void birth_calculator();
void currency();
void energy();
void length();
void mass();
void matrix_addition();
void matrix_determind();
void matrix_devided();
void matrix_multiply();
void matrix_substraction();
void simple_calculator();
void speed();
void temperature();
void timec();
void trigonometric_function();
void sine();
void cosine();
void tangent();
void clear();
void delay(int mseconds);



void clear()
{
    system("PAUSE");
    system("CLS");
}

void delay(int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
int calc()
{
    system("cls");
    printf("\n\t\t\t===========================================================");  
    printf("\n\n\t\t\t\t\tCalculator Menu :");
    printf("\n\n\t\t\t\t\t> 1.Simple Calculator\n\t\t\t\t\t> 2.Scientific Calculator\n\t\t\t\t\t> 3.Converter Calculator\n\t\t\t\t\t> 4.back to Main Menu\n\t\t\t\t\t> 5.Exit the Program");
    printf("\n\n\t\t\t===========================================================\n\n");
    printf("\n\n\t\t\tEnter Your Choice => ");

    int n;
    int s_number;
    int c_number;
    scanf("%d", &n);
    system("cls");
    while(n > 0 && n <= 5){
        switch(n){
            case 1:
                simple_calculator();
                clear();
                break;
            case 2:
                printf("\n\t\t\t===========================================================");  
                printf("\n\n\t\t\t\t\tScientific Calculator Menu :");
                printf("\n\n\t\t\t\t\t> 1.Simple Calculator\n\t\t\t\t\t> 2.Trigonometric Function\n\t\t\t\t\t> 3.Matrix Addition\n\t\t\t\t\t> 4.Matrix Subtraction\n\t\t\t\t\t> 5.Matrix Multiply\n\t\t\t\t\t> 6.back To Calculator Menu\n\t\t\t\t\t> 7.Exit the Program");
                printf("\n\n\t\t\t===========================================================\n\n");
                printf("\n\n\t\t\tEnter Your Choice => ");
                scanf("%d", &s_number);
                while(s_number > 0 && s_number <= 8){
                    switch(s_number){
                        case 1:
                            simple_scientific_calculator();
                            clear();
                            break;
                        case 2:
                            system("cls");
                            trigonometric_function();
                            clear();
                            break;
                        case 3:
                            matrix_addition();
                            clear();
                            break;
                        case 4:
                            matrix_substraction();
                            clear();
                            break;
                        case 5:
                            matrix_multiply();
                            clear();
                            break;
                        case 6:
                            calc();
                            clear();
                            break;
                        case 7:
                            exit(0);
                            break;
                        default:
                            break;
                    }
                    printf("\n\t\t\t===========================================================");  
                    printf("\n\n\t\t\t\t\tScientific Calculator Menu :");
                    printf("\n\n\t\t\t\t\t> 1.Simple Calculator\n\t\t\t\t\t> 2.Trigonometric Function\n\t\t\t\t\t> 3.Matrix Addition\n\t\t\t\t\t> 4.Matrix Subtraction\n\t\t\t\t\t> 5.Matrix Multiply\n\t\t\t\t\t> 6.back To Calculator Menu\n\t\t\t\t\t> 7.Exit the Program");
                    printf("\n\n\t\t\t===========================================================\n\n");
                    printf("\n\n\t\t\tEnter Your Choice => ");
                    scanf("%d", &s_number);
                }
            case 3:
                printf("\n\t\t\t===========================================================");  
                printf("\n\n\t\t\t\t\tConverter Calculator Menu :");
                printf("\n\n\t\t\t\t\t> 1.Convert Length");
                printf("\n\t\t\t\t\t> 2.Convert Mass");
                printf("\n\t\t\t\t\t> 3.Convert Temperature");
                printf("\n\t\t\t\t\t> 4.Convert Speed");
                printf("\n\t\t\t\t\t> 5.Convert Time");
                printf("\n\t\t\t\t\t> 6.Convert Currency");
                printf("\n\t\t\t\t\t> 7.Convert Energy");
                printf("\n\t\t\t\t\t> 8.back To Calculator Menu");
                printf("\n\t\t\t\t\t> 9.Exit the Program");
                printf("\n\n\t\t\t===========================================================\n\n");
                printf("\n\n\t\t\tEnter Your Choice => ");
                scanf("%d", &c_number);
                while(c_number > 0 && c_number <= 10){
                    switch(c_number){
                        case 1:
                            length();
                            clear();
                            break;
                        case 2:
                            mass();
                            clear();
                            break;
                        case 3:
                            temperature();
                            clear();
                            break;
                        case 4:
                            speed();
                            clear();
                            break;
                        case 5:
                            timec();
                            clear();
                            break;
                        case 6:
                            currency();
                            clear();
                            break;
                        case 7:
                            energy();
                            clear();
                            break;
                        case 8:
                            calc();
                            clear();
                            break;
                        case 9:
                            exit(0);
                            break;
                        default:
                            break;
                    }
                    printf("\n\t\t\t===========================================================");  
                    printf("\n\n\t\t\t\t\tConverter Calculator Menu :");
                    printf("\n\n\t\t\t\t\t> 1.Convert Length");
                    printf("\n\t\t\t\t\t> 2.Convert Mass");
                    printf("\n\t\t\t\t\t> 3.Convert Temperature");
                    printf("\n\t\t\t\t\t> 4.Convert Speed");
                    printf("\n\t\t\t\t\t> 5.Convert Time");
                    printf("\n\t\t\t\t\t> 6.Convert Currency");
                    printf("\n\t\t\t\t\t> 7.Convert Energy");
                    printf("\n\t\t\t\t\t> 8.back To Calculator Menu");
                    printf("\n\t\t\t\t\t> 9.Exit the Program");
                    printf("\n\n\t\t\t===========================================================\n\n");
                    printf("\n\n\t\t\tEnter Your Choice => ");
                    scanf("%d", &c_number);
                    system("cls");
                }
            case 4:
                main();
                break;
            case 5:
                exit(0);
                break;
            default :
                break;
        }
        
    printf("\n\t\t\t===========================================================");  
    printf("\n\n\t\t\t\t\tCalculator Menu :");
    printf("\n\n\t\t\t\t\t> 1.Simple Calculator\n\t\t\t\t\t> 2.Scientific Calculator\n\t\t\t\t\t> 3.Converter Calculator\n\t\t\t\t\t> 4.back to Main Menu\n\t\t\t\t\t> 5.Exit the Program");
    printf("\n\n\t\t\t===========================================================\n\n");
    printf("\n\n\t\t\tEnter Your Choice => ");
    scanf("%d", &n);
    system("cls");
    }

    return 0;
}


void simple_calculator()
{
     printf("\n\t\t\t===========================================================");  
    printf("\n\n\t\t\t\t\tSimple Calculator Menu :");               
    printf("\n\n\t\t\t\t\t> 1.Calculate Addition");
    printf("\n\t\t\t\t\t> 2.Calculate Subtraction");
    printf("\n\t\t\t\t\t> 3.Calculate Multiply");
    printf("\n\t\t\t\t\t> 4.Calculate Divided");
    printf("\n\t\t\t\t\t> 5.Calculate Power");
    printf("\n\t\t\t\t\t> 6.Calculate Root");
    printf("\n\t\t\t\t\t> 7.Going To Menu");
    printf("\n\t\t\t\t\t> 8.Exit");
    printf("\n\n\t\t\t===========================================================\n\n");
    printf("\n\n\t\t\tEnter Your Choice => ");int simple_number;
    int a, b, result;
    double number,num, p;
    scanf("%d", &simple_number);
    while(simple_number > 0 && simple_number < 9){
        switch(simple_number){
            case 1:
                printf("\nEnter the first value  : ");
                scanf("%d", &a);
                printf("Enter the Second value : ");
                scanf("%d", &b);
                result = a + b;
                printf("Addition = %d\n\n", result);
                clear();
                break;
            case 2:
                printf("\nEnter the first value  : ");
                scanf("%d", &a);
                printf("Enter the Second value : ");
                scanf("%d", &b);
                result = a - b;
                printf("Subtraction = %d\n\n", result);
                clear();
                break;
            case 3:
                printf("\nEnter the first value  : ");
                scanf("%d", &a);
                printf("Enter the Second value : ");
                scanf("%d", &b);
                result = a * b;
                printf("Multiply = %d\n\n", result);
                clear();
                break;
            case 4:
                printf("\nEnter the first value  : ");
                scanf("%d", &a);
                printf("Enter the Second value : ");
                scanf("%d", &b);
                float result = (float) a / (float) b;
                printf("Divided = %.2f\n\n", result);
                clear();
                break;
            case 5:
                printf("\nEnter The numbers and Power\n");
                printf("Enter The Number : ");
                scanf("%lf",&number);
                printf("Enter The Power : ");
                scanf("%lf",&num);
                p = pow(number, num);
                printf("Result = %.2lf\n\n", p);
                clear();
                break;
            case 6:
                printf("\nTo Root Enter The number\n");
                printf("Enter The Number : ");
                scanf("%lf",&number);
                p = sqrt(number);
                printf("Result = %.2lf\n\n", p);
                clear();
                break;
            case 7:
                calc();
                clear();
                break;
            case 8:
                exit(0);
                break;
            default:
                break;
        }
     printf("\n\t\t\t===========================================================");  
    printf("\n\n\t\t\t\t\tSimple Calculator Menu :");               
    printf("\n\n\t\t\t\t\t> 1.Calculate Addition");
    printf("\n\t\t\t\t\t> 2.Calculate Subtraction");
    printf("\n\t\t\t\t\t> 3.Calculate Multiply");
    printf("\n\t\t\t\t\t> 4.Calculate Divided");
    printf("\n\t\t\t\t\t> 5.Calculate Power");
    printf("\n\t\t\t\t\t> 6.Calculate Root");
    printf("\n\t\t\t\t\t> 7.Going To Menu");
    printf("\n\t\t\t\t\t> 8.Exit");
    printf("\n\n\t\t\t===========================================================\n\n");
    printf("\n\n\t\t\tEnter Your Choice => ");
    scanf("%d", &simple_number);
    }
    return;
}


void simple_scientific_calculator(){
    float a, b;
    float result;
    int count = 0;
    char check;
    printf("\nInter the value and calculate : ");
    scanf("%f %c %f", &a, &check, &b);
    if(check == '+'){
            result = a + b;
    }
    else if(check == '-'){
            result = a - b;
    }
    else if(check == '*'){
            result = a * b;
    }
    else if(check == '/'){
            result = a / b;
            count++;
    }
    else if(check == '^'){
            result = pow(a , b);
    }

    scanf("%c", &check);
    float c;
    while(check != '+' && check != '-' && check != '*' && check != '/' && check != '\n'){
        scanf("%c", &check);
        scanf("%f", &c);
        if(check == '+'){
            result = result + c;
        }
        else if(check == '-'){
            result = result - c;
        }
        else if(check == '*'){
            result = result * c;
        }
        else if(check == '/'){
            result =  result / c;
            count++;
        }
        scanf("%c", &check);
        }

    if(count != 0){
        printf("Result = %.2f\n\n", result);
    }
    else{
        printf("Result = %.0f\n\n", result);
    }

    return;
}


void trigonometric_function(){
    int trigonometric_number;
     printf("\n\t\t\t===========================================================");  
    printf("\n\n\t\t\t\t\tTrigonometric Calculator Menu :");               
    printf("\n\n\t\t\t\t\t> 1.Find the value of sine");
    printf("\n\t\t\t\t\t> 2.Find the value of cos");
    printf("\n\t\t\t\t\t> 3.Find the value of tan");
    printf("\n\t\t\t\t\t> 4.Going To Menu");
    printf("\n\t\t\t\t\t> 5.Exit");
    printf("\n\n\t\t\t===========================================================\n\n");
    printf("\n\n\t\t\tEnter Your Choice => ");
    scanf("%d", &trigonometric_number);
    while(trigonometric_number >= 1 && trigonometric_number <= 4){
        switch(trigonometric_number){
            case 1:
                sine();
                clear();
                break;
            case 2:
                cosine();
                clear();
                break;
            case 3:
                tangent();
                clear();
                break;
            case 4:
                calc();
                break;
                clear();
            case 5:
                exit(0);
                break;
            default:
                break;
        }
          printf("\n\t\t\t===========================================================");  
        printf("\n\n\t\t\t\t\tTrigonometric Calculator Menu :");               
        printf("\n\n\t\t\t\t\t> 1.Find the value of sine");
        printf("\n\t\t\t\t\t> 2.Find the value of cos");
        printf("\n\t\t\t\t\t> 3.Find the value of tan");
        printf("\n\t\t\t\t\t> 4.Going To Menu");
        printf("\n\t\t\t\t\t> 5.Exit");
        printf("\n\n\t\t\t===========================================================\n\n");
        printf("\n\n\t\t\tEnter Your Choice => ");
        scanf("%d", &trigonometric_number);
    }
}
void sine(){
    system("cls");
    int k;
    double input, output;
      printf("\n\t\t\t=========================================================="); 
    printf("\n\t\t\tDo You Want Input Value in Radian Or Degre?\n\t\t\t> 1.Radian\n\t\t\t> 2.Degree");
    printf("\n\t\t\t             __");
    printf("\n\t\t\t> 3.Input in || Format    ");
      printf("\n\n\t\t\t==========================================================="); 
    printf("\n\n\t\t\tEnter Your Choice => ");
    scanf("%d", &k);
    system("cls");
    if(k==3)
    {
        printf("\n\n\t\t          __\n");
        printf("\t\tNOTE::USE || =pi Instead ");
    char a[200];
    char b[]={'0','1','2','3','4','5','6','7','8','9'};
    char p;
    double val=0.0;
    int cnt=0;
    printf("\n\n\t\t\tEnter Value :");
    scanf("%s",&a);
    strlwr(a);

    int k1=0;
    while(a[k1]!='p')
    {
        for(int j=0;j<10;j++)
        {
            if(a[k1]==b[j])
            {
                cnt=1;
                val=(val*10)+j;
            }
        }
        k1++;
    }

    if(cnt!=1)
    {
        val=1.0;
    }

    for(int i=0;i<strlen(a);i++)
    {
        if(a[i]=='p' && a[i+1]=='i')
        {
            val=val*PIs;
        }
    }

    for(int i=0;i<strlen(a);i++)
    {
        if(a[i]=='/')
        {
            for(int j=1;j<10;j++)
            {
                if(a[i+1]==b[j])
                {
                    val=val/j;
                }
            }
        }
    }


        double input=val, output;
        double pi = 3.14159;
        input=input * (180/pi);
        output = sin(input*PI/180);
        printf ("\n\t\t\tIn Radian sin : %.3lf\n\n\n\n", output );
        output = sin(val*PI/180);
        printf ("\n\t\t\tIn Degree sin :%.3lf\n\n\n\n", output );
    
        return;
    }
    if(k==1)
    { 
        printf("\n\n\n\t\t\tEnter the Radian Value for sin : ");
        scanf("%lf", &input);
        double pi = 3.14159;
        input=input * (180/pi);
        output = sin(input*PI/180);
        printf ("\n\t\t\tsin : %.3lf\n\n\n\n", output );

    }
    else
    {
        printf("\n\n\n\t\t\tEnter the value of sin : ");
        scanf("%lf", &input);
        output = sin(input*PI/180);
        printf ("\n\t\t\tsin of %.0lf Degree is %.3lf\n\n\n\n", input, output );
        return;
    }
}
void cosine(){
    system("cls");
    int k;
    double input, output;
    printf("\n\t\t\t==========================================================="); 
    printf("\n\t\t\tDo You Want Input Value in Radian Or Degre?\n\t\t\t> 1.Radian\n\t\t\t> 2.Degree");
    printf("\n\t\t\t             __");
    printf("\n\t\t\t> 3.Input in || Format    ");
    printf("\n\n\t\t\t==========================================================="); 
    printf("\n\n\t\t\tEnter Your Choice => ");
    scanf("%d", &k);
    system("cls");
    if(k==3)
    {
    printf("\n\n\t\t          __\n");
    printf("\t\tNOTE::USE || =pi Instead ");
    char a[200];
    char b[]={'0','1','2','3','4','5','6','7','8','9'};
    char p;
    double val=0.0;
    int cnt=0;
    printf("\n\n\t\t\t Enter Value :");
    scanf("%s",&a);
    strlwr(a);

    int k1=0;
    while(a[k1]!='p')
    {
        for(int j=0;j<10;j++)
        {
            if(a[k1]==b[j])
            {
                cnt=1;
                val=(val*10)+j;
            }
        }
        k1++;
    }

    if(cnt!=1)
    {
        val=1.0;
    }

    for(int i=0;i<strlen(a);i++)
    {
        if(a[i]=='p' && a[i+1]=='i')
        {
            val=val*PIs;
        }
    }

    for(int i=0;i<strlen(a);i++)
    {
        if(a[i]=='/')
        {
            for(int j=1;j<10;j++)
            {
                if(a[i+1]==b[j])
                {
                    val=val/j;
                }
            }
        }
    }


        double input=val, output;
        double pi = 3.14159;
        input=input * (180/pi);
        output = cos(input*PI/180);
        printf ("\n\t\t\tIn Radian  cos : %.3lf\n\n\n\n", output );
        output = cos(val*PI/180);
        printf ("\n\t\t\tIn Degree  cos :%.3lf\n\n\n\n", output );
    
    return ;
    }
    if(k==1)
    { 
        printf("\n\n\t\t\tEnter the Radian Value for cos : ");
        scanf("%lf", &input);
        double pi = 3.14159;
        input=input * (180/pi);
        output = cos(input*PI/180);
        printf ("\n\t\t\tcos : %.3lf\n\n\n\n", output );

    }
    else
    {
        printf("\n\n\t\t\tEnter the value of cos : ");
        scanf("%lf", &input);
        output = cos(input*PI/180);
        printf ("\n\t\t\tcos of %.0lf Degree is %.3lf\n\n\n\n", input, output );
        return;
    }
}
void tangent(){
    system("cls");
    int k;
    double input, output;
    printf("\n\t\t\t==========================================================="); 
    printf("\n\t\t\tDo You Want Input Value in Radian Or Degre?\n\t\t\t> 1.Radian\n\t\t\t> 2.Degree");
    printf("\n\t\t\t             __");
    printf("\n\t\t\t> 3.Input in || Format    ");
    printf("\n\n\t\t\t==========================================================="); 
    printf("\n\n\t\t\tEnter Your Choice => ");
    scanf("%d", &k);
    system("cls");
    if(k==3)
{
  printf("\n\n\t\t          __");
    printf("\n\t\tNOTE::USE || =pi Instead ");
    char a[200];
    char b[]={'0','1','2','3','4','5','6','7','8','9'};
    char p;
    double val=0.0;
    int cnt=0;
    printf("\n\n\t\t\tEnter Value :");
    scanf("%s",&a);
    strlwr(a);

    int k1=0;
    while(a[k1]!='p')
    {
        for(int j=0;j<10;j++)
        {
            if(a[k1]==b[j])
            {
                cnt=1;
                val=(val*10)+j;
            }
        }
        k1++;
    }

    if(cnt!=1)
    {
        val=1.0;
    }

    for(int i=0;i<strlen(a);i++)
    {
        if(a[i]=='p' && a[i+1]=='i')
        {
            val=val*PIs;
        }
    }

    for(int i=0;i<strlen(a);i++)
    {
        if(a[i]=='/')
        {
            for(int j=1;j<10;j++)
            {
                if(a[i+1]==b[j])
                {
                    val=val/j;
                }
            }
        }
    }


        double input=val, output;
        double pi = 3.14159;
        input=input * (180/pi);
        output = tan(input*PI/180);
        printf ("\n\t\t\tIn Radian tan : %.3lf\n\n\n\n", output );
        output = tan(val*PI/180);
        printf ("\n\t\t\tIn Degree tan :%.3lf\n\n\n\n", output );
    
    return;
}
    if(k==1)
    { 
        printf("\n\n\t\t\tEnter the Radian Value for tan : ");
        scanf("%lf", &input);
        double pi = 3.14159;
        input=input * (180/pi);
        output = tan(input*PI/180);
        printf ("\n\t\t\tsin : %.3lf\n\n\n\n", output );

    }
    else
    {
        printf("\n\n\n\t\t\tEnter the value of tan : ");
        scanf("%lf", &input);
        output = tan(input*PI/180);
        printf ("\n\t\t\ttan of %.0lf Degree is %.3lf\n\n\n\n", input, output );
        return;
    }
}


void matrix_addition()
{
    int row_size, column_size;
    printf("\nInsert Row Size    : ");
    scanf("%d", &row_size);
    printf("Insert Column Size : ");
    scanf("%d", &column_size);
    int array1[row_size][column_size], array2[row_size][column_size];
    printf("Insert the %d * %d Matrix A :\n", row_size, column_size);
    int i, j;
    for(i = 0; i < row_size; i++){
        for(j = 0; j < column_size; j++){
            scanf("%d", &array1[i][j]);
        }
    }
    printf("Insert the %d * %d Matrix B :\n", row_size, column_size);
    int k, l;
    for(k = 0; k < row_size; k++){
        for(l = 0; l < column_size; l++){
            scanf("%d", &array2[k][l]);
        }
    }
    printf("Here Matrix A + B\n", row_size, column_size);
    for(i = 0; i < row_size; i++){
        for(j = 0; j < column_size; j++){
            printf("%d ", array1[i][j]);
            printf("+");
            printf(" %d", array2[i][j]);
            printf("\t");
        }

    printf("\n");
    }
    //int sum = 0;
    printf("Summation of A , B Matrix is : \n");
    for(i = 0; i < row_size; i++){
        int sum = 0;
        //printf("\t\t\t\t\t        ");
        for(j = 0; j < column_size; j++){
            sum = array1[i][j] + array2[i][j];
        printf("%d\t", sum);
        }
        printf("\n");

    }
    printf("\n");


    //getch();
    return;
}


void matrix_substraction(){
    system("color 4a");
    int row_size, column_size;
    printf("\nInsert Row Size    : ");
    scanf("%d", &row_size);
    printf("Insert Column Size : ");
    scanf("%d", &column_size);
    int array1[row_size][column_size], array2[row_size][column_size];
    printf("Insert the %d * %d Matrix A :\n", row_size, column_size);
    int i, j;
    for(i = 0; i < row_size; i++){
        for(j = 0; j < column_size; j++){
            scanf("%d", &array1[i][j]);
        }
    }
    printf("Insert the %d * %d Matrix B :\n", row_size, column_size);
    int k, l;
    for(k = 0; k < row_size; k++){
        for(l = 0; l < column_size; l++){
            scanf("%d", &array2[k][l]);
        }
    }
    printf("Here Matrix A - B\n", row_size, column_size);
    for(i = 0; i < row_size; i++){
        for(j = 0; j < column_size; j++){
            printf("%d ", array1[i][j]);
            printf("-");
            printf(" %d", array2[i][j]);
            printf("\t");
        }

    printf("\n");
    }
    printf("SubsTraction of A , B Matrix is : \n");
    for(i = 0; i < row_size; i++){
        int sum = 0;
        for(j = 0; j < column_size; j++){
            sum = array1[i][j] - array2[i][j];
        printf("%d\t", sum);
        }
        printf("\n");
    }
    printf("\n");


    return;
}


void matrix_multiply()
{
    system("cls");
    int a[10][10], b[10][10], mult[10][10], a_row_size, a_column_size, b_row_size, b_column_size, i, j, k;
    int row_size, column_size;
    printf("Enter 1st Matrix Rows and Column : ");
    scanf("%d %d", &a_row_size, &a_column_size);
    printf("Enter 2nd Matrix Rows and Column : ");
    scanf("%d %d", &b_row_size, &b_column_size);
    printf("\nInsert the %d * %d Matrix A :\n", a_row_size, a_column_size);
    for(i = 0; i < a_row_size; i++){
            for(j = 0; j < a_column_size; j++){
        scanf("%d",&a[i][j]);
        }
    }
    printf("Insert the %d * %d Matrix B :\n", b_row_size, b_column_size);
    for(i = 0; i < b_row_size; i++){
        for(j = 0; j < b_column_size; j++){
            scanf("%d",&b[i][j]);
        }
    }
    for(i = 0; i < a_row_size; i++){
        for(j = 0; j < b_column_size; j++){
           mult[i][j]=0;
        }
    }
    printf("Here Matrix A * B\n", a_row_size, b_column_size);
    for(i = 0; i < a_row_size; i++){
        for(j = 0; j < b_column_size; j++){
            int count = 0;
            for(k = 0; k < a_column_size; k++){
                printf("%d * %d", a[i][k], b[k][j]);
                mult[i][j] += a[i][k]*b[k][j];
                if(count == a_column_size - 1){
                break;
            }
            count++;
            printf(" + ");
            }
           printf("\t");
        }
        printf("\n");
    }
    printf("\nResult of Matrix A * B\n", row_size, column_size);
    for(i=0; i<a_row_size; ++i){
        for(j=0; j<b_column_size; ++j){
            printf("%d\t",mult[i][j]);
        }
        printf("\n");
    }
    printf("\n");


    return;
}




void length(){
    system("cls");
    float centimetre, Metre, kilometre, convert_number;
    int length_number;
   printf("\n\t\t\t===========================================================");  
    printf("\n\n\t\t\t\t\tLength Calculator Menu :");               
    printf("\n\n\t\t\t\t\t> 1.Convert Centimetre to Metre");
    printf("\n\t\t\t\t\t> 2.Convert Centimetre to Kilometre");
    printf("\n\t\t\t\t\t> 3.Convert Metre to Centimetre");
    printf("\n\t\t\t\t\t> 4.Convert Metre to Kilometre");
    printf("\n\t\t\t\t\t> 5.Convert Kilometre to Centimetre");
    printf("\n\t\t\t\t\t> 6.Convert Kilometre to Metre");
    printf("\n\t\t\t\t\t> 7.Calculator Menu");
    printf("\n\n\t\t\t===========================================================\n\n");
    printf("\n\n\t\t\tEnter Your Choice => ");
    scanf("%d", &length_number);
    system ("cls");
    while(length_number > 0 && length_number < 7){
        switch(length_number){
            case 1:
                printf("\nCentimetre : ");
                scanf("%f", &convert_number);
                printf("metre      : %.3f\n", convert_number / 100);
                clear();
                break;
            case 2:
                printf("\nCentimetre : ");
                scanf("%f", &convert_number);
                printf("Kilometre  : %.3f\n", convert_number / 1000);
                clear();
                break;
            case 3:
                printf("\nMetre      : ");
                scanf("%f", &convert_number);
                printf("Centimetre : %.3f\n", convert_number * 100);
                clear();
                break;
            case 4:
                printf("\nMetre     : ");
                scanf("%f", &convert_number);
                printf("Kilometre : %.3f\n", convert_number / 100);
                clear();
                break;
            case 5:
                printf("\nKilometre  : ");
                scanf("%f", &convert_number);
                printf("Centimetre : %.3f\n", convert_number * 1000);
                clear();
                break;
            case 6:
                printf("\nKilometre : ");
                scanf("%f", &convert_number);
                printf("Metre     : %.3f\n", convert_number * 100);
                clear();
                break;
            default:
                break;
        }
        system ("cls");
        printf("\n\t\t\t===========================================================");  
        printf("\n\n\t\t\t\t\tLength Calculator Menu :");               
        printf("\n\n\t\t\t\t\t> 1.Convert Centimetre to Metre");
        printf("\n\t\t\t\t\t> 2.Convert Centimetre to Kilometre");
        printf("\n\t\t\t\t\t> 3.Convert Metre to Centimetre");
        printf("\n\t\t\t\t\t> 4.Convert Metre to Kilometre");
        printf("\n\t\t\t\t\t> 5.Convert Kilometre to Centimetre");
        printf("\n\t\t\t\t\t> 6.Convert Kilometre to Metre");
        printf("\n\t\t\t\t\t> 7.Calculator Menu");
        printf("\n\n\t\t\t===========================================================\n\n");
        printf("\n\n\t\t\tEnter Your Choice => ");
        scanf("%d", &length_number);
        system ("cls");
    }


    return;
}



void mass(){
    system("cls");
    float convert_number;
    int mass_number;
    
    printf("\n\t\t\t===========================================================");  
    printf("\n\n\t\t\t\t\tMass Calculator Menu :");               
    printf("\n\n\t\t\t\t\t> 1.Convert Centigram to Gram");
    printf("\n\t\t\t\t\t> 2.Convert Centigram to Kilogram");
    printf("\n\t\t\t\t\t> 3.Convert Gram to Centigram");
    printf("\n\t\t\t\t\t> 4.Convert Gram to Kilogram");
    printf("\n\t\t\t\t\t> 5.Convert Kilogram to Centigram");
    printf("\n\t\t\t\t\t> 6.Convert Kilogram to Gram");
    printf("\n\t\t\t\t\t> 7.Calculator Menu");
    printf("\n\n\t\t\t===========================================================\n\n");
    printf("\n\n\t\t\tEnter Your Choice => ");
    scanf("%d", &mass_number);
    system ("cls");
    while(mass_number > 0 && mass_number < 7){
        switch(mass_number){
            case 1:
                printf("\nCentigram : ");
                scanf("%f", &convert_number);
                printf("Gram      : %.3f\n", convert_number / 100);
                clear();
                break;
            case 2:
                printf("\nCentigram : ");
                scanf("%f", &convert_number);
                printf("Kilogram  : %.3f\n", convert_number / 1000);
                clear();
                break;
            case 3:
                printf("\nGram      : ");
                scanf("%f", &convert_number);
                printf("Centigram : %.3f\n", convert_number * 100);
                clear();
                break;
            case 4:
                printf("\nGram     : ");
                scanf("%f", &convert_number);
                printf("Kilogram : %.3f\n", convert_number / 100);
                clear();
                break;
            case 5:
                printf("\nKilogram  : ");
                scanf("%f", &convert_number);
                printf("Centigram : %.3f\n", convert_number * 1000);
                clear();
                break;
            case 6:
                printf("\nKilogram : ");
                scanf("%f", &convert_number);
                printf("Gram     : %.3f\n", convert_number * 100);
                clear();
                break;
            default:
                break;
        }
        system ("cls");
        
    printf("\n\t\t\t===========================================================");  
    printf("\n\n\t\t\t\t\tMass Calculator Menu :");               
    printf("\n\n\t\t\t\t\t> 1.Convert Centigram to Gram");
    printf("\n\t\t\t\t\t> 2.Convert Centigram to Kilogram");
    printf("\n\t\t\t\t\t> 3.Convert Gram to Centigram");
    printf("\n\t\t\t\t\t> 4.Convert Gram to Kilogram");
    printf("\n\t\t\t\t\t> 5.Convert Kilogram to Centigram");
    printf("\n\t\t\t\t\t> 6.Convert Kilogram to Gram");
    printf("\n\t\t\t\t\t> 7.Calculator Menu");
    printf("\n\n\t\t\t===========================================================\n\n");
    printf("\n\n\t\t\tEnter Your Choice => ");
    scanf("%d", &mass_number);
    system ("cls");
    }

    return;
}


void temperature()
{
    system ("cls");
    float convert_number;
    int temperature_number;
    
    printf("\n\t\t\t===========================================================");  
    printf("\n\n\t\t\t\t\tTempreture Calculator Menu :");               
    printf("\n\n\t\t\t\t\t> 1.Convert Celsius to Fahrenheit");
    printf("\n\t\t\t\t\t> 2.Convert Celsius to Kelvin");
    printf("\n\t\t\t\t\t> 3.Convert Fahrenheit to Celsius");
    printf("\n\t\t\t\t\t> 4.Convert Fahrenheit to Kelvin");
    printf("\n\t\t\t\t\t> 5.Convert Kelvin to Celsius");
    printf("\n\t\t\t\t\t> 6.Convert Kelvin to Fahrenheit");
    printf("\n\t\t\t\t\t> 7.Calculator Menu");
    printf("\n\n\t\t\t===========================================================\n\n");
    printf("\n\n\t\t\tEnter Your Choice => ");
    scanf("%d", &temperature_number);
    system ("cls");
    while(temperature_number > 0 && temperature_number < 7){
        switch(temperature_number){
            case 1:
                printf("\nCelsius    : ");
                scanf("%f", &convert_number);
                printf("Fahrenheit : %.3f\n", convert_number * 1.8 + 32);
                clear();
                break;
            case 2:
                printf("\nCelsius : ");
                scanf("%f", &convert_number);
                printf("Kelvin  : %.3f\n", convert_number + 273.15);
                clear();
                break;
            case 3:
                printf("\nFahrenheit : ");
                scanf("%f", &convert_number);
                printf("Celsius    : %.3f\n", (convert_number - 32) * .5556);
                clear();
                break;
            case 4:
                printf("\nFahrenheit : ");
                scanf("%f", &convert_number);
                printf("Kelvin     : %.3f\n", (convert_number + 459.67) * 5/9);
                clear();
                break;
            case 5:
                printf("\nKelvin  : ");
                scanf("%f", &convert_number);
                printf("Celsius : %.3f\n",  convert_number - 273.15);
                clear();
                break;
            case 6:
                printf("\nKelvin     : ");
                scanf("%f", &convert_number);
                printf("Fahrenheit : %.3f\n", convert_number * 9/5 - 459.67);
                clear();
                break;
            default:
                break;
        }
    system ("cls");
    printf("\n\t\t\t===========================================================");  
    printf("\n\n\t\t\t\t\tTempreture Calculator Menu :");               
    printf("\n\n\t\t\t\t\t> 1.Convert Celsius to Fahrenheit");
    printf("\n\t\t\t\t\t> 2.Convert Celsius to Kelvin");
    printf("\n\t\t\t\t\t> 3.Convert Fahrenheit to Celsius");
    printf("\n\t\t\t\t\t> 4.Convert Fahrenheit to Kelvin");
    printf("\n\t\t\t\t\t> 5.Convert Kelvin to Celsius");
    printf("\n\t\t\t\t\t> 6.Convert Kelvin to Fahrenheit");
    printf("\n\t\t\t\t\t> 7.Calculator Menu");
    printf("\n\n\t\t\t===========================================================\n\n");
    printf("\n\n\t\t\tEnter Your Choice => ");
    scanf("%d", &temperature_number);
    system ("cls");
    }

    return;
}



void speed()
{
    system ("cls");
    float centimetre, Metre, kilometre, convert_number;
    int speed_number;
   
    printf("\n\t\t\t===========================================================");  
    printf("\n\n\t\t\t\t\tSpeed Calculator Menu :");               
    printf("\n\n\t\t\t\t\t> 1.Convert metres per Second to Kilometres per Hours");
    printf("\n\t\t\t\t\t> 2.Convert metres per Second to Miles per Hours");
    printf("\n\t\t\t\t\t> 3.Convert Kilometres per Hours to metres per Second");
    printf("\n\t\t\t\t\t> 4.Convert Kilometres per Hours to Miles per Hours");
    printf("\n\t\t\t\t\t> 5.Convert Miles per Hours to metres per Second");
    printf("\n\t\t\t\t\t> 6.Convert Miles per Hours to Kilometres per Hours");
    printf("\n\t\t\t\t\t> 7.Calculator Menu");
    printf("\n\n\t\t\t===========================================================\n\n");
    printf("\n\n\t\t\tEnter Your Choice => ");
    scanf("%d", &speed_number);
    system ("cls");
    while(speed_number > 0 && speed_number < 0){
        switch(speed_number){
            case 1:
                printf("\nmetres per Second    : ");
                scanf("%f", &convert_number);
                printf("Kilometres per Hours : %.2f\n\n", convert_number * 3.60);
                clear();
                break;
            case 2:
                printf("\nmetres per Second : ");
                scanf("%f", &convert_number);
                printf("Miles per Hours   : %.2f\n\n", convert_number * 2.24);
                clear();
                break;
            case 3:
                printf("\nKilometres per Hours : ");
                scanf("%f", &convert_number);
                printf("metres per Second    : %.2f\n\n", convert_number * 0.28);
                clear();
                break;
            case 4:
                printf("\nKilometres per Hours : ");
                scanf("%f", &convert_number);
                printf("Miles per Hours      : %.2f\n\n", convert_number * 0.62);
                clear();
                break;
            case 5:
                printf("\nMiles per Hours   : ");
                scanf("%f", &convert_number);
                printf("metres per Second : %.2f\n\n", convert_number * 0.45);
                clear();
                break;
            case 6:
                printf("\nMiles per Hours      : ");
                scanf("%f", &convert_number);
                printf("Kilometres per Hours : %.2f\n\n", convert_number * 1.61);
                clear();
                break;
            default:
                break;
        }
        system ("cls");
    printf("\n\t\t\t===========================================================");  
    printf("\n\n\t\t\t\t\tSpeed Calculator Menu :");               
    printf("\n\n\t\t\t\t\t> 1.Convert metres per Second to Kilometres per Hours");
    printf("\n\t\t\t\t\t> 2.Convert metres per Second to Miles per Hours");
    printf("\n\t\t\t\t\t> 3.Convert Kilometres per Hours to metres per Second");
    printf("\n\t\t\t\t\t> 4.Convert Kilometres per Hours to Miles per Hours");
    printf("\n\t\t\t\t\t> 5.Convert Miles per Hours to metres per Second");
    printf("\n\t\t\t\t\t> 6.Convert Miles per Hours to Kilometres per Hours");
    printf("\n\t\t\t\t\t> 7.Calculator Menu");
    printf("\n\n\t\t\t===========================================================\n\n");
    printf("\n\n\t\t\tEnter Your Choice => ");
    scanf("%d", &speed_number);
    system ("cls");
    }

    return;
}


void timec(){
    system ("cls");

    float centimetre, Metre, kilometre, convert_number;
    int time_number;
    int min,minu,h;
    printf("\n\t\t\t===========================================================");  
    printf("\n\n\t\t\t\t\tTime  Calculator Menu :");               
    printf("\n\t\t\t\t\t> 1.Convert Seconds to Minutes");
    printf("\n\t\t\t\t\t> 2.Convert Seconds to Hours");
    printf("\n\t\t\t\t\t> 3.Convert Minutes to Seconds");
    printf("\n\t\t\t\t\t> 4.Convert Minutes to Hours");
    printf("\n\t\t\t\t\t> 5.Convert Hours to Seconds");
    printf("\n\t\t\t\t\t> 6.Convert Hours to Minutes");
    printf("\n\t\t\t\t\t> 7.Calculator Menu");
    printf("\n\t\t\t\t\t> 8.Exit");
    printf("\n\n\t\t\t===========================================================\n\n");
    printf("\n\n\t\t\tEnter Your Choice => ");
    scanf("%d", &time_number);
    system ("cls");
    while(time_number > 0 && time_number < 7){
        switch(time_number){
            case 1:
                printf("\nSeconds : ");
                scanf("%f", &convert_number);
                printf("Minutes : %.2f\n\n", convert_number / 60);
                clear();
                break;
            case 2:
                printf("\nSeconds : ");
                scanf("%f", &convert_number);
                printf("Hours   : %.5f\n\n", convert_number / 3600);
                clear();
                break;
            case 3:
                printf("\nMinutes : ");
                scanf("%f", &convert_number);
                printf("Seconds : %.2f\n\n", 60 * convert_number);
                clear();
                break;
            case 4:
                printf("\nMinutes : ");
                scanf("%i", &min);
                h=min/60;
                minu=min%60;
                printf("Hours   : %d hr %i min\n\n",h,minu);
                clear();
                break;
            case 5:
                printf("\nHours   : ");
                scanf("%f", &convert_number);
                printf("Seconds : %.2f\n\n", convert_number * 3600);
                clear();
                break;
            case 6:
                printf("\nHours   : ");
                scanf("%f", &convert_number);
                printf("Minutes : %.2f\n\n", convert_number * 60);
                clear();
                break;
            case 7:
                calc();
                clear();
                break;
            case 8:
                exit(0);
                break;
            default:
                break;
        }
    system ("cls");
    printf("\n\t\t\t===========================================================");  
    printf("\n\n\t\t\t\t\tTime  Calculator Menu :");               
    printf("\n\t\t\t\t\t> 1.Convert Seconds to Minutes");
    printf("\n\t\t\t\t\t> 2.Convert Seconds to Hours");
    printf("\n\t\t\t\t\t> 3.Convert Minutes to Seconds");
    printf("\n\t\t\t\t\t> 4.Convert Minutes to Hours");
    printf("\n\t\t\t\t\t> 5.Convert Hours to Seconds");
    printf("\n\t\t\t\t\t> 6.Convert Hours to Minutes");
    printf("\n\t\t\t\t\t> 7.Calculator Menu");
    printf("\n\t\t\t\t\t> 8.Exit");
    printf("\n\n\t\t\t===========================================================\n\n");
    printf("\n\n\t\t\tEnter Your Choice => ");
    scanf("%d", &time_number);
    system ("cls");
    }


    return;
}


void currency()
{
    system ("cls");
    float centimetre, Metre, kilometre, convert_number;
    int currency_number;
    printf("\n\t\t\t===========================================================");  
    printf("\n\n\t\t\t\t\tCurrency Calculator Menu :");               
    printf("\n\t\t\t\t\t> 1.Convert Bangladeshi Taka to US Dollar");
    printf("\n\t\t\t\t\t> 2.Convert Bangladeshi Taka to Euro");
    printf("\n\t\t\t\t\t> 3.Convert US Dollar to Bangladeshi Taka");
    printf("\n\t\t\t\t\t> 4.Convert US Dollar to Euro");
    printf("\n\t\t\t\t\t> 5.Convert Euro to Bangladeshi Taka");
    printf("\n\t\t\t\t\t> 6.Convert Euro to US Dollar");
    printf("\n\t\t\t\t\t> 7.Calculator To Menu");
    printf("\n\t\t\t\t\t> 8.Exit");
    printf("\n\n\t\t\t===========================================================\n\n");
    printf("\n\n\t\t\tEnter Your Choice => "); 
    scanf("%d", &currency_number);
    while(currency_number > 0 && currency_number < 7){
        switch(currency_number){
            case 1:
                printf("\nBangladeshi Taka : ");
                scanf("%f", &convert_number);
                printf("US Dollar   : %.2f\n\n", convert_number *  0.0122133);
                clear();
                break;
            case 2:
                printf("\nBangladeshi Taka : ");
                scanf("%f", &convert_number);
                printf("Euro        : %.3f\n\n", convert_number * 0.0103774);
                clear();
                break;
            case 3:
                printf("\nUS Dollar    : ");
                scanf("%f", &convert_number);
                printf("Bangladeshi Taka : %10.f\n\n", 81.8783 * convert_number);
                clear();
                break;
            case 4:
                printf("\nUS Dollar     : ");
                scanf("%f", &convert_number);
                printf("Euro      : %.3f\n\n", convert_number * 0.848139);
                clear();
                break;
            case 5:
                printf("\nEuro       : ");
                scanf("%f", &convert_number);
                printf("Bangladeshi Taka : %.3f\n\n", convert_number * 96.4136);
                clear();
                break;
            case 6:
                printf("\nEuro     : ");
                scanf("%f", &convert_number);
                printf("US Dollar : %f\n\n", convert_number * 1.17905);
                clear();
                break;
            case 7:
                calc();
                clear();
                break;
            case 8:
                exit(0);
                break;
            default:
                break;
        }
    printf("\n\t\t\t===========================================================");  
    printf("\n\n\t\t\t\t\tCurrency Calculator Menu :");               
    printf("\n\t\t\t\t\t> 1.Convert Bangladeshi Taka to US Dollar");
    printf("\n\t\t\t\t\t> 2.Convert Bangladeshi Taka to Euro");
    printf("\n\t\t\t\t\t> 3.Convert US Dollar to Bangladeshi Taka");
    printf("\n\t\t\t\t\t> 4.Convert US Dollar to Euro");
    printf("\n\t\t\t\t\t> 5.Convert Euro to Bangladeshi Taka");
    printf("\n\t\t\t\t\t> 6.Convert Euro to US Dollar");
    printf("\n\t\t\t\t\t> 7.Calculator To Menu");
    printf("\n\t\t\t\t\t> 8.Exit");
    printf("\n\n\t\t\t===========================================================\n\n");
    printf("\n\n\t\t\tEnter Your Choice => "); 
    scanf("%d", &currency_number);

    }


    return;
}


void energy(){
    system ("cls");
    float centimetre, Metre, kilometre, convert_number;
    int energy_number;
    printf("\n\t\t\t===========================================================");  
    printf("\n\n\t\t\t\t\tEnergy Calculator Menu :");               
    printf("\n\t\t\t\t\t> 1.Convert Joules to Kilowatts");
    printf("\n\t\t\t\t\t> 2.Convert Joules to Kilojoules");
    printf("\n\t\t\t\t\t> 3.Convert Kilowatts to Joules");
    printf("\n\t\t\t\t\t> 4.Convert Kilowatts to Kilojoules");
    printf("\n\t\t\t\t\t> 5.Convert Kilojoules to Joules");
    printf("\n\t\t\t\t\t> 6.Convert Kilojoules to Kilowatts");
    printf("\n\t\t\t\t\t> 7.Calculator To Menu");
    printf("\n\t\t\t\t\t> 8.Exit");
    printf("\n\n\t\t\t===========================================================\n\n");
    printf("\n\n\t\t\tEnter Your Choice => "); 
    scanf("%d", &energy_number);
    while(energy_number > 0 && energy_number <= 8){
        switch(energy_number){
            case 1:
                printf("\nJoules    : ");
                scanf("%f", &convert_number);
                printf("Kilowatts : %.10f\n\n", convert_number / 3600000);
                clear();
                break;
            case 2:
                printf("\nJoules     : ");
                scanf("%f", &convert_number);
                printf("KiloJoules : %.3f\n\n", convert_number / 1000);
                clear();
                break;
            case 3:
                printf("\nKilowatts : ");
                scanf("%f", &convert_number);
                printf("Joules    : %10.f\n\n", 3600000 * convert_number);
                clear();
                break;
            case 4:
                printf("\nKilowatts  : ");
                scanf("%f", &convert_number);
                printf("Kilojoules : %.3f\n\n", convert_number * 3600);
                clear();
                break;
            case 5:
                printf("\nKilojoules : ");
                scanf("%f", &convert_number);
                printf("Joules     : %.3f\n\n", convert_number * 1000);
                clear();
                break;
            case 6:
                printf("\nKilojoules : ");
                scanf("%f", &convert_number);
                printf("Kilowatts  : %f\n\n", convert_number / 3600);
                clear();
                break;
            case 7:
                calc();
                clear();
                break;
            case 8:
                exit(0);
                break;
            default:
                break;
        }
    printf("\n\t\t\t===========================================================");  
    printf("\n\n\t\t\t\t\tEnergy Calculator Menu :");               
    printf("\n\t\t\t\t\t> 1.Convert Joules to Kilowatts");
    printf("\n\t\t\t\t\t> 2.Convert Joules to Kilojoules");
    printf("\n\t\t\t\t\t> 3.Convert Kilowatts to Joules");
    printf("\n\t\t\t\t\t> 4.Convert Kilowatts to Kilojoules");
    printf("\n\t\t\t\t\t> 5.Convert Kilojoules to Joules");
    printf("\n\t\t\t\t\t> 6.Convert Kilojoules to Kilowatts");
    printf("\n\t\t\t\t\t> 7.Calculator To Menu");
    printf("\n\t\t\t\t\t> 8.Exit");
    printf("\n\n\t\t\t===========================================================\n\n");
    printf("\n\n\t\t\tEnter Your Choice => "); 
    scanf("%d", &energy_number);
    }
    return;
}


int game()
{
    system("cls");
    int n;
    while(1)
    {
        printf("\n\t\t\t===========================================================");  
    printf("\n\n\t\t\t\t\tPlay:");               
    printf("\n\t\t\t\t\t> 1.Ai Tic-Tac-Toe");
    printf("\n\t\t\t\t\t> 2.Back To Menu");
    printf("\n\n\t\t\t===========================================================\n\n");
    printf("\n\n\t\t\tEnter Your Choice => "); 
    scanf("%d",&n);
        switch (n)
        {
        case 1:
        
            system("cls");
            printf("\n\n\n\n\n\t\t\t\t LOADING...\n\n\t\t\t\t");
            for(int r=1;r<=20;r++)
            {
                for(int q=0;q<=100000000;q++);//to display the character slowly
                printf("%c",222);
            }
            printf("\n\n\t\t\t\tCOMPLETED...");
            getch();
            ttt();
            break;
        case 2:
            main();
        default:
            break;
        }
        system("cls");
    }
    return 0;
    
}

//Tic-tac-toe playing AI. Exhaustive tree-search. WTFPL

char gridChar(int i) {
    switch(i) {
        case -1:
            return 'X';
        case 0:
            return ' ';
        case 1:
            return 'O';
    }
}

void draw(int b[9]) {
    printf("\n\t\t----------------------------------------------------------------------------------------");
    printf("\n\t\t\t\t\t\t  !! Ai Tic-Tac-Toe !!");
    printf("\n\t\t----------------------------------------------------------------------------------------");
    printf("\n\n\n\n\n\n");
    printf("\n\t\t\t\tNumbered as below \t\t\tLIVE TRACK!\n\n");
    printf("\t\t\t\t 0 | 1 | 2\t\t|\t\t %c | %c | %c\n",gridChar(b[0]),gridChar(b[1]),gridChar(b[2]));
    printf("\t\t\t\t---+---+---\t\t|\t\t---+---+---\n");
    printf("\t\t\t\t 3 | 4 | 5\t \t|\t\t %c | %c | %c\n",gridChar(b[3]),gridChar(b[4]),gridChar(b[5]));
    printf("\t\t\t\t---+---+---\t\t|\t\t---+---+---\n");
    printf("\t\t\t\t 6 | 7 | 8\t\t|\t\t %c | %c | %c\n\n",gridChar(b[6]),gridChar(b[7]),gridChar(b[8]));

}

int win(const int board[9]) {
    //determines if a player has won, returns 0 otherwise.
    unsigned wins[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    int i;
    for(i = 0; i < 8; ++i) {
        if(board[wins[i][0]] != 0 &&
           board[wins[i][0]] == board[wins[i][1]] &&
           board[wins[i][0]] == board[wins[i][2]])
            return board[wins[i][2]];
    }
    return 0;
}

int minimax(int board[9], int player) {
    //How is the position like for player (their turn) on board?
    int winner = win(board);
    if(winner != 0) return winner*player;

    int move = -1;
    int score = -2;//Losing moves are preferred to no move
    int i;
    for(i = 0; i < 9; ++i) {//For all moves,
        if(board[i] == 0) {//If legal,
            board[i] = player;//Try the move
            int thisScore = -minimax(board, player*-1);
            if(thisScore > score) {
                score = thisScore;
                move = i;
            }//Pick the one that's worst for the opponent
            board[i] = 0;//Reset board after try
        }
    }
    if(move == -1) return 0;
    return score;
}

void computerMove(int board[9]) {
    int move = -1;
    int score = -2;
    int i;
    for(i = 0; i < 9; ++i) {
        if(board[i] == 0) {
            board[i] = 1;
            int tempScore = -minimax(board, -1);
            board[i] = 0;
            if(tempScore > score) {
                score = tempScore;
                move = i;
            }
        }
    }
    //returns a score based on minimax tree at a given node.
    board[move] = 1;
}

void playerMove(int board[9]) {
    int move = 0;
    do {
        printf("\n\n\t\t\t\tInput move ([0..8]): ");
        scanf("%d", &move);
        printf("\n");
    } while (move >= 9 || move < 0 && board[move] == 0);
    board[move] = -1;
}

int ttt() {
    system("cls");
    int board[9] = {0,0,0,0,0,0,0,0,0};
    //computer squares are 1, player squares are -1.

    
    printf("\n\t\t\t===========================================================");  
    printf("\n\n\t\t\t\t\tComputer: O , You: X");               
    printf("\n\t\t\t\t\t> Play (1)st or (2)nd?");
    printf("\n\n\t\t\t===========================================================\n\n");
    printf("\n\n\t\t\tEnter Your Choice => "); 
    int player=0;
    scanf("%d",&player);
    printf("\n");
    unsigned turn;
    for(turn = 0; turn < 9 && win(board) == 0; ++turn) {
        system("cls");
        if((turn+player) % 2 == 0)
            computerMove(board);
        else {
            draw(board);
            playerMove(board);
        }
    }
    system("cls");
    switch(win(board)) {
        case 0:
    
    printf("\n\t\t\t===========================================================");  
    printf("\n\n\t\t\t\t\t\tMatch Drawn!!");
    printf("\n\n\t\t\t===========================================================\n\n");
    
            getch();
            main();
            break;
        case 1:
            draw(board);
            
    
    printf("\n\t\t\t===========================================================");  
    printf("\n\n\t\t\t\t\t\tYou Lose!!");
    printf("\n\n\t\t\t===========================================================\n\n");
    
            getch();
            main();
            break;
        case -1:
            printf("\n\tYou win. Inconceivable!\n\n\n");
            getch();
            main();
            break;
    }
}
