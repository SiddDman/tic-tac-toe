#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define vi vector<int>

using namespace std;

const int N = 1e9 + 7;

vector<vector<char>> createBoard()
{
    vector<vector<char>> board(3, vector<char>(3, '0'));
    int cnt = 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = '0' + cnt++;
    return board;
}

void drawBoard(vector<vector<char>> &board)
{

    cout << "---------------" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << " | ";
        for (int j = 0; j < 3; j++)
            cout << board[i][j] << " | ";
        cout << endl;
        cout << "---------------" << endl;
    }
}

int getSlot(vector<vector<char>> &board)
{
    int slot;

    cin >> slot;

    int row = slot / 3, col = slot % 3 - 1;
    if (slot % 3 == 0)
    {
        row = slot / 3 - 1;
        col = 2;
    }
    if (slot >= 1 && slot <= 9 && board[row][col] >= '1' && board[row][col] <= '9')
        return slot;
    if (slot * 1LL < 1 || slot * 1LL > 9)
    {
        cout << "This is an invalid slot, please enter a slot between 1-9: ";
        getSlot(board);
    }
    else if (board[row][col] < '1' || board[row][col] > '9')
    {
        cout << "This is already occupied slot, please enter another slot : ";
        getSlot(board);
    }
}

void placeMarker(int slot, char marker, vector<vector<char>> &board)
{
    int row = slot / 3, col = slot % 3 - 1;
    if (slot % 3 == 0)
    {
        row = slot / 3 - 1;
        col = 2;
    }

    board[row][col] = marker;
}

bool checkWinner(vector<vector<char>> &board)
{
    // Row check
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
    // Column check
    for (int i = 0; i < 3; i++)
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;

    // Diagonal check
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;

    return 0;
}

void swapPlayerAndMarker(int &player, char &marker)
{
    if (player == 1)
        player = 2;
    else
        player = 1;
    if (marker == 'X')
        marker = 'O';
    else
        marker = 'X';
}

void twoPlayer(vector<vector<char>> &board)
{
    cout << "Two Player Mode" << endl
         << endl;

    char player_1_marker, player_2_marker = 'O';
    cout << "Player 1 choose O or X : ";
    cin >> player_1_marker;

    if (player_1_marker == 'o' || player_1_marker == 'O' || player_1_marker == '0')
        player_1_marker = 'O';
    else
        player_1_marker = 'X';

    if (player_1_marker == 'O')
        player_2_marker = 'X';

    cout << "Player 1: " << player_1_marker << endl;
    cout << "Player 2: " << player_2_marker << endl;

    int player = 1;
    char marker = player_1_marker;

    cout << "Enter the key corresponding to the number in the board to enter your move" << endl
         << endl;

    cout << "Game Started" << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << "Player " << player << "'s turn" << endl;
        cout << "Enter the slot you want to place your marker: ";
        int slot = getSlot(board);
        placeMarker(slot, marker, board);
        drawBoard(board);
        if (checkWinner(board))
        {
            cout << "Player " << player << " wins!!!!" << endl;
            cout << "Congratulations Player " << player << " !!!" << endl;
            return;
        }
        swapPlayerAndMarker(player, marker);
    }
    cout << "It's a Tie !!!!" << endl;
}

void singlePlayer(vector<vector<char>> &board)
{
    cout << "Single Player Mode" << endl;
    cout << "Enter the key corresponding to the number in the board to enter your move" << endl
         << endl;

    cout << "Choose O or X : ";
    char player_marker, ai_marker;
    if (player_marker == 'o' || player_marker == 'O' || player_marker == '0')
        player_marker = 'O';
    else
        player_marker = 'X';

    if (player_marker == 'O')
        ai_marker = 'X';

    cout << "Player : " << player_marker << endl;
    cout << "Computer: " << ai_marker << endl;
    return;
}

void game()
{
    int gameMode;

    cout << "Select game mode :" << endl;
    cout << "[1] Single Player vs A.I" << endl;
    cout << "[2] Multiplayer" << endl;
    cout << "[3] Exit" << endl;
    cin >> gameMode;

    vector<vector<char>> board = createBoard();
    drawBoard(board);
    if (gameMode == 1)
        singlePlayer(board);
    else if (gameMode == 2)
        twoPlayer(board);
    else
        return;
}

int main()
{
    game();

    return 0;
}