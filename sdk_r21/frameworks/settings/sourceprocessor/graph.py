'''
MAXON API Graph Module
'''

import sys
import bspline
import array
import math
from lexer import *
from declarations import *


class CharLine(object):
    def __init__(self, s):
        self.array = bytearray(s, 'ascii')
        # self.array = array.array('B', s)

    def __getitem__(self, col):
        return self.array[col] if 0 <= col and col < len(self.array) else ord(' ')


emptyCharLine = CharLine('')


class CharMatrix(object):
    def __init__(self, str):
        lines = str.rstrip().split('\n')
        self.width = max([len(line) for line in lines])
        self.height = len(lines)
        self.lines = [CharLine(line + ' ' * (self.width - len(line))) for line in lines]

    def __getitem__(self, row):
        return self.lines[row] if 0 <= row and row < self.height else emptyCharLine


directionMap = [# direction 'right':        ??        ??
                #                     --?  -'   -.?  -*?   ->           
                #                                ??   ??
                [(0, ord('-'), [0]), (0, ord('\''), [1, 2]), (0, ord('.'), [0, 6, 7]), (0, ord('*'), [0, 1, 7, 2, 6]), (0, ord('>'), None), (0, ord('|'), False)],
                # direction 'top-right':  ?  ?           ???
                #                        /   |   ,?  .?   *?
                #                       /   /   /   /    / ? 
                [(1, ord('/'), [1]), (1, ord('|'), [2]), (1, ord('.'), [0]), (1, ord(','), [0]), (1, ord('*'), [1, 2, 0, 3, 7])],
                # direction 'top': ?    ?  ?    ?  ??? 
                #                   \   |  :   /   ?*?  ?.?  ,?  ^
                #                    |  |  |  |     |    |   |   |
                [(3, ord('\\'), [3]), (2, ord('|'), [2]), (2, ord(':'), [2]), (1, ord('/'), [1]), (2, ord('*'), [2, 3, 1, 4, 0]), (2, ord('.'), [0, 4]), (2, ord(','), [0]), (2, ord('^'), None), (2, ord('-'), False)],
                # direction 'top-left':  ?    ?       ???
                #                         \   |  ?.   ?*
                #                          \   \   \  ? \
                [(3, ord('\\'), [3]), (3, ord('|'), [2]), (3, ord('.'), [4]), (3, ord('*'), [3, 4, 2, 5, 1])],
                # direction 'left':       ??  ??            ??
                #                     ?--  '-  `- ?.-  ,-   ?*-   <-
                #                                 ??  ??    ??
                [(4, ord('-'), [4]), (4, ord('\''), [2, 3]), (4, ord('`'), [2, 3]), (4, ord('.'), [4, 5, 6]), (4, ord(','), [5, 6]), (4, ord('*'), [4, 5, 3, 6, 2]), (4, ord('<'), None), (4, ord('|'), False)],
                # direction 'bottom-left':   /   /    /   ? /
                #                           /   |   ?'    ?*
                #                          ?    ?         ??? 
                [(5, ord('/'), [5]), (5, ord('|'), [6]), (5, ord('\''), [4]), (5, ord('*'), [5, 6, 4, 7, 3])],
                # direction 'bottom':   |  |  |  |     |    |   |   |
                #                      /   |  :   \   ?*?  ?'?  `?  v
                #                     ?    ?  ?    ?  ???
                [(5, ord('/'), [5]), (6, ord('|'), [6]), (6, ord(':'), [6]), (7, ord('\\'), [7]), (6, ord('*'), [6, 7, 5, 0, 4]), (6, ord('\''), [0, 4]), (6, ord('`'), [0]), (6, ord('v'), None), (6, ord('-'), False)],
                # direction 'bottom-right': \    \   \    \ ?
                #                            \    |   `?   *?
                #                             ?   ?       ???
                [(7, ord('\\'), [7]), (7, ord('|'), [6]), (7, ord('`'), [0]), (7, ord('*'), [7, 0, 6, 1, 5])]
                ] 

