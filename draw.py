from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import csv

log = dict()
bodies = list()
def draw(startfile,outfile):
	with open(startfile) as file:
		raw_data = csv.reader(file, delimiter=',')
		for row in raw_data:
			if row[0] == "#Body":
				log[row[1]]=[[],[],[]]
				bodies.append(row[1])

	with open(outfile) as file:
		raw_data = csv.reader(file, delimiter=',')

		for row in raw_data:
			if row[0] in bodies:
				log[row[0]][0].append(float(row[2]))
				log[row[0]][1].append(float(row[3]))
				log[row[0]][2].append(float(row[4]))


	fig = plt.figure()
	ax = fig.add_subplot(111, projection='3d')

	for body in bodies:
		ax.scatter((log[body][0]), (log[body][1]), (log[body][2]))

	plt.savefig("1.png")
	plt.show()

if __name__ == "__main__":
	draw("burn_test.start","output.txt")
