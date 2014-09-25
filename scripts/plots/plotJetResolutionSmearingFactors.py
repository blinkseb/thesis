#! /bin/env python

import matplotlib.pyplot as plt
import numpy

x = numpy.array([0.25, (1.1 + 0.5) / 2., (1.7 + 1.1) / 2., (2.3 + 1.7) / 2., (2.8 + 2.3) / 2., (3.2 + 2.8) / 2., (5. + 3.2) / 2.])
y = numpy.array([1.079, 1.099, 1.121, 1.208, 1.254, 1.395, 1.056])
yerr = numpy.array([[1.053, 1.071, 1.092, 1.162, 1.192, 1.332, 0.865], [1.105, 1.127, 1.150, 1.254, 1.316, 1.458, 1.247]])

ymin = min(yerr[0]) * 0.9
ymax = max(yerr[1]) * 1.05

one = numpy.empty(len(x))
one.fill(1)

for i in range(0, len(y)):
    yerr[0][i] = abs(yerr[0][i] - y[i])
    yerr[1][i] = abs(yerr[1][i] - y[i])

fig = plt.figure()

plt.plot(one, 'k--', aa=True)
plt.errorbar(x, y, yerr=yerr, fmt='o', color='#C44D58', markeredgecolor='#C44D58', aa=True)
plt.xlim(0, 5)
plt.ylim(ymin, ymax)


plt.xlabel('$|\eta|$')
plt.ylabel('f($|\eta|$)')

fig.savefig('jetResolutionSmearingFactors.pdf')
