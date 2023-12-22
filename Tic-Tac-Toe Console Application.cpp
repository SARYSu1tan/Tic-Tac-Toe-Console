import 'dart:io';
class XO 
{
  List<List<String>> BOARD = List.generate(3, (_)=>List.filled (3,' '));
  String Player1 = 'X';

  void Board()
  {
    for (var row in BOARD)
    {
      print (row.join(' | '));

      print ('---------');
    }
  }
  bool makemove ( int position)
{
  if ( position<1||position>9)
  {
    print ('invalid move!!!\n. please enter a number between 1 - 9.');
      return false;
  }

int row = (position-1)~/3;
int col= (position-1)%3;

if(BOARD[row][col]!=' ')
{
  print ('Cell already chosen!!!!!! Please choose an empty cell.');
      return false;
}
BOARD [row][col] = Player1;
return true;
}
bool Win()
// Check rows and columns(to win)
{
for(int counter=0;counter<3;++counter)
{
  if(BOARD[counter][0]==Player1&&BOARD[counter][1]==Player1&&BOARD[counter][2]==Player1)
  {
    return true; // Row win
  }
if (BOARD[0][counter] == Player1 &&BOARD[1][counter] == Player1 &&BOARD[2][counter] == Player1)
{
    return true; // Col win
}
}

// Check diagonal
if (BOARD[0][0] == Player1 &&BOARD[1][1] == Player1&&BOARD[2][2] == Player1)
 {
  return true; // Diagonal win
  
 }
 if (BOARD[0][2] ==Player1&&BOARD[1][1]==Player1&&BOARD[2][0]== Player1) 
 {
  return true; //Diagonal win
 }

  return false;
}

bool testdraw() 
{
  for (var row in BOARD) 
  {
      if (row.contains(' ')) 
      {
        return false; //game not a draw
      }
    }
    return true; // game is a draw
    
}

void changeplayer()
{
  Player1=(Player1=='X')?'O':'X';
}

void play()
 {
    print('Welcome to Tic Tac Toe! \n');
    Board();

    do {
      int position;
      do
       {
        print('\nPlayer $Player1\n Enter your move (1-9): ');
        try 
        {
          position = int.parse(stdin.readLineSync()!);
        } 
        catch (e)
        {
          position = 0;
        }
      } while (!makemove(position));

      Board();

      if (Win()) 
      {
        print('Player $Player1 win!!!!');
        break;
      }

      if (testdraw())
       {
        print('The game is a draw!!!');
        break;
      }

      changeplayer();
    } while (true);
    print('\nDo you want to play again?(Yes=y/No=n)');
    String playAgain = stdin.readLineSync()!.toLowerCase();
    if (playAgain == 'y') 
    {
      resetGame();
      play();
    } else 
    {
      print('Thanks for playing!');
    }
  }

  void resetGame() {
    BOARD = List.generate(3, (_) => List.filled(3, ' '));
    Player1 = 'X';
  }
}
void main()
 {
  XO game = XO();
  game.play();
}