crossingChars = set([ord('-'), ord('|'), ord(':'), ord('/'), ord('\\')])

dx = [1, 1, 0, -1, -1, -1, 0, 1]
dy = [0, -1, -1, -1, 0, 1, 1, 1]
diamondChar = [ord('<'), -1, ord('v'), -1, ord('>'), -1, ord('^'), -1]
triangleChar = [ord('|'), -1, ord('-'), -1, ord('|'), -1, ord('-'), -1]

fx = 6
fy = 15
wirex = 3
wirey = 8
inportx = 4
outportx = 1
portrad = 3


def tuplemul(t, s):
    return tuple([x*s for x in t])

def tupleadd(t, s):
    return tuple([x+s for x in t])

def vadd(a, b):
    return (a[0]+b[0], a[1]+b[1])

def vsub(a, b):
    return (a[0]-b[0], a[1]-b[1])

def vlen(v):
    return math.sqrt(v[0]*v[0]+v[1]*v[1])

def listmul(l, s):
    return [tuple([x*s for x in t]) for t in l]

class MagDraw(object):
    def __init__(self, draw, mag):
        self.draw = draw
        self.mag = mag

    def rectangle(self, xy, fill, outline):
        xy = listmul(xy, self.mag)
        for i in range(0, self.mag):
            self.draw.rectangle([tupleadd(xy[0], i), tupleadd(xy[1], self.mag-1-i)], fill=fill, outline=outline)

    def polygon(self, xy, outline, filled):
        if filled:
            self.draw.polygon(listmul(xy, self.mag), fill=outline)
        return self.line(xy + [xy[0]], outline)

    def line(self, xy, fill):
        return self.draw.line([tuple([round(x*self.mag) for x in t]) for t in xy], fill=fill, width=self.mag)

    def ellipse(self, xy, outline):
        xy = listmul(xy, self.mag)
        for i in range(0, self.mag):
            self.draw.ellipse([tupleadd(xy[0], i), tupleadd(xy[1], self.mag-1-i)], outline=outline)

    def text(self, xy, s, fill, font):
        return self.draw.text(tuplemul(xy, self.mag), s, fill=fill, font=font)

    def textsize(self, s, font):
        return tuple([round(x*1.0/self.mag) for x in self.draw.textsize(s, font=font)])

def isPortNamePart(ch):
    return isIdentifierPart(ch) or ch in ['<', ',', '>', '.']


class WireAttribs(object):
    def __init__(self, attribs=None):
        self.color = attribs.color if attribs else 'black'
        self.text = attribs.text if attribs else ''
        self.dashed = attribs and attribs.dashed
        self.dotted = attribs and attribs.dotted
        self.diamond = attribs and attribs.diamond
        self.triangle = attribs and attribs.triangle
        self.filled = attribs and attribs.filled
        self.undirected = attribs and attribs.undirected

WIREATTRIBS_DEFAULT = WireAttribs()

def dirDist(a, b):
    dist = abs(a - b)
    return dist if dist < 4 else 8 - dist

