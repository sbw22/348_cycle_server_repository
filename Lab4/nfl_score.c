#include <stdio.h>

int find_score_combos(int score) {
    // Print off every unique combination of scores, with possibles of scores being safety (2), field goal (3), touchdown (6), touchdown with extra point (7), and touchdown with 2 point conversion (8)
    int num_of_possible_safeties = score / 2;
    int num_of_possible_field_goals = score / 3;
    int num_of_possible_touchdowns = score / 6;
    int num_of_possible_touchdowns_with_extra_points = score / 7;
    int num_of_possible_touchdowns_with_two_point_conversions = score / 8;

    for (int i = 0; i <= num_of_possible_safeties; i++) {
        for (int j = 0; j <= num_of_possible_field_goals; j++) {
            for (int k = 0; k <= num_of_possible_touchdowns; k++) {
                for (int l = 0; l <= num_of_possible_touchdowns_with_extra_points; l++) {
                    for (int m = 0; m <= num_of_possible_touchdowns_with_two_point_conversions; m++) {
                        if (i * 2 + j * 3 + k * 6 + l * 7 + m * 8 == score) {
                            printf("%d safeties, %d field goals, %d 6-point touchdowns, %d 7-point touchdowns, %d 8-point touchdowns\n", i, j, k, l, m);
                            printf("Summed count of scores: %d\n\n", (i*2) + (j*3) + (k*6) + (l*7) + (m*8));
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score = 0;
    while (score <= 1) {
        printf("Please enter a score greater than 1: ");
        scanf("%d", &score);
    }
    printf("\n");


    find_score_combos(score);
}