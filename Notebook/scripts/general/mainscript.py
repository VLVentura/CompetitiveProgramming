import os

class Script:

    PATH_TO_SAVE_FILE = r''

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
                if argv != None:
                    function(argv)
                else:
                    function()
        except IndexError:
            exit()

    def script_compile(self):
        print('<<< Compiling >>>')
        os.system('g++ {} -o problem -std=c++14 -O2 -Wall'.format(self.get_file_name()))

    def script_run(self):
        print('<<< Running >>>')
        command = 'problem.exe' if os.name == 'nt' else './problem'
        os.system(command)

    def compare(self):
        if os.name == 'nt':
            warning = 'fc command do not show the \'\\n\' (new line) character in the end of the file!' 
            command = 'fc'
        else:
            warning = 'if nothing was printed they\'re identical'
            command = 'diff'
        print('<<< Comparing out.out and cmp.out - {} >>>'.format(warning))
        os.system('{} out.out cmp.out'.format(command))

    def test(self, out):
        print('<<< Testing >>>')
        command = 'problem.exe' if os.name == 'nt' else './problem'
        if out:
            command += ' < in.in > out.out'
        else:
            command += ' < in.in'
        os.system(command)
    
    def remove_files(self):
        print('<<< Removing Files >>>')
        command = 'del' if os.name == 'nt' else 'rm'
        extension = '.exe' if os.name == 'nt' else ''
        os.system('{} *.out *.in problem{}'.format(command, extension))
    
    def make_files(self):
        print('<<< Making Files >>>')
        command = 'copy NUL' if os.name == 'nt' else '>'
        os.system('{} in.in'.format(command))
        os.system('{} out.out'.format(command))
        os.system('{} cmp.out'.format(command))
    
    def save(self, name):
        name = ' '.join(name)
        print('<<< Copying File >>>')
        if os.name == 'nt':
            command = 'copy {} {}'.format(self.get_file_name(), self.format_file_name(name))
        else:
            command = 'cp {} {}/{}.cpp'.format(self.get_file_name(), Script.PATH_TO_SAVE_FILE, self.format_file_name(name))
        os.system(command)
        del self.args[2:]

    def get_file_name(self):
        for file in os.listdir():
            if '.cpp' in file:
                return file
        print('Missing .cpp file')
    
    def format_file_name(self, name):
        if os.name == 'nt':
            return '\"{}\{}.cpp\"'.format(Script.PATH_TO_SAVE_FILE, name)
        return name.replace(' ', '\ ')