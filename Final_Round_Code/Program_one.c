//Carbon dating to find age of objects
#include <stdio.h>
#include <math.h>

/* 
 Function to compute age of object based on C-14 dating
 Arguments : Carbon Percentage lost , halfLife of C-14
 Output    : Age of object  
*/
double computeAge(double lostMass,double halfLife){
   
   double presentMass = 100-lostMass; // Present Mass 
   
   if(presentMass == 100){
       return 0;
   }
   if(presentMass == 0){
       return -1;
   }
   double age = (log10(presentMass/100.0)/log10(0.5) * halfLife);
   return age;
}

int main()
{
    double lostMass,presentMass,age;
    
    /* Carbon-14 half life*/
    double halfLife = 5730;
    
    /* Input : Percentage of carbon lost */
    printf("How much carbon has been lost(0-100%)?");
    scanf("%lf",&lostMass); // 
    
    /* Validation of Percentage of carbon lost input */
    if(lostMass>100 || lostMass <0){
        printf("Invalid input");
        return 0;
    }
    
    /* Age computation by using Carbon Percentage lost and Carbon-14 half life */
    age = computeAge(lostMass,halfLife);
    
    
    /* Output : Age of the object based on carbon-14 dating */
    if(age == -1){ // To handle infinity age
        printf("The object is infinite years old.");
        return 0;
    }
    printf("The object is %lf years old.",age);

    return 0;
}
