#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable: 4996)

// 基本的な算術演算
double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) {
    if (b != 0) {
        return a / b;
    }
    else {
        printf("エラー: 0で割ることはできません。\n");
        return NAN; // Not a Number を返す
    }
}

// 数学関数
double sine(double a) { return sin(a); }
double cosine(double a) { return cos(a); }
double tangent(double a) { return tan(a); }
double logarithm(double a) {
    if (a > 0) {
        return log(a); // 自然対数
    }
    else {
        printf("エラー: 正でない値の対数は定義されていません。\n");
        return NAN;
    }
}
double power(double base, double exp) { return pow(base, exp); }
double square_root(double a) {
    if (a >= 0) {
        return sqrt(a);
    }
    else {
        printf("エラー: 負の数の平方根は実数ではありません。\n");
        return NAN;
    }
}

int main() {
    int choice;
    double num1, num2, result;

    printf("関数電卓\n");
    printf("--------------------\n");
    printf("1. 足し算 (+)\n");
    printf("2. 引き算 (-)\n");
    printf("3. 掛け算 (*)\n");
    printf("4. 割り算 (/)\n");
    printf("5. サイン (sin)\n");
    printf("6. コサイン (cos)\n");
    printf("7. タンジェント (tan)\n");
    printf("8. 自然対数 (ln)\n");
    printf("9. べき乗 (pow)\n");
    printf("10. 平方根 (sqrt)\n");
    printf("0. 終了\n");
    printf("--------------------\n");

    while (1) {
        printf("実行する操作を選んでください (番号を入力): ");
        if (scanf("%d", &choice) != 1) {
            printf("無効な入力です。\n");
            // バッファクリア
            while (getchar() != '\n');
            continue;
        }

        if (choice == 0) {
            printf("電卓を終了します。\n");
            break;
        }

        switch (choice) {
        case 1: // 足し算
        case 2: // 引き算
        case 3: // 掛け算
        case 4: // 割り算
            printf("2つの数値を入力してください: ");
            if (scanf("%lf %lf", &num1, &num2) != 2) {
                printf("無効な入力です。\n");
                while (getchar() != '\n');
                continue;
            }
            switch (choice) {
            case 1: result = add(num1, num2); break;
            case 2: result = subtract(num1, num2); break;
            case 3: result = multiply(num1, num2); break;
            case 4: result = divide(num1, num2); break;
            }
            if (!isnan(result)) {
                printf("結果: %.2lf\n", result);
            }
            break;
        case 5: // サイン
        case 6: // コサイン
        case 7: // タンジェント
        case 8: // 自然対数
        case 9: // べき乗
        case 10: // 平方根
            if (choice == 9) {
                printf("底と指数を入力してください: ");
                if (scanf("%lf %lf", &num1, &num2) != 2) {
                    printf("無効な入力です。\n");
                    while (getchar() != '\n');
                    continue;
                }
                result = power(num1, num2);
                if (!isnan(result)) {
                    printf("結果: %.2lf\n", result);
                }
            }
            else {
                printf("数値を入力してください: ");
                if (scanf("%lf", &num1) != 1) {
                    printf("無効な入力です。\n");
                    while (getchar() != '\n');
                    continue;
                }
                switch (choice) {
                case 5: result = sine(num1); break;
                case 6: result = cosine(num1); break;
                case 7: result = tangent(num1); break;
                case 8: result = logarithm(num1); break;
                case 10: result = square_root(num1); break;
                }
                if (!isnan(result)) {
                    printf("結果: %.2lf\n", result);
                }
            }
            break;
        default:
            printf("無効な操作です。\n");
        }
        printf("\n");
    }

    return 0;
}