# Thought experiment: If you randomly generated some number of people on a 2D plane at random (x,y) coordinates, 
# gave them all waterguns, and had them shoot the person closest to them once, what fraction of them would be wet?

import random
import statistics as stat
import math

lenList = [] # List of the number of people who were soaked in each simulation
simulations = 50 # has to be more than 1 to calculate standard deviation.
population = 1000

for simulation in range(simulations):
	random.seed(simulation)
	XY = []
	soakedPoints = [] # List of the locations of soaked people

	for people in range(population):
		r = random.random()
		theta = random.random()*2*math.pi
		XY.append([r*math.cos(theta), r*math.sin(theta)])

	for s in range(len(XY)): # Goes through each subject s
		minDist = 3
		xmin, ymin = 0, 0
		for t in range(len(XY)): # Determines closest target t for subject s
			if (s != t):
				dist = (XY[t][0] - XY[s][0])**2 + (XY[t][1] - XY[s][1])**2
				if dist < minDist:
					minDist = dist
					xmin, ymin = XY[t] 
		if [xmin, ymin] not in soakedPoints:
			soakedPoints.append([xmin, ymin]) # Add soaked person to soakedPoints

	lenList.append(len(soakedPoints)) # Appends number of people soaked for given simulation
	if (simulation > 1 and simulation % 10 == 0):
		aveSoaked = sum(lenList)/len(lenList)
		print("Simulation ", simulation, ". Average: ", 100*aveSoaked/population, ". Standard Deviation: ", stat.stdev(lenList), ". Median: ", stat.median(lenList), sep='')

aveSoaked = sum(lenList)/len(lenList)
stanDev = stat.stdev(lenList)
med = stat.median(lenList)

print("\n", simulations, " simulations run with population ", population, sep='')
print("Average percent soaked across all simulations: ", 100*aveSoaked/population) # Average fraction of soaked people per simulation
print("Standard deviation:", stanDev)
print("Median:", med, "\n")

