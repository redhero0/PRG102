#include <stdio.h>

/**
 * converte_temperatura: converte uma temperatura em fahrenheit para uma temperatura em celsius
 * @param float temp_f
 * @return ((temp_f-32)*5)/9
 */
float converte_temperatura(float temp_f)
{
    return ((temp_f-32)*5)/9;
}
int main()
{
    printf("%.2f\n", converte_temperatura(77.2));
}