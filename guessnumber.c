#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char playAgain;
    do {
        int targetNumber;
        int guess;
        int attempts = 0;
        int maxAttempts = 10;

        // 乱数のシードを初期化
        srand(time(0));

        // 1から100までのランダムな数を生成
        targetNumber = rand() % 100 + 1;

        printf("1から100までの数を当ててください！\n");

        do {
            printf("予想した数を入力してください：");
            scanf("%d", &guess);

            // 入力された数とランダムに選ばれた数を比較
            if (guess > targetNumber) {
                printf("もっと小さい数です\n");
            } else if (guess < targetNumber) {
                printf("もっと大きい数です\n");
            }

            attempts++;
        } while (guess != targetNumber && attempts < maxAttempts);

        if (guess == targetNumber) {
            printf("おめでとうございます！正解です！\n");
            printf("あなたの試行回数：%d\n", attempts);
        } else {
            printf("残念ながら正解できませんでした。正解は %d でした。\n", targetNumber);
        }

        printf("もう一回プレイしますか？（y/n）：");
        scanf(" %c", &playAgain); // 注意：スペースを付けてバッファをクリア

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
