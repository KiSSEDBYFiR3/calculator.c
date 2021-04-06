#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    
    //Здесь хранятся переменные
    double a, b; //Переменные, в которых хрянятся числа
    char c, d, e, l; // В 'c' хранится обознаечние операции; в 'd' и 'e' хрянятся значения 'y/n'(yes/no), используемые в цикле while и операторе switch-case, в l значения для цилка с векторами
    long int f = 1;
    int size, op_choice; // В size хранится размер векторов, op_choice - выбор типа операций (над векторами или числами)
    float *vector1, *vector2;
    float vector_res = 0; // Здесь хранится результат операций над векторами
    char vect_op; // Здесь хранятся операции над векторами
    
    //Цикл, существующий для того чтобы была возможность продолжить работу с программой после завершения первых вычислений
    do{
        //Эта часть служит для того, чтобы выбрать по какому из путей пойдет калькулятор(работа с числами или векторами)
        printf("Выберите с чем будет работать калькулятор (0 - работа с векторами, 1 - работа с числами)\n");
        scanf(" %i", &op_choice);
        if(op_choice == 0)
        {
            //Здесь назначаются вектора и все, что с этим связано
            printf("Выберите размер вектора \n");
            scanf("%i", &size);
            vector1 = malloc(size*sizeof(int));
            vector2 = malloc(size*sizeof(int));
            
            printf("Назначьте первый вектор \n");
            for(int i = 0; i < size; i++) scanf("%f",&vector1[i]);
            
            printf("Назначьте второй вектор \n");
            for(int i = 0; i < size; i++) scanf("%f",&vector2[i]);
            
            printf("Выберите операцию (+, -, *) \n");
            scanf(" %c", &vect_op);
            
            //Здесь происходят операции над векторами
            switch(vect_op)
            {
                case('+'):
    				for(int i = 0; i < size; i++) printf("%f ",vector1[i] + vector2[i]);
    				break;
			
			    case('-'):
    				for(int i = 0; i < size; i++) printf("%f ",vector1[i] + vector2[i]);
    				break;
			
			    case('*'):
			        for(int i = 0; i < size ;i++){
					    vector_res += vector1[i] * vector2[i];
				    }
			        printf("%f \n", vector_res);
				    break;
				default:
			    printf("Ошибка! Операция не выбрана или не существует \n");
			    free(vector1);
			    free(vector2);
        		printf("\nЖелаете продолжить вычисления(y/n)?\n");
                scanf(" %c", &e);
            }
        }
        else
        {
            //Здесь записываются данные в переменные
            printf("Введите первое число:\n");
            scanf(" %lf", &a);
    
            /*В этом участке отключается возможность использовать два числа, если вычисляется факториал или квадратный корень,
            дабы не занимать память*/
            printf("Будут ли использоваться два числа для расчета(y/n)?\n");
            scanf(" %c", &d);
            switch(d)
            {   
                case 'y':
                    printf("Выберите второе число:\n");
                    scanf(" %lf", &b);
                    break;
                case 'n':
                    printf("Доступно только вычисление факториала и квадратного корня!\n");
                    break;
            }
            printf("Выберите операцию(+, -, *, /, !, ^, s(корень квадратный)):\n"); // s от squre root(sqrt) - корень квадратный
            scanf(" %c", &c);
            
        
        
            //Здесь происходят операции вычисления
            switch(c)
            {
                case '+':
                    printf("Результат: %lf", a+b); 
                    break;
                case '-':
                    printf("Результат: %lf", a-b); 
                    break;
                case '*':
                    printf("Результат: %lf", a*b); 
                    break;
                case '/':
                    printf("Результат: %lf", a/b); 
                    break;
                case '!':
                    if (a > 0)
        	    {
        	        for(int i=1;i<=a;i=i+1) 
        	        {
            	        f = f * i;
        
        	        } printf("%li", f);
        	    }
        	        else if (a == 0)
        	        {
        	        	printf("Результат: 1");
        	        }
        	        else
        	        {
        	            printf("Ошибка! Число должно быть не меньше 0\n");
        	        }
                break;
        	    case '^':
        	        printf("Результат: %lf", pow(a, b));
        	        break;
        	    case 's':
        	        printf("Результат: %lf", sqrt(a));
        	        break;
        	    default:
        	    printf("Ошибка! Операция не выбрана либо не существует. Перезапустите калькулятор\n");
        }
        	    
        	    printf("\nЖелаете продолжить вычисления(y/n)?\n");
                scanf(" %c", &e);
        }
        
    } while(e == 'y');
    
    return 0;    
}