# we have reached the position (r,c) from direction prevDir and may continue in the directions given by dirs
def trackWire(source, r, c, startDir, prevDir, prevChar, dashDotCnt, addPointCnt, dirs, matrix, portPoints, points, length, attribs, maybeTriangle=False):
    for step in range(2):
        found = False
        tracked = set()
        for dir in dirs:
            for d, ch, newDirs in directionMap[dir]:
                r2 = r+dy[d]
                c2 = c+dx[d]
                if matrix[r2][c2] == ch and not (r2, c2) in tracked and not (prevChar == ord('*') and (ch == prevChar or dirDist(d, prevDir) > 2)):
                    tracked.add((r2, c2))
                    a = attribs
                    ddc = dashDotCnt
                    if prevDir == d and (prevChar == ord(':') or prevChar == ord('.')):
                        a = WireAttribs(a)
                        a.dotted = True
                        ddc = 1
                    elif ddc == 1:
                        if ch == ord(':') or ch == ord('.'):
                            a = WireAttribs(a)
                            a.dashed = True
                        ddc = 0
                    addPoint = d != prevDir or addPointCnt > 5
                    if addPoint:
                        points.append((r2, c2))
                    if not newDirs:
                        if newDirs == False:
                            port = portPoints.get((r2, c2), None)
                        else:
                            r2 += dy[d]
                            c2 += dx[d]
                            port = portPoints.get((r2, c2), None)
                            if not port:
                                r2 += dy[d]
                                c2 += dx[d]
                                port = portPoints.get((r2, c2), None)
                        if port:
                            points.append((r2, c2))
                            if maybeTriangle or newDirs == False:
                                a = WireAttribs(a)
                                if maybeTriangle:
                                    a.triangle = True 
                                if newDirs == False:
                                    a.undirected = True
                            source.connections.append((port, [p for p in points], length, a, startDir, d))
                            points.pop()
                        if port or (newDirs == None):
                            found = True
                    else:
                        trackWire(source, r2, c2, startDir, d, ch, ddc, 0 if addPoint else addPointCnt+1, newDirs, matrix, portPoints, points, length + step + 1, a, maybeTriangle)
                        found = True
                    if addPoint:
                        points.pop()
        if found or len(dirs) != 1:
            return
        r += dy[dirs[0]]
        c += dx[dirs[0]]
        ch = matrix[r][c]
        if ch == ord(' '):
            attribs = WireAttribs(attribs)
            attribs.dashed = True
        elif ch == diamondChar[dirs[0]]:
            attribs = WireAttribs(attribs)
            attribs.diamond = True
            if matrix[r+dy[dirs[0]]][c+dx[dirs[0]]] == ord('*'):
                attribs.filled = True
        elif ch == ord('#') or ch == ord('"'):
            if dir != 4:
                end = c + 1
                while matrix[r][end] != ch:
                    if end >= matrix.width:
                        return
                    end += 1
                s = matrix[r].array[c+1:end].decode('ascii')
            else:
                end = c - 1
                while matrix[r][end] != ch:
                    if end < 0:
                        return
                    end -= 1
                s = matrix[r].array[end+1:c].decode('ascii')
            if dir == 0 or dir == 4:
                c = end
            if ch == ord('#'):
                attribs = WireAttribs(attribs)
                attribs.color = '#' + s
            elif ch == ord('"'):
                attribs = WireAttribs(attribs)
                attribs.text = s
        elif ch in crossingChars:
            maybeTriangle = ch == triangleChar[dirs[0]]
        else:
            break
            

