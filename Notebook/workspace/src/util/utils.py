import json
import os
import pathlib


def get_settings():
    with open('src/util/settings.json', 'r') as file:
        return json.load(file)


def get_authorization_code():
    return get_settings()['udebug_authorization_code']


JUDGES_FOLDER_NAME = {
    'uri': 'Uri',
    'cf': 'CodeForces',
    'uva': 'UVa'
}

num_cpp_files = len(list(pathlib.Path().glob(r'*.cpp')))
num_java_files = len(list(pathlib.Path().glob(r'*.java')))
num_py_files = len(list(pathlib.Path().glob(r'*.py'))) - 1


def get_file_name(extension: str):
    if extension is None:
        return None

    for file in os.listdir():
        if extension in file and file != 'run.py':
            return file
    return None


def get_file_extension():
    try:
        check_if_extensions_are_valid()
    except FileExistsError as error:
        raise error

    if num_cpp_files != 0:
        return '.cpp'
    elif num_java_files != 0:
        return '.java'
    elif num_py_files != 0:
        return '.py'

    return None


def check_if_extensions_are_valid():
    if (num_py_files == 1 and (num_java_files >= 1 or num_cpp_files >= 1)) or num_py_files > 1:
        raise FileExistsError('Too much files. Select one to continue.')
    elif (num_java_files == 1 and (num_py_files >= 1 or num_cpp_files >= 1)) or num_java_files > 1:
        raise FileExistsError('Too much files. Select one to continue.')
    elif (num_cpp_files == 1 and (num_py_files >= 1 or num_java_files >= 1)) or num_cpp_files > 1:
        raise FileExistsError('Too much files. Select one to continue.')
