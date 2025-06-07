#include <stdio.h>

int width = 80;
int height = 25;
int paddle_size = 3;
int win_score = 21;

// Положение мяча и его направление
int ball_x;
int ball_y;
int ball_dx;
int ball_dy;

// Положение ракеток (по вертикали)
int left_paddle_y;
int right_paddle_y;

// Счёт
int score_left = 0;
int score_right = 0;

void clear_screen() {
    // printf("\033[H\033[J"); 
}

void draw_game_line(int y) {
    for (int x = 1; x < width; ++x) {
        // условие отрисовки границы по середине
        if (x == width / 2 && y % 2 == 0)
            printf("|");
        else if (x == 1 && y >= left_paddle_y && y < left_paddle_y + paddle_size)
            printf("|");
        else if (x == width - 2 && y >= right_paddle_y && y < right_paddle_y + paddle_size)
            printf("|");
        else if (x == ball_x && y == ball_y)
            printf("O");
        else
            printf(" ");
    }
    printf("\n");
}

void draw_field() {
    clear_screen();
    printf("Score: Left [%d] - Right [%d]\n", score_left, score_right);
    for (int y = 0; y < height; ++y) {
        draw_game_line(y);
    }
}

int move_paddle(int paddle_y, int direction) {
    int new_y = paddle_y + direction;
    if (new_y >= 0 && new_y + paddle_size <= height)
        return new_y;
    else
        return paddle_y;
}

void update_ball() {
    int next_x = ball_x + ball_dx;
    int next_y = ball_y + ball_dy;

    if (next_y < 0 || next_y >= height) {
        ball_dy *= -1;
        return;
    }

    if (next_x == 1 && next_y >= left_paddle_y && next_y < left_paddle_y + paddle_size) {
        ball_dx *= -1;
        return;
    }

    if (next_x == width - 2 && next_y >= right_paddle_y && next_y < right_paddle_y + paddle_size) {
        ball_dx *= -1;
        return;
    }

    if (next_x < 0) {
        ++score_right;
        ball_x = width / 2;
        ball_y = height / 2;
        ball_dx = 1;
        ball_dy = 1;
        return;
    }

    if (next_x >= width) {
        ++score_left;
        ball_x = width / 2;
        ball_y = height / 2;
        ball_dx = -1;
        ball_dy = -1;
        return;
    }

    ball_x += ball_dx;
    ball_y += ball_dy;
}

void game_loop() {
    char input;

    ball_x = width / 2;
    ball_y = height / 2;
    ball_dx = 1;
    ball_dy = 1;
    left_paddle_y = height / 2 - paddle_size / 2;
    right_paddle_y = height / 2 - paddle_size / 2;

    while (score_left < win_score && score_right < win_score) {
        draw_field();
       
        input = getchar();
        while (getchar() != '\n'); 

        if (input == 'a' || input == 'A') 
            left_paddle_y = move_paddle(left_paddle_y, -1);
        else if (input == 'z' || input == 'Z') 
            left_paddle_y = move_paddle(left_paddle_y, 1);
        else if (input == 'k' || input == 'K') 
            right_paddle_y = move_paddle(right_paddle_y, -1);
        else if (input == 'm' || input == 'M') 
            right_paddle_y = move_paddle(right_paddle_y, 1);
        else if (input == ' ') 
            update_ball();
    }

    draw_field();
    if (score_left >= win_score)
        printf("Left Player Wins!\n");
    else
        printf("Right Player Wins!\n");
}

int main() {
    game_loop();
    return 0;
}
