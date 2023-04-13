/*	
Escreva um programa em C utilizando EH (Estrutura Heterogênea) para o cálculo do salário líquido de N funcionários de uma empresa. Nessa empresa, sabe-se que: 

* Salário bruto = salário por hora * número de horas trabalhadas, adicionado de R$198.50 por dependente.

* Desconto de INSS =  
    * 10% do salário bruto se este for <= a R$ 1350.00.
    * R$300.00 caso contrário.

* Desconto de IR = 
    * Isento se (salário bruto - INSS) for < que R$ 1350.00 11% do saláro bruto, se (salário bruto - INSS) for <= a R$ 5000.00.
    * 20% do salário bruto, para os demais casos.

Para cada funcionario, informe o nome, salario bruto, descontos de INSS, IR e salario liquido.
*/




#include <stdio.h>
#include <stdlib.h>

struct staff {
    char name[50];
    float salaryPerHour, grossSalary, netSalary, inss, iR;  //Inss is similar to SSA, while IR is similar to income tax in the USA.
    int numHours, numDepen;
};

void calculus(struct staff *s, int numEmployees){
    for(int i = 0; i < numEmployees; i++){
        s[i].grossSalary = s[i].salaryPerHour * s[i].numHours + 198.50 * s[i].numDepen;
        if (s[i].grossSalary <= 1350.00){
            s[i].inss = 0.10 * s[i].grossSalary;
        } else {
            s[i].inss = 300.00;
        }
        float baseSalary = s[i].grossSalary - s[i].inss;
        if (baseSalary < 1350.00) {
            s[i].iR = 0.00;
        } else if (baseSalary <= 5000.00) {
            s[i].iR = 0.11 * s[i].grossSalary;
        } else {
            s[i].iR = 0.20 * s[i].grossSalary;
        }
        s[i].netSalary = s[i].grossSalary - s[i].inss - s[i].iR;
    }
}

int main(int numEmployees) {
    puts("Salary Calculation:");
    puts("Enter the number of employees: ");
    scanf("%d", &numEmployees);
    struct staff *s = malloc(numEmployees * sizeof(struct staff));
    
    for(int i = 0; i < numEmployees; i++) {
        printf("-->Employee %d<--\n", i+1);
        puts("Name: ");
        scanf("%s", s[i].name);
        puts("Salary per Hour: ");
        scanf("%f", &s[i].salaryPerHour);
        puts("Number of hours worked: ");
        scanf("%d", &s[i].numHours);
        puts("Number of Dependents: ");
        scanf("%d", &s[i].numDepen);
    }

    calculus(s, numEmployees);

    for (int i = 0; i < numEmployees; i++) {
        printf("Name: %s\n", s[i].name);
        printf("Gross Salary: R$%.2f\n", s[i].grossSalary);
        printf("INSS: R$%.2f\n", s[i].inss);
        printf("IR: R$%.2f\n", s[i].iR);
        printf("Net Salary: R$%.2f\n", s[i].netSalary);
    }

    free(s);
    return(0);
}











/* printf("Funcionários:\n");
    for (int i = 0; i < numEmployees; i++) {
    printf("%s\n", s[i].name);
    }   */ 
