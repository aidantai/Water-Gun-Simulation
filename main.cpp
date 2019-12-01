#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <algorithm>
#include <boost/array.hpp>


int main() {
    srand(time(NULL)); // Random seed
    unsigned short simulations = 100;
    unsigned short population = 10;
    unsigned short dimensions = 10;

    for (int s = 0; s < simulations; s++) {
        
        double XYZ[population][dimensions];
        for (int p = 0; p < population; p++) {
            for (int d = 0; d < dimensions; d++) {
                XYZ[p][d] = ((double) rand() / (RAND_MAX));
            }
        }

        std::vector<boost::array<double, dimensions> > soakedPoints;

        for (int subject = 0; subject < population; subject++) {
            double minDist = 3;
            double XYZclosest[dimensions];
            for (int target = 0; target < population; target++) {
                if (subject != target) {
                    double dist = 0;
                    for (int d = 0; d < dimensions; d++) {
                        dist += pow((XYZ[target][d] - XYZ[subject][d]), 2);
                    }
                    if (dist < minDist) {
                        minDist = dist;
                        for (int d = 0; d < dimensions; d++) {
                            XYZclosest[d] = XYZ[target][d];
                        }
                    }
                }
            }
            std::vector<double>::iterator it;
            it = find(soakedPoints.begin(), soakedPoints.end(), );
            double *foo = std::find(std::begin(soakedPoints), std::end(soakedPoints), )
        }

Foo array[10];
... // Init the array here
Foo *foo = std::find(std::begin(array), std::end(array), someObject);
// When the element is not found, std::find returns the end of the range
if (foo != std::end(array)) {
    cerr << "Found at position " << std::distance(array, foo) << endl;
} else {
    cerr << "Not found" << endl;
}


    }
}