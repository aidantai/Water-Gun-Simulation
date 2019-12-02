#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>

int main() {
    srand(time(NULL)); // Random seed
    const int simulations = 1000;
    const int population = 1000;
    const int dimensions = 1;

    double totalSoakedAverages;

    for (int sim = 0; sim < simulations; sim++) {
        
        double numInSample = 0;

        // Create all random points
        double XYZ[population][dimensions]; 
        for (int p = 0; p < population; p++) {
            for (int d = 0; d < dimensions; d++) {
                XYZ[p][d] = ((double) rand() / (RAND_MAX));
            }
        }

        // I don't like this... but it creates a list for all the coordinates of soaked people. Defaults to -1. 
        // I could have used a vector but idk how to use multi-dimensional vectors.
        double soakedPoints[population][dimensions];
        for (int p = 0; p < population; p++) {
            for (int d = 0; d < dimensions; d++) {
                soakedPoints[p][d] = -5;
            }
        }
        int soakedIndex = 0;

        for (int subject = 0; subject < population; subject++) {
            double minDist = 3;
            double XYZclosest[dimensions];
            bool subjectInSample = true;
            bool targetInSample = true;

            for (int target = 0; target < population; target++) {
                if (subject != target) {
                    double dist = 0;
                    for (int d = 0; d < dimensions; d++) {
                        dist += ((XYZ[target][d] - XYZ[subject][d])*(XYZ[target][d] - XYZ[subject][d]));
                    }
                    if (dist < minDist) {
                        minDist = dist;
                        for (int d = 0; d < dimensions; d++) {
                            XYZclosest[d] = XYZ[target][d]; // XYZclosest becomes the target that will ultimately be shot
                        }
                    }
                }
            }

            for (int d = 0; d < dimensions; d++) {
                if (XYZ[subject][d] < 0.25 || XYZ[subject][d] > 0.75) {
                    subjectInSample = false;
                }
                if (XYZclosest[d] < 0.25 || XYZclosest[d] > 0.75) {
                    targetInSample = false;
                }
            }

            if (subjectInSample) {
                numInSample++;
            }

            if (targetInSample) {
                // Checks if the XYZclosest point already exists in soakedPoints.
                int matchCounter;
                bool alreadyExists = false;
                for (int s = 0; s <= subject; s++) {
                    matchCounter = 0;
                    for (int d = 0; d < dimensions; d++) {
                        if (XYZclosest[d] == soakedPoints[s][d]) {
                            matchCounter++;
                        }
                    }
                    if (matchCounter == dimensions) {
                        alreadyExists = true;
                    }
                }
                // Adds XYZclosest to soakedPoints if it isn't already there.
                if (!alreadyExists) {
                    for (int d = 0; d < dimensions; d++) {
                        soakedPoints[soakedIndex][d] = XYZclosest[d];
                    }
                    soakedIndex++;
                }
            }
        }

        // Find the number of soaked people in soakedPoints.
        bool endOfSP = false;
        double numSoaked = 0;
        for (int p = 0; p < population; p++) {
            for (int d = 0; d < dimensions; d++) {
                if (soakedPoints[p][d] == -5) {
                    endOfSP = true;
                    break;
                }
            }
            if (!endOfSP) {
                numSoaked++;
            } else {
                break;
            }
        }
        totalSoakedAverages += numSoaked/numInSample;
    }

    double aveSoaked = 100*totalSoakedAverages/simulations;

    std::cout << aveSoaked << std::endl;
}