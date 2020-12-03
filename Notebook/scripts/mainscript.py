import os
import json

class Script:
    def __init__(self, args):
        self.settings = self.get_settings()
        self.args = args
        self.flags = {
            '-c': (self.script_compile, 'normal'),
            '-compile': (self.script_compile, 'normal'),
            '-cpedantic': (self.script_compile, 'pedantic'),
            '-cpd': (self.script_compile, 'pedantic'),
            '-r': (self.script_run, None),
            '-run': (self.script_run, None),
            '-cmp': (self.compare, None),
            '-compare': (self.compare, None),
            '-tin': (self.test, 'in'),
            '-tout': (self.test, 'out'),
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

    def script_compile(self, option):
        print('<<< Compiling >>>')
        os.system('{} {} -o problem'.format(self.settings['script_compile'][option], self.get_file_name()))

    def script_run(self):
        print('<<< Running >>>')
        os.system(self.settings[os.name]['script_run'])

    def compare(self):
        print('<<< Comparing out.out and cmp.out - {} >>>'.format(self.settings[os.name]['compare']['message']))
        os.system(self.settings[os.name]['compare']['command'])

    def test(self, option):
        print('<<< Testing >>>')
        os.system(self.settings[os.name]['test'][option])
    
    def remove_files(self):
        print('<<< Removing Files >>>')
        os.system(self.settings[os.name]['remove_files'])
    
    def make_files(self):
        print('<<< Making Files >>>')
        os.system(self.settings[os.name]['make_files'])
    
    def save(self, name):
        name = ' '.join(name)
        print('<<< Copying File >>>')
        if os.name == 'nt':
            command = 'copy {} {}'.format(self.get_file_name(), self.format_file_name(name))
        else:
            command = 'cp {} {}/{}.cpp'.format(self.get_file_name(), self.settings['path'], self.format_file_name(name))
        os.system(command)
        del self.args[2:]

    def get_file_name(self):
        for file in os.listdir():
            if '.cpp' in file:
                return file
        print('Missing .cpp file')
    
    def format_file_name(self, name):
        if os.name == 'nt':
            return '\"{}\{}.cpp\"'.format(self.settings['path'], name)
        return name.replace(' ', '\ ')
    
    def get_settings(self):
        with open('scripts/settings.json', 'r') as file:
            return json.load(file)