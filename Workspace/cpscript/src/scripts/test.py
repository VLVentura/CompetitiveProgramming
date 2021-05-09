import os
import subprocess

import src.util.colors as colors
import src.util.utils as util


class Test:
    _settings = util.get_settings()
    _judges_folder_name = util.JUDGES_FOLDER_NAME

    @staticmethod
    def test_in(lang):
        print(colors.CBLUE2 + colors.CBOLD + 'TESTING: in option' + colors.CEND)
        command_to_test = Test._settings[os.name]['run'][lang]
        command_to_test += Test._settings['test']['std_output']
        os.system(command_to_test)

    @staticmethod
    def test_out(lang):
        print(colors.CBLUE2 + colors.CBOLD + 'TESTING: out option' + colors.CEND)
        command_to_test = Test._settings[os.name]['run'][lang]
        command_to_test += Test._settings['test']['output_to_file']
        os.system(command_to_test)

    @staticmethod
    def test_cases(args):
        judge = Test._judges_folder_name[str(args[0]).lower()]
        problem = str(args[1]).upper()

        root_path = 'TestCases'
        if root_path not in os.listdir():
            print('TestCases folder not found.')
            exit(-1)
        if judge not in os.listdir(root_path):
            print('{} folder not found.'.format(judge))
            exit(-1)

        problems_path = root_path + '/' + judge + '/'
        problem_folder = None
        for prob in os.listdir(problems_path):
            if prob.split(' ')[0] == problem:
                problem_folder = problems_path + prob + '/'
                break

        if problem_folder is None:
            print('problem folder not found')
            exit(-1)

        file_extension = args[2]
        command_to_run = Test._settings[os.name]['run'][file_extension]
        command_to_compare = Test._settings[os.name]['compare']['command']
        input_path = '\'' + problem_folder + 'input/'
        output_path = problem_folder + 'output/'
        log_file = ''
        
        print(colors.CBLUE2 + colors.CBOLD + 'RESULTS' + colors.CEND)
        for i in range(len(os.listdir(problem_folder + 'input/'))):
            subprocess.call(
                [command_to_run + ' < ' + '{}in{}.in\''.format(input_path, i) + ' > ' + 'out.out'], 
                shell=True, timeout=1
            )
            output_from_compare = subprocess.run(
                [command_to_compare, 'out.out', '{}cmp{}.out'.format(output_path, i)],
                capture_output=True, timeout=1
            )
            if output_from_compare.returncode == 1:
                print(colors.CRED2 + colors.CBOLD + ' X | TEST CASE #{} - FAILED'.format(i + 1) + colors.CEND)
                log_file += 'X | TEST CASE #{} - FAILED\n'.format(i + 1) + output_from_compare.stdout.decode('utf-8') + '\n'
            elif output_from_compare.returncode == 0:
                print(colors.CGREEN2 + colors.CBOLD + 'OK | TEST CASE #{} - SUCCESS'.format(i + 1) + colors.CEND)
            else:
                print(output_from_compare.stdout.decode('utf-8'))
        
        if log_file:
            with open('LOG.txt', 'w') as file:
                file.write(log_file)
            print(colors.CVIOLET + colors.CBOLD + '--  check LOG.txt to see the errors --' + colors.CEND)

    @staticmethod
    def compare():
        warning_message = Test._settings[os.name]['compare']['warning_message']
        print(colors.CBLUE2 + colors.CBOLD + 'COMPARING out.out and cmp.out' + colors.CEND.format())
        print(colors.CVIOLET + colors.CBOLD + '--  {} --'.format(warning_message) + colors.CEND)
        command_to_compare = Test._settings[os.name]['compare']['execute']
        os.system(command_to_compare)
