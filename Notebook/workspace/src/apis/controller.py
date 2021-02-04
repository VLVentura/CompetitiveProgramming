import os

from src.apis.cf import Cf
from src.apis.uri import Uri
from src.apis.uva import Uva

import src.util.colors as colors
import src.util.utils as util


class ApiController:
    _judges = {
        'uri': Uri,
        'cf': Cf,
        'uva': Uva
    }
    _judges_folder_name = util.JUDGES_FOLDER_NAME

    @staticmethod
    def execute(judge, problem):
        problem_data = ApiController.get_data(judge, problem)
        path_to_problem = ApiController.create_folders(judge, problem_data['name'])
        ApiController.create_files(judge, path_to_problem, problem_data['test_cases'])

    @staticmethod
    def create_files(judge, path_to_problem, problem_data):
        print(colors.CBLUE2 + colors.CBOLD + 'CREATING TEST CASES' + colors.CEND)
        for i, path in enumerate(problem_data):
            with open(path_to_problem + 'input/in{}.in'.format(i), 'w') as file:
                file.write(problem_data[i][0])
            with open(path_to_problem + 'output/cmp{}.out'.format(i), 'w') as file:
                file.write(problem_data[i][1])
                if judge != 'uva':
                    file.write('\n')

    @staticmethod
    def create_folders(judge, problem_name):
        ApiController.create_test_cases_folder()

        root_path = 'TestCases/'
        folder_name = ApiController._judges_folder_name[judge]
        for i in range(2):
            if folder_name not in os.listdir(root_path):
                print(colors.CBLUE2 + colors.CBOLD + 'CREATING \'{}\' FOLDER'.format(folder_name) + colors.CEND)
                os.mkdir(root_path + folder_name)
                if i == 1:
                    os.mkdir(root_path + folder_name + '/input/')
                    os.mkdir(root_path + folder_name + '/output/')

            root_path = root_path + folder_name + '/'
            folder_name = problem_name

        return root_path

    @staticmethod
    def create_test_cases_folder():
        folder_name = 'TestCases'
        create_folder = True

        for thing in os.listdir():
            if os.path.isdir(thing) and thing == folder_name:
                create_folder = False
                break
        if not create_folder:
            return

        print(colors.CBLUE2 + colors.CBOLD + 'CREATING TEST CASES FOLDER' + colors.CEND)
        os.mkdir(folder_name)

    @staticmethod
    def get_data(name, problem):
        """
        - URI
            param name -> 'uri': str
            param problem -> 1130: str or int

        - CF
            param name -> 'cf': str
            param problem -> '1461F': str

        -UVa
            param name -> 'uva': str
            param problem -> '272': int

        - Return: dict\n
            dict['name'] -> problem name\n
            dict['test_cases'] -> test cases[0]: input, test_cases[1]: output
        """
        judge = ApiController._judges[name](problem)
        return {'name': judge.problem_name, 'test_cases': judge.problem_data}
