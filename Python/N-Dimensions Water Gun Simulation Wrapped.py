# Thought experiment: If you randomly generated some number of people on a 2D plane at random (x,y) coordinates, 
# gave them all waterguns, and had them shoot the person closest to them once, what fraction of them would be wet?

import random
import statistics as stat
lenList = [] # List of the number of people who were soaked in each simulation
simulations = 30 # has to be more than 1 to calculate standard deviation.
population = 2000
dimensions = 1
random.seed(9)

for simulation in range(simulations):

	XYZ = [] # list of people's coordinates per simulation
	for people in range(population): # coordinates per person
		randomPoint = [None] * dimensions
		for d in range(dimensions):
			randomPoint[d] = random.random()
		XYZ.append(randomPoint)
		
	soakedPoints = [] # List of the locations of soaked people
	samplePoints = [] # Points in smaller square
	numInSample = 0;

	for s in range(len(XYZ)): # Goes through each subject s
		minDist = 100000
		XYZclosest = [None] * dimensions
		targetInSample = True
		subjectInSample = True

		for t in range(len(XYZ)): # Determines closest target t for subject s
			if (s != t):
				dist = 0
				for d in range(dimensions):
					dist += (XYZ[t][d] - XYZ[s][d])**2
				if dist < minDist:
					minDist = dist
					XYZclosest = XYZ[t]

		for d in range(dimensions):
			if XYZ[s][d] < .25 or XYZ[s][d] > .75:
				subjectInSample = False
			if XYZclosest[d] < .25 or XYZclosest[d] > .75:
				targetInSample = False
		if subjectInSample:
			numInSample += 1
		if ((XYZclosest not in soakedPoints) and targetInSample):
			soakedPoints.append(XYZclosest) # Add soaked person to soakedPoints

	if numInSample != 0:
		lenList.append(len(soakedPoints)/numInSample) # Appends fraction people soaked for given simulation

	if (len(lenList) > 1 and simulation % 1 == 0):
		aveSoaked = sum(lenList)/len(lenList)
		print("Simulation ", simulation, ". Average: ", 100*aveSoaked, ". Standard Deviation: ", stat.stdev(lenList), ". Median: ", stat.median(lenList), sep='')

aveSoaked = sum(lenList)/len(lenList)
stanDev = stat.stdev(lenList)
med = stat.median(lenList)

print("\n", simulations, " simulations run with population ", population, sep='')
print("Average percent soaked across all simulations: ", 100*aveSoaked) # Average fraction of soaked people per simulation
print("Standard deviation:", stanDev)
print("Median:", med)