class GraphObject(object):
    def __init__(self, name):
        self.children = []
        self.name = name
        self.connections = []

    def toPoint(self, p, dir):
        if dir == 0:
            return (p[1]*fx+fx, p[0]*fy+wirey)
        elif dir == 4:
            return (p[1]*fx, p[0]*fy+wirey)
        elif dir == 2:
            return (p[1]*fx+wirex, p[0]*fy)
        elif dir == 6:
            return (p[1]*fx+wirex, p[0]*fy+fy)
        else:
            return (p[1]*fx+wirex, p[0]*fy+wirey)

    def drawWires(self, draw):
        arrowx = 6
        arrowy = 4
        if isinstance(self, Port):
            if self.input:
                start = (self.column*fx+self.textwidth+14, self.row*fy+wirey)
            else:
                start = (self.column*fx+outportx+portrad, self.row*fy+wirey)
        for c, points, length, attribs, startDir, dir in self.connections:
            start = self.toPoint(points[0], startDir)
            end = c.toPoint(points[-1], (dir+4) & 7)
            arrow1 = (end[0]-dx[dir]*arrowx+dy[dir]*arrowy, end[1]+dx[dir]*arrowy-dy[dir]*arrowx)
            arrow2 = (end[0]-dx[dir]*arrowx-dy[dir]*arrowy, end[1]-dx[dir]*arrowy-dy[dir]*arrowx)
            if attribs.diamond:
                dend = (end[0]-2*dx[dir]*arrowx, end[1]-2*dy[dir]*arrowx)
                draw.polygon([arrow1, end, arrow2, dend], attribs.color, attribs.filled)
                end = dend
            elif attribs.triangle:
                dend = (end[0]-dx[dir]*arrowx, end[1]-dy[dir]*arrowx)
                draw.polygon([arrow1, end, arrow2], attribs.color, attribs.filled)
                end = dend
            elif not attribs.undirected:
                draw.line([arrow1, end, arrow2], attribs.color)
            points = [start] + [(p[1]*fx+wirex, p[0]*fy+wirey) for p in points[1:-1]] + [end]
            n = len(points) - 1
            k = min(n - 1, 3)          # degree of curve
            m = n + k + 1  # property of b-splines: m = n + k + 1
            _t = 1.0 / (m - k * 2) # t between clamped ends will be evenly spaced
            # clamp ends and get the t between them
            t = k * [0] + [t_ * _t for t_ in range(m - (k * 2) + 1)] + [1] * k
            spline = bspline.BSpline(points, t, k)
            pts = [start]
            steps = 2*length
            for i in range(1, steps):
                t_ = i * (1.0 / steps)
                x, y = spline(t_)
                pts.append((x, y))
            pts.append(end)
            pathlen = 0
            for i in range(1, len(pts)):
                pathlen += vlen(vsub(pts[i], pts[i-1]))
            if attribs.dotted:
                if attribs.dashed:
                    numPts = (int(round(pathlen * 0.08)) * 3) + 3 # numPts will be divisible by 3 and >= 3
                else:
                    numPts = (int(round(pathlen * 0.18)) | 1) + 3 # numPts will be even and >= 4
            else:
                numPts = (int(round(pathlen * 0.25)) | 1) + 3 # numPts will be even and >= 4
            arclenPts = [start]
            i = 1
            arclen = 0
            center = None
            tangent = None
            for s in range(1, numPts-1):
                t = s * (pathlen / (numPts-1))
                while True:
                    a = vlen(vsub(pts[i], pts[i-1]))
                    if t-arclen < a:
                        break
                    i += 1
                    arclen += a
                t = (t-arclen) / a
                pt = vadd(tuplemul(pts[i-1], 1-t), tuplemul(pts[i], t))
                arclenPts.append(pt)
                if 2*s == numPts-2:
                    center = pt
                elif 2*s == numPts:
                    tangent = vsub(pt, center)
                    center = tuplemul(vadd(center, pt), 0.5)
            arclenPts.append(end)
            if attribs.dotted:
                d = (0.5, 0.5)
                if attribs.dashed:
                    for i in range(0, numPts, 3):
                        draw.line([arclenPts[i], arclenPts[i+1]], fill=attribs.color)
                        draw.ellipse([vsub(arclenPts[i+2], d), vadd(arclenPts[i+2], d)], outline=attribs.color)
                else:
                    for i in range(0, numPts):
                        draw.ellipse([vsub(arclenPts[i], d), vadd(arclenPts[i], d)], outline=attribs.color)
            elif attribs.dashed:
                for i in range(0, numPts, 2):
                    draw.line([arclenPts[i], arclenPts[i+1]], fill=attribs.color)
            else:
                draw.line(arclenPts, fill=attribs.color)
            if attribs.text:
                w, h = draw.textsize(attribs.text, font=draw.font)
                if abs(tangent[0]) > abs(tangent[1]):
                    pos = vsub(center, (w*0.5,h+2))
                else:
                    pos = vadd(center, (3,0))
                draw.text(pos, attribs.text, fill=attribs.color, font=draw.font)

        
