import argparse

import src.util.utils as util
from src.apis.controller import ApiController
from src.scripts.controller import ScriptsController


class Script:
    def __init__(self):
        self._settings = util.get_settings()
        self._args = self._get_args()

    def run(self):
        for arg, function in self._get_execute():
            if arg and function[0] not in ['uri', 'cf']:
                ScriptsController.execute(function[0], function[1])
            elif arg and function[0] in ['uri', 'cf']:
                ApiController.execute(function[0], function[1])

    def _get_execute(self):
        file_name = self._file_name_to_save()
        args_to_compile = [self._args['version'], self._args['pedantic']]
        language = self._args['lang']

        excluded_args = ['version', 'lang', 'pedantic', 'uri_problem', 'cf_problem', 'yes_to_all']
        args = [
            val for key, val in self._args.items() if key not in excluded_args
        ]
        commands = [
            ('compile', args_to_compile), ('run', language),
            ('test_in', language), ('test_out', language), ('test_cases', self._args['test_cases']),
            ('make_files', language), ('remove_files', None), ('compare', None),
            ('save', file_name), ('copy', file_name),
            ('uri', self._args['uri_problem']), ('cf', self._args['cf_problem'])
        ]
        return zip(args, commands)

    def _file_name_to_save(self):
        file_name = None
        if self._args['copy_file'] or self._args['save_file'] is not None:
            file_name = util.get_file_name(util.get_file_extension())
            if file_name is None:
                print('No file to save.')
                exit(-1)
            elif self._args['copy_file']:
                file_name = file_name.split('.')[0]
            else:
                file_name = ' '.join(self._args['save_file'])

        return file_name

    def _get_args(self):
        """
        - Compiler Options\n
            -c -l cpp(default) -v=14*(default) -pd=False*(default)
            -c -l java*
            -c -l py*
        
        - General Options*
            -r\n
            -t | -tin | -tout\n
            -mkfiles | rmfiles\n
            -cmp\n
            -sv actual file name(default) | -cp
        
        - Judges\n
            -uri -urip=problem**\n
            -cf -cfp=problem**\n
        
        * -> optional\n
        ** -> required
        """
        parser = argparse.ArgumentParser()

        compiler = parser.add_argument_group('compiler options')
        compiler.add_argument('-c', '--compile', help='compile the program', action='store_true')

        default_language = self._settings['default_language']
        default_version = self._settings['compiler']['cpp']['default_version']
        pedantic = self._settings['compiler']['cpp']['pedantic']
        pedantic_choices = [1, True] if pedantic is False else [0, False]
        yes_to_all = self._settings['yes_to_all']
        yes_choices = [1, True] if yes_to_all is False else [0, False]

        compiler.add_argument('-l', '--lang', type=str, default=default_language, choices=['cpp', 'java', 'py'],
                              help='select the language to program: ' + default_language + ' by default')
        compiler.add_argument('-v', '--version', type=str, default=default_version, choices=['11', '14', '17'],
                              help='compiler version: ' + default_version + ' by default - c++ option')
        compiler.add_argument('-pd', '--pedantic', type=bool, default=pedantic, choices=pedantic_choices,
                              help='pedantic flag: {} by default - c++ option'.format(pedantic))

        general_problems = parser.add_argument_group('general problems')
        run_group = general_problems.add_mutually_exclusive_group()
        run_group.add_argument('-r', '--run', help='run the program', action='store_true')
        run_group.add_argument('-tin', '--test-in', action='store_true',
                               help='run the program with the inputs from in.in file')
        run_group.add_argument('-tout', '--test-out', action='store_true',
                               help='run the program with the input from in.in file and output to out.out file')
        run_group.add_argument('-tc', '--test-cases', nargs='+',
                               help='test all the cases from the problem - format: <judge> <problem>')

        files_group = general_problems.add_mutually_exclusive_group()
        files_group.add_argument('-mkfiles', '--make-files', help='creates problem.cpp *.in and *.out files',
                                 action='store_true')
        files_group.add_argument('-rmfiles', '--remove-files', help='removes *.in, *.out, *.class and problem',
                                 action='store_true')

        parser.add_argument('-cmp', '--compare', help='compare out.out with cmp.out files', action='store_true')

        save_option = parser.add_mutually_exclusive_group()
        save_option.add_argument('-sv', '--save-file', nargs='+', type=str,
                                 help='save file as <name that you passed>.<lang> to path specified at settings')
        save_option.add_argument('-cp', '--copy-file', action='store_true',
                                 help='copy file to path specified at settings')

        judges = parser.add_argument_group('judges options')
        judges.add_argument('-uri', '--uri-judge', help='URI "API"', action='store_true')
        judges.add_argument('-urip', '--uri-problem', help='get tests cases from this uri problem', type=int)
        judges.add_argument('-cf', '--code-forces', help='CodeForces "API"', action='store_true')
        judges.add_argument('-cfp', '--cf-problem', help='get tests cases from this code forces problem', type=str)

        return vars(parser.parse_args())
