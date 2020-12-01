import os

class Script:
    def __init__(self, args):
        self.args = args
        self.flags = {
            '-c': (self.script_compile, None),
            '-compile': (self.script_compile, None),
            '-r': (self.script_run, None),
            '-run': (self.script_run, None),
            '-cmp': (self.compare, None),
            '-compare': (self.compare, None),
            '-tin': (self.test, False),
            '-tout': (self.test, True)
        }
    
    def run(self):
        for i in range(1, len(self.args)):
            function, argv = self.flags[self.args[i]]
            if argv:
                function(argv)
            else:
                function()

    def script_compile(self):
        os.system('echo Compiling')
        os.system('g++ {} -o problem -std=c++14 -O2 -Wall -pedantic'.format(self.get_file_name()))

    def script_run(self):
        os.system('./problem')

    def compare(self):
        os.system('echo Comparing out.out and cmp.out - if nothing was printed they\'re identical')
        os.system('diff out.out cmp.out')

    def test(self, out):
        os.system('echo Testing')
        command = './problem'
        if out:
            command += ' < in.in > out.out'
        else:
            command += ' < in.in'
        os.system(command)
    
    def get_file_name(self):
        for file in os.listdir():
            if '.cpp' in file:
                return file
        print('Missing .cpp file')