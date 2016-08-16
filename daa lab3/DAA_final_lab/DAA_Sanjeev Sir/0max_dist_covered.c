#include <stdio.h>
 
// Returns maximum distance that can be traveled by n bikes and given fuel
// in every bike
double maxDistance(int n, int fuel)
{
    // dist_covered is the result of this function
    double dist_covered = 0;
 
    while (n > 0)
    {
        // after ever fuel/n km we are discarding one bike and filling
        // all the other bikes with fuel/n liters of fuel i.e. to their
        // maximum limit (100 litre)
 
        dist_covered += (double)fuel / n;
 
        n -= 1;  // reduce number of bikes
    }
    return dist_covered;
}
 
// Driver program to test above function
int main()
{
    int n = 3; // number of bikes
    int fuel = 100;
    printf("Maximum distance possible with %d bikes is %f",
            n, maxDistance(n, fuel));
    return 0;
}