class Port(GraphObject):
    def __init__(self, name, row, column, columnEnd, input):
        GraphObject.__init__(self, name)
        self.row = row
        self.column = column
        self.columnEnd = columnEnd
        self.rowEnd = row
        self.input = input

    def toPoint(self, p, dir):
        if dir == 0:
            if self.input:
                return (self.column*fx+self.textwidth+13, self.row*fy+wirey)
            else:
                return (p[1]*fx+fx, p[0]*fy+wirey)
        elif dir == 4:
            if self.input:
                return (self.column*fx, self.row*fy+wirey)
            else:
                return (self.column*fx-self.textwidth-7, self.row*fy+wirey)
        else:
                return GraphObject.toPoint(self, p, dir)

    # dir is 1 for inputs and -1 for outputs
    @staticmethod
    def parse(matrix, portPoints, row, column, dir):
        children = []
        while True:
            line = matrix.lines[row]
            if line[column] != ord('o'):
                return (row, children)
            name = ''
            columnEnd = column 
            if line[column + dir] == ord(' '):
                start = column + 2*dir
                i = start
                while isPortNamePart(chr(line[i])):
                    columnEnd = i
                    i += dir
                name = (line.array[start:i] if dir > 0 else line.array[i+1:start+1]).decode('ascii')
            port = Port(name, row, column, columnEnd, dir > 0)
            for c in range(min(column, columnEnd), max(column,columnEnd)+1):
                portPoints[(row, c)] = port
            row, port.children = Port.parse(matrix, portPoints, row+1, column+dir, dir)
            for p in port.children:
                p.owner = port
            port.rowEnd = row-1
            children.append(port)

    def parseWires(self, matrix, portPoints, errors):
        line = matrix[self.row]
        if self.input:
            c = self.columnEnd
        else:
            c = self.column
        if line[c+1] != ord(' '):
            trackWire(self, self.row, c, 0, -1, 0, 0, 0, [0], matrix, portPoints, [(self.row, c)], 1, WIREATTRIBS_DEFAULT)
        elif line[c+2] != ord(' '):
            trackWire(self, self.row, c+1, 0, -1, 0, 0, 0, [0], matrix, portPoints, [(self.row, c)], 1, WIREATTRIBS_DEFAULT)
        for col in range(min(self.column, self.columnEnd), max(self.column, self.columnEnd)+1):
            if matrix[self.row-1][col] == ord('|'):
                trackWire(self, self.row, col, 2, -1, 0, 0, 0, [2], matrix, portPoints, [(self.row, col)], 1, WIREATTRIBS_DEFAULT)
            if matrix[self.row+1][col] == ord('|'):
                trackWire(self, self.row, col, 6, -1, 0, 0, 0, [6], matrix, portPoints, [(self.rowEnd, col)], 1, WIREATTRIBS_DEFAULT)
        for p in self.children:
            p.parseWires(matrix, portPoints, errors)

    def dumpHierarchy(self, indent):
        sys.stdout.write(indent + (self.name if self.name else '?') + '\n')
        for c, points, length, attribs, startDir, dir in self.connections:
            sys.stdout.write(indent + ' -> ' + (c.name if c.name else '?') + '\n')
        for c in self.children:
            c.dumpHierarchy(indent + ' ')

    def drawWidth(self, draw):
        self.textwidth = 0
        if self.name:
            self.textwidth, h = draw.textsize(self.name, font=draw.font)
        width = self.textwidth + 12
        for c in self.children:
            cw = c.drawWidth(draw) + fx
            if cw > width:
                width = cw
        self.width = width
        return width  
            
    def draw(self, draw, nesting):
        gray = 210 - nesting * 15
        if self.input:
            draw.rectangle([(self.column*fx, self.row*fy), (self.column*fx+self.width, self.rowEnd*fy+fy)], fill=(gray, gray, 255), outline='black')
        else:
            draw.rectangle([(self.column*fx-self.width+fx-1, self.row*fy), (self.column*fx+fx-1, self.rowEnd*fy+fy)], fill=(255, gray, gray), outline='black')
        cx = self.column*fx + (inportx if self.input else outportx)
        cy = self.row*fy + wirey
        draw.ellipse([(cx-portrad, cy-portrad), (cx+portrad, cy+portrad)], outline='black')
        if self.name:
            if self.input:
                draw.text((cx + portrad + 4, self.row*fy + 1), self.name, fill='black', font=draw.font)
            else:
                draw.text((cx - self.textwidth - portrad - 2, self.row*fy + 1), self.name, fill='black', font=draw.font)
        for c in self.children:
            c.draw(draw, nesting+1)
            
    def drawConnections(self, draw):
        for c in self.children:
            c.drawConnections(draw)
        self.drawWires(draw)


