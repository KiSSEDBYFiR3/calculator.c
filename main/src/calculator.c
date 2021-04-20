//Версия калькулятора, работающая с файлами. 
//Для работы с программой во входной файл неободимо передать значения, указанные в пояснениях к коду.
//Пример: "0 2 1 2 3 4 +"- происходит сложение двух векторов размером 2.  

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

    //Здесь хранятся переменные
    double a, b; //Переменные, в которых хрянятся числа
    char c, d, e; // В 'c' хранится обознаечние операции; в 'd' и 'e' хрянятся значения 'y/n'(yes/no), используемые в цикле while и операторе switch-case
    long int f = 1;
    int size, op_choice; // В size хранится размер векторов, op_choice - выбор типа операций (над векторами или числами)
    float *vector1, *vector2;
    float vector_res = 0; // Здесь хранится результат операций над векторами
    char vect_op, input[40], output[40]; // Здесь хранятся операции над векторами и названия файло в ввода/вывода



    //Цикл, существующий для того чтобы была возможность продолжить работу с программой после завершения первых вычислений
    do{
	//Задаем название входного и выходного файлов 
    	printf("Введите имя входного файла \n");                                            
    	scanf(" %s", &input);
    	printf("Введите имя файла, в который будет выведен результат работы программы\n");
    	scanf(" %s", &output);

    	FILE *in, *out;
    	in = fopen(input, "r");
    	out = fopen(output, "w");

    	//Эта часть служит для того, чтобы выбрать по какому из путей пойдет калькулятор(работа с числами или векторами)
        fprintf(out, "Выберите с чем будет работать калькулятор (0 - работа с векторами, 1 - работа с числами)\n");
        fscanf(in, " %i", &op_choice);

        switch(op_choice)
        {
	case(0):
		//Здесь назначаются вектора и все, что с этим связано
		fprintf(out, "Выберите размер вектора \n");
		fscanf(in, " %i", &size);
		vector1 = malloc(size*sizeof(int));
		vector2 = malloc(size*sizeof(int));

		fprintf(out, "Назначьте первый вектор \n");
		for(int i = 0; i < size; i++) fscanf(in, "%f",&vector1[i]);

		fprintf(out, "Назначьте второй вектор \n");
		for(int i = 0; i < size; i++) fscanf(in, "%f",&vector2[i]);

		fprintf(out, "Выберите операцию (+, -, *) \n");
		fscanf(in, " %c", &vect_op);

		//Здесь происходят операции над векторами
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
			fprintf(out, "Ошибка! Операция не выбрана или не существует \n");
			free(vector1);
			free(vector2);
		} break;
        case(1):

            //Здесь записываются данные в переменные
            fprintf(out, "Введите первое число:\n");
            fscanf(in," %lf", &a);

            /*В этом участке отключается возможность использовать два числа, если вычисляется факториал или квадратный корень,
            дабы не занимать память*/
            fprintf(out, "Будут ли использоваться два числа для расчета(y/n)?\n");
            fscanf(in, " %c", &d);
            switch(d)
            {
                case 'y':
                    fprintf(out, "Выберите второе число:\n");
                    fscanf(in, " %lf", &b);
                    break;
                case 'n':
                    fprintf(out, "Доступно только вычисление факториала и квадратного корня!\n");
                    break;
            }
            fprintf(out, "Выберите операцию(+, -, *, /, !, ^, s(корень квадратный)):\n"); // s от squre root(sqrt) - корень квадратный
            fscanf(in, " %c", &c);



            //Здесь происходят операции вычисления
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
        	            fprintf(out, "Ошибка! Число должно быть не меньше 0\n");
        	        }
                break;
        	    case '^':
        	        fprintf(out, "%lf ^ %lf = %lf", a , b, pow(a, b));
        	        break;
        	    case 's':
        	        fprintf(out, "%lf ^ %lf = %lf", a, b, sqrt(a));
        	        break;
        	    default:
        	    fprintf(out, "Ошибка! Операция не выбрана либо не существует. Перезапустите калькулятор\n");
        }
	    fclose(in);
	    fclose(out);
        break;
        default:
        fprintf(out, "Ошибка! Операция не выбрана или не существует\n");
        }
        printf("\nЖелаете продолжить вычисления(y/n)?\n");
		scanf(" %c", &e);
    } while(e == 'y');
    return 0;
}
