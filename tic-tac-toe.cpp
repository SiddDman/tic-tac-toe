#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define vi vector<int>

using namespace std;

const int N = 1e9 + 7;

class AiMove
{
public:
    int row, col, score;
    AiMove(int score)
    {
        this->score = score;
    }
    AiMove(int x, int y, int score)
    {
        this->row = x;
        this->col = y;
        this->score = score;
    }
};

bool isSlotValid(vector<vector<char>> &board, int row, int col)
{
    return board[row][col] >= '1' && board[row][col] <= '9';
}

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
    int slot;
    cin >> slot;

    int row = slot / 3, col = slot % 3 - 1;
    if (slot % 3 == 0)
    {
        row = slot / 3 - 1;
        col = 2;
    }
    if (slot >= 1 && slot <= 9 && isSlotValid(board, row, col))
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

    return false;
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

AiMove aiMove(vector<vector<char>> &board, char &aiMarker, char &playerMarker, bool isAi)
{
    // Base case : Check for win
    if (checkWinner(board))
    {
        return isAi ? AiMove(10) : AiMove(-10);
    }

    bool movesLeft = false;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (isSlotValid(board, i, j))
            {
                movesLeft = true;
                break;
            }
    if (!movesLeft)
        return AiMove(0);

    vector<AiMove> moves;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (isSlotValid(board, i, j))
            {
                char temp = board[i][j];
                AiMove move(i, j, 0);
                board[i][j] = isAi ? aiMarker : playerMarker;
                if (isAi == true)
                    move.score += aiMove(board, aiMarker, playerMarker, !isAi).score;
                else
                    move.score += aiMove(board, aiMarker, playerMarker, isAi).score;

                // backtracking
                board[i][j] = temp;
                moves.push_back(move);
            }

    int bestMove;
    if (isAi)
    {
        int bestScore = INT_MIN;
        for (int i = 0; i < moves.size(); i++)
            if (moves[i].score > bestScore)
            {
                bestMove = i;
                bestScore = moves[i].score;
            }
        cout << "AI best score " << moves[bestMove].score << endl;
    }
    else
    {
        int bestScore = INT_MAX;
        for (int i = 0; i < moves.size(); i++)
            if (moves[i].score < bestScore)
            {
                bestMove = i;
                bestScore = moves[i].score;
            }
        cout << "Player best move " << moves[bestMove].row << " " << moves[bestMove].col << endl;
        cout << "Player best score " << moves[bestMove].score << endl;
    }
    return moves[bestMove];
}

void playerMove(vector<vector<char>> &board, char playerMarker)
{
    int slot = getSlot(board);
    placeMarker(slot, playerMarker, board);
    drawBoard(board);
}

void singlePlayer(vector<vector<char>> &board)
{
    cout << "Single Player Mode" << endl;
    char player_marker, ai_marker = 'O';

    cout << "Choose O or X : ";
    cin >> player_marker;

    if (player_marker == 'o' || player_marker == 'O' || player_marker == '0')
    {
        player_marker = 'O';
        ai_marker = 'X';
    }
    else
        player_marker = 'X';

    cout << "Player : " << player_marker << endl;
    cout << "Computer: " << ai_marker << endl;
    cout << "Enter the key corresponding to the number in the board to enter your move" << endl
         << endl;
    cout << "Game Started" << endl;

    int player = 1, ai_player = 2;
    for (int i = 0; i < 9; i++)
    {
        bool isAi = true;
        if (i & 1)
        {
            AiMove bestMove = aiMove(board, ai_marker, player_marker, isAi);
            board[bestMove.row][bestMove.col] = ai_marker;
        }
        else
        {
            cout << "Your turn" << endl;
            cout << "Enter the slot you want to place your marker: ";
            playerMove(board, player_marker);
        }

        if (checkWinner(board))
        {
            if (i & 1)
            {
                cout << "Computer wins!!!!" << endl;
                cout << "Better Luck Next Time!!!" << endl;
                return;
            }
            else
            {
                cout << "Player wins!!!!" << endl;
                cout << "Congratulations!!!" << endl;
                return;
            }
        }
    }
    cout << "It's a Tie !!!!" << endl;
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