class Node(GraphObject):
    def __init__(self, owner, name, transparent, pos, row, column, rowEnd, columnEnd):
        GraphObject.__init__(self, name)
        self.owner = owner
        if owner:
            owner.children.append(self)
        self.inports = []
        self.outports = []
        self.text = []
        self.transparent = transparent
        self.blankVerticalBorder = False
        self.rootPos = pos
        self.row = row
        self.column = column
        self.rowEnd = rowEnd
        self.columnEnd = columnEnd

    def dumpHierarchy(self, indent):
        sys.stdout.write(indent + (self.name if self.name else '?') + '\n')
        if self.inports:
            sys.stdout.write(indent + ' in\n')
            for p in self.inports:
                p.dumpHierarchy(indent + '  ')
        if self.outports:
            sys.stdout.write(indent + ' out\n')
            for p in self.outports:
                p.dumpHierarchy(indent + '  ')
        for c in self.children:
            c.dumpHierarchy(indent + ' ')

    def position(self, row, column):
        return SourcePosition(self.rootPos.file, 0, self.rootPos.line + row, self.rootPos.pos + column)
    
    def parseNested(self, matrix, portPoints, nodePoints, errors):
        for row in range(self.row, self.rowEnd+1):
            nodePoints[(row, self.column)] = self
            nodePoints[(row, self.columnEnd)] = self
        for col in range(self.column+1, self.columnEnd):
            nodePoints[(self.row, col)] = self
            nodePoints[(self.rowEnd, col)] = self
        for row in range(self.row+1, self.rowEnd):
            line = matrix.lines[row]
            for column in range(self.column+1, self.columnEnd):
                n = None
                if line[column] == ord('+'):
                    # we have found a new nested node, parse its top line which might include a name
                    columnEnd = -1
                    name = ''
                    transparent = True
                    for c in range(column+1, self.columnEnd):
                        if line[c] == ord('+'):
                            columnEnd = c
                            break
                        elif line[c] == ord('-'):
                            transparent = False
                        else:
                            name += chr(line[c])
                    name = name.strip()
                    if columnEnd < 0:
                        errors.append(self.position(row, column), 'No top-right +')
                        return False
                    rowEnd = -1
                    r = row+1
                    inports = []
                    blankBorder = None
                    while r < self.rowEnd:
                        x = matrix[r][column]
                        if x == ord('+'):
                            rowEnd = r
                            break
                        elif x == ord('o'):
                            r, list = Port.parse(matrix, portPoints, r, column, 1)
                            inports += list
                        else:
                            r += 1
                        if x != ord(' ') and x != ord('-'):
                            blankBorder = False
                        elif blankBorder == None:
                            blankBorder = True
                    if rowEnd < 0: 
                        errors.append(self.position(row, column), 'No bottom-left +')
                        return False
                    if matrix[rowEnd][columnEnd] != ord('+'):
                        errors.append(self.position(rowEnd, columnEnd), 'Expected bottom-right + at this position')
                        return False
                    n = Node(self, name, transparent, self.rootPos, row, column, rowEnd, columnEnd)
                    n.inports = inports
                    n.blankVerticalBorder = blankBorder == True
                    for p in inports:
                        p.owner = n
                    r = row+1
                    while r < rowEnd:
                        if matrix[r][columnEnd] == ord('o'):
                            r, list = Port.parse(matrix, portPoints, r, columnEnd, -1)
                            for p in list:
                                p.owner = n
                                n.outports.append(p)
                        else:
                            r += 1
                    r = row+1
                    while r < rowEnd:
                        x = matrix[r][column]
                        if x == ord('|') and matrix[r][column+1] != ord(' '):
                            n.text.append((r, column+1, ''.join(chr(ch) for ch in matrix[r].array[column+1:columnEnd]).rstrip()))
                            for c in range(column+1, columnEnd):
                                matrix.lines[r].array[c] = ord(' ')
                        r += 1
                elif line[column] == ord('#') and line[column+1] in [ord(' '), ord('-'), ord('<')] and line[column-1] in [ord(' '), ord('-'), ord('>')]:
                    # we have found a new one-char node
                    n = Node(self, '', True, self.rootPos, row, column, row, column)
                elif line[column] == ord('"') and line[column-1] != ord('-'):
                    # check if we have found a text label.
                    end = column + 1
                    while end < matrix.width:
                        if line[end] == ord('"'):
                            # To distinguish from a text label for a wire, we check the surrounding characters
                            if line[end+1] != ord('-'):
                                if all(c == ord(' ') for c in matrix[row-1].array[column:end+1]) or all(c == ord(' ') for c in matrix[row+1].array[column:end+1]):
                                    s = line.array[column+1:end].decode('ascii')
                                    self.text.append((row, column, s))
                                    for c in range(column, end+1):
                                        matrix.lines[row].array[c] = ord(' ')
                            break
                        end += 1
                if n:
                    if not n.parseNested(matrix, portPoints, nodePoints, errors):
                        return False
                    for r in range(n.row,n.rowEnd+1):
                        for c in range(n.column, n.columnEnd+1):
                            matrix.lines[r].array[c] = ord(' ')
        return True

    def parseWires(self, matrix, portPoints, nodePoints, errors):
        for p in self.inports:
            p.parseWires(matrix, portPoints, errors)
        for p in self.outports:
            p.parseWires(matrix, portPoints, errors)
        for c in self.children:
            c.parseWires(matrix, portPoints, nodePoints, errors)
        for row in range(self.row, self.rowEnd+1):
            line = matrix[row]
            ch = ord('|') if row > self.row and row < self.rowEnd else matrix[self.row][self.column]
            if line[self.columnEnd] == ch and line[self.columnEnd+1] == ord('-'):
                trackWire(self, row, self.columnEnd, 0, -1, 0, 0, 0, [0], matrix, nodePoints, [(row, self.columnEnd)], 1, WIREATTRIBS_DEFAULT)
            if line[self.column] == ch and line[self.column-1] == ord('-'):
                trackWire(self, row, self.column, 4, -1, 0, 0, 0, [4], matrix, nodePoints, [(row, self.column)], 1, WIREATTRIBS_DEFAULT)
        for col in range(self.column, self.columnEnd+1):
            ch = ord('-') if col > self.column and col < self.columnEnd else matrix[self.row][self.column]
            if (matrix[self.row][col] != ord('|') if ch == ord('-') else matrix[self.row][col] == ch) and matrix[self.row-1][col] == ord('|'):
                trackWire(self, self.row, col, 2, -1, 0, 0, 0, [2], matrix, nodePoints, [(self.row, col)], 1, WIREATTRIBS_DEFAULT)
            if matrix[self.rowEnd][col] == ch and matrix[self.rowEnd+1][col] == ord('|'):
                trackWire(self, self.rowEnd, col, 6, -1, 0, 0, 0, [6], matrix, nodePoints, [(self.rowEnd, col)], 1, WIREATTRIBS_DEFAULT)

    def writeImage(self, path):
        from PIL import Image, ImageDraw, ImageFont
        mag = 6
        img = Image.new('RGB', (fx * self.columnEnd * mag, fy * self.rowEnd * mag), 'white')
        draw = MagDraw(ImageDraw.Draw(img), mag)
        processorPath = os.path.abspath(os.path.dirname(sys.argv[0]))
        draw.font = ImageFont.load(os.path.join(processorPath, 'frutiger.pil'))
        self.drawChildren(draw, 0)
        for c in self.children:
            c.drawConnections(draw)
        self.drawLabels(draw)
        img = img.resize((fx * self.columnEnd, fy * self.rowEnd), resample=Image.LANCZOS)
        img.save(path, 'PNG')

    def drawChildren(self, draw, nesting):
        for s in range(0, 2):
            for c in self.children:
                if (s==1) == c.blankVerticalBorder:
                    c.draw(draw, nesting)
                    
    def drawLabels(self, draw):
        for r, col, txt in self.text:
            if txt and all([c=='-' for c in txt]):
                draw.line([(self.column*fx, (r+0.5)*fy), (self.columnEnd*fx+fx-1, (r+0.5)*fy)], fill='black')
            else:
                draw.text(((col-1)*fx + 3, r*fy + 1), txt, fill='black', font=draw.font)
        
    def draw(self, draw, nesting):
        if not self.transparent:
            gray = 240 - nesting * 10
            draw.rectangle([(self.column*fx, self.row*fy), (self.columnEnd*fx+fx-1, self.rowEnd*fy+fy-1)], fill=(gray,gray,gray), outline='black')
            if self.blankVerticalBorder:
                draw.rectangle([(self.column*fx-1, self.row*fy+1), (self.columnEnd*fx+fx, self.rowEnd*fy+fy-2)], fill=(gray,gray,gray), outline=(gray,gray,gray))
        if self.name:
            draw.text((self.column*fx + 3, self.row*fy + 1), self.name, fill='black', font=draw.font)
        self.drawChildren(draw, nesting+1)
        for p in self.inports:
            p.drawWidth(draw)
            p.draw(draw, 0)
        for p in self.outports:
            p.drawWidth(draw)
            p.draw(draw, 0)
        self.drawLabels(draw)

    def drawConnections(self, draw):
        for c in self.children:
            c.drawConnections(draw)
        for p in self.inports:
            p.drawConnections(draw)
        for p in self.outports:
            p.drawConnections(draw)
        self.drawWires(draw)

