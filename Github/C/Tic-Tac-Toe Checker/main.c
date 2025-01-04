#include <stdbool.h>

enum game_state {
    NOT_FINISHED = -1, DRAW = 0, X_WON = 1, O_WON = 2
};

enum square { EMPTY = 0, X = 1, O = 2 };

enum game_state check_game_state(const enum square board[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == X) return X_WON;
            if (board[i][0] == O) return O_WON;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if (board[0][i] == X) return X_WON;
            if (board[0][i] == O) return O_WON;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == X) return X_WON;
        if (board[0][0] == O) return O_WON;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == X) return X_WON;
        if (board[0][2] == O) return O_WON;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY) return NOT_FINISHED;
        }
    }

    return DRAW;
}