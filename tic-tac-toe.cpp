#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define vi vector<int>

using namespace std;

const int N = 1e9 + 7;

bool isSlotValid(vector<vector<char>> &board, int row, int col)
{
    return board[row][col] >= '1' && board[row][col] <= '9';
}

vector<vector<char>> createBoard()
{
    vector<vector<char>> board(3, vector<char>(3, ' '));
    int cnt = 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = '0' + cnt++;
    return board;
}

void drawBoard(vector<vector<char>> &board)
{

    cout << " +---+---+---+" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << " | ";
        for (int j = 0; j < 3; j++)
            cout << board[i][j] << " | ";
        cout << endl;
        cout << " +---+---+---+" << endl;
    }
}

int getSlot(vector<vector<char>> &board)
{
    char ip;

    while (true)
    {
        cin >> ip;
        if (ip < '1' || ip > '9')
        {
            cout << "This is an invalid slot, please enter a slot between 1-9: " << endl;
            continue;
        }

        int slot = ip - '0';
        int row = slot / 3, col = slot % 3 - 1;
        if (slot % 3 == 0)
        {
            row = slot / 3 - 1;
            col = 2;
        }

        if (board[row][col] < '1' || board[row][col] > '9')
        {
            cout << "This is already occupied slot, please enter another slot : " << endl;
            continue;
        }

        return slot;
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

    return false;
}

void swapPlayerAndMarker(int &player, char &marker)
{
    if (player == 1)
        player = 0;
    else
        player = 1;
}

void twoPlayer(vector<vector<char>> &board)
{
    cout << "Two Player Mode" << endl
         << endl;

    char player_1_marker, player_2_marker = 'O';
    cout << "Player 1 choose O or X : ";
    cin >> player_1_marker;

    if (player_1_marker == 'o' || player_1_marker == 'O' || player_1_marker == '0')
    {
        player_1_marker = 'O';
        player_2_marker = 'X';
    }
    else
        player_1_marker = 'X';

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

bool isBoardFull(vector<vector<char>> &board)
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] >= '1' && board[i][j] <= '9')
                return false;
    return true;
}

int minimax(vector<vector<char>> &board, bool isMaximizing, char &ai_marker, char &player_marker, int depth)
{
    if (checkWinner(board))
        return isMaximizing ? -10 : 10;
    if (isBoardFull(board))
        return 0;

    int bestScore = isMaximizing ? -1e9 : 1e9; // AI is maximising the score and human is minimizing
    char currentMarker = isMaximizing ? ai_marker : player_marker;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] >= '1' && board[i][j] <= '9')
            {
                char backup = board[i][j];
                board[i][j] = currentMarker;

                int score = minimax(board, !isMaximizing, ai_marker, player_marker, depth + 1);

                bestScore = isMaximizing ? max(score, bestScore) : min(score, bestScore);

                board[i][j] = backup; // backtrack
            }
    return bestScore;
}

int findBestMove(vector<vector<char>> &board, char &ai_marker, char &player_marker)
{
    int bestScore = -1e9;
    int bestMove = -1;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] >= '1' && board[i][j] <= '9') // if spot available
            {
                char temp = board[i][j];
                board[i][j] = ai_marker;

                int score = minimax(board, false, ai_marker, player_marker, 0);

                board[i][j] = temp; // backtrack

                if (score > bestScore)
                {
                    bestScore = score;
                    bestMove = (i * 3) + j + 1;
                }
            }
    return bestMove;
}

void singlePlayer(vector<vector<char>> &board)
{
    cout << "Single Player Mode (You vs A.I)" << endl
         << endl;

    int player = 1;

    char marker, ai_marker = 'O';

    cout << "Choose O or X : ";
    cin >> marker;

    if (marker == 'o' || marker == 'O' || marker == '0')
    {
        marker = 'O';
        ai_marker = 'X';
    }
    else
        marker = 'X';

    cout << "Select turn order:" << endl;
    cout << "[1] Player makes the first move" << endl;
    cout << "[2] Computer makes the first move" << endl;
    int firstMove;
    cin >> firstMove;

    if (firstMove == 1)
        player = 1;
    else
        player = 0;

    for (int i = 0; i < 9; i++)
    {
        if (player & 1)
        {
            cout << "Your turn" << endl;
            cout << "Enter the slot you want to place your marker: ";
            int slot = getSlot(board);
            placeMarker(slot, marker, board);
        }
        else
        {
            cout << "Computer's turn" << endl;
            int bestMove = findBestMove(board, ai_marker, marker);
            placeMarker(bestMove, ai_marker, board);
            cout << "Computer placed marker at slot " << bestMove << endl;
        }
        drawBoard(board);
        if (checkWinner(board))
        {
            if (player & 1)
                cout << "You win!!!!" << endl;
            else
                cout << "Computer wins!!" << endl
                     << "Better Luck Next Time!!";
            return;
        }
        player = !player;
    }
    cout << "It's a Tie !!!!" << endl;
}

void game()
{
    int gameMode;

    cout << "Select game mode :" << endl;
    cout << "[1] Single Player vs A.I" << endl;
    cout << "[2] Multiplayer" << endl;
    cout << "[3] Exit" << endl;
    cin >> gameMode;
    if (gameMode == 3)
        return;

    vector<vector<char>> board = createBoard();
    drawBoard(board);

    if (gameMode == 1)
        singlePlayer(board);
    else if (gameMode == 2)
        twoPlayer(board);
}

int main()
{
    game();

    return 0;
}