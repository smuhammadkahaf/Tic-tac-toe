#include <iostream>
#include <windows.h>
#include <strings.h>
using namespace std;

//function prototypes
char menu (void);
void grids (char [3][3]);
void help(void);
void loading(void);
int  data_1(char [3][3]);
int  data_2(char [3][3]);
int  check(char  [3][3]);
void reset(char[3][3]);
int  back();
void exchange(string*,string*,int*,int*);
void animation();

//main function
int main()
{
    int point1,point2;
    int u=0,player,winer;
    char choice;
    char game [3][3];
    string p1,p2;

    homescreen:
    point1=0;
    point2=0;
    animation();
    choice = menu();

    switch(choice)
    {
    case '1':
        {
            help();
            system ("cls");
            goto homescreen;
            break;
        }
    case '2':
        {
           // start:
            system("cls");
            cout<<"starting";
            loading ();
            while(u==0)
            {
                cout<<"Enter Player [1] name : ";
                cin.ignore();
                getline(cin,p1);

                if (p1=="")
                {
                    system("cls");
                    cout<<"please insert a name"<<endl;
                }
                else
                {
                    break;
                }
            }
            while(u==0)
            {
                cout<<"Enter Player [2] name : ";
                getline(cin,p2);
                if(p2=="")
                {system("cls");
                    cout<<"Please insert a name"<<endl;
                }
                else
                {
                    break;
                }
            }
            if (p1==p2)
            {
                p2.append("(1)");
            }
            cout<<endl<<"<Wish You Guys The Best>"<<endl;
            Sleep(1000);
            restart://restart
            reset(game);
            u=0;
            for (int i=0;i<9;)
            {
                //player-1 turns
                system ("cls");
                grids(game);
                while (u==0)
                {
                    cout<<p1<<"[X] Turn : "<<endl;
                    u=data_1(game);
                    if(u==2)
                    {
                        system("cls");
                        cout<<"Restarting";
                        loading();
                        exchange(&p1,&p2,&point1,&point2);
                        goto restart;
                    }
                    else if(u==3)
                    {
                        system("cls");
                        cout<<"loading";
                        loading();
                        goto homescreen;
                    }
                }
                u=0;
                i++;
                winer=check(game);
                if (winer==1)
                {
                    break;
                }
                //player-2 turns
                if(i!=9)
                {
                    system ("cls");
                    grids(game);

                    while (u==0)
                    {
                        cout<<p2<<"[O] Turn : "<<endl;
                        u=data_2(game);
                        if(u==2)
                        {
                            system("cls");
                            cout<<"Restarting";
                            exchange(&p1,&p2,&point1,&point2);
                            loading();
                            goto restart;
                        }
                        else if(u==3)
                        {
                            system("cls");
                            cout<<"loading";
                            loading();
                            goto homescreen;
                        }
                    }
                    u=0;
                    i++;
                    winer=check(game);
                    if (winer==2)
                    {
                        break;
                    }
                }
            }
            system("cls");
            grids(game);

            if (winer==1)
            {
                cout<<p1<<" Won the Match"<<endl;
                point1++;
            }
            if (winer==2)
            {
                cout<<p2<<" Won the Match"<<endl;
                point2++;
            }
            if (winer==0)
            {
                cout<<"Game Draw"<<endl;
            }
            cout<<endl<<"Current score"<<endl;
            cout<<p1<<" = "<<point1<<endl;
            cout<<p2<<" = "<<point2<<endl;
            cout<<endl<<"If you want to restart with same players enter 'R'"<<endl;
            cout<<"Else enter any key to go back to main menu"<<endl;
            u=back();
            system ("cls");
            if (u==1)
            {
                system("cls");
                cout<<"Restarting";
                loading();
                exchange(&p1,&p2,&point1,&point2);
                goto restart;
            }
            goto homescreen;

            break;
        }
    case '3':
        {
           return 0;
        }
    default:
        {
            system ("cls");
            cout<<"Invalid choice select again"<<endl;
            goto homescreen;
        }
    }
    return 0;
}
//this function is the interface of main menu + selecting choice
char menu(void)
{   char menu;
    cout<<endl;
    cout<<"Menu:"<<endl;
    cout<<"1. How to play (strongly recommended)"<<endl;
    cout<<"2. Start game"<<endl;
    cout<<"3. Exit"<<endl;
    cout<<"(Enter corresponding number to select option)"<<endl<<endl;
    cin >> menu;
    return menu;
}
//this function will display the array in grid
void grids (char x[3][3])
{
    cout<<"\t     |     |     "<<endl;
    cout<<"\t  "<<x[0][0]<<"  |  "<<x[0][1]<<"  |  "<<x[0][2]<<"  "<<endl;
    cout<<"\t     |     |     "<<endl;
    cout<<"\t-----------------"<<endl;
    cout<<"\t     |     |     "<<endl;
    cout<<"\t  "<<x[1][0]<<"  |  "<<x[1][1]<<"  |  "<<x[1][2]<<"  "<<endl;
    cout<<"\t     |     |     "<<endl;
    cout<<"\t-----------------"<<endl;
    cout<<"\t     |     |     "<<endl;
    cout<<"\t  "<<x[2][0]<<"  |  "<<x[2][1]<<"  |  "<<x[2][2]<<"  "<<endl;
    cout<<"\t     |     |     "<<endl;
}
//this function will use as help menu or to pause the game
void help(void)
{
    char waste;
    char eg [3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    system ("cls");
    cout<<endl;
    cout<<endl<<"---> If you want to restart the game in your turn then press r";
    cout<<endl<<"---> After restarting game will continue with same player and their current score";
    cout<<endl<<"---> how to mark your turn?"<<endl;
    cout<<endl<<"Enter the corresponding number to mark the slot"<<endl;
    grids(eg);
    cout<<"For example, to mark the top left box, press '1'"<<endl;
    for (int i=0;i<3;i++)
   {
       for(int j=0;j<3;j++)
       {
           eg[i][j]=' ';
       }
   }
    grids(eg);
    cout<<endl;
    eg[0][0]='X';
    cout<<"It will be mark as "<<endl;
    grids(eg);
    cout<<endl<< "Press any character to back"<<endl;
    cin >> waste;
}
//this function is for starting ANIMATIONION
void loading(void)
{
    Sleep(400);
    cout<<".";
    Sleep(400);
    cout<<".";
    Sleep(400);
    cout<<".";
    Sleep(400);
    system ("cls");
}
//Player 1 input + comparision
int data_1(char game[3][3])
{
    string input;
    getline(cin,input);
    if (input=="r"||input=="R")
    {
        return 2;
    }
    else if(input=="E"||input=="e")
    {
        return 3;
    }
    else if (input=="1" && game[0][0]==' ')
    {
        game[0][0]='X';
    }
    else if (input=="2" && game[0][1]==' ')
    {
        game[0][1]= 'X';
    }
    else if (input=="3" && game[0][2]==' ')
    {
        game[0][2]= 'X';
    }
    else if (input=="4" && game[1][0]==' ')
    {
        game[1][0]= 'X';
    }
    else if (input=="5" && game[1][1]==' ')
    {
        game[1][1]= 'X';
    }
    else if (input=="6" && game[1][2]==' ')
    {
        game[1][2]= 'X';
    }
    else if (input=="7" && game[2][0]==' ')
    {
        game[2][0]= 'X';
    }
    else if (input=="8" && game[2][1]==' ')
    {
        game[2][1]= 'X';
    }
    else if (input=="9" && game[2][2]==' ')
    {
        game[2][2]= 'X';
    }
    else
    {
        cout<<"Invalid choice or slot is already used"<<endl;
        cout<<"try again"<<endl;
        return 0;
    }
    return 1;
}
//player 2 input +comparsion
int data_2(char game[3][3])
{
    string input;

    getline(cin,input);
    if (input=="r"||input=="R")
    {
        return 2;
    }
    else if(input=="E"||input=="e")
    {
        return 3;
    }
    else if (input=="1" && game[0][0]==' ')
    {
        game[0][0]='O';
    }
    else if (input=="2" && game[0][1]==' ')
    {
        game[0][1]= 'O';
    }
    else if (input=="3" && game[0][2]==' ')
    {
        game[0][2]= 'O';
    }
    else if (input=="4" && game[1][0]==' ')
    {
        game[1][0]= 'O';
    }
    else if (input=="5" && game[1][1]==' ')
    {
        game[1][1]= 'O';
    }
    else if (input=="6" && game[1][2]==' ')
    {
        game[1][2]= 'O';
    }
    else if (input=="7" && game[2][0]==' ')
    {
        game[2][0]= 'O';
    }
    else if (input=="8" && game[2][1]==' ')
    {
        game[2][1]= 'O';
    }
    else if (input=="9" && game[2][2]==' ')
    {
        game[2][2]= 'O';
    }
    else
    {
        cout<<"Invalid choice or slot is already used"<<endl;
        cout<<"try again"<<endl;
        return 0;
    }
    return 1;
}
//check winning state:
int check(char game[3][3])
{
    //horizontal match
    if (game[0][0]==game[0][1] && game[0][1]==game[0][2])
    {
        if (game[0][0]=='X')
        {
            return 1;
        }
        else if (game[0][0]=='O')
        {
            return 2;
        }
    }
    if (game[1][0]==game[1][1] && game[1][1]==game[1][2])
    {
        if (game[1][0]=='X')
        {
            return 1;
        }
        else if (game[1][0]=='O')
        {
            return 2;
        }
    }
     if (game[2][0]==game[2][1] && game[2][1]==game[2][2])
    {


        if (game[2][0]=='X')
        {
            return 1;
        }
        else if (game[2][0]=='O')
        {
            return 2;
        }
    }
    //vertical match
    if (game[0][0]==game[1][0] && game[1][0]==game[2][0])
    {
        if (game[0][0]=='X')
        {
            return 1;
        }
        else if (game[0][0]=='O')
        {
            return 2;
        }
    }
    else if (game[0][1]==game[1][1] && game[1][1]==game[2][1])
    {
        if (game[0][1]=='X')
        {
            return 1;
        }
        else if (game[0][1]=='O')
        {
            return 2;
        }
    }
    if (game[0][2]==game[1][2] && game[1][2]==game[2][2])
    {
        if (game[0][2]=='X')
        {
            return 1;
        }
        else if (game[0][2]=='O')
        {
            return 2;
        }
    }
    //diagonal Match
    if (game[0][0]==game[1][1] && game[1][1]==game[2][2])
    {
        if (game[0][0]=='X')
        {
            return 1;
        }
        else if (game[0][0]=='O')
        {
            return 2;
        }
    }
    if (game[2][0]==game[1][1] && game[1][1]==game[0][2])
    {
        if (game[2][0]=='X')
        {
            return 1;
        }
        else if (game[2][0]=='O')
        {
            return 2;
        }
    }
return 0;
}
//reset function
void reset(char game[3][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            game[i][j]=' ';
        }
    }
}
//after game over take input for restart or back
int back()
{
    string i;

    getline(cin,i);
    if (i=="r"||i=="R")
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//swap player turn after each restart

void exchange(string* p1,string* p2, int* point1,int* point2)
{
    int temp;
    string temp1;
    temp1=* p1;
    *p1 =*p2;
    *p2 =temp1;

    temp   =*point1;
    *point1=*point2;
    *point2=temp;
}
void animation()
{
	cout<<"<";  Sleep(100);
	cout<<"T";  Sleep(100);
	cout<<"i";  Sleep(100);
	cout<<"c";  Sleep(100);
	cout<<" ";  Sleep(100);
	cout<<"T";  Sleep(100);
	cout<<"a";  Sleep(100);
	cout<<"c";  Sleep(100);
	cout<<" ";  Sleep(100);
	cout<<"T";  Sleep(100);
	cout<<"o";  Sleep(100);
	cout<<"e";  Sleep(100);
	cout<<">";  Sleep(100);
}
