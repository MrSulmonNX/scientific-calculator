#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable: 4996)

// ��{�I�ȎZ�p���Z
double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) {
    if (b != 0) {
        return a / b;
    }
    else {
        printf("�G���[: 0�Ŋ��邱�Ƃ͂ł��܂���B\n");
        return NAN; // Not a Number ��Ԃ�
    }
}

// ���w�֐�
double sine(double a) { return sin(a); }
double cosine(double a) { return cos(a); }
double tangent(double a) { return tan(a); }
double logarithm(double a) {
    if (a > 0) {
        return log(a); // ���R�ΐ�
    }
    else {
        printf("�G���[: ���łȂ��l�̑ΐ��͒�`����Ă��܂���B\n");
        return NAN;
    }
}
double power(double base, double exp) { return pow(base, exp); }
double square_root(double a) {
    if (a >= 0) {
        return sqrt(a);
    }
    else {
        printf("�G���[: ���̐��̕������͎����ł͂���܂���B\n");
        return NAN;
    }
}

int main() {
    int choice;
    double num1, num2, result;

    printf("�֐��d��\n");
    printf("--------------------\n");
    printf("1. �����Z (+)\n");
    printf("2. �����Z (-)\n");
    printf("3. �|���Z (*)\n");
    printf("4. ����Z (/)\n");
    printf("5. �T�C�� (sin)\n");
    printf("6. �R�T�C�� (cos)\n");
    printf("7. �^���W�F���g (tan)\n");
    printf("8. ���R�ΐ� (ln)\n");
    printf("9. �ׂ��� (pow)\n");
    printf("10. ������ (sqrt)\n");
    printf("0. �I��\n");
    printf("--------------------\n");

    while (1) {
        printf("���s���鑀���I��ł������� (�ԍ������): ");
        if (scanf("%d", &choice) != 1) {
            printf("�����ȓ��͂ł��B\n");
            // �o�b�t�@�N���A
            while (getchar() != '\n');
            continue;
        }

        if (choice == 0) {
            printf("�d����I�����܂��B\n");
            break;
        }

        switch (choice) {
        case 1: // �����Z
        case 2: // �����Z
        case 3: // �|���Z
        case 4: // ����Z
            printf("2�̐��l����͂��Ă�������: ");
            if (scanf("%lf %lf", &num1, &num2) != 2) {
                printf("�����ȓ��͂ł��B\n");
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
                printf("����: %.2lf\n", result);
            }
            break;
        case 5: // �T�C��
        case 6: // �R�T�C��
        case 7: // �^���W�F���g
        case 8: // ���R�ΐ�
        case 9: // �ׂ���
        case 10: // ������
            if (choice == 9) {
                printf("��Ǝw������͂��Ă�������: ");
                if (scanf("%lf %lf", &num1, &num2) != 2) {
                    printf("�����ȓ��͂ł��B\n");
                    while (getchar() != '\n');
                    continue;
                }
                result = power(num1, num2);
                if (!isnan(result)) {
                    printf("����: %.2lf\n", result);
                }
            }
            else {
                printf("���l����͂��Ă�������: ");
                if (scanf("%lf", &num1) != 1) {
                    printf("�����ȓ��͂ł��B\n");
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
                    printf("����: %.2lf\n", result);
                }
            }
            break;
        default:
            printf("�����ȑ���ł��B\n");
        }
        printf("\n");
    }

    return 0;
}