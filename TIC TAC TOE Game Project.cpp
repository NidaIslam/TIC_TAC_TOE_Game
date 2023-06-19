#include<iostream>
using namespace std;

char board[3][3]={ {'1','2', '3',} , {'4','5', '6'}, {'7','8','9'}};
char turn='X';
int row , coloumn;
bool draw=false;

void display_board()
{
	system ("cls");
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t T I C  T A C  T O E  G A M E  "<<endl<<endl;
	cout<<"\t\tPLAYER1 [X] \n\t\tPLAYER2 [O]"<<endl<<endl<<endl;
	
	cout<<"\t\t		      |	     |	   \n";
	cout<<"\t\t  "<< board[0][0]<<" \t  \t      |  "<<board[0][1]<<"   |  "<<board[0][2]<<"  \n";
	cout<<"\t\t\t\t______|______|______\n";
	cout<<"\t\t		      |	     |	   \n";
	cout<<"\t\t	 "<<board[1][0]<<" \t      |  "<<board[1][1]<<"   |  "<<board[1][2]<<"  \n";
	cout<<"\t\t\t\t______|______|______\n";
	cout<<"\t\t		      |	     |	   \n";
	cout<<"\t\t	 "<<board[2][0]<<"\t      |  "<<board[2][1]<<"   |  "<<board[2][2]<<"  \n"; 
	cout<<"\t\t		      |	     |	   \n";

}

void player_turn()
{
	
	int choice;
	if( turn ='X')
	{
		cout<<"\tPLAYER1[X] TURN:";
		cin>>choice;	
	}
	if( turn ='O')
	{
		cout<<"\tPLAYER2[O] TURN:";
		cin>>choice;
	}
	
	switch(choice)
	{
		case 1: row=0;coloumn=0; break;
		case 2: row=0;coloumn=1; break;
		case 3: row=0;coloumn=2; break;
		case 4: row=1;coloumn=0; break;
		case 5: row=1;coloumn=1; break;
		case 6: row=1;coloumn=2; break;
		case 7: row=2;coloumn=0; break;
		case 8: row=2;coloumn=1; break;
		case 9: row=2;coloumn=2; break;		
		default:
		cout<<"invalid choice..!!"<<endl;
		break;
		
	}
	
	if(turn=='X' && board[row][coloumn] !='X' && board[row][coloumn]!='O')
	{
		board[row][coloumn] ='X';
		turn='O'; 
	}
	else if(turn=='O' && board[row][coloumn] !='X' && board[row][coloumn]!='O')
	{
		board[row][coloumn] ='O';
		turn='X'; 
	}
	else
	{
		cout<<"BOX ALREADY FILLED...!!\n PLEASE TRY AGAIN "<<endl;
		player_turn();
		
	}
	display_board();
	
}

bool gameover()
{
	//check win
	
	for( int i=0; i<3; i++)
	{
		if( board[i][0]= board[i][1] &&  board[i][0]== board[i][2] ||  board [0][i]== board[1][i] &&  board[0][i]== board[2][i]   )
	    return false;
	}
	if( board[0][0]= board[1][1] &&  board[0][0]== board[2][2] ||  board [0][2]== board[1][1] &&  board [0][2]== board[2][0]   )
    {
	  
	    return false;
	}
	
	//game playing 
	
	for(int i=0; i<3; i++)
	for(int j=0; j<3; j++)
	if(board[i][j]!= 'X' && board[i][j]!= 'O')
	{
		return true;
	}
		
		//game draw 
		draw = true;
		return false;
				
}

int main()
{
	 while(gameover())
	{
		display_board();
		player_turn();
		gameover();
	}
	
	if( draw =='X' && draw == false)
	{
		cout<<"PLAYER2[O] WINS !!!"<<endl;
	}
	else if( draw =='O' && draw == false)
	{
		cout<<"PLAYER1[X] WINS !!!"<<endl;
	}
	else 
	{
		cout<<"GAME DRAW!!"<<endl;
	}
	
	
	
}
