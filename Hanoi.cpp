#include <iostream>
#include <vector>

void moveDisk(int disk, char source, char destination) {
    std::cout << "Move disk " << disk << " from peg " << source << " to peg " << destination << std::endl;
}

void towerOfHanoi(int disks, char source, char auxiliary, char destination) {
    if (disks == 1) {
        moveDisk(disks, source, destination);
        return;
    }
    towerOfHanoi(disks - 1, source, destination, auxiliary);
    moveDisk(disks, source, destination);
    towerOfHanoi(disks - 1, auxiliary, source, destination);
}

int main() {
    int numDisks = 3; // Change the number of disks here
    std::cout << "Number of disks: " << numDisks << std::endl;

    char source = 'A';
    char auxiliary = 'B';
    char destination = 'C';

    towerOfHanoi(numDisks, source, auxiliary, destination);

    return 0;
}

