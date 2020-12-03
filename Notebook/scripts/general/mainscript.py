import os

class Script:

    PATH_TO_SAVE_FILE = ''

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
            '-tout': (self.test, True),
            '-rmfiles': (self.remove_files, None),
            '-mkfiles': (self.make_files, None),
            '-sv': (self.save, self.args[2:])
        }
    
    def run(self):
        try:
            for i in range(1, len(self.args)):
                function, argv = self.flags[self.args[i]]
                if argv:
                    function(argv)
                else:
                    function()
        except IndexError:
            exit()

    def script_compile(self):
        print('<<< Compiling >>>')
        os.system('g++ {} -o problem -std=c++14 -O2 -Wall'.format(self.get_file_name()))

    def script_run(self):
        os.system('./problem')

    def compare(self):
        print('<<< Comparing out.out and cmp.out - if nothing was printed they\'re identical >>>')
        os.system('diff out.out cmp.out')

    def test(self, out):
        print('<<< Testing >>>')
        command = './problem'
        if out:
            command += ' < in.in > out.out'
        else:
            command += ' < in.in'
        os.system(command)
    
    def remove_files(self):
        print('<<< Removing Files >>>')
        os.system('rm *.out *.in problem')
    
    def make_files(self):
        print('<<< Making Files >>>')
        os.system('> in.in')
        os.system('> out.out')
        os.system('> cmp.out')
    
    def save(self, name):
        name = ' '.join(name)
        print('<<< Copying File >>>')
        os.system('cp {} {}/{}.cpp'.format(self.get_file_name(), Script.PATH_TO_SAVE_FILE, self.format_file_name(name)))
        del self.args[2:]

    def get_file_name(self):
        for file in os.listdir():
            if '.cpp' in file:
                return file
        print('Missing .cpp file')
    
    def format_file_name(self, name):
        return name.replace(' ', '\ ')