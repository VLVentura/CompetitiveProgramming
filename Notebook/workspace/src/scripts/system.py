import os

import src.util.colors as colors
import src.util.utils as util


class System:
    try:
        _file_extension = util.get_file_extension()
        _settings = util.get_settings()
        _file_name = util.get_file_name(_file_extension)
    except FileExistsError as error:
        print('ERROR:', error)

    @staticmethod
    def compile(args):
        if System._file_extension == '.py':
            print(colors.CBLUE2 + colors.CBOLD + 'DONT NEED TO COMPILE PYTHON FILE' + colors.CEND)
            return

        print(colors.CBLUE2 + colors.CBOLD + 'COMPILING' + colors.CEND)
        command_to_compile = None
        if System._file_extension == '.java':
            command_to_compile = System._settings['compiler']['java']['compile']
            command_to_compile += ' Main.java'

        if System._file_extension == '.cpp':
            version = args[0]
            command_to_compile = System._settings['compiler']['cpp']['compile'] + version + ' '
            command_to_compile = command_to_compile if args[1] is False else command_to_compile + '-pedantic '
            command_to_compile += '\'' + System._file_name + '\' -o problem'

        if command_to_compile is None:
            print(colors.CBLUE2 + colors.CBOLD + 'ERROR TRYING TO COMPILING' + colors.CEND)
            exit(-1)

        os.system(command_to_compile)

    @staticmethod
    def run(lang):
        print(colors.CBLUE2 + colors.CBOLD + 'RUNNING' + colors.CEND)
        command_to_run = System._settings[os.name]['run'][lang]
        os.system(command_to_run)

    @staticmethod
    def make_files(lang):
        print(colors.CBLUE2 + colors.CBOLD + 'MAKING FILES' + colors.CEND)
        command_to_make_files = System._settings[os.name]['make']['input_and_output_files']
        os.system(command_to_make_files)

    @staticmethod
    def remove_files():
        print(colors.CBLUE2 + colors.CBOLD + 'REMOVING FILES' + colors.CEND)
        command_to_remove_files = System._settings[os.name]['remove_files']
        os.system(command_to_remove_files)

    @staticmethod
    def save_file(file_name):
        print(colors.CBLUE2 + colors.CBOLD + 'SAVING FILE' + colors.CEND)

        path_to_save_file = System._settings['path_to_save_file']
        if len(path_to_save_file) == 0:
            print('Need to specify a path at settings.json')
            exit(-1)

        file_name = file_name + System._file_extension
        path_to_save_file += '/"' + file_name + '"'
        command_to_save_file = System._settings[os.name]['copy'] + ' ' + System._file_name + ' ' + path_to_save_file
        os.system(command_to_save_file)
