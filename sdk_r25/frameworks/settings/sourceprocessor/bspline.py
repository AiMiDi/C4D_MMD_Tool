'''
Simple B-spline evaluation using De Boor's algorithm
'''

class BSpline(object):
    def __init__(self, points, knots, degree):
        self.points = points
        self.knots = knots
        self.degree = degree
        
    def __call__(self, t):
        if t <= self.knots[0]:
            return self.points[0]
        elif t >= self.knots[-1]:
            return self.points[-1]
        for span in range(0, len(self.knots)-1):
            if self.knots[span+1] > t:
                break
        return self.deBoor(self.degree, span, t)

    def deBoor(self, j, span, t):
        if j == 0:
            return self.points[span]
        t0 = self.knots[span]
        tau = (t - t0) / (self.knots[span+self.degree+1-j] - t0)
        p0 = self.deBoor(j-1, span-1, t)
        p1 = self.deBoor(j-1, span, t)
        return tuple([(1-tau) * x0 + tau * x1 for x0, x1 in zip(p0, p1)]) 
