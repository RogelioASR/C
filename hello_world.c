 #include <stdio.h>
 main()
 {
     printf("hello, world\n\n");

 float fahr, celsius;
 #define LOWER 0
 #define UPPER 300
 #define STEP 20
 fahr = 0;

    printf ("Farenheit\tCelsius\n");

 while (fahr <= UPPER) {
    celsius = (5/9.0) * (fahr-32.0);
        printf("%3.0f\t\t %4.1f\n", fahr, celsius);
        fahr = fahr + STEP;
 }
    printf("\n\n");

 for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP) {
    printf("%3.0f \t\t %5.1f\n", fahr, (5.0/9.0)*(fahr-32));
 }

}
