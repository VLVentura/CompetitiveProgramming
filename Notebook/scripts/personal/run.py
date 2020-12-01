#!/usr/bin/env python3.8
import sys
import os

class Run:

    def __init__(self, mode, name='File', path='~/GitHub/CompetitiveProgramming/Solutions'):
        self.path = path
        self.name = self.formatFileName(name)
        self.command, self.txt = self.wichCommand(mode)

    def __call__(self):
        print(self.txt)
        os.system(self.command)
    
    def wichCommand(self, mode):
        if mode == '-mk':
            if 'problem' not in os.listdir('.'):
                os.mkdir('./problem')
                os.chdir('problem/')
                os.system('> in.in && > output.out')
                os.chdir('..')
            return ('cp Template.cpp problem/ && cp run.py problem/', '<<< Creating workspace >>>')
        if mode == '-c':
            return ('g++ -std=c++14 -Wall -O2 ' + self.getFileName() + ' -o program', '<<< Compiling >>>')
        if mode == '-r':
            return ('./program', '<<< Running >>>')
        if mode == '-tout':
            return ('./program < in.in > out.out', '<<< Test with output in out file >>>')
        if mode == '-tp':
            return ('./program < in.in', '<<< Test with print output >>>')
        if mode == '-diff':
            # Need to install colordiff
            return ('colordiff -s -c out.out output.out', '<<< Checking differences between two outputs')
        if mode == '-sv':
            return ('cp {} {}/{}.cpp'.format(self.getFileName(), self.path, self.name), '<<< Copying file >>>')
        if mode == '-rm':
            if 'problem' in os.listdir('.'):
                return ('rm -rf problem/', '<<< Deleting workspace >>>')
            return ('ls', '<<< Workspace was not created >>>')
    
    def getFileName(self):
        for file in os.listdir('.'):
            if file[-3:] == 'cpp':
                return file
    
    def formatFileName(self, name):
        return name.replace(' ', '\ ')

if __name__ == '__main__':
    args = sys.argv

    if len(args) == 2:
        Run(args[1])()
    elif len(args) == 3:
        Run(args[1], args[2])()
    else:
        Run(args[1], args[2], args[3])()