canBeUsedResult = None

def canBeUsed():
    global canBeUsedResult
    if canBeUsedResult == None:
        try:
            from PIL import Image, ImageDraw, ImageFont
            canBeUsedResult = True
        except (KeyboardInterrupt, SystemExit):
            raise
        except:
            canBeUsedResult = False
    return canBeUsedResult
                    
def parseGraph(graphString, errors, pos):
    matrix = CharMatrix(graphString)
    root = Node(None, 'Root', True, SourcePosition(pos.file, 0, pos.line + graphString.pos.line - 1, pos.pos + 4), -1, -1, matrix.height, matrix.width)
    portPoints = {}
    nodePoints = {}
    if not root.parseNested(matrix, portPoints, nodePoints, errors):
        return None
    matrix = CharMatrix(graphString)
    root.parseWires(matrix, portPoints, nodePoints, errors)
    return root

def parseGraphWriteImage(graphToken, errors, pos, dir):
    makeDir(dir)
    imgName = 'graph_' + base32HashCode(graphToken) + '.png'
    file = os.path.join(dir, imgName)
    if os.path.isfile(file) and os.path.getmtime(file) > os.path.getmtime(__file__):
        return imgName
    g = parseGraph(graphToken, errors, pos)
    if not g:
        removeFile(file)
        return None
    g.writeImage(file)
    return imgName

def main():
    errors = []
    file = sys.argv[1]
    str = ''
    f = open(file, 'r')
    for line in f:
        str += line
    f.close()
    g = parseGraph(Token(str, Token.GRAPH, SourcePosition(file, 0, 0, 0)), errors, SourcePosition(file, 0, 0, 0))
    if g:
        g.writeImage(sys.argv[2])

if __name__ == "__main__":
    main()
