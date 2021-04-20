#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

    //����� �������� ����������
    double a, b; //����������, � ������� �������� �����
    char c, d, e; // � 'c' �������� ����������� ��������; � 'd' � 'e' �������� �������� 'y/n'(yes/no), ������������ � ����� while � ��������� switch-case
    long int f = 1;
    int size, op_choice; // � size �������� ������ ��������, op_choice - ����� ���� �������� (��� ��������� ��� �������)
    float *vector1, *vector2;
    float vector_res = 0; // ����� �������� ��������� �������� ��� ���������
    char vect_op, input[40], output[40]; // ����� �������� �������� ��� ��������� � �������� ����� � �����/������



    //����, ������������ ��� ���� ����� ���� ����������� ���������� ������ � ���������� ����� ���������� ������ ����������
    do{
    	printf("������� ��� �������� ����� \n");
    	scanf(" %s", &input);
    	printf("������� ��� �����, � ������� ����� ������� ��������� ������ ���������\n");
    	scanf(" %s", &output);

    	FILE *in, *out;
    	in = fopen(input, "r");
    	out = fopen(output, "w");

    	//��� ����� ������ ��� ����, ����� ������� �� ������ �� ����� ������ �����������(������ � ������� ��� ���������)
        fprintf(out, "�������� � ��� ����� �������� ����������� (0 - ������ � ���������, 1 - ������ � �������)\n");
        fscanf(in, " %i", &op_choice);

        switch(op_choice)
        {
        	case(0):
				//����� ����������� ������� � ���, ��� � ���� �������
				fprintf(out, "�������� ������ ������� \n");
				fscanf(in, " %i", &size);
				vector1 = malloc(size*sizeof(int));
				vector2 = malloc(size*sizeof(int));

				fprintf(out, "��������� ������ ������ \n");
				for(int i = 0; i < size; i++) fscanf(in, "%f",&vector1[i]);

				fprintf(out, "��������� ������ ������ \n");
				for(int i = 0; i < size; i++) fscanf(in, "%f",&vector2[i]);

				fprintf(out, "�������� �������� (+, -, *) \n");
				fscanf(in, " %c", &vect_op);

				//����� ���������� �������� ��� ���������
				switch(vect_op)
				{
					case('+'):
						for(int i = 0; i < size; i++) fprintf(out, "%f ", vector1[i] + vector2[i]);
						break;

					case('-'):
						for(int i = 0; i < size; i++) fprintf(out, "%f ", vector1[i] - vector2[i]);
						break;

					case('*'):
						for(int i = 0; i < size ;i++){
							vector_res += vector1[i] * vector2[i];
						}
						fprintf(out, "%f \n", vector_res);
						break;
					default:
					fprintf(out, "������! �������� �� ������� ��� �� ���������� \n");
					free(vector1);
					free(vector2);


				} break;
        case(1):

            //����� ������������ ������ � ����������
            fprintf(out, "������� ������ �����:\n");
            fscanf(in," %lf", &a);

            /*� ���� ������� ����������� ����������� ������������ ��� �����, ���� ����������� ��������� ��� ���������� ������,
            ���� �� �������� ������*/
            fprintf(out, "����� �� �������������� ��� ����� ��� �������(y/n)?\n");
            fscanf(in, " %c", &d);
            switch(d)
            {
                case 'y':
                    fprintf(out, "�������� ������ �����:\n");
                    fscanf(in, " %lf", &b);
                    break;
                case 'n':
                    fprintf(out, "�������� ������ ���������� ���������� � ����������� �����!\n");
                    break;
            }
            fprintf(out, "�������� ��������(+, -, *, /, !, ^, s(������ ����������)):\n"); // s �� squre root(sqrt) - ������ ����������
            fscanf(in, " %c", &c);



            //����� ���������� �������� ����������
            switch(c)
            {
                case '+':
                    fprintf(out, "%lf + %lf = %lf",a, b, a+b);
                    break;
                case '-':
                    fprintf(out, "%lf - %lf = %lf",a, b,  a-b);
                    break;
                case '*':
                    fprintf(out, "%lf * %lf = %lf",a, b, a*b);
                    break;
                case '/':
                    fprintf(out, "%lf/%lf = %lf",a, b, a/b);
                    break;
                case '!':
                    if (a > 0)
        	    {
        	        for(int i=1;i<=a;i=i+1)
        	        {
            	        f = f * i;

        	        } fprintf(out, "%li! = %li", a, f);
        	    }
        	        else if (a == 0)
        	        {
        	        	fprintf(out, "0! = 1");
        	        }
        	        else
        	        {
        	            fprintf(out, "������! ����� ������ ���� �� ������ 0\n");
        	        }
                break;
        	    case '^':
        	        fprintf(out, "%lf ^ %lf = %lf", a , b, pow(a, b));
        	        break;
        	    case 's':
        	        fprintf(out, "%lf ^ %lf = %lf", a, b, sqrt(a));
        	        break;
        	    default:
        	    fprintf(out, "������! �������� �� ������� ���� �� ����������. ������������� �����������\n");
        }
        	    fclose(in);
        	    fclose(out);



        break;
        default:
        fprintf(out, "������! �������� �� ������� ��� �� ����������\n");
        }
        printf("\n������� ���������� ����������(y/n)?\n");
		scanf(" %c", &e);

    } while(e == 'y');
    return 0;
}
