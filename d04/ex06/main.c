#include "header.h"

int main(int ac, char **av)
{
        unsigned int parkingRow;
        int pos;

        if (ac == 3 && (pos = atoi(av[2])) >= 0 && pos < 20) {
                parkingRow = atoi(av[1]);
        }else{
                printf("Usage: ./setPlace parkingRow pos\n");
                return (0);
        }
        
        printf("New parking row: %d\n", setPlace(parkingRow, pos));

        return (0);
}



// Function used for the test
// Don't go further